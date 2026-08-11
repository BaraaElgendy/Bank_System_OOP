#pragma once
#include<iostream>
#include"clsDate.h"
#include"clsUser.h"
#include"Global.h"
using namespace std;
class clsScreen
{

protected:

	static void _ShowDateAndUser() {
		
		cout << "\t\t\t\tUser: " << CurrentUser.UserName() <<endl;
		cout << "\t\t\t\tDate: "<<clsDate::DateToString(clsDate());

	}

	static void _DrawScreenHeader(string Title, string Subtitle = " ") {
		cout << "\t\t\t\t----------------------------------------------------\n\n";
		cout << "\t\t\t\t\t" << Title << endl;
		if (Subtitle != " ") {
			cout << "\n\t\t\t\t\t" << Subtitle << endl;
		}
		cout << "\n\t\t\t\t----------------------------------------------------\n\n";
		_ShowDateAndUser();
		cout << "\n\n";
	}

	static bool CheckAccessRights(clsUser::enPermessions Permession) {

		if (!CurrentUser.CheckPermessionAccess(Permession)) {
			cout << "\t\t\t\t----------------------------------------------------\n\n";
			cout << "\t\t\t\t\tAccess Denied! Contact Your Admin\n\n";
			cout << "\t\t\t\t----------------------------------------------------\n\n";
			return false;
		}

		else
		{
			return true;
		}

	}

};

