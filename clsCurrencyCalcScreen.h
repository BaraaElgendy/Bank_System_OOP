#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include "clsCurrency.h"

class clsCurrencyCalcScreen : protected clsScreen
{


private:
	static void _PrintCurrencyCard(clsCurrency Currency,string Title) {
		cout << "\n" << Title;
		cout << "\n____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n____________________________\n\n";
	}

	static clsCurrency _GetCurrency(string Message) {
		string code;
		cout << Message;
		code = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(code);

		while (Currency.IsEmpty()) {
			cout << "\nCurrency Not Found, Try Again: ";
			code = clsInputValidate::ReadString();
			Currency = clsCurrency::FindByCode(code);
		}

		return Currency;
	}

	static float _GetAmount() {
		float Amount;
		cout << "\nEnter The Amount To Exchange: ";
		Amount = clsInputValidate::ReadFloatNumber();
		return Amount;
	}

	static void _PrintResults(float Amount, clsCurrency Currency1, clsCurrency Currency2) {

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		if (Currency1.CurrencyCode() == "USD") {

			float ConvertedAmount = Currency1.ConvertToOtherCurrency(Amount, Currency2);

			_PrintCurrencyCard(Currency2, "To:");

			cout << Amount << " " << Currency1.CurrencyCode() << " = " << ConvertedAmount << " " << Currency2.CurrencyCode();

		}
		else {

			_PrintCurrencyCard(Currency1, "Converting From: ");



			cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD\n";


			if (Currency2.CurrencyCode() == "USD") {
				return;
			}


			float ConvertedAmount = Currency1.ConvertToOtherCurrency(Amount, Currency2);
			_PrintCurrencyCard(Currency2, "To:");

			cout << Amount << " " << Currency1.CurrencyCode() << " = " << ConvertedAmount << " " << Currency2.CurrencyCode();

		}
	}

public:

	static void ShowCurrencyCalacScreen() {
		char Ans = 'y';

		while (tolower(Ans) == 'y') {


			system("cls");
			_DrawScreenHeader("\tCurrency Calculator Screen");


			clsCurrency CurrencyFrom = _GetCurrency("\nEnter Currency 1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nEnter Currency 2 Code: ");


			float Amount = _GetAmount();

			_PrintResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo You Want To Do Another Calculation? (Y/N) ";
			cin >> Ans;

		}


	}
};

