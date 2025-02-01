#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h" 

using namespace std;

class clsUser : public clsPerson 
{

private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;

    string _UserName;
    string _Password;
    int _Permissions;
    bool _MarkedForDelete = false;


    static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],vUserData[3], 
            vUserData[4], DecryptedPassword(vUserData[5]), stoi(vUserData[6]));   

    }

    static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
    {
        string UserRecord = "";

        UserRecord += User.FirstName + Seperator;
        UserRecord += User.LastName + Seperator;
        UserRecord += User.Email + Seperator;
        UserRecord += User.Phone + Seperator;
        UserRecord += User.UserName + Seperator;
        //here we encypt store the encrypted Password not the real one.
        UserRecord += EncryptedPassword(User.Password) + Seperator;
        UserRecord += to_string(User.Permissions);

        return UserRecord;
    }

    static  vector <clsUser> _LoadUsersDataFromFile()
    {
        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in); //Read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                vUsers.push_back(User);
            }

            MyFile.close();
        }
        return vUsers;
    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out); //Overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsUser U : vUsers)
            {
                if (U.MarkedForDeleted() == false)
                {
                    //We Only Write Records That Are Not Marked For Delete.  
                    DataLine = _ConvertUserObjectToLine(U); 
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }

    }


    void _Update()
    {
        vector <clsUser> _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);
    }


    void _AddNew()
    {
        _AddDataLineToFile(_ConvertUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }


    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }


    string _PrepareLogInRecord(string Seperator = "#//#") {

        string LoginRecord = "";

        LoginRecord += clsDate::Get_SystemDateTimeString() + Seperator;
        LoginRecord += UserName + Seperator;
        //here we encypt store the encrypted Password not the real one.
        LoginRecord += EncryptedPassword(Password) + Seperator;  
        LoginRecord += to_string(Permissions); 

        return LoginRecord;    
    }


    struct stLoginRegisterRecord;
    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
    {
        stLoginRegisterRecord LoginRegisterRecord;
        vector <string> vLoginRegisterDataLine = clsString::Split(Line, Seperator);

        LoginRegisterRecord.DateTime = vLoginRegisterDataLine[0]; 
        LoginRegisterRecord.UserName = vLoginRegisterDataLine[1]; 
        LoginRegisterRecord.Password = DecryptedPassword(vLoginRegisterDataLine[2]);
        LoginRegisterRecord.Permissions = stoi(vLoginRegisterDataLine[3]); 

        return LoginRegisterRecord;
    }


    static vector <stLoginRegisterRecord> _LoadLoginRegisterDataFromFile() {

        vector <stLoginRegisterRecord> vLoginRegisterRecord; 
        fstream MyFile; 

        MyFile.open("LoginRegister.txt", ios::in); // Read Mode

        if (MyFile.is_open()) 
        {
            string Line; 
            stLoginRegisterRecord LoginRegisterRecord; 

            while (getline(MyFile, Line)) {

                LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line); 
                vLoginRegisterRecord.push_back(LoginRegisterRecord);
            }

            MyFile.close(); 
        }

        return vLoginRegisterRecord; 

    }
        




    static string EncryptedPassword(string Password) {

        return clsUtil::Encryption_Text(Password); 
    }
    static string DecryptedPassword(string Password) {

        return clsUtil::Decryption_Text(Password);
    }



public:

    enum enPermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClients = 8,
        pFindClient = 16, pTranactions = 32, pManageUsers = 64, pLogInRegister = 128 
    };

    struct stLoginRegisterRecord
    {
        string DateTime;
        string UserName;
        string Password;
        int Permissions;
    };


    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, 
        string UserName, string Password, int Permissions) 
        : clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }
    
    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }


    string GetUserName()
    {
        return _UserName;
    }
    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }
    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;



    void SetPassword(string Password)
    {
        _Password = Password;
    }
    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;


    
    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }
    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;



    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in); //Read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line); 

                if (User.UserName == UserName)  
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();
        }

        return _GetEmptyUserObject();
    }


    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in); //Read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                 
                if (User.UserName == UserName && User.Password == Password) 
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();
        }

        return _GetEmptyUserObject();
    }


    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {

        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            // This Will Add New Record To File Or Database
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();

                //We Need To Set The Mode To Update After Add New
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }

        }
    }


    static bool IsUserExist(string UserName)
    {
        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }


    bool Delete()
    {
        vector <clsUser> _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }
        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();
        return true;
    }


    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }


    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }



    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->Permissions == enPermissions::eAll)
            return true;

        if ((Permission & this->Permissions) == Permission)
            return true;
        else
            return false;

    }


    void RegisterLogIn() {

        string stDataLine = _PrepareLogInRecord();

        fstream My_File;
        My_File.open("LoginRegister.txt", ios::out | ios::app);

        if (My_File.is_open())
        {
            My_File << stDataLine << endl;

            My_File.close();
        }

    }


    static vector <stLoginRegisterRecord> GetLoginRegisterList()
    {
        return _LoadLoginRegisterDataFromFile();
    }

};