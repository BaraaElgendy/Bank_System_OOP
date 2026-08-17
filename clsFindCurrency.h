#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include "clsCurrency.h"

class clsFindCurrency : protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency) {
		cout << "____________________________\n";
		cout << "\nCurrency Card:\n";
		cout << "____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n____________________________\n";
	}

	static short _GetFindChoice() {
		short Choice;
		cout << "Find By [1] Code or [2] Country? ";
		Choice = clsInputValidate::ReadNumberBetween(1, 2, "Choose 1 or 2");
		return Choice;
	}

public:

	static void ShowFindCurrencyScreen() {

		_DrawScreenHeader("\tFind Currency Screen");

		clsCurrency Currency = clsCurrency::FindByCode("");

		short Choice = _GetFindChoice();

		if (Choice == 1) {

			do {

				string code;
				cout << "\nEnter Currency Code: ";
				code = clsInputValidate::ReadString();

				Currency = clsCurrency::FindByCode(code);

				if (Currency.IsEmpty()) {
					cout << "\nCurrency Doesn't Exist, Try Again\n";
				}

			} while (Currency.IsEmpty());

			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);

		}

		if (Choice == 2) {

			do {

				string country;
				cout << "\nEnter Country Name: ";
				country = clsInputValidate::ReadString();

				Currency = clsCurrency::FindByCountry(country);

				if (Currency.IsEmpty()) {
					cout << "\nCurrency Doesn't Exist, Try Again: ";
				}

			} while (Currency.IsEmpty());

			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);

		};



	}


};

