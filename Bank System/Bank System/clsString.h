#pragma once

#include <iostream>
#include <string> 
#include <cctype>
#include <vector>

using namespace std;

class clsString
{

private:
	string _Value;


public:
	clsString() {

		_Value = "";
	}

	clsString(string Value) {

		_Value = Value;
	}

	void SetValue(string Value) {

		_Value = Value;
	}

	string GetValue() {

		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;


	static short Length(string S1) {

		return S1.length();
	}

	short Length() { 

		return _Value.length();  
	}


	static void Print_First_Letter_Of_Each_Word(string S1) {

		bool isFirstLeter = true;

		cout << "\nFirst Letters Of This String : \n";

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLeter) {

				cout << S1[i] << endl;
			}

			isFirstLeter = (S1[i] == ' ' ? true : false);
		}
	}


	void Print_First_Letter_Of_Each_Word() {

		Print_First_Letter_Of_Each_Word(_Value);
	}


	static string Upper_First_Letter_Of_Each_Word(string S1) {

		bool isFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}

			isFirstLetter = (S1[i] == ' ' ? true : false);
		}

		return S1;
	}

	void Upper_First_Letter_Of_Each_Word() {

		// No Need To return Value , This Function Will Directly Update The Object Value
		_Value = Upper_First_Letter_Of_Each_Word(_Value);
	}


	static string Lower_First_Letter_Of_Each_Word(string S1) {

		bool isFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter) {

				S1[i] = tolower(S1[i]);
			}

			isFirstLetter = (S1[i] == ' ' ? true : false);
		}

		return S1;
	}

	void Lower_First_Letter_Of_Each_Word() {

		_Value = Lower_First_Letter_Of_Each_Word(_Value);
	}

	static string Upper_All_String(string S1) {

		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}

		return S1;
	}

	void Upper_All_String() {  

		_Value = Upper_All_String(_Value);
	}


	static string Lower_All_String(string S1) {

		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}

		return S1;
	}

	void Lower_All_String() {

		_Value = Lower_All_String(_Value);   
	}


	static char Invert_Character_Case(char C1) {

		return isupper(C1) ? tolower(C1) : toupper(C1);
	}

	static string Invert_All_Letters_Case(string S1) {

		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = Invert_Character_Case(S1[i]);
		}

		return S1;
	}

	void Invert_All_Letters_Case() {

		_Value = Invert_All_Letters_Case(_Value);
	}


	enum enWhatToCount { Small_Letters = 1, Capital_Letters = 2, All = 3 };

	static short Count_Letters(string S1, enWhatToCount Type = enWhatToCount::All) {

		if (Type == enWhatToCount::All)
		{
			return S1.length();
		}

		short Count = 0;

		for (int i = 0; i < S1.length(); i++)
		{
			if (Type == enWhatToCount::Capital_Letters && isupper(S1[i]))
			{
				Count++;
			}

			if (Type == enWhatToCount::Small_Letters && islower(S1[i]))
			{
				Count++;
			}

		}

		return Count;
	}


	static short Count_Small_Letters(string S1) {

		short Count = 0;

		for (int i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
				Count++;
		}

		return Count;
	}

	short Count_Small_Letters() {

		return Count_Small_Letters(_Value);
	}


	static short Count_Capital_Letters(string S1) {

		short Count = 0;

		for (int i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
				Count++;
		}

		return Count;
	}

	short Count_Capital_Letters() {

		return Count_Capital_Letters(_Value);
	}




	static short Count_Specific_Letter(string S1, char Letter, bool MatchCase = true) {

		short Count = 0;

		for (int i = 0; i < S1.length(); i++)
		{
			if (MatchCase) {

				if (S1[i] == Letter)
					Count++;
			}

			else
			{
				if (toupper(S1[i]) == toupper(Letter))
					Count++;
			}
		}

		return Count;
	}


	short Count_Specific_Letter(char Letter, bool MatchCase = true) {

		return Count_Specific_Letter(_Value, Letter, MatchCase);
	}


	static bool Is_Vowel(char Letter) {

		Letter = toupper(Letter);

		return ((Letter == 'A') || (Letter == 'E') || (Letter == 'I') || (Letter == 'O') || (Letter == 'U'));
	}

	static short Count_Vowels(string S1) {

		short Count = 0;

		for (int i = 0; i < S1.length(); i++)
		{
			if (Is_Vowel(S1[i])) {
				Count++;
			}

		}
		return Count;
	}

	short Count_Vowels() {

		return Count_Vowels(_Value);  
	}

	static void Print_All_Vowels(string S1) {

		cout << "\nVowels In String Are : \n";

		for (int i = 0; i < S1.length(); i++)
		{
			if (Is_Vowel(S1[i]))
				cout << S1[i] << " ";

		}
	}


	void Print_All_Vowels() {

		Print_All_Vowels(_Value);
	}



	static void Print_Words(string S1, string Delimiter = " ") {

		short Counter = 0;
		short Pos = 0;

		string sWord;

		while ((Pos = S1.find(Delimiter)) != std::string::npos) {

			sWord = S1.substr(0, Pos);

			if (sWord != "")
			{
				cout << sWord << endl;  
			}

			S1.erase(0, Pos + Delimiter.length());
		}

		if (S1 != "")
		{
			cout << S1 << endl;
		}

	}

	void Print_Words() {

		 Print_Words(_Value);
	}




	static short Count_Words(string S1, string Delimiter = " ") {

		short Counter = 0;
		short Pos = 0;

		string sWord;

		while ((Pos = S1.find(Delimiter)) != std::string::npos) {

			sWord = S1.substr(0, Pos);

			if (sWord != "")
			{
				Counter++;
			}

			S1.erase(0, Pos + Delimiter.length());
		}

		if (S1 != "")
		{
			Counter++;
		}

		return Counter;
	}

	short Count_Words() {

		return Count_Words(_Value);
	}





	static vector <string> Split(string S1, string Delimiter = " ") {

		short Pos = 0;
		string sWord;

		vector <string> vString;

		while ((Pos = S1.find(Delimiter)) != std::string::npos) {

			sWord = S1.substr(0, Pos);

			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			S1.erase(0, Pos + Delimiter.length());
		}

		if (S1 != "")
		{
			vString.push_back(S1);
		}

		return vString;
	}


	vector <string> Split(string Delimiter = " ") {

		return Split(_Value, Delimiter);
	}
	   


	static string Trim_Left(string S1) {

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}

		}

		return "";
	}


	void Trim_Left() {

		_Value = Trim_Left(_Value);
	}


	static string Trim_Right(string S1) {

		for (int i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ') {

				return S1.substr(0, i + 1);
			}
		}

		return "";
	}


	void Trim_Right() {

		_Value = Trim_Right(_Value);
	}


	static string Trim(string S1) {

		return Trim_Left(Trim_Right(S1));
	}

	void Trim() {

		_Value = Trim(_Value);  
	}


	static string Join_String(vector <string> vString, string Delimiter = " ") {

		string S1 = "";

		for (string& s : vString)
		{
			S1 += s + Delimiter;
		}

		return S1.substr(0, S1.length() - Delimiter.length());
	}


	static string Join_String(string arrString[], short length, string Delimiter = " ") {

		string S1 = "";

		for (int i = 0; i < length; i++)  
		{
			S1 += arrString[i] + Delimiter; 
		}

		return S1.substr(0, S1.length() - Delimiter.length());
	}


	static string Reverse_Words_In_String(string S1) {  

		vector <string> vString = Split(S1, " ");
		vector <string>::iterator iter = vString.end();

		string S2 = "";
		string Delimiter = " "; 

		while (iter != vString.begin()) {

			--iter;

			S2 += *iter + Delimiter;
		}

		S2 = S2.substr(0, S2.length() - Delimiter.length());  

		return S2; 
	}	


	void Reverse_Words_In_String() {

		_Value = Reverse_Words_In_String(_Value);   
	}

	static string Replace_Words(string S1, string ToReplace, string ReplaceTo) {

		short Pos = 0;

		while ((Pos = S1.find(ToReplace)) != std::string::npos) {

			S1 = S1.replace(Pos, ToReplace.length(), ReplaceTo);
		}

		return S1; 
	}

	void Replace_Words(string ToReplace,string ReplaceTo) {

		_Value = Replace_Words(_Value, ToReplace, ReplaceTo);
	}
	 

	static string Replace_Words_Using_Split_And_Join(string S1, string ToReplace, string ReplaceTo, bool MatchCase = true) {

		vector <string> vString = Split(S1, " ");

		for (string& s : vString)
		{
			if (MatchCase)
			{
				if (s == ToReplace)
				{
					s = ReplaceTo;
				}

			}

			else
			{
				if (Upper_All_String(s) == Upper_All_String(ToReplace))
				{ 
					s = ReplaceTo;
				}
			}

		}

		return Join_String(vString); 
	}

	void Replace_Words_Using_Split_And_Join(string ToReplace, string ReplaceTo, bool MatchCase = true) {

		_Value = Replace_Words_Using_Split_And_Join(_Value, ToReplace, ReplaceTo, MatchCase); 
	}


	static string Remove_Punctuations(string S1) {

		string S2 = "";

		for (int i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}

		return S2; 
	}

	void Remove_Punctuations() {

		_Value = Remove_Punctuations(_Value);   
	} 

};