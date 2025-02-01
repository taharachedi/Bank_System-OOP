#pragma once

#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h" 
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h" 
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h" 

using namespace std; 

class clsTransactionsScreen : protected clsScreen 
{

private:

    enum enTransactionsMenuOptions {
        eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, 
        eTransfer = 4, eTransferLog = 5, eShowMainMenu = 6 
    };

    static short _ReadTransactionsMenuOption()
    {
        cout << setw(37) << left << "" << "Choose What Do U Want To Do? [1 to 6]? ";
        short Choice = clsInputValidate::Read_Short_Number_Between(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }


    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen(); 
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances(); 
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogScreen()
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }

    static void _GoBackToTransactionsMenu()
    {
        cout << "\n\nPress Any Key To Go Back To Transactions Menu...";

        system("pause>0");
        ShowTransactionsMenu();   
    }

    static void _PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionsMenuOption) 
    {
        switch (TransactionsMenuOption)  
        {
        case enTransactionsMenuOptions::eDeposit: 
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();   
            break;
        }

        case enTransactionsMenuOptions::eWithdraw: 
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenu();  
            break;
        }

        case enTransactionsMenuOptions::eShowTotalBalance: 
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenu();  
            break;
        }

        case enTransactionsMenuOptions::eTransfer:
        {
            system("cls"); 
            _ShowTransferScreen(); 
            _GoBackToTransactionsMenu(); 
            break;
        }

        case enTransactionsMenuOptions::eTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenu();
            break;
        }

        case enTransactionsMenuOptions::eShowMainMenu: 
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }


    }




public:


    static void ShowTransactionsMenu()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;// this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenuOption((enTransactionsMenuOptions)_ReadTransactionsMenuOption()); 
    }



};