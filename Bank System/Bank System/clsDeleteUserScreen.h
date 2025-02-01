#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen  
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
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

public:
    static void ShowDeleteUserScreen()
    {

        _DrawScreenHeader("\tDelete User Screen");

        cout << "\nPlease Enter UserName: ";
        string UserName = clsInputValidate::Read_String();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is Not Found, Choose Another One: ";
            UserName = clsInputValidate::Read_String();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\nAre U Sure U Want To Delete This User (y/n)? ";

        char Answer = 'n';
        cin >> Answer;

        if (toupper(Answer) == 'Y')
        {

            if (User.Delete()) 
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nError User Was Not Deleted\n";
            }

        }

    }

};