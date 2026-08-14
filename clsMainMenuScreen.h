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
#include"Global.h"
#include"clsLoginRegisterScreen.h"
#include"clsUser.h"
using namespace std;

class clsMainMenuScreen : protected clsScreen
{

private:
	enum enMainMenuOptions { eClientList = 1, eAddNew, eDelete, eUpdate, eFind, eTransactions, eManageUsers, eLoginRegister, eLogout };

	static string _GetPermessionSymbol(clsUser::enPermessions Permession) {
		if (CurrentUser.CheckPermessionAccess(Permession)) {
			return "\033[32m[\xFB]\033[0m ";
		}
		else {
			return "\033[31m[x]\033[0m ";
		}


	}

	static short _ReadMainMenuOption() {
		cout << setw(37) << left << "" << "Choose What You Want To Do [1 to 9] ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 9, "Enter Number From 1 to 9: ");
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

	static void _ShowLoginRegisterScreen() {
		clsLoginRegisterScreen::ShowLoginRegisterList();
	}

	static void _Logout() {
		CurrentUser = clsUser::Find("", "");
	}

	static void _GoBackToMainMenuScreen()
	{
		cout << "\nPress Any Button To Go To Main Menu....";
		system("pause>0");
		ShowMainMenu();
	};

	static void _PerformMainMenuOption(enMainMenuOptions Option) {

		system("cls");

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

		case eLoginRegister:
			_ShowLoginRegisterScreen();
			break;

		case eLogout:
			_Logout();
			break;

		}
		
		if (Option != eLogout) {

			_GoBackToMainMenuScreen();
		}

	};


public:

	static void ShowMainMenu() {
		system("cls");
		clsScreen::_DrawScreenHeader("\t      Main Menu");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t       Main Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << _GetPermessionSymbol(clsUser::enPermessions::pListClients) << "[1] Show Client List\n";
		cout << setw(37) << left << "" << _GetPermessionSymbol(clsUser::enPermessions::pAddClient) << "[2] Add New Client\n";
		cout << setw(37) << left << "" << _GetPermessionSymbol(clsUser::enPermessions::pDeleteClient) << "[3] Delete Client\n";
		cout << setw(37) << left << "" << _GetPermessionSymbol(clsUser::enPermessions::pUpdateClient) << "[4] Update Client Info\n";
		cout << setw(37) << left << "" << _GetPermessionSymbol(clsUser::enPermessions::pFindClient) << "[5] Find Client\n";
		cout << setw(37) << left << "" << _GetPermessionSymbol(clsUser::enPermessions::pTransactionsMenu) << "[6] Transactions\n";
		cout << setw(37) << left << "" << _GetPermessionSymbol(clsUser::enPermessions::pManageUsers) << "[7] Manage Users\n";
		cout << setw(37) << left << "" << _GetPermessionSymbol(clsUser::enPermessions::pLoginRegister) << "[8] Login Register\n";
		cout << setw(37) << left << "" << "\t [9] Logout\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());


	};

};

