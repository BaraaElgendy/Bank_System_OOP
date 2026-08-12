#pragma once
#include <iostream>
#include"clsScreen.h"
#include "clsUser.h"
#include"Global.h"
#include"clsMainMenuScreen.h"

using namespace std;

class clsLoginScreen :protected clsScreen
{

private:
	static bool _Login() {


		bool LoginFailed = false;

		short LoginCounter = 0;

		string UserName, Password;

		do {

			if (LoginFailed) {

				LoginCounter++;

				cout << "\nInvalid Username/Password!\n";
				cout << "You Have " << (3 - LoginCounter) << " Tries Left\n";
			
}

			if (LoginCounter == 3) {
				cout << "\nYou Are Locked Out Of The System After 3 Failed Tries\n";
				return false;
			}

			cout << "\nEnter Username: ";
			cin >> UserName;

			cout << "Enter Password: ";
			cin >> Password;


			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

			

		} while (LoginFailed);

		
			clsMainMenuScreen::ShowMainMenu();
			return true;
		
	}
	

public:

	static bool ShowLoginScreen() {
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}

};

