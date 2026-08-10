#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsUtil.h"

class clsShowBalances : protected clsScreen
{

private:
	static void _PrintClientRecordLine(clsBankClient Client, bool BalanceMode = false) {

		if (BalanceMode) {
			cout << "\t   " << "| " << setw(15) << left << Client.AccountNumber();
			cout << "\t   " << "| " << setw(40) << left << Client.PinCode();
			cout << "\t   " << "| " << setw(12) << left << Client.AccountBalance() << endl;
		}
		else
		{

			cout << "| " << setw(15) << left << Client.AccountNumber();
			cout << "| " << setw(20) << left << Client.FullName();
			cout << "| " << setw(12) << left << Client.Phone();
			cout << "| " << setw(20) << left << Client.Email();
			cout << "| " << setw(10) << left << Client.PinCode();
			cout << "| " << setw(12) << left << Client.AccountBalance() << endl;

		}
	}


public:
	static void ShowTotalBalances() {
		system("cls");
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t Total Balances Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s)";

		_DrawScreenHeader(Title, SubTitle);


		cout << "\t   " << "-------------------------------------------------------------------------------------------------\n\n";
		cout << "\t   " << "| " << left << setw(15) << "Account Number";
		cout << "\t   " << "| " << left << setw(40) << "Client Name";
		cout << "\t   " << "| " << left << setw(12) << "Balance";
		cout << "\t   " << "\n\n\t   -------------------------------------------------------------------------------------------------\n\n";

		double TotalBalances = clsBankClient::GetTotalBalances();

		if (vClients.size() == 0) {
			cout << "\t\t\tNo Clients Availabile In System!";
		}
		else {
			for (clsBankClient Client : vClients) {
				_PrintClientRecordLine(Client, true);

			}
		}

		cout << "\t   " << "\n\t   -------------------------------------------------------------------------------------------------\n\n";
		cout << "\t   " << "\t\t\t\tTotal Balances: " << TotalBalances << endl;
		cout << "\t   " << "\t\t\t\t(" << clsUtil::NumberToText(TotalBalances) << ") " << endl;


	}


};

