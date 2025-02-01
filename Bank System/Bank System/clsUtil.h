#pragma once

#include <cstdlib>
#include "clsDate.h"

using namespace std;

class clsUtil
{

public:

	//Seeds The Random Number Generator in C++, Called Only Once
	static void Srand() {

		srand((unsigned)time(NULL));
	}

	static int Random_Number(int From, int To) {

		return rand() % (To - From + 1) + From;
	}
	
	enum enCharType {
		Special_Character = 1, Digit = 2, Capital_Letter = 3, Small_Letter = 4, MixChars = 5
	};


	static char Get_RandomCharacter(enCharType CharType) {

		if (CharType == enCharType::MixChars) {
			CharType = (enCharType)Random_Number(2, 4);
		}


		switch (CharType)
		{
		case enCharType::Special_Character:
		{
			return char(Random_Number(33, 47));
			break;
		}

		case enCharType::Digit:
		{
			return char(Random_Number(48, 57));
			break;
		}

		case enCharType::Capital_Letter:
		{
			return char(Random_Number(65, 90));
			break;
		}

			
		case enCharType::Small_Letter: 
		{
			return char(Random_Number(97, 122));
			break; 
		}

			
		default:
		{
			return char(Random_Number(65, 90));
			break;
		}

		}

	}


	static string Generate_Word(enCharType CharType, short Length) {

		string Word = "";

		for (int i = 0; i < Length; i++)
		{
			Word += Get_RandomCharacter(CharType);
		}


		return Word;
	}  

	static string Generate_Key(enCharType CharType = enCharType::Capital_Letter) {

		string Key = "";

		Key += Generate_Word(CharType, 4) + "-";
		Key += Generate_Word(CharType, 4) + "-";
		Key += Generate_Word(CharType, 4) + "-"; 
		Key += Generate_Word(CharType, 4);

		return Key;   
	}

	static void Generate_Keys(short NumOfKeys, enCharType CharType) {

		for (int i = 0; i < NumOfKeys; i++)
		{
			cout << "Key [" << i + 1 << "] : " << Generate_Key(CharType) << endl; 
		}
	}


	static void Fill_Array_With_Random_Words(string Arr[100], short ArrLength, enCharType CharType, short WordLength) {

		for (int i = 0; i < ArrLength; i++)
		{
			Arr[i] = Generate_Word(CharType, WordLength);  
		}

	}


	static void Fill_Array_With_Random_Keys(string Arr[100], short ArrLength, enCharType CharType) {

		for (int i = 0; i < ArrLength; i++)
		{
			Arr[i] = Generate_Key(CharType);    
		}
	}


	static void Fill_Array_With_Random_Numbers(int Arr[100], short ArrLength, short From, short To) {

		for (int i = 0; i < ArrLength; i++)
		{
			Arr[i] = Random_Number(From, To);
		}
	}


	static void Swap(int& A, int& B) {

		int Temp;

		Temp = A;
		A = B;
		B = Temp; 
	}


	static void Swap(double& A, double& B) {

		double Temp; 

		Temp = A;
		A = B;
		B = Temp; 
	}

	static void Swap(bool& A, bool& B) {

		bool Temp;

		Temp = A;
		A = B;
		B = Temp;   
	}


	static void Swap(char& A, char& B) {

		char Temp;

		Temp = A;
		A = B; 
		B = Temp;  
	}


	static void Swap(string& A, string& B) {

		string Temp;

		Temp = A;
		A = B;
		B = Temp;  
	} 


	static void Swap(clsDate& A, clsDate& B) {

		clsDate::Swap_Dates(A, B); 
	}


	static void Shuffle_Array(int Arr[100], int ArrLength) {

		for (int i = 0; i < ArrLength; i++) 
		{
			Swap(Arr[Random_Number(1, ArrLength) - 1], Arr[Random_Number(1, ArrLength) - 1 ]);
		}
	}


	static void Shuffle_Array(string Arr[100], int ArrLength) { 

		for (int i = 0; i < ArrLength; i++)
		{
			Swap(Arr[Random_Number(1, ArrLength) - 1], Arr[Random_Number(1, ArrLength) - 1]);
		}
	}


	static string Tabs(short NumberOfTabs) {

		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t += "\t";
			cout << t; 
		}

		return t; 
	}



	static string Encryption_Text(string Text, short EncryptionKey = 2) {

		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((short)Text[i] + EncryptionKey); 
		}

		return Text;    
	}

	static string Decryption_Text(string Text, short EncryptionKey = 2) {

		for (int i = 0; i < Text.length(); i++)  
		{
			Text[i] = char((short)Text[i] - EncryptionKey);   
		}

		return Text;
	}


	static string NumberToText(int Number) {

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string Arr[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
			"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return Arr[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			string Arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };

			return Arr[Number / 10] + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + " Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + " Million " + NumberToText(Number % 1000000);
		}
		
		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return NumberToText(Number / 1000000000) + " Billion " + NumberToText(Number % 1000000000);
		}
	}



};