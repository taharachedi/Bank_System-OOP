#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsClient.h"
#include "clsInputValidate.h"


class clsFindClientScreen : protected clsScreen  
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


    static void ShowFindClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient)) 
        {
            return; // this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tFind Client Screen");

        cout << "\nPlease Enter Account Number: "; 
        string AccountNumber = clsInputValidate::Read_String(); 

        while (!clsClient::Is_Client_Exist(AccountNumber)) 
        {
            cout << "\nAccount Number Is Not Found, Choose Another One: ";
            AccountNumber = clsInputValidate::Read_String();  
        }

        clsClient Client = clsClient::Find(AccountNumber);

        if (!Client.Is_Empty()) 
        {
            cout << "\nClient Found :-)\n";
            _PrintClient(Client);
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

    }

};