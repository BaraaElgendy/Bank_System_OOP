#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsListUsers.h"
#include"clsAddNewUser.h"
#include"clsDeleteUser.h"
#include"clsUpdateUser.h"
#include"clsFindUser.h"
class clsManageUsersMenu:protected clsScreen
{

private:

	enum enUsersMenuOption { eListUsers = 1, eAddUser, eDeleteUser, eUpdateUser, eFindUser, eMainMenu };

	static short _ReadManageUsersMenuOption() {
		cout << setw(37) << left << "" << "Choose What You Want To Do [1 to 6] ";
		short Choice = clsInputValidate::ReadNumberBetween(1, 6, "Enter Number From 1 to 6: ");
		return Choice;
	}

	static void _ShowListUsersScreen(){
		clsListUsers::ShowUsersList();
	}

	static void _ShowAddUsersScreen() {
		clsAddNewUser::ShowAddNewUserScreen();
	
	}

	static void _ShowDeleteUsersScreen() {
		clsDeleteUser::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen() {
		clsUpdateUser::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen() {
		clsFindUser::ShowFindUserScreen();
	}

	static void _GoBackToManageUsersScreen()
	{
		cout << "\nPress Any Button To Go To Manage Users Menu....";
		system("pause>0");
		ShowManageUsersMenu();
	};



	static void _PerformMenuOption(short Choice) {
		system("cls");

		switch (Choice) {

		case enUsersMenuOption::eListUsers:
			_ShowListUsersScreen();
			break;

		case enUsersMenuOption::eAddUser:
			_ShowAddUsersScreen();
			break;

		case enUsersMenuOption::eDeleteUser:
			_ShowDeleteUsersScreen();
			break;

		case enUsersMenuOption::eUpdateUser:
			_ShowUpdateUserScreen();
			
			break;

		case enUsersMenuOption::eFindUser:
			_ShowFindUserScreen();
			
			break;

		case enUsersMenuOption::eMainMenu:

			break;
		}

		if (Choice != enUsersMenuOption::eMainMenu) {
			_GoBackToManageUsersScreen();
		}

	}


public:

	static void ShowManageUsersMenu() {
		
		if (!CheckAccessRights(clsUser::enPermessions::pManageUsers)) {
			return;
		}
		system("cls");
		clsScreen::_DrawScreenHeader("\t Manage Users Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t     Manage Users\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users\n";
		cout << setw(37) << left << "" << "\t[2] Add New User\n";
		cout << setw(37) << left << "" << "\t[3] Delete Delete\n";
		cout << setw(37) << left << "" << "\t[4] Update User Info\n";
		cout << setw(37) << left << "" << "\t[5] Find User\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformMenuOption((enUsersMenuOption)_ReadManageUsersMenuOption());


	}



};

