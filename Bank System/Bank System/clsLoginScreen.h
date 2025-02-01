#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen 
{

private:

    static bool _Login()
    {
        bool LoginFaild = false;
        short FaildLoginCount = 0;

        string Username, Password;
 
        do
        {
            if (LoginFaild)
            {
                FaildLoginCount++;

                cout << "\nInvlaid Username/Password!";
                cout << "\nU have " << (3 - FaildLoginCount) << " Trial(s) To Login.\n\n";
            }

            if (FaildLoginCount == 3) 
            {
                cout << "\nU are Locked after 3 Faild Trails \n\n";
                return false;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password); 

            LoginFaild = CurrentUser.IsEmpty(); 

        } while (LoginFaild);
        
        CurrentUser.RegisterLogIn();  
        clsMainScreen::ShowMainMenu(); 
        return true; 
    }


public:

    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader ("\t  Login Screen");
        
        return _Login(); 
    }

}; 