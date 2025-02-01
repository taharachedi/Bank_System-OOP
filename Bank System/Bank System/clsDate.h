#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <string> 
#include "clsString.h"

using namespace std;


class clsDate
{
private:

	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;


public:

	clsDate() {

		time_t t = time(0);
		tm* Now = localtime(&t);

		_Day = Now->tm_mday;
		_Month = Now->tm_mon + 1;
		_Year = Now->tm_year + 1900;
	}

	clsDate(string sDate) {

		vector <string> vDate = clsString::Split(sDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);

	}


	clsDate(short Day, short Month, short Year) {

		_Day = Day;
		_Month = Month;
		_Year = Year;
	}


	clsDate(short DateOrderInYear, short Year) {

		clsDate Date = Get_Date_From_Day_Order_In_A_Year(DateOrderInYear, Year); 

		_Day = Date.Day;
		_Month = Date.Month;
		_Year = Date.Year; 
	}


	void Set_Day(short Day) {
		_Day = Day;
	}

	short Get_Day() {
		return _Day;
	}

	__declspec(property(get = Get_Day, put = Set_Day)) short Day;



	void Set_Month(short Month) {
		_Month = Month;
	}

	short Get_Month() {
		return _Month;
	}

	__declspec(property(get = Get_Month, put = Set_Month)) short Month;




	void Set_Year(short Year) {
		_Year = Year;
	}

	short Get_Year() {
		return _Year;
	}

	__declspec(property(get = Get_Year, put = Set_Year)) short Year;




