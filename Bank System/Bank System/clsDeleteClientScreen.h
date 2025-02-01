#pragma once

#include <iostream>
#include <cctype>

#include "clsScreen.h"
#include "clsClient.h"
#include "clsInputValidate.h"


class clsDeleteClientScreen : protected clsScreen
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



public:


    static void ShowDeleteClientScreen() {

        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tDelete Client Screen");  

        cout << "\nPlease Enter Account Number : ";
        string AccountNumber = clsInputValidate::Read_String();

        while (!clsClient::Is_Client_Exist(AccountNumber)) {

            cout << "\nAccount Number is Not Found, Choose Another One: ";
            AccountNumber = clsInputValidate::Read_String();
        }

        clsClient Client = clsClient::Find(AccountNumber);
        _PrintClient(Client); 

        cout << "\nAre U Sure U Want To Delete This Client (y/n?) ";
        char Answer = 'n';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            if (Client.Delete())
            {
                cout << "\nClient Deleted Successfully :-)\n";
                _PrintClient(Client);   
            }

            else
            {
                cout << "\nError Client Was not Deleted\n";
            }

        }

    }

};