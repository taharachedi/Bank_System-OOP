#pragma once

#include <iostream>
#include <cctype>

#include "clsScreen.h"
#include "clsClient.h"
#include "clsInputValidate.h"


class clsDepositScreen : protected clsScreen 
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
        cout << "\nPlease Enter Account Number : ";
        string AccountNumber = clsInputValidate::Read_String();

        while (!clsClient::Is_Client_Exist(AccountNumber))
        {
            cout << "\nClient With [" << AccountNumber << "] Does Not Exist.\n";
            AccountNumber = clsInputValidate::Read_String();
        }
        return AccountNumber;
    }


public:


    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t   Deposit Screen");

        string AccountNumber = _ReadAccountNumber();

        clsClient Client = clsClient::Find(AccountNumber);
        _PrintClient(Client); 

        cout << "\nPlease Enter Deposit Amount? ";
        double Amount = clsInputValidate::Read_Double_Number();     

        cout << "\nAre U Sure U Want To Perform This Transaction? (Y/N)";
        char Answer = 'n';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            Client.Deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << Client.AccountBalance;  

        }
        else
        {
            cout << "\nOperation Was Cancelled.\n";
        }

    }

};