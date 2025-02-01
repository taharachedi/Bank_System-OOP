#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "clsString.h"
using namespace std;

class clsCurrency
{

private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _Mode;

    string _Country;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate;

    static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#")
    {
        vector<string> vCurrencyData = clsString::Split(Line, Seperator);
        return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
    }

    static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
    {
        string stCurrencyRecord = "";

        stCurrencyRecord += Currency.Country() + Seperator;
        stCurrencyRecord += Currency.CurrencyCode() + Seperator;
        stCurrencyRecord += Currency.CurrencyName() + Seperator;
        stCurrencyRecord += to_string(Currency.Rate());

        return stCurrencyRecord;
    }

    static  vector <clsCurrency> _LoadCurrencyDataFromFile()
    {
        vector <clsCurrency> vCurrency;
        fstream My_File;

        My_File.open("Currencies.txt", ios::in); // Read Mode

        if (My_File.is_open())
        {
            string Line;

            while (getline(My_File, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                vCurrency.push_back(Currency);
            }

            My_File.close();
        }

        return vCurrency;  
    }

    static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrency)
    {
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::out); // Overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsCurrency C : vCurrency)  
            {
                DataLine = _ConvertCurrencyObjectToLine(C);    
                MyFile << DataLine << endl;
            }

            MyFile.close();
        }

    }

    void _Update()
    {
        vector <clsCurrency> _vCurrency = _LoadCurrencyDataFromFile();

        for (clsCurrency& C : _vCurrency)  
        {
            if (C.CurrencyCode() == CurrencyCode())
            {
                C = *this;
                //break;
            }
        }

        _SaveCurrencyDataToFile(_vCurrency);   
    }

    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(enMode::EmptyMode, "", "", "", 0);
    }


public:

    clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
    {
        _Mode = Mode; 
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
    }

    static vector <clsCurrency> GetAllUSDRates()
    {
        return _LoadCurrencyDataFromFile();   
    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    string Country()
    {
        return _Country;
    }

    string CurrencyCode()
    {
        return _CurrencyCode;
    }

    string CurrencyName()
    {
        return _CurrencyName;
    }

    void UpdateRate(float NewRate)
    {
        _Rate = NewRate;
        _Update(); // Update File
    }

    float Rate()
    {
        return _Rate;
    }


    static clsCurrency FindByCode(string CurrencyCode)
    {
        CurrencyCode = clsString::Upper_All_String(CurrencyCode); 

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in); //Read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

                if (Currency.CurrencyCode() == CurrencyCode)
                {
                    MyFile.close();
                    return Currency;
                }
            }

            MyFile.close();
        }

        return _GetEmptyCurrencyObject();
    }


    static clsCurrency FindByCountry(string Country)
    {
        Country = clsString::Upper_All_String(Country);  

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in); // Read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

                if (clsString::Upper_All_String(Currency.Country()) == Country)
                {
                    MyFile.close();
                    return Currency;
                }
            }

            MyFile.close();
        }

        return _GetEmptyCurrencyObject();
    }

    static bool IsCurrencyExist(string CurrencyCode)
    {
        clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
        return (!C1.IsEmpty());
    }

    static vector <clsCurrency> GetCurrenciesList()
    {
        return _LoadCurrencyDataFromFile();  
    }



    float ConvertToUSD(float Amount)
    {
        return (float)(Amount / Rate());
    }

    float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
    {
        float AmountInUSD = ConvertToUSD(Amount);

        if (Currency2.CurrencyCode() == "USD")
        {
            return AmountInUSD; 
        }

        return (float)(AmountInUSD * Currency2.Rate());
    }

};