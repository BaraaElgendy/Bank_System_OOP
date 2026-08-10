#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"

class clsListUsers : protected clsScreen
{

private:

	static void _PrintUserRecordLine(clsUser User, bool BalanceMode = false) {

		

			cout << setw(8) << left << "" << "| " << setw(15) << left << User.UserName();
			cout << "| " << setw(20) << left << User.FullName();
			cout << "| " << setw(12) << left << User.Phone();
			cout << "| " << setw(20) << left << User.Email();
			cout << "| " << setw(10) << left << User.Password();
			cout << "| " << setw(12) << left << User.Permessions() << endl;

		
	};


public:



	static void ShowUsersList() {
		vector<clsUser> vUsers = clsUser::GetUsersList();

		system("cls");

		string Title = "\t  List Users Screen";
		string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s)";

		_DrawScreenHeader(Title, SubTitle);



		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Permessions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;



		if (vUsers.size() == 0) {
			cout << "\t\t\tNo Users Availabile In System!";
		}
		else {
			for (clsUser User : vUsers) {
				_PrintUserRecordLine(User);

			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;


	}

};

