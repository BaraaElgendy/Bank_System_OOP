#pragma once
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{

	static void _PrintLoginRegisterRecordLine(clsBankClient::stTransferInfo Client) {



		cout << setw(8) << left << "" << "| " << setw(22) << left << Client.DateTime;
		cout << "| " << setw(10) << left << Client.SourceAccount;
		cout << "| " << setw(10) << left << Client.DestenationAccount;
		cout << "| " << setw(10) << left << Client.Amount ;
		cout << "| " << setw(10) << left << Client.SourceBalance;
		cout << "| " << setw(10) << left << Client.DestenationBalance;
		cout << "| " << setw(10) << left << Client.User <<endl;
	};





public:

	static void ShowTransferLogScreen() {

		system("cls");
		vector<clsBankClient::stTransferInfo> vUsers = clsBankClient::GetTransferLogInfo();


		string Title = "\t   Transfer Log Screen";
		string SubTitle = "\t      (" + to_string(vUsers.size()) + ") Log(s)";

		_DrawScreenHeader(Title, SubTitle);



		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(22) << "Date/Time";
		cout << "| " << left << setw(10) << "s.Acc";
		cout << "| " << left << setw(10) << "d.Acc";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(10) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;



		if (vUsers.size() == 0) {
			cout << "\t\t\tNo Users Availabile In System!";
		}
		else {
			for (clsBankClient::stTransferInfo User : vUsers) {
				_PrintLoginRegisterRecordLine(User);

			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;


	}


};

