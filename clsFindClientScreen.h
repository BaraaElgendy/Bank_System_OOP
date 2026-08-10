#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsFindClientScreen : protected clsScreen
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

	static void ShowFindClientScreen() {
		system("cls");

		_DrawScreenHeader("\tFind Client Screen");

		string AccountNumber = "";

		cout << "Please Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "Client Not Found, Try Again: ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		//if (!Client.IsEmpty()) {
		//	cout << "\nClient Is Found :-)\n";
		//}
		//else {
		//	cout << "\nClient Is Not Found\n";
		//}


		_PrintClientInfo(Client);
	}





};

