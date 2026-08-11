#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
using namespace std;
class clsListClients:protected clsScreen
{

private:

	static void _PrintClientRecordLine(clsBankClient Client, bool BalanceMode = false) {

		if (BalanceMode) {
			cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
			cout << setw(8) << "| " << setw(40) << left << Client.PinCode();
			cout << setw(8) << "| " << setw(12) << left << Client.AccountBalance() << endl;
		}
		else
		{

			cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
			cout << "| " << setw(20) << left << Client.FullName();
			cout << "| " << setw(12) << left << Client.Phone();
			cout << "| " << setw(20) << left << Client.Email();
			cout << "| " << setw(10) << left << Client.PinCode();
			cout << "| " << setw(12) << left << Client.AccountBalance() << endl;

		}
	};


public:



	static void ShowClientsList() {

		if (!CheckAccessRights(clsUser::enPermessions::pListClients)) {
			return;
		}

		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		system("cls");

		string Title = "\t  Client List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s)";

		_DrawScreenHeader(Title, SubTitle);

		

		 cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout <<  setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;



		if (vClients.size() == 0) {
			cout << "\t\t\tNo Clients Availabile In System!";
		}
		else {
			for (clsBankClient Client : vClients) {
				_PrintClientRecordLine(Client);

			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


	}

};

