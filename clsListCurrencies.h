#pragma once

#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"

class clsListCurrencies : protected clsScreen
{

private:

	static void _PrintCurrencyRecordLine(clsCurrency Currency) {



		cout << setw(8) << left << "" << "| " << setw(35) << left << Currency.Country();
		cout << "| " << setw(10) << left << Currency.CurrencyCode();
		cout << "| " << setw(40) << left << Currency.CurrencyName();
		cout << "| " << setw(8) << left << Currency.Rate()<<endl;

	};


public:



	static void ShowCurrenciesList() {
		vector<clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();

		system("cls");

		string Title = "\t List Currencies Screen";
		string SubTitle = "\t   (" + to_string(vCurrency.size()) + ") Currency(s)";

		_DrawScreenHeader(Title, SubTitle);



		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(8) << "Rate/($)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________________\n" << endl;



		if (vCurrency.size() == 0) {
			cout << "\t\t\tNo Currencies Availabile In System!";
		}
		else {
			for (clsCurrency Currency : vCurrency) {
				_PrintCurrencyRecordLine(Currency);

			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;


	}

};


