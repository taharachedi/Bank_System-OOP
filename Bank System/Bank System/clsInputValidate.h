#pragma once
#include "clsDate.h"



class clsInputValidate
{
public:


	static bool Is_Number_Between(short Number, short From, short To) {

		return (Number >= From && Number <= To);
	}

	static bool Is_Number_Between(int Number, int From, int To) {

		return (Number >= From && Number <= To);
	}

	static bool Is_Number_Between(float Number, float From, float To) {

		return (Number >= From && Number <= To);
	}

	static bool Is_Number_Between(double Number, double From, double To) {
		 
		return (Number >= From && Number <= To); 
	}

	static bool Is_Date_Between(clsDate Date, clsDate DateFrom, clsDate DateTo) {

		if (clsDate::Compare_Dates(DateFrom,DateTo) == clsDate::After)
		{
			clsDate::Swap_Dates(DateFrom, DateTo); 
		}

		if ((Date.Compare_Dates(DateFrom) == clsDate::Before) ||
			(Date.Compare_Dates(DateTo) == clsDate::After))
			return false;

		return true;
	}


	static short Read_Short_Number(string ErrorMessage = "Invalid Number, Enter again\n") {

		short Number;

		while (!(cin >> Number)) {

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}

		return Number;
	}


	static short Read_Short_Number_Between(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n") {

		short Number = Read_Short_Number(); 

		while (!Is_Number_Between(Number, From, To))
		{
			cout << ErrorMessage;
			Number = Read_Short_Number(); 
		}

		return Number;
	}



	static int Read_Int_Number(string ErrorMessage = "Invalid Number, Enter again\n") {

		int Number;  

		while (!(cin >> Number)) {

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;  
		}

		return Number;  
	}


	static int Read_Int_Number_Between(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n") {

		int Number = Read_Int_Number(); 

		while (!Is_Number_Between(Number,From,To))
		{
			cout << ErrorMessage;
			Number = Read_Int_Number();  
		} 

		return Number;  
	}



	static float Read_Float_Number(string ErrorMessage = "Invalid Number, Enter again\n") {

		float Number;

		while (!(cin >> Number)) {

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}

		return Number;
	}


	static float Read_Float_Number_Between(float From, float To, string ErrorMessage = "Number is not within range, Enter again:\n") {

		float Number = Read_Float_Number();

		while (!Is_Number_Between(Number, From, To))
		{
			cout << ErrorMessage;
			Number = Read_Float_Number(); 
		}

		return Number;
	}



	static double Read_Double_Number(string ErrorMessage = "Invalid Number, Enter again\n") {

		double Number;

		while (!(cin >> Number)) { 

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage; 
		}

		return Number;
	}



	static double Read_Double_Number_Between(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n") {

		double Number = Read_Double_Number();   

		while (!Is_Number_Between(Number, From, To))
		{
			cout << ErrorMessage; 
			Number = Read_Double_Number(); 
		}

		return Number;
	}

	static bool Is_Valide_Date(clsDate Date) {

		return Date.Is_Valid_Date();   
	}
	

	static string Read_String() {

		string S1 = "";
		getline(cin >> ws, S1);

		return S1;   
	}


};