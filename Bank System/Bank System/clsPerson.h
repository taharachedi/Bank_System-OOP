#pragma once
#include "InterfaceCommunication.h"

class clsPerson : public InterfaceCommunication  
{

private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;


public:

	clsPerson(string FirstName, string LastName, string Email, string Phone) {

		_FirstName = FirstName;  
		_LastName = LastName; 
		_Email = Email;   
		_Phone = Phone;   
	}

	void Set_FirstName(string FirstName) {
		_FirstName = FirstName;  
	}
	string Get_FirstName() {
		return _FirstName;    
	}
	__declspec(property(get = Get_FirstName, put = Set_FirstName))string FirstName; 


	void Set_LastName(string LastName) {
		_LastName = LastName;  
	}
	string Get_LastName() {
		return _LastName; 
	}
	__declspec(property(get = Get_LastName, put = Set_LastName))string LastName; 


	void Set_Email(string Email) {
		_Email = Email;  
	}
	string Get_Email() {
		return _Email;  
	}
	__declspec(property(get = Get_Email, put = Set_Email))string Email;  


	void Set_Phone(string Phone) {
		_Phone = Phone;  
	}
	string Get_Phone() {
		return _Phone;   
	}
	__declspec(property(get = Get_Phone, put = Set_Phone))string Phone;   
	

	string FullName() {
		return _FirstName + " " + _LastName;   
	}

/*	void Print() {

		cout << "\nInfo:";
		cout << "\n___________________";
		cout << "\nFirstName: " << _FirstName; 
		cout << "\nLastName : " << _LastName; 
		cout << "\nFull Name: " << FullName();
		cout << "\nEmail    : " << _Email;
		cout << "\nPhone    : " << _Phone;
		cout << "\n___________________\n";
	}
*/

	void SendEmail(string Title, string Body)
	{

	}

	void SendFax(string Title, string Body)
	{

	}

	void SendSMS(string Title, string Body)
	{


	}



};