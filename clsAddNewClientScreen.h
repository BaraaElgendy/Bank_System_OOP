#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;



class clsAddNewClientScreen : protected clsScreen
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
	static void ShowAddNewClientScreen() {
		system("cls");

		_DrawScreenHeader("\tAdd New Client Screen");
		
		string AccountNumber = "";

		cout << "Please Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber)) {

			cout << "Client Alrady Exist, Try Again: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult) {

		case clsBankClient::svSaveFailedEmptyObject:
			cout << "\nError, Didn't Save Because The Account Is Empty\n";
			break;

		case clsBankClient::svSaveDone:
			cout << "\nClient Added Successfuly :-)\n";
			_PrintClientInfo(NewClient);
			break;

		case clsBankClient::svFailedClientExist:
			cout << "\nError, Didn't Save Because Account Already Exists\n";
			break;
		}

	}

};

