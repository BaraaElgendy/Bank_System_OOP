#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include "clsCurrency.h"
class clsUpdateCurrencyRate : protected clsScreen
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

	static void _UpdateCurrencyRate(clsCurrency& Currency) {
		cout << "\nUpdate Currency Rate\n";
		cout << "____________________________\n";
		float rate;
		cout << "\nEnter New Rate: ";
		cin >> rate;

		Currency.UpdateRate(rate);

	}

public:

	static void ShowUpdateRateScreen() {
		_DrawScreenHeader("\tUpdate Currency Rate Screen");

		clsCurrency Currency = clsCurrency::FindByCode("");


		do {

			string code;
			cout << "\nEnter Currency Code: ";
			code = clsInputValidate::ReadString();

			Currency = clsCurrency::FindByCode(code);

			if (Currency.IsEmpty()) {
				cout << "\nCurrency Doesn't Exist, Try Again\n";
			}

		} while (Currency.IsEmpty());

		_PrintCurrency(Currency);


		char Ans = 'n';
		cout << "\nAre You Sure You Want To Update This Currency Rate? (Y/N) ";
		cin >> Ans;

		if (tolower(Ans) == 'y') {
			_UpdateCurrencyRate(Currency);
			cout << "\nCurrency Rate Updated Successfuly :-)\n";
			_PrintCurrency(Currency);
		}



	}


};





