#pragma once

#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h" 

using namespace std;

class clsCurrencyExchangeMainScreen : protected clsScreen 
{

private:

    enum enCurrenciesMainMenuOptions {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
        eCurrencyCalculator = 4, eMainMenu = 5
    };

    static short ReadCurrenciesMainMenuOptions()
    {
        cout << setw(37) << left << "" << "Choose What Do U Want To Do? [1 to 5]? ";
        short Choice = clsInputValidate::Read_Short_Number_Between(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToCurrenciesMenu()
    {
        cout << "\n\nPress Any Key To Go Back To Currencies Menu...";
        system("pause>0");
        ShowCurrenciesMenu();
    }


    static void _ShowCurrenciesListScreen()
    {
        clsCurrenciesListScreen::ShowCurrenciesListScreen(); 
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen(); 
    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen(); 
    }

    static void _PerformCurrenciesMainMenuOptions(enCurrenciesMainMenuOptions CurrenciesMainMenuOptions)
    {
        switch (CurrenciesMainMenuOptions) 
        {
        case enCurrenciesMainMenuOptions::eListCurrencies: 
        {
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrenciesMenu(); 
            break;
        }

        case enCurrenciesMainMenuOptions::eFindCurrency: 
        { 
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrenciesMenu(); 
            break;
        }

        case enCurrenciesMainMenuOptions::eUpdateCurrencyRate: 
        {
            system("cls");
            _ShowUpdateCurrencyRateScreen();
            _GoBackToCurrenciesMenu();  
            break;
        }

        case enCurrenciesMainMenuOptions::eCurrencyCalculator:  
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrenciesMenu(); 
            break;
        }

        case enCurrenciesMainMenuOptions::eMainMenu:  
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }

public:

    static void ShowCurrenciesMenu()
    {
        system("cls");
        _DrawScreenHeader("    Currency Exhange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exhange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrenciesMainMenuOptions((enCurrenciesMainMenuOptions)ReadCurrenciesMainMenuOptions());
    }


};