#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;

class clsTransferScreen : protected clsScreen
{
private:


	static clsBankClient _ReadClient() {
		string AccountNumber = "";

		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "Client Not Found, Try Again: ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		return Client;
	}

	static void _PrintClientInfo(clsBankClient Client) {

		cout << "\nClient Card:";
		cout << "\n______________________\n";
		cout << "\nFirstName  : " << Client.FirstName();
		cout << "\nAcc Number : " << Client.AccountNumber();
		cout << "\nBalance    : " << Client.AccountBalance();
		cout << "\n______________________\n\n";
	}


public:

	static void ShowTransferScreen() {
		system("cls");

		_DrawScreenHeader("\t   Transfer Screen");

		cout << "Please Enter Account Number You Want To Transfer From: ";
		clsBankClient ClientFrom = _ReadClient();
		_PrintClientInfo(ClientFrom);

		cout << "Please Enter Account Number You Want To Transfer To: ";
		clsBankClient ClientTo = _ReadClient();

		while (ClientFrom.AccountNumber() == ClientTo.AccountNumber()) {

			cout << "\nYou Can't Pick The Same Account, Enter Another Account To Transfer To: ";
			ClientTo = _ReadClient();

		}
		_PrintClientInfo(ClientTo);

		double Amount;
		cout << "\nEnter Transfer Amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > ClientFrom.AccountBalance()) {

			cout << "Amount Exeeds Balance, Try Another Amount: ";
			Amount = clsInputValidate::ReadDblNumber();

		};


		char Ans = 'n';
		cout << "\nAre You Sure You Want To Do This Transfer? (Y/N) ";
		cin >> Ans;



		if ('y' == tolower(Ans)) {

			if (ClientFrom.Transfer(Amount, ClientTo)) {
				cout << "\nOperation Done Successfuly!\n";

				_PrintClientInfo(ClientFrom);
				_PrintClientInfo(ClientTo);

			}

		}

	};

};
