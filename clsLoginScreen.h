#pragma once
#include <iostream>
#include"clsScreen.h"
#include "clsUser.h"
#include"Global.h"
#include"clsMainMenuScreen.h"
using namespace std;
class clsLoginScreen:protected clsScreen
{

private:
	static void _Login() {
		

		bool LoginFailed = false;

		string UserName, Password;

		do {

			if (LoginFailed) {
				cout << "\nWrong Username/Password, Try Again\n\n";
			}

			cout << "Enter Username: ";
			cin >> UserName;

			cout << "Enter Password: ";
			cin >> Password;


			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();


		} while (LoginFailed);

		
		clsMainMenuScreen::ShowMainMenu();
	}

public:

	static void ShowLoginScreen() {
		_DrawScreenHeader("\t  Login Screen");
		_Login();
	}

};

