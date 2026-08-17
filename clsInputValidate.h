#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;

class clsInputValidate
{
public:

	template <typename T> static bool IsNumberBetween(T Number, T From, T To) {

		return (Number >= From) && (Number <= To) ? true : false;
	};


	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) {
		if (clsDate::IsDate1AfterDate2(From, To)) {
			clsDate::SwapDates(From, To);
		}

		return ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) && (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)));

	}

	template <typename T> static T ReadNumber(string Message= "Invalid Input, Try Again") {
		
		T Number;
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


	template <typename T> static T ReadNumberBetween(T From, T To, string Message = "Number Not In Range, Try Again") {

		T num = ReadNumber<T>();


		while (!IsNumberBetween(num, From, To)) {
			cout << Message << endl;
			num = ReadNumber<T>();
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

