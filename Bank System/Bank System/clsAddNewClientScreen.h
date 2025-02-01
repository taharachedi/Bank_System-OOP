#pragma once

#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsClient.h"
#include "clsInputValidate.h"


class clsAddNewClientScreen : protected clsScreen
{

private:

    static void _Read_ClientInfo(clsClient& Client) { 

        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::Read_String();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::Read_String();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::Read_String();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::Read_String();

        cout << "\nEnter PIN Code: ";
        Client.PINCode = clsInputValidate::Read_String();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::Read_Float_Number();
    }
    


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

    static void ShowAddNewClientScreen() {

        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\t  Add New Client Screen"); 

        cout << "\nPlease Enter Account Number : ";
        string AccountNumber = clsInputValidate::Read_String();

        while (clsClient::Is_Client_Exist(AccountNumber)) {

            cout << "\nAccount Number Is Already Used, Choose another one: ";
            AccountNumber = clsInputValidate::Read_String();
        }


        clsClient NewClient = clsClient::GetAddNewClientObject(AccountNumber);
        _Read_ClientInfo(NewClient);

        clsClient::enSaveResults SaveResults = NewClient.Save();

        switch (SaveResults)
        {

        case clsClient::enSaveResults::svSuccessed:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }

        case clsClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError Account Was Not Saved Because it's Empty";
            break;
        }

        case clsClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError Account Was Not Saved Because Account Number is Used!\n";
            break;
        }

        }

    }

};