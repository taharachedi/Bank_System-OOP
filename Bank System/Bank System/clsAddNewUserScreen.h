#pragma once

#include <iostream>
#include <iomanip>
#include <cctype>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"


class clsAddNewUserScreen : protected clsScreen   
{

private:

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::Read_String();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::Read_String();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::Read_String();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::Read_String();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::Read_String();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet(); 
    }


    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';

        cout << "\nDo U Want To Give Full Access? (y/n) ";
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {
            return -1;
        }

        cout << "\nDo U Want To Give Access To : \n ";

        cout << "\nShow Client List? (y/n) ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? (y/n) ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient; 
        }

        cout << "\nDelete Client? (y/n) ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? (y/n) ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? (y/n) ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? (y/n) ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? (y/n) ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }


        cout << "\nShow Login Register? (y/n) ";
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            Permissions += clsUser::enPermissions::pLogInRegister;   
        }


        return Permissions;
    }


public:

    static void ShowAddNewUserScreen()
    {
        _DrawScreenHeader("\t  Add New User Screen");


        cout << "\nPlease Enter UserName: ";
        string UserName = clsInputValidate::Read_String(); 

        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Already Used, Choose Another One: ";
            UserName = clsInputValidate::Read_String(); 
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User Was Not Saved Because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError User Was Not Saved Because UserName is Used!\n";
            break;

        }
        }
    }

};