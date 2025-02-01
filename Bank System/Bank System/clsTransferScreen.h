#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsClient.h"
#include "clsInputValidate.h"


class clsTransferScreen : protected clsScreen 
{

private:

    static void _PrintClientCard(clsClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName(); 
        cout << "\nAcc. Number : " << Client.Get_AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance; 
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        cout << "\nPlease Enter Account Number To Transfer : "; 
        string AccountNumber = clsInputValidate::Read_String(); 

        while (!clsClient::Is_Client_Exist(AccountNumber))
        {
            cout << "\nAccount Number is Not Found, Choose Another One: ";
            AccountNumber = clsInputValidate::Read_String(); 
        }
        return AccountNumber;
    }


    static float ReadAmount(clsClient SourceClient)
    {
        float Amount;
        cout << "\nEnter Transfer Amount? ";
        Amount = clsInputValidate::Read_Float_Number(); 

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds The Available Balance, Enter Another Amount ? ";
            Amount = clsInputValidate::Read_Float_Number(); 
        }
        return Amount;
    }



public:


    static void ShowTransferScreen()
    {

        _DrawScreenHeader("\tTransfer Screen");

        clsClient SourceClient = clsClient::Find(_ReadAccountNumber());
        _PrintClientCard(SourceClient);

        clsClient DestinationClient = clsClient::Find(_ReadAccountNumber());

        while (DestinationClient.Get_AccountNumber() == SourceClient.Get_AccountNumber()) {

            cout << "\nU Can't Transfer Money To Ur Self!!! ";
            DestinationClient = clsClient::Find(_ReadAccountNumber());
        }

        _PrintClientCard(DestinationClient); 

        float Amount = ReadAmount(SourceClient);


        cout << "\nAre U Sure U Want To Perform This Operation? (y/n)? ";
        char Answer = 'n';
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName)) 
            {
                cout << "\nTransfer Done Successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
        }

        _PrintClientCard(SourceClient);
        _PrintClientCard(DestinationClient);
    }


};