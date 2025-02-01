#pragma once

#include <iostream>
#include <cctype>

#include "clsScreen.h"
#include "clsClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen 
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


    static void _Read_ClientInfo(clsClient& Client) {

        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::Read_String();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::Read_String();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::Read_String();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::Read_String();

        cout << "\nEnter PinCode: ";
        Client.PINCode = clsInputValidate::Read_String();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::Read_Float_Number();
    }


public:


    static void ShowUpdateClientScreen() {


        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\tUpdate Client Screen");

        cout << "\nPlease Enter Client Account Number : ";
        string AccountNumber = clsInputValidate::Read_String();

        while (!clsClient::Is_Client_Exist(AccountNumber)) {

            cout << "\nAccount Number is Not Found, Choose Another One: ";
            AccountNumber = clsInputValidate::Read_String();
        }

        clsClient Client = clsClient::Find(AccountNumber);
        _PrintClient(Client); 


        cout << "\nAre U Sure U Want To Update This Client (y/n)? ";  
        char Answer = 'n'; 
        cin >> Answer; 
         
        if (toupper(Answer) == 'Y')
        {
            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";

            _Read_ClientInfo(Client);

            clsClient::enSaveResults SaveResult = Client.Save();

            switch (SaveResult)
            {

            case clsClient::enSaveResults::svSuccessed:
            {
                cout << "\nAccount Updated Successfully :-)\n";
                _PrintClient(Client);     
                break;
            }

            case clsClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError Account Was Not Saved Because it's Empty";
                break;
            }

            }
        }

    }


};