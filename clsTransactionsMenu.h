#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsShowBalances.h"
#include"clsTransferScreen.h"
class clsTransactionsMenu : protected clsScreen
{

private:

	enum enTransactionsMenuChoice { eDeposit = 1, eWithdraw, eTotalBalances, eTransfer,eMainMenu };

	static short _ReadTransactionsMenuOption() {
		cout << setw(37) << left << "" << "Choose What You Want To Do [1 to 5] ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number From 1 to 5: ");
		return Choice;
	}

	static void _ShowDepositScreen() {
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen() {
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen() {
		clsShowBalances::ShowTotalBalances();
	}

	static void _ShowTransferScreen() { 
		clsTransferScreen::ShowTransferScreen();
	
	}

	static void _GoBackToTransactionsMenuScreen()
	{
		cout << "\nPress Any Button To Go To Transactions Menu....";
		system("pause>0");
		ShowTransactionsMenu();
	};



	static void _PerformTransactionsMenuOption(enTransactionsMenuChoice Choice) {
		

		switch (Choice) {
		case eDeposit:
		{
			_ShowDepositScreen();
			_GoBackToTransactionsMenuScreen();
			break;
		}

		case eWithdraw:
		{
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenuScreen();
			break;
		}

		case eTotalBalances:

		{
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenuScreen();
			break;
		}

		case eTransfer:
		{
			_ShowTransferScreen();
			_GoBackToTransactionsMenuScreen();
			break;
		}
		case eMainMenu:
		{

			break;

		}

		}
	}


public:


	static void ShowTransactionsMenu() {
		system("cls");
		if (!CheckAccessRights(clsUser::enPermessions::pTransactionsMenu)) {
			return;
		}

		_DrawScreenHeader("\t Transactions Menu");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tTransactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances\n";
		cout << setw(37) << left << "" << "\t[4] Transfer\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformTransactionsMenuOption((enTransactionsMenuChoice)_ReadTransactionsMenuOption());


	}


};

