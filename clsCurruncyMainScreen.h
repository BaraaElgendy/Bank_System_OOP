#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsListCurrencies.h"
#include"clsFindCurrency.h"
#include"clsUpdateCurrencyRate.h"
#include"clsCurrencyCalcScreen.h"
class clsCurruncyMainScreen : protected clsScreen
{

	enum enCurrencyMenuOption { eListCurrencies = 1, eFindCurrency, eUpdateRate, eCurrencyCalc, eMainMenu };

	static short _ReadManageCurrencyMenuOption() {
		cout << setw(37) << left << "" << "Choose What You Want To Do [1 to 5] ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number From 1 to 5: ");
		return Choice;
	}

	static void _ShowListCurrenciesScreen() {
		clsListCurrencies::ShowCurrenciesList();
	}

	static void _ShowFindCurrencyScreen() {
		clsFindCurrency::ShowFindCurrencyScreen();
	
	}

	static void _ShowUpdateRateScreen() {
	
		clsUpdateCurrencyRate::ShowUpdateRateScreen();
	}

	static void _ShowCurrencyCalcScreen() {
		clsCurrencyCalcScreen::ShowCurrencyCalacScreen();
	}

	static void _GoBackToCurrencyScreen()
	{
		cout << "\nPress Any Button To Go To Currency Exchange Menu....";
		system("pause>0");
		ShowCurrencyMenu();
	};



	static void _PerformCurrencyOption(short Choice) {
		system("cls");

		switch (Choice) {

		case enCurrencyMenuOption::eListCurrencies:
			_ShowListCurrenciesScreen();
			break;

		case enCurrencyMenuOption::eFindCurrency:
			_ShowFindCurrencyScreen();
			break;

		case enCurrencyMenuOption::eUpdateRate:
			_ShowUpdateRateScreen();
			break;

		case enCurrencyMenuOption::eCurrencyCalc:
			_ShowCurrencyCalcScreen();

			break;

		case enCurrencyMenuOption::eMainMenu:

			break;
		}

		if (Choice != enCurrencyMenuOption::eMainMenu) {
			_GoBackToCurrencyScreen();
		}

	}


public:

	static void ShowCurrencyMenu() {

		if (!CheckAccessRights(clsUser::enPermessions::pCurrencyExchange)) {
			return;
		}
		system("cls");
		clsScreen::_DrawScreenHeader("\tCurrency Exchange Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformCurrencyOption((enCurrencyMenuOption)_ReadManageCurrencyMenuOption());


	}






};

