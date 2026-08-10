#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsDeleteClient : protected clsScreen
{
private:
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

	static void ShowDeleteClientScreen() {

		_DrawScreenHeader("\tDelete Client Screen");

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
		cout << "\nAre You Sure You Want To Delete This Client? (Y/N) ";
		cin >> Ans;

		if ('y' == tolower(Ans)) {

			if (Client.Delete()) {
				cout << "\nClient Deleted Successfuly\n";
				_PrintClientInfo(Client);
			}
			else {
				cout << "\nError Occured, Client Isn't Deleted\n";
			}


		}

	}

};

