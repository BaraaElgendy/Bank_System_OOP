#pragma once
#include<iostream>
#include<string>
#include"clsString.h"
#include<fstream>
#include<vector>

class clsCurrency
{

private:
	enum enMode { eEmptyMode = 0, eUpdateMode = 1 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;


	static clsCurrency _ConvertLineToCurrencyObject(string Line) {

		

		vector<string> vCurrency;
		vCurrency = clsString::Split(Line, "#//#");

		return clsCurrency(enMode::eUpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stof(vCurrency[3]));

	}

	static string _ConvertObjectToCurrencyLine(clsCurrency Currency, string Delim = "#//#") {
		string DataLine = "";

		DataLine += Currency._Country + Delim;
		DataLine += Currency._CurrencyCode + Delim;
		DataLine += Currency._CurrencyName + Delim;
		DataLine += to_string(Currency._Rate);

		return DataLine;
	}

	static vector<clsCurrency> _LoadCurrencyDataFromFile() {

		fstream MyFile;

		vector<clsCurrency> vCurrency;

		

		MyFile.open("Currencies.txt", ios::in); //read Mode

		if (MyFile.is_open())
		{

			string Line;
			while (getline(MyFile, Line))

			{
				vCurrency.push_back(_ConvertLineToCurrencyObject(Line));

			}

			MyFile.close();

		};

		return vCurrency;
	}

	static void _SaveCurrencyDataToFile(vector<clsCurrency> vCurrency) {

		string DataLine;
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::out ); //append Mode

		if (MyFile.is_open()) {

			for (clsCurrency C : vCurrency) {

				DataLine = _ConvertObjectToCurrencyLine(C);

				MyFile << DataLine << endl;

			}

			MyFile.close();


		}
	}

	void _Update() {

		vector<clsCurrency> vCurrency;

		vCurrency = _LoadCurrencyDataFromFile();

		for (clsCurrency& C : vCurrency) {

			if (C.CurrencyCode() == CurrencyCode()) {
				
				C = *this;
				break;
			
			}

		}

		_SaveCurrencyDataToFile(vCurrency);
	}

	static clsCurrency _GetEmptyCurrencyObject() {
		return clsCurrency(enMode::eEmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode Mode,string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
		_Mode = Mode;
	}


	string Country() {
		return _Country;
	}

	string CurrencyCode() {
		return _CurrencyCode;
	}

	string CurrencyName() {
		return _CurrencyName;
	}

	float Rate() {
		return _Rate;
	}

	void UpdateRate(float Rate) {
		_Rate = Rate;
		_Update();
	}

	static   clsCurrency FindByCode(string CurrencyCode)
	{

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static   clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}

	bool IsEmpty() {
		return (_Mode == eEmptyMode);
	}

	static bool IsCurrencyExist(string CurrencyCode) {

		return !(clsCurrency::FindByCode(CurrencyCode).IsEmpty());
	
	}

	static vector<clsCurrency> GetCurrenciesList() {
		return _LoadCurrencyDataFromFile();
	}

};

