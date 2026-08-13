#pragma once
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
class clsLoginRegisterScreen: protected clsScreen
{
private:

	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord User) {



		cout << setw(8) << left << "" << "| " << setw(30) << left << User.DateTime;
		cout << "| " << setw(20) << left << User.UserName;
		cout << "| " << setw(20) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permessions << endl;


	};

	



public:

	static void ShowLoginRegisterList() {


		if (!CheckAccessRights(clsUser::enPermessions::pLoginRegister)) {
			return;
		}

		vector<clsUser::stLoginRegisterRecord> vUsers = clsUser::GetLoginRegisterLine();


		string Title = "\t Login Register Screen";
		string SubTitle = "\t      (" + to_string(vUsers.size()) + ") Log(s)";

		_DrawScreenHeader(Title, SubTitle);



		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Date/Time";
		cout << "| " << left << setw(20) << "User Name";
		cout << "| " << left << setw(20) << "Pin Code";
		cout << "| " << left << setw(12) << "Permessions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;



		if (vUsers.size() == 0) {
			cout << "\t\t\tNo Users Availabile In System!";
		}
		else {
			for (clsUser::stLoginRegisterRecord User : vUsers) {
				_PrintLoginRegisterRecordLine(User);

			}
		}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "______________________________________________\n" << endl;


	}



};