	static string DateToString(clsDate Date) {

		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	string DateToString() {

		return DateToString(*this);   
	}

	void Print() {

		cout << DateToString() << endl; 
	}


	static clsDate Get_System_Date() {

		time_t t = time(0);
		tm* Now = localtime(&t);

		short Day, Month, Year;

		Day = Now->tm_mday;
		Month = Now->tm_mon + 1;
		Year = Now->tm_year + 1900;

		return clsDate(Day, Month, Year);
	}


	static string Get_SystemDateTimeString() {

		time_t t = time(0);
		tm* Now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = Now->tm_year + 1900;
		Month = Now->tm_mon + 1;
		Day = Now->tm_mday;

		Hour = Now->tm_hour;
		Minute = Now->tm_min;
		Second = Now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second));
	}


	static bool Is_Valid_Date(clsDate Date) {

		if (Date.Day < 1 || Date.Day > 31)
			return false;

		if (Date.Month < 1 || Date.Month > 12)
			return false;

		if (Date.Month == 2)  
		{
			if (Is_Leap_Year(Date.Year))
			{
				if (Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day > 28)
					return false;
			}
		}

		short NumberOfDaysInMonth = Number_Of_Days_In_A_Month(Date.Month, Date.Year);

		if (Date.Day > NumberOfDaysInMonth)
		{
			return false;
		}

		return true;
	}


	bool Is_Valid_Date() {

		return Is_Valid_Date(*this);
	}
	 


	static bool Is_Leap_Year(short Year) {

		return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0));
	}
	bool Is_Leap_Year() {

		return Is_Leap_Year(_Year);    
	}




	static short Number_Of_Days_In_A_Year(short Year) { 

		return (Is_Leap_Year(Year) ? 366 : 365);
	}
	short Number_Of_Days_In_A_Year() {

		return Number_Of_Days_In_A_Year(_Year);  
	}



	static short Number_Of_Hours_In_A_Year(short Year) {

		return Number_Of_Days_In_A_Year(Year) * 24;
	}
	short Number_Of_Hours_In_A_Year() {

		return Number_Of_Hours_In_A_Year(_Year);  
	}



	static int Number_Of_Minutes_In_A_Year(short Year) {

		return Number_Of_Hours_In_A_Year(Year) * 60;
	}
	int Number_Of_Minutes_In_A_Year() {

		return Number_Of_Minutes_In_A_Year(_Year);  
	}



	static int Number_Of_Seconds_In_A_Year(short Year) {

		return Number_Of_Minutes_In_A_Year(Year) * 60; 
	}
	int Number_Of_Seconds_In_A_Year() {

		return Number_Of_Seconds_In_A_Year(_Year);  
	} 




	static short Number_Of_Days_In_A_Month1(short Month, short Year) {

		if (Month == 2)
		{
			return (Is_Leap_Year(Year) ? 29 : 28);
		}

		short Arr_31_Day[7] = { 1,3,5,7,8,10,12 };

		for (int i = 0; i < 7; i++)
		{
			if (Arr_31_Day[i] == Month)
				return 31;
		}

		return 30;
	}


	static short Number_Of_Days_In_A_Month(short Month, short Year) {

		if (Month < 1 || Month > 12)
			return 0;

		short NumOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? ((Is_Leap_Year(Year)) ? 29 : 28) : NumOfDays[Month - 1];
	}
	short Number_Of_Days_In_A_Month() {

		return Number_Of_Days_In_A_Month(_Month, _Year);    
	}



	static short Number_Of_Hours_In_A_Month(short Month, short Year) {

		return Number_Of_Days_In_A_Month(Month, Year) * 24;
	}
	short Number_Of_Hours_In_A_Month() {

		return Number_Of_Days_In_A_Month(_Month, _Year) * 24;
	}




	static int Number_Of_Minutes_In_A_Month(short Month, short Year) {

		return Number_Of_Hours_In_A_Month(Month, Year) * 60;
	}
	int Number_Of_Minutes_In_A_Month() {

		return Number_Of_Minutes_In_A_Month(_Month, _Year);    
	}



	static int Number_Of_Seconds_In_A_Month(short Month, short Year) {

		return Number_Of_Minutes_In_A_Month(Month, Year) * 60;
	}
	int Number_Of_Seconds_In_A_Month() {

		return Number_Of_Seconds_In_A_Month(_Month, _Year);
	}



	static short Day_Of_Week_Order(short Day, short Month, short Year) { 

		short a, y, m;

		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short Day_Of_Week_Order() {

		return Day_Of_Week_Order(_Day, _Month, _Year);
	}



	static string Day_ShortName(short NumOfDay) { 

		string ArrDayName[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return ArrDayName[NumOfDay];
	}
	static string Day_ShortName(short Day, short Month, short Year) {

		string ArrDayName[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return ArrDayName[Day_Of_Week_Order(Day, Month, Year)];
	}
	string Day_ShortName() {

		string ArrDayName[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return ArrDayName[Day_Of_Week_Order(_Day, _Month, _Year)];
	}




	static string Month_ShortName(short NumOfMonth) { 

		string Arr_Month[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

		return Arr_Month[NumOfMonth - 1];    
	}
	string Month_ShortName() {

		return Month_ShortName(_Month);   
	}




	static void Print_Month_Calendar(short Month, short Year) {

		printf("\n------------------ %s ----------------\n\n", Month_ShortName(Month).c_str());
		printf("  Sat  Mon  Tue  Wed  Thu  Fri  Sat\n\n");

		short First_Day = Day_Of_Week_Order(1, Month, Year);

		int i;
		for (i = 0; i < First_Day; i++)
		{
			printf("     ");
		}

		short Num_Of_Days = Number_Of_Days_In_A_Month(Month, Year);

		for (short j = 1; j <= Num_Of_Days; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n\n---------------------------------------\n\n");
	}
	void Print_Month_Calendar() {

		Print_Month_Calendar(_Month, _Year);  
	}




	static void Print_Year_Calendar(short Year) {   

		printf("\n------------------------------------\n\n");
		printf("\t Calendar - %d \n", Year);      
		printf("\n------------------------------------\n\n");

		for (short i = 1; i <= 12; i++)
		{
			Print_Month_Calendar(i, Year);   
		}

	}
	void Print_Year_Calendar() {

		printf("\n------------------------------------\n\n");
		printf("\t Calendar - %d \n", _Year);  
		printf("\n------------------------------------\n\n");
		 
		for (short i = 1; i <= 12; i++)
		{
			Print_Month_Calendar(i, _Year);   
		}

	}


	static short Number_Of_Days_From_The_Beginning_Of_Year(short Day, short Month, short Year) {

		short Total_Days = 0;

		for (int i = 1; i <= Month - 1; i++)
		{
			Total_Days += Number_Of_Days_In_A_Month(i, Year);
		}

		Total_Days += Day;

		return Total_Days;
	}
	short Number_Of_Days_From_The_Beginning_Of_Year() {

		short Total_Days = 0;

		for (int i = 1; i <= _Month - 1; i++)
		{
			Total_Days += Number_Of_Days_In_A_Month(i, _Year); 
		}

		Total_Days += _Day;   

		return Total_Days;
	}




	static clsDate Get_Date_From_Day_Order_In_A_Year(short DayOfYearOrder, short Year) { 

		clsDate Date;
		short RemainingDays = DayOfYearOrder;
		short NumOfDaysInMonth = 0;

		Date.Year = Year;
		Date.Month = 1;

		while (true) {

			NumOfDaysInMonth = Number_Of_Days_In_A_Month(Date.Month, Year);

			if (RemainingDays > NumOfDaysInMonth) 
			{
				RemainingDays -= NumOfDaysInMonth;  
				Date.Month++;
			}

			else
			{
				Date.Day = RemainingDays;
				break;
			}

		}

		return Date;
	}





	void Add_Days(short DaysToAdd) {

		short RemainingDays = DaysToAdd + Number_Of_Days_From_The_Beginning_Of_Year(_Day, _Month, _Year);
		short NumberOfDaysInMonth = 0;

		_Month = 1;

		while (true) {

			NumberOfDaysInMonth = Number_Of_Days_In_A_Month(_Month, _Year);

			if (RemainingDays > NumberOfDaysInMonth)
			{
				RemainingDays -= NumberOfDaysInMonth;
				_Month++;

				if (_Month > 12)
				{
					_Month = 1;
					_Year++;
				}

			}

			else
			{
				_Day = RemainingDays;
				break;
			}
		}

	}




	static bool isDate1BeforeDate2(clsDate Date1, clsDate Date2) {

		return (Date1.Year < Date2.Year) ? true :
			((Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true :
				((Date1.Month == Date2.Month) ? Date1.Day < Date2.Day : false)) : false);
	}
	bool isDateBeforeDate2(clsDate Date2) {

		return isDate1BeforeDate2(*this, Date2);   // *this Sends The Current Object
	}




	static bool isDate1EqualDate2(clsDate Date1, clsDate Date2) {

		return ((Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ?
			((Date1.Day == Date2.Day) ? true : false) : false) : false);
	}
	bool isDateEqualDate2(clsDate Date2) {

		return isDate1EqualDate2(*this, Date2);  
	}




	static bool is_Last_Day_In_Month(clsDate Date) { 

		return Date.Day == Number_Of_Days_In_A_Month(Date.Month, Date.Year);
	}
	bool is_Last_Day_In_Month() {

		return is_Last_Day_In_Month(*this);
	}




	static bool is_Last_Month_In_Year(short Month) { 

		return (Month == 12);
	}




	static clsDate Increase_Date_By_One_Day(clsDate Date) {

		if (is_Last_Day_In_Month(Date))
		{
			if (is_Last_Month_In_Year(Date.Month)) {

				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}

		else
		{
			Date.Day++;
		}

		return Date;
	}
	void Increase_Date_By_One_Day() {

		*this = Increase_Date_By_One_Day(*this);
	}



	
	static void Swap_Dates(clsDate& Date1, clsDate& Date2) {

		clsDate Temp_Date;

		Temp_Date = Date1;
		Date1 = Date2;
		Date2 = Temp_Date;
	}



	static int Get_Difference_In_Days(clsDate Date1, clsDate Date2, bool IncludeEndDay = false) {  

		short SwapFlagValue = 1;
		short Diff = 0;

		if (!isDate1BeforeDate2(Date1,Date2))
		{
			Swap_Dates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (isDate1BeforeDate2(Date1, Date2)) {

			Diff++;
			Date1 = Increase_Date_By_One_Day(Date1);
		}

		return IncludeEndDay ? ++Diff * SwapFlagValue : Diff * SwapFlagValue;  
	}
	int Get_Difference_In_Days(clsDate Date2, bool IncludeEndDay = false) {

		return Get_Difference_In_Days(*this, Date2, IncludeEndDay); 
	}




	static short CalculateMyAgeInDays(clsDate DateOfBirth) {

		return Get_Difference_In_Days(DateOfBirth, clsDate::Get_System_Date(), true);
	}



	static clsDate Increase_Date_By_X_Days(clsDate& Date, short Days) { 

		for (int i = 0; i < Days; i++)
		{
			Date = Increase_Date_By_One_Day(Date);
		}
		return Date; 
	}
	void Increase_Date_By_X_Days(short Days) {

		Increase_Date_By_X_Days(*this, Days);
	}



	static clsDate Increase_Date_By_One_Week(clsDate& Date) { 

		for (int i = 0; i < 7; i++)
		{
			Date = Increase_Date_By_One_Day(Date);
		}
		return Date;
	}
	void Increase_Date_By_One_Week() {

		Increase_Date_By_One_Week(*this);   
	}


	static clsDate Increase_Date_By_X_Weeks(clsDate& Date, short Weeks) {

		for (int i = 0; i < Weeks; i++)
		{
			Date = Increase_Date_By_One_Week(Date);  
		}
		return Date;
	}
	void Increase_Date_By_X_Weeks(short Weeks) {

		Increase_Date_By_X_Weeks(*this, Weeks);
	}



	static clsDate Increase_Date_By_One_Month(clsDate& Date) {

		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		short NumberOfDaysInCurrentMonth = Number_Of_Days_In_A_Month(Date.Month, Date.Year);

		if (Date.Day > NumberOfDaysInCurrentMonth)  
		{
			Date.Day = NumberOfDaysInCurrentMonth;  
		}

		return Date;    
	}
	void Increase_Date_By_One_Month() {

		Increase_Date_By_One_Month(*this);
	}



	static clsDate Increase_Date_By_X_Months(clsDate& Date, short Months) {
		 
		for (int i = 0; i < Months; i++) 
		{
			Date = Increase_Date_By_One_Month(Date);
		}
		return Date;  
	}
	void Increase_Date_By_X_Months(short Months) {

		Increase_Date_By_X_Months(*this, Months);
	}



	static clsDate Increase_Date_By_One_Year(clsDate &Date) { 

		Date.Year++;
		return Date; 
	}
	void Increase_Date_By_One_Year() {

		Increase_Date_By_One_Year(*this);
	}



	static clsDate Increase_Date_By_X_Years(clsDate& Date, short Years) { 

		for (int i = 0; i < Years; i++)
		{
			Date = Increase_Date_By_One_Year(Date);
		}
		return Date;  
	}
	void Increase_Date_By_X_Years(short Years) {

		Increase_Date_By_X_Years(*this, Years); 
	}



	static clsDate Increase_Date_By_X_Years_Faster(clsDate& Date, short Years) {
		
		Date.Year += Years;   
		return Date;   
	}
	void Increase_Date_By_X_Years_Faster(short Years) {

		Increase_Date_By_X_Years_Faster(*this, Years);    
	}



	static clsDate Increase_Date_By_One_Decade(clsDate& Date) {  

		Date.Year += 10;
		return Date;  
	}
	void Increase_Date_By_One_Decade() {

		Increase_Date_By_One_Decade(*this);  
	}



	static clsDate Increase_Date_By_X_Decades(clsDate& Date, short Decades) {  

		for (int i = 0; i < Decades * 10; i++)
		{
			Date = Increase_Date_By_One_Year(Date);
		}
		return Date;
	}
	void Increase_Date_By_X_Decades(short Decades) {

		Increase_Date_By_X_Decades(*this, Decades); 
	}


	static clsDate Increase_Date_By_X_Decades_Faster(clsDate& Date, short Decades) {

		Date.Year += Decades * 10;
		return Date; 
	}
	void Increase_Date_By_X_Decades_Faster(short Decades) {

		Increase_Date_By_X_Decades_Faster(*this, Decades);
	}




	static clsDate Increase_Date_By_One_Century(clsDate& Date) { 

		Date.Year += 100;
		return Date;   
	}
	void Increase_Date_By_One_Century() {

		Increase_Date_By_One_Century(*this); 
	}




	static clsDate Increase_Date_By_One_Millennium(clsDate& Date) { 

		Date.Year += 1000;
		return Date; 
	}
	void Increase_Date_By_One_Millennium() {

		Increase_Date_By_One_Millennium(*this);
	}




	static clsDate Decrease_Date_By_One_Day(clsDate& Date) {

		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Day = 31;
				Date.Month = 12;
				Date.Year--;
			}

			else
			{
				Date.Month--;   
				Date.Day = Number_Of_Days_In_A_Month(Date.Month, Date.Year);
			}

		}

		else
		{
			Date.Day--;
		}

		return Date;   
	}

	void Decrease_Date_By_One_Day() {

		Decrease_Date_By_One_Day(*this);
	}




	static clsDate Decrease_Date_By_X_Days(clsDate& Date, short Days) {

		for (int i = 0; i < Days; i++)
		{
			Date = Decrease_Date_By_One_Day(Date);
		}
		return Date;
	}
	void Decrease_Date_By_X_Days(short Days) {

		Decrease_Date_By_X_Days(*this, Days);
	}


	static clsDate Decrease_Date_By_One_Week(clsDate& Date) {

		for (int i = 0; i < 7; i++) 
		{
			Date = Decrease_Date_By_One_Day(Date);
		}
		return Date;
	}
	void Decrease_Date_By_One_Week() {

		Decrease_Date_By_One_Week(*this);
	}




	static clsDate Decrease_Date_By_X_Week(clsDate& Date, short Weeks) {

		for (int i = 0; i < Weeks; i++)  
		{    
			Date = Decrease_Date_By_One_Week(Date);   
		}
		return Date;
	}
	void Decrease_Date_By_X_Week(short Weeks) {

		Decrease_Date_By_X_Week(*this, Weeks);
	}




	static clsDate Decrease_Date_By_One_Month(clsDate& Date) { 

		if (Date.Month == 1) 
		{  
			Date.Year--;
			Date.Month = 12; 
		}

		else
		{
			Date.Month--;
		}

		short NumberOfDaysInCurrentMonth = Number_Of_Days_In_A_Month(Date.Month, Date.Year);

		if (Date.Day > NumberOfDaysInCurrentMonth) 
		{
			Date.Day = NumberOfDaysInCurrentMonth; 
		}

		return Date; 
	}
	void Decrease_Date_By_One_Month() {

		Decrease_Date_By_One_Month(*this);  
	}




	static clsDate Decrease_Date_By_X_Months(clsDate& Date, short Months) { 

		for (int i = 0; i < Months; i++)
		{
			Date = Decrease_Date_By_One_Month(Date);
		}
		return Date;
	}
	void Decrease_Date_By_X_Months(short Months) {

		Decrease_Date_By_X_Months(*this, Months);  
	}



	static clsDate Decrease_Date_By_One_Year(clsDate& Date) {

		Date.Year--;
		return Date;
	}
	void Decrease_Date_By_One_Year() {

		Decrease_Date_By_One_Year(*this);
	}



	static clsDate Decrease_Date_By_X_Years(clsDate& Date, short Years) { 

		for (int i = 0; i < Years; i++)
		{
			Date = Decrease_Date_By_One_Year(Date);
		}
		return Date;   
	}
	void Decrease_Date_By_X_Years(short Years) {

		Decrease_Date_By_X_Years(*this, Years); 
	}




	static clsDate Decrease_Date_By_X_Years_Faster(clsDate& Date, short Years) {

		Date.Year -= Years; 
		return Date;    
	}  
	void Decrease_Date_By_X_Years_Faster(short Years) {

		Decrease_Date_By_X_Years_Faster(*this, Years);
	}



	static clsDate Decrease_Date_By_One_Decade(clsDate&  Date) {

		Date.Year -= 10;
		return Date; 
	}
	void Decrease_Date_By_One_Decade() {

		Decrease_Date_By_One_Decade(*this);
	}




	static clsDate Decrease_Date_By_X_Decades(clsDate& Date, short Decades) {

		for (int i = 0; i < Decades * 10; i++)
		{
			Date = Decrease_Date_By_One_Year(Date);
		}
		return Date; 
	}
	void Decrease_Date_By_X_Decades(short Decades) {

		Decrease_Date_By_X_Decades(*this, Decades); 
	}



	static clsDate Decrease_Date_By_X_Decades_Faster(clsDate& Date, short Decades) {

		Date.Year -= Decades * 10;
		return Date;  
	}
	void Decrease_Date_By_X_Decades_Faster(short Decades) {

		Decrease_Date_By_X_Decades_Faster(*this, Decades);  
	}



	static clsDate Decrease_Date_By_One_Century(clsDate& Date) {

		Date.Year -= 100;
		return Date;
	}
	void Decrease_Date_By_One_Century() {

		Decrease_Date_By_One_Century(*this);
	}



	static clsDate Decrease_Date_By_One_Millennium(clsDate& Date) {

		Date.Year -= 1000;
		return Date;
	}
	void Decrease_Date_By_One_Millennium() {

		Decrease_Date_By_One_Millennium(*this);
	}



	static short Day_Of_Week_Order(clsDate Date) {  

		return Day_Of_Week_Order(Date.Day, Date.Month, Date.Year);
	}

	static bool Is_End_Of_Week(clsDate Date) { 

		return Day_Of_Week_Order(Date) == 6;   
	}
	bool Is_End_Of_Week() {

		return Is_End_Of_Week(*this);
	}



	static bool Is_WeekEnd(clsDate Date) {

		short DayIndex = Day_Of_Week_Order(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}
	bool Is_WeekEnd() {

		return Is_WeekEnd(*this);
	}



	static bool Is_Business_Day(clsDate Date) {

		return !Is_WeekEnd(Date);  
	}
	bool Is_Business_Day() {

		return Is_Business_Day(*this);
	}




	static short Days_Until_The_End_Of_Week(clsDate Date) { 

		return 6 - Day_Of_Week_Order(Date);
	}
	short Days_Until_The_End_Of_Week() {

		Days_Until_The_End_Of_Week(*this);
	}



	static short Days_Until_The_End_Of_Month(clsDate Date) {

		clsDate EndOfMonthDate;

		EndOfMonthDate.Day = Number_Of_Days_In_A_Month(Date.Month, Date.Year);
		EndOfMonthDate.Month = Date.Month;
		EndOfMonthDate.Year = Date.Year;

		return Get_Difference_In_Days(Date, EndOfMonthDate, true);  
	} 
	short Days_Until_The_End_Of_Month() {

		return Days_Until_The_End_Of_Month(*this);
	}



	static short Days_Until_The_End_Of_Year(clsDate Date) {

		clsDate EndOfYearDate; 

		EndOfYearDate.Day = 31; 
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date.Year;

		return Get_Difference_In_Days(Date, EndOfYearDate, true);
	}
	short Days_Until_The_End_Of_Year() {

		return Days_Until_The_End_Of_Year(*this);
	}




	static short Calculate_Business_Days(clsDate DateFrom, clsDate DateTo) {  

		short DaysCount = 0; 

		while (isDate1BeforeDate2(DateFrom, DateTo)) { 

			if (Is_Business_Day(DateFrom))  
			{
				DaysCount++; 
			}

			DateFrom = Increase_Date_By_One_Day(DateFrom); 
		}

		return DaysCount; 

	}



	static short Calculate_Vacation_Days(clsDate DateFrom, clsDate DateTo) {

		return Calculate_Business_Days(DateFrom, DateTo);   
	}


	static clsDate Calculate_Vacation_Return_Date(clsDate DateFrom, short VacationDays) {

		short WeekEndCounter = 0;   

		while (Is_WeekEnd(DateFrom)) {

			DateFrom = Increase_Date_By_One_Day(DateFrom);
		}

		for (int i = 0; i < VacationDays + WeekEndCounter; i++)
		{
			if (Is_WeekEnd(DateFrom))
			{
				WeekEndCounter++;
			}
			DateFrom = Increase_Date_By_One_Day(DateFrom);
		}

		while (Is_WeekEnd(DateFrom)) {

			DateFrom = Increase_Date_By_One_Day(DateFrom);
		}

		return DateFrom;   
	}



	static bool isDate1AfterDate2(clsDate Date1, clsDate Date2) {

		return (!isDate1BeforeDate2(Date1, Date2) && !isDate1EqualDate2(Date1, Date2));
	}
	bool isDate1AfterDate2(clsDate Date2) {

		return isDate1AfterDate2(*this, Date2);  
	}



	enum enDateCompare { Before = -1, Equal = 0, After = 1};

	static enDateCompare Compare_Dates(clsDate Date1, clsDate Date2) {

		if (isDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (isDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;   

		return enDateCompare::After;    
	}

	enDateCompare Compare_Dates(clsDate Date2) {

		return Compare_Dates(*this, Date2);
	}


	static string Format_Date(clsDate Date, string DateFormat = "dd/mm/yyyy") {

		string FormattedDateString = "";

		FormattedDateString = clsString::Replace_Words(DateFormat, "dd", to_string(Date.Day));
		FormattedDateString = clsString::Replace_Words(FormattedDateString, "mm", to_string(Date.Month));
		FormattedDateString = clsString::Replace_Words(FormattedDateString, "yyyy", to_string(Date.Year));

		return FormattedDateString;   
	}
	string Format_Date(string DateFormat = "dd/mm/yyyy") {

		return Format_Date(*this, DateFormat); 
	}


};