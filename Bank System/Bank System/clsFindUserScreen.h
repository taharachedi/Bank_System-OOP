#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen : protected clsScreen 
{

private:

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName    : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:

    static void ShowFindUserScreen()
    {

        _DrawScreenHeader("\t  Find User Screen");

        cout << "\nPlease Enter UserName: ";
        string UserName = clsInputValidate::Read_String(); 

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is Not Found, Choose Another One: ";
            UserName = clsInputValidate::Read_String(); 
        }

        clsUser User = clsUser::Find(UserName);

        if (!User.IsEmpty()) 
        {
            cout << "\nUser Found :-)\n";
            _PrintUser(User); 
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

    }
};