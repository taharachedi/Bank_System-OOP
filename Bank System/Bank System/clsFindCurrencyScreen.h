#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"


class clsFindCurrencyScreen : protected clsScreen 
{

private:

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();
        cout << "\n_____________________________\n";
    }

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was Not Found :-(\n";
        }
    }

public:

    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\t  Find Currency Screen");

        cout << "\nFind By: [1] Code or [2] Country ? ";
        short Answer = clsInputValidate::Read_Short_Number_Between(1, 2);

        if (Answer == 1)
        {
            cout << "\nPlease Enter CurrencyCode: ";
            string CurrencyCode = clsInputValidate::Read_String(); 

            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else
        {

            cout << "\nPlease Enter Country Name: ";
            string Country = clsInputValidate::Read_String();  

            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _ShowResults(Currency);
        }

    }


};