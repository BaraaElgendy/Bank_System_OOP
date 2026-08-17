#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsWithdrawScreen : protected clsScreen
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

	static void ShowWithdrawScreen() {

		system("cls");
		_DrawScreenHeader("\t Withdraw Screen");

		string AccountNumber = "";

		cout << "Please Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "Client With Account Number [" << AccountNumber << "] Is Not Found, Try Again : ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClientInfo(Client);


		double Amount = 0;
		cout << "\nEnter Withdraw Amount: ";
		Amount = clsInputValidate::ReadNumber<double>();

		while (Amount < 0) {
			cout << "\nEnter Positive Amount: ";
			Amount = clsInputValidate::ReadNumber<double>();
		}

		if (Client.Withdraw(Amount) == false) {
			cout << "\nCannot Withdraw, Insuffecient Amount\n";
			cout << "\nAmount To Withdraw: " << Amount << endl;
			cout << "Your Balance Is: " << Client.AccountBalance() << endl;
		}
		else {



			char Ans = 'n';
			cout << "\nAre You Sure You Want To Perform This Withdraw? (Y/N) ";
			cin >> Ans;

			if (tolower(Ans) == 'y') {
				cout << "\nWithdraw Done Successfuly\n";
				cout << "\nAccount Balance: " << Client.AccountBalance() << endl;
			}
			else {
				cout << "\nOperation Canceled\n";
			}

		}

	}



};

