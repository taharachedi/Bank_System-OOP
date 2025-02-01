#pragma once

#include <iostream>
#include <string> 
#include <vector>
#include <fstream>

#include "clsString.h" 
#include "clsDate.h" 
#include "clsPerson.h"  

using namespace std;  

class clsClient : public clsPerson
{

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };   
	enMode _Mode;   

	string _AccountNumber;
	string _PINCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;   


	static clsClient _ConvertLineToClientObject(string Line, string Seperator = "#//#") { 

		vector <string> vClient = clsString::Split(Line, Seperator);  
		return clsClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stof(vClient[6]));
	}

	static clsClient _GetEmptyClientObject() {

		return clsClient(enMode::EmptyMode, "", "", "", "", "", "", 0); 
	}

	static string _ConvertClientObjectToLine(clsClient Client, string Seperator = "#//#") {

		string Line = "";

		Line += Client.FirstName + Seperator; 
		Line += Client.LastName + Seperator;
		Line += Client.Email + Seperator;
		Line += Client.Phone + Seperator;
		Line += Client._AccountNumber + Seperator;
		Line += Client.PINCode + Seperator;
		Line += to_string(Client.AccountBalance);

		return Line;  
	}

	static vector <clsClient> _LoadClientsDataFromFile() {

		vector <clsClient> vClient;

		fstream My_File;
		My_File.open("Clients.txt", ios::in); // Read Mode

		if (My_File.is_open())
		{
			string Line;

			while (getline(My_File, Line)) {

				clsClient Client = _ConvertLineToClientObject(Line);
				vClient.push_back(Client);   
			}

			My_File.close();
		}

		return vClient; 
	}


	static void _SaveClientsDataToFile(vector <clsClient> vClient) {

		fstream My_File; 
		My_File.open("Clients.txt", ios::out); // OverWrite

		if (My_File.is_open())
		{
			string Line; 

			for (clsClient& Client : vClient)
			{
				if (Client._MarkedForDelete == false) 
				{ 
					// We Only Write Records That Are Not Marked For Delete
					Line = _ConvertClientObjectToLine(Client);  
					My_File << Line << endl; 
				}

			}

			My_File.close();
		}

	}


	void _Update() {

		vector <clsClient> _vClient = _LoadClientsDataFromFile();

		for (clsClient& Client : _vClient)
		{
			if (Client._AccountNumber == _AccountNumber) {
				
				Client = *this;
				break; 
			}
		}

		_SaveClientsDataToFile(_vClient); 
	}


	void _AddDataLineToFile(string sDataLine) {

		fstream My_File;
		My_File.open("Clients.txt", ios::out | ios::app);

		if (My_File.is_open())
		{
			My_File << sDataLine << endl;
			My_File.close();
		}

	}

	void _AddNew() {

		_AddDataLineToFile(_ConvertClientObjectToLine(*this));  
	}



	string _PrepareTransferLogRecord(float Amount, clsClient DestinationClient, string UserName, string Seperator = "#//#") {

		string TransferLogRecord = ""; 

		TransferLogRecord += clsDate::Get_SystemDateTimeString() + Seperator; 
		TransferLogRecord += Get_AccountNumber() + Seperator; 
		TransferLogRecord += DestinationClient.Get_AccountNumber() + Seperator;   
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName; 
		  
		return TransferLogRecord; 
	}

	void _RegisterTransferLog(float Amount, clsClient DestinationClient, string UserName)
	{
		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);
		fstream MyFile;

		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}

	}


	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#") 
	{
		stTransferLogRecord TransferLogRecord;
		vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);

		TransferLogRecord.DateTime = vTrnsferLogRecordLine[0];
		TransferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
		TransferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
		TransferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
		TransferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
		TransferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
		TransferLogRecord.UserName = vTrnsferLogRecordLine[6]; 

		return TransferLogRecord;
	}


	static vector <stTransferLogRecord> _LoadTransferLogsDataFromFile() {

		vector <stTransferLogRecord> vTransferLogRecord; 

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in); //Read Mode

		if (MyFile.is_open())
		{
			string Line;
			stTransferLogRecord TransferRecord;

			while (getline(MyFile, Line))
			{
				TransferRecord = _ConvertTransferLogLineToRecord(Line);
				vTransferLogRecord.push_back(TransferRecord);
			}

			MyFile.close();
		}

		return vTransferLogRecord;
	}



