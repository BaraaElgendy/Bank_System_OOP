#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{

private:
	static void _ReadClientInfo(clsBankClient& Client) {
		cout << "\nEnter First Name: ";
		Client.setFirstName(clsInputValidate::ReadString());

		cout << "\nEnter Last Name: ";
		Client.setLastName(clsInputValidate::ReadString());

		cout << "\nEnter Email: ";
		Client.setEmail(clsInputValidate::ReadString());

		cout << "\nEnter Phone: ";
		Client.setPhone(clsInputValidate::ReadString());

		cout << "\nEnter Pincode: ";
		Client.setPinCode(clsInputValidate::ReadString());

		cout << "\nEnter Balance: ";
		Client.setAccountBalance(clsInputValidate::ReadDblNumber());

	};

	static void _PrintClientInfo(clsBankClient Client) {
		cout << "\nClient Card:";
		cout << "\n______________________";
		cout << "\nFirstName  : " << Client.FirstName();
		cout << "\nLastName   : " << Client.LastName();
		cout << "\nFull Name  : " << Client.FullName();
		cout << "\nEmail      : " << Client.Email();
		cout << "\nPhone      : " << Client.Phone();
		cout << "\nAcc Number : " << Client.AccountNumber();
		cout << "\nPassword   : " << Client.PinCode();
		cout << "\nBalance    : " << Client.AccountBalance();
		cout << "\n______________________\n";
	}


public:
	static void ShowUpdateClientScreen() {

		system("cls");

		_DrawScreenHeader("\tUpdate Client Screen");

		string AccountNumber = "";

		cout << "Please Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "Client Not Found, Try Again: ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientInfo(Client);

		char Ans = 'n';
		cout << "\nAre You Sure You Want To Update This Client? (Y/N) ";
		cin >> Ans;

		if ('y' == tolower(Ans)) {

			cout << "\n----------------------------------";
			cout << "\n      Update Client Info\n";
			cout << "----------------------------------\n";
			_ReadClientInfo(Client);

			clsBankClient::enSaveResults SaveResult;

			SaveResult = Client.Save();

			switch (SaveResult) {
			case clsBankClient::svSaveFailedEmptyObject:
				cout << "\nError, Didn't Save Because The Account Is Empty\n";
				break;

			case clsBankClient::svSaveDone:
				cout << "\nAccount Updated Successfuly :-)\n";
				break;
			}
		};

		
	}





};

