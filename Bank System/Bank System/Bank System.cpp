#include <iostream>
#include "clsLoginScreen.h"

int main()
{
    system("color f3"); 
 

    while (true) {

        if (!clsLoginScreen::ShowLoginScreen())
        {
            break; 
        }
    }
    

    system("pause>0");
    return 0;
}