public:

	struct stTransferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		double Amount;
		double srcBalanceAfter;
		double destBalanceAfter;
		string UserName;
	};


	clsClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, 
		string AccountNumber, string PINCode, float AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone) {

		_Mode = Mode;   
		_AccountNumber = AccountNumber; 
		_PINCode = PINCode;
		_AccountBalance = AccountBalance;  
	}


	bool Is_Empty() {
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDeleted() { 
		return _MarkedForDelete;   
	}


	string Get_AccountNumber() {
		return _AccountNumber;    
	}


	void Set_PINCode(string PINCode) {
		_PINCode = PINCode;
	}
	string Get_PINCode() {
		return _PINCode; 
	}
	__declspec(property(get = Get_PINCode, put = Set_PINCode))string PINCode; 


	void Set_AccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;  
	}
	float Get_AccountBalance() {
		return _AccountBalance;   
	}
	__declspec(property(get = Get_AccountBalance, put = Set_AccountBalance))float AccountBalance;   







	static clsClient Find(string AccountNumber) {

		fstream My_File;
		My_File.open("Clients.txt", ios::in); // Read Mode

		if (My_File.is_open())
		{
			string Line; 

			while (getline(My_File, Line)) {

				clsClient Client = _ConvertLineToClientObject(Line);

				if (Client._AccountNumber == AccountNumber)   
				{
					My_File.close(); 
					return Client; 
				}

			}
			My_File.close();
		}

		return _GetEmptyClientObject(); 
	}



	static clsClient Find(string AccountNumber, string PINCode) {

		fstream My_File;
		My_File.open("Clients.txt", ios::in); // Read Mode


		if (My_File.is_open())
		{
			string Line;

			while (getline(My_File, Line)) {

				clsClient Client = _ConvertLineToClientObject(Line); 

				if (Client._AccountNumber == AccountNumber && Client.PINCode == PINCode) 
				{
					My_File.close();  
					return Client;
				}

				My_File.close();
			}

		}

		return _GetEmptyClientObject();  
	}
	


	static bool Is_Client_Exist(string AccountNumber) {

		clsClient Client = clsClient::Find(AccountNumber);
		return !(Client.Is_Empty()); 
	}



	enum enSaveResults { svFaildEmptyObject = 0, svSuccessed = 1, svFaildAccountNumberExists = 2};  

	enSaveResults Save() {

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (Is_Empty())
			{
				return enSaveResults::svFaildEmptyObject;
			}
		}

		case enMode::UpdateMode:  
		{
			_Update();

			return enSaveResults::svSuccessed; 
			break; 
		}

		case enMode::AddNewMode:
		{
			if (clsClient::Is_Client_Exist(_AccountNumber)) 
			{
				return enSaveResults::svFaildAccountNumberExists; 
			}
			else
			{
				_AddNew(); 

				_Mode = enMode::UpdateMode;
				return enSaveResults::svSuccessed;  
			}

			break;
		}

		}
	}


	static clsClient GetAddNewClientObject(string AccountNumber) {

		return clsClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}


	bool Delete() {

		vector <clsClient> _vClient = _LoadClientsDataFromFile();

		for (clsClient& Client : _vClient)
		{
			if (Client._AccountNumber == _AccountNumber)
			{
				Client._MarkedForDelete = true; 
				break;
			}

		}
		
		_SaveClientsDataToFile(_vClient); 

		*this = _GetEmptyClientObject();
		return true;  
	}


	static vector <clsClient> GetClientsList() {

		return _LoadClientsDataFromFile();  
	}


	static double GetTotalBalances() {

		vector <clsClient> vClient = clsClient::GetClientsList();
		double TotalBalances = 0;

		for (clsClient& Client : vClient)
		{
			TotalBalances += Client.AccountBalance;  
		}

		return TotalBalances;  
	}
 

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}


	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}

	}



	bool Transfer(float Amount, clsClient& DestinationClient, string UserName) {

		if (_AccountNumber == DestinationClient.Get_AccountNumber())
		{
			return false; 
		}

		if (Amount > AccountBalance)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);

		_RegisterTransferLog(Amount, DestinationClient, UserName);

		return true;
	}


	static vector <stTransferLogRecord> Get_TransferLogList()
	{
		return _LoadTransferLogsDataFromFile();
	} 

};