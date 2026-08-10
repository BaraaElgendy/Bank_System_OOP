#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

class clsAddNewUser : protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser& User) {
		cout << "\nEnter First Name: ";
		User.setFirstName(clsInputValidate::ReadString());

		cout << "\nEnter Last Name: ";
		User.setLastName(clsInputValidate::ReadString());

		cout << "\nEnter Email: ";
		User.setEmail(clsInputValidate::ReadString());

		cout << "\nEnter Phone: ";
		User.setPhone(clsInputValidate::ReadString());

		cout << "\nEnter Password: ";
		User.setPassword(clsInputValidate::ReadString());

		cout << "\nSet Permessions:-\n";
		User.setPermessions(_ReadPermessionsToSet());
	};

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

	static int _ReadPermessionsToSet() {
		int Permessions = 0;
		char Ans = 'n';

		
		cout << "\nDo You Want To Give Full Access? (Y/N) ";
		cin >> Ans;
	
		if (tolower(Ans) == 'y') {

			return clsUser::enPermessions::eAll;
		
		}

		cout << "\nDo You Want To Give Permessions To:\n";
		
		cout << "\nShow Client List? (Y/N) ";
		cin >> Ans;
		
		if (tolower(Ans) == 'y')
		{
			Permessions += clsUser::enPermessions::pListClients;
		}

		cout << "\nAdd New Client? (Y/N) ";
		cin >> Ans;
		
		if (tolower(Ans) == 'y')
		{
			Permessions += clsUser::enPermessions::pAddClient;
		}

		cout << "\nDelete Client? (Y/N) ";
		cin >> Ans;
		
		if (tolower(Ans) == 'y')
		{
			Permessions += clsUser::enPermessions::pDeleteClient;
		}

		cout << "\nUpdate Client? (Y/N) ";
		cin >> Ans;
		
		if (tolower(Ans) == 'y')
		{
			Permessions += clsUser::enPermessions::pUpdateClient;
		}

		cout << "\nFind Client? (Y/N) ";
		cin >> Ans;
		
		if (tolower(Ans) == 'y')
		{
			Permessions += clsUser::enPermessions::pFindClient;
		}

		cout << "\nTransactions Menu? (Y/N) ";
		cin >> Ans;
		
		if (tolower(Ans) == 'y')
		{
			Permessions += clsUser::enPermessions::pTransactionsMenu;
		}

		cout << "\nManage Users Menu? (Y/N) ";
		cin >> Ans;
		
		if (tolower(Ans) == 'y')
		{
			Permessions += clsUser::enPermessions::pManageUsers;
		}

		return Permessions;

	}

public:


	static void ShowAddNewUserScreen() {

		_DrawScreenHeader("\tAdd New User Screen");

		string UserName = "";

		cout << "Please Enter User Name: ";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName)) {

			cout << "User Alrady Exist, Try Again: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult;

		SaveResult = NewUser.Save();

		switch (SaveResult) {

		case clsUser::svSaveFailedEmptyObject:
			cout << "\nError, Didn't Save Because The Account Is Empty\n";
			break;

		case clsUser::svSaveDone:
			cout << "\nUser Added Successfuly :-)\n";
			_PrintUserInfo(NewUser);
			break;

		case clsUser::svFailedUserExist:
			cout << "\nError, Didn't Save Because Account Already Exists\n";
			break;
		}

	}





};

