#pragma once

#include <iostream>
#include <cctype>

#include "clsScreen.h"
#include "clsClient.h"
#include "clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen 
{

private:

    static void _PrintClient(clsClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.Get_AccountNumber();
        cout << "\nPIN Code    : " << Client.PINCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }


    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease Enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public:


    static void ShowWithdrawScreen() {

        _DrawScreenHeader("\t   Withdraw Screen");

        string AccountNumber = _ReadAccountNumber();

        while (!clsClient::Is_Client_Exist(AccountNumber)) 
        {
            cout << "\nClient With [" << AccountNumber << "] Does Not Exist.\n";
            AccountNumber = _ReadAccountNumber();
        }

        clsClient Client = clsClient::Find(AccountNumber);
        _PrintClient(Client); 


        cout << "\nPlease Enter Withdraw Amount? ";
        double Amount = clsInputValidate::Read_Double_Number(); 

        cout << "\nAre U Sure U Want To Perform This Transaction? (Y/N)";
        char Answer = 'n';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (Client.Withdraw(Amount)) 
            {
                cout << "\nAmount Withdrew Successfully.\n";
                cout << "\nNew Balance Is: " << Client.AccountBalance;
            }
            else
            {
                cout << "\nCannot Withdraw, Insufficient Balance!\n";
                cout << "\nAmout To Withdraw is: " << Amount;
                cout << "\nYour Balance is: " << Client.AccountBalance; 

            }
        }
        else
        {
            cout << "\nOperation Was Cancelled.\n";
        }
    }

};