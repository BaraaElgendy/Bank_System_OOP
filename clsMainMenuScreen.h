#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsListClients.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClient.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsMenu.h"
#include"clsManageUsersMenu.h"
using namespace std;

class clsMainMenuScreen : protected clsScreen
{

private:
	enum enMainMenuOptions { eClientList = 1, eAddNew, eDelete, eUpdate, eFind, eTransactions, eManageUsers, eLogout };

	static short _ReadMainMenuOption() {
		cout << setw(37) << left << "" << "Choose What You Want To Do [1 to 8] ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 8, "Enter Number From 1 to 8: ");
		return Choice;
	}

	static void _ShowClientList() {

		clsListClients::ShowClientsList();

	}

	static void _ShowAddClientScreen() {
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen() {

		clsDeleteClient::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen() {

		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen() {

		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenu() {
	
		clsTransactionsMenu::ShowTransactionsMenu();
	
	}

	static void _ShowManageUsersScreen() {
	
		clsManageUsersMenu::ShowManageUsersMenu();
	}

	static void _ShowExitScreen() {}



	static void _GoBackToMainMenuScreen()
	{
		cout << "\nPress Any Button To Go To Main Menu....";
		system("pause>0");
		ShowMainMenu();
	};



	static void _PerformMainMenuOption(enMainMenuOptions Option) {

		switch (Option) {
		case eClientList:
			_ShowClientList();
			break;
			

		case eAddNew:
			_ShowAddClientScreen();
			break;
		case eDelete:
			_ShowDeleteClientScreen();
			break;
		case eUpdate:
			_ShowUpdateClientScreen();
			break;
		case eFind:
			_ShowFindClientScreen();
			break;

		case eTransactions:
			_ShowTransactionsMenu();
			break;

		case eManageUsers:
			_ShowManageUsersScreen();
			break;
		case eLogout:
			_ShowExitScreen();
			break;

		}

		_GoBackToMainMenuScreen();
	}


public:

	static void ShowMainMenu() {
		system("cls");
		clsScreen::_DrawScreenHeader("\t      Main Menu");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info\n";
		cout << setw(37) << left << "" << "\t[5] Find Client\n";
		cout << setw(37) << left << "" << "\t[6] Transactions\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users\n";
		cout << setw(37) << left << "" << "\t[8] Logout\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());


	}



};

