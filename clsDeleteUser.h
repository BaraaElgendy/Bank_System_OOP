#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

class clsDeleteUser : protected clsScreen
{
private:

	static void _PrintUserInfo(clsUser User) {
		cout << "\n______________________\n";
		cout << "\n      User Card";
		cout << "\n______________________\n";
		cout << "\nFirstName   : " << User.FirstName();
		cout << "\nLastName    : " << User.LastName();
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email();
		cout << "\nPhone       : " << User.Phone();
		cout << "\nUser Name   : " << User.UserName();
		cout << "\nPassword    : " << User.Password();
		cout << "\nPermessions : " << User.Permessions();
		cout << "\n______________________\n";
	}


public:

	static void ShowDeleteUserScreen() {

		_DrawScreenHeader("\tDelete User Screen");

		string UserName = "";

		cout << "Please Enter User Name: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName)) {

			cout << "\nUser Not Found, Try Again: ";
			UserName = clsInputValidate::ReadString();

		}

		clsUser User = clsUser::Find(UserName);
		_PrintUserInfo(User);

		if (User.Permessions() == -1) {
			cout << "\nUser Is Admin And Cannot Be Deleted\n";
		}
		else {
			char Ans = 'n';
			cout << "\nAre You Sure You Want To Delete This User? (Y/N) ";
			cin >> Ans;

			if ('y' == tolower(Ans)) {

				if (User.Delete()) {
					cout << "\nUser Deleted Successfuly\n";
					_PrintUserInfo(User);
				}
				else {
					cout << "\nError Occured, User Isn't Deleted\n";
				}


			}

		}
	}


};

