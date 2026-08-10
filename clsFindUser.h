#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

class clsFindUser : protected clsScreen
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

	static void ShowFindUserScreen() {
		
		_DrawScreenHeader("\tFind User Screen");

		string UserName = "";

		cout << "Please Enter User Name: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName)) {

			cout << "User Not Found, Try Again: ";
			UserName = clsInputValidate::ReadString();

		}

		clsUser User = clsUser::Find(UserName);


		_PrintUserInfo(User);
	}


};

