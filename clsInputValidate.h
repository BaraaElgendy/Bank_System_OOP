#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;

class clsInputValidate
{
public:

	static bool IsNumberBetween(int Number, int From, int To) {
		return (Number >= From) && (Number <= To) ? true : false;
	};

	static bool IsNumberBetween(double Number, double From, double To) {
		return (Number >= From) && (Number <= To) ? true : false;
	};

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) {
		if (clsDate::IsDate1AfterDate2(From, To)) {
			clsDate::SwapDates(From, To);
		}

		return ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) && (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)));

	}

	static int ReadIntNumber(string Message= "Invalid Input, Try Again") {
		int Number;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message << endl;
			cin >> Number;
		}
		return Number;
	}


	static int ReadIntNumberBetween(int From, int To, string Message= "Number Not In Range, Try Again") {

		int num = ReadIntNumber();

	
		while (!IsNumberBetween(num, From, To)) {
			cout << Message << endl;
			num = ReadIntNumber();
		}
		return num;


	}


	static short ReadShortNumber(string Message = "Invalid Input, Try Again") {
		short Number;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message << endl;
			cin >> Number;
		}
		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string Message = "Number Not In Range, Try Again") {

		short num = ReadShortNumber();


		while (!IsNumberBetween(num, From, To)) {
			cout << Message << endl;
			num = ReadShortNumber();
		}
		return num;


	}

	static double ReadDblNumber(string Message= "Invalid Input, Try Again") {
		double Number;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message << endl;
			cin >> Number;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string Message= "Number Not In Range, Try Again") {

		double num = ReadDblNumber();


		while (!IsNumberBetween(num, From, To)) {
			cout << Message << endl;
			num = ReadDblNumber();
		}
		return num;


	}


	static float ReadFloatNumber(string Message = "Invalid Input, Try Again") {
		float Number;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << Message << endl;
			cin >> Number;
		}
		return Number;
	}

	static float ReadFloatNumberBetween(float From, float To, string Message = "Number Not In Range, Try Again") {

		float num = ReadDblNumber();


		while (!IsNumberBetween(num, From, To)) {
			cout << Message << endl;
			num = ReadDblNumber();
		}
		return num;


	}



	static bool IsValidDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}


	static string ReadString() {
		string S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}

};

