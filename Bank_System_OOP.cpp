#include <iostream>
#include<string>
#include<iomanip>
#include"clsPerson.h"
#include"clsBankClient.h"
#include"clsUtil.h"
#include"clsMainMenuScreen.h"
using namespace std;


void PrintClientRecordLine(clsBankClient Client, bool BalanceMode = false) {

	if (BalanceMode) {
		cout << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.PinCode();
		cout << "| " << setw(12) << left << Client.AccountBalance() << endl;
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

void ListClients() {
	vector<clsBankClient> vClients = clsBankClient::GetClientsList();

	cout << "\n\t\t\t\tClient List (" << vClients.size() << ") Client(s)\n";
	cout << "-------------------------------------------------------------------------------------------------\n\n";
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(20) << "Email";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

	if (vClients.size() == 0) {
		cout << "\t\t\tNo Clients Availabile In System!";
	}
	else {
		for (clsBankClient Client : vClients) {
			PrintClientRecordLine(Client);

		}
	}

	cout << "\n-------------------------------------------------------------------------------------------------\n\n";


}

void ShowTotalBalances() {
	vector<clsBankClient> vClients = clsBankClient::GetClientsList();

	cout << "\n\t\t\t\tBalances List (" << vClients.size() << ") Client(s)\n";
	cout << "-------------------------------------------------------------------------------------------------\n\n";
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n\n-------------------------------------------------------------------------------------------------\n\n";

	double TotalBalances = clsBankClient::GetTotalBalances();

	if (vClients.size() == 0) {
		cout << "\t\t\tNo Clients Availabile In System!";
	}
	else {
		for (clsBankClient Client : vClients) {
			PrintClientRecordLine(Client, true);

		}
	}

	cout << "\n-------------------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t\tTotal Balances: " << TotalBalances << endl;
	cout << "\t\t\t\t(" << clsUtil::NumberToText(TotalBalances) << ") " << endl;


}

int main() {

	clsMainMenuScreen::ShowMainMenu();
}
