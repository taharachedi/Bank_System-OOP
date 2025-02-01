#pragma once

#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsCurrency.h"


class clsCurrenciesListScreen : protected clsScreen
{

private:

    static void _PrintCurrencyRecordLine(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(45) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();
    }


public:

    static void ShowCurrenciesListScreen()
    {
        vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();

        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Currency."; 

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________\n\n";

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";

        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________\n\n";


        if (vCurrency.size() == 0) 
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency Currency : vCurrency) 
            {

                _PrintCurrencyRecordLine(Currency); 
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________\n\n";

    }

};