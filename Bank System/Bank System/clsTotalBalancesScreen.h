#pragma once

#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsClient.h"
#include "clsUtil.h"


class clsTotalBalancesScreen : protected clsScreen 
{

private:

    static void _PrintClientRecordBalanceLine(clsClient Client)
    {

        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.Get_AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }


public:


    static void ShowTotalBalances()
    {

        vector <clsClient> vClients = clsClient::GetClientsList();

        string Title = "\t  Balances List Screen"; 
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";   

        _DrawScreenHeader(Title, SubTitle);  


        cout << setw(25) << left << "" << "\n\t\t_________________________________________________________________________________\n\n";

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";

        cout << setw(25) << left << "" << "\n\t\t_________________________________________________________________________________\n\n"; 


        double TotalBalances = clsClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";

        else

            for (clsClient Client : vClients)
            {
                _PrintClientRecordBalanceLine(Client);
                cout << endl;
            }

        cout << setw(25) << left << "" << "\n\t\t_________________________________________________________________________________\n\n"; 


        cout << setw(8) << left << "" << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
        cout << setw(8) << left << "" << "\t\t\t ( " << clsUtil::NumberToText(TotalBalances) << ")";
    }


};