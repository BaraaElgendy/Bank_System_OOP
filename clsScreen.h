#pragma once
#include<iostream>
using namespace std;
class clsScreen
{

protected:

  static void _DrawScreenHeader(string Title, string Subtitle = " ") {
		cout << "\t\t\t\t----------------------------------------------------\n\n";
		cout << "\t\t\t\t\t" << Title << endl;
		if (Subtitle != " ") {
			cout << "\n\t\t\t\t\t" << Subtitle << endl;
		}
		cout << "\n\t\t\t\t----------------------------------------------------\n\n";
		

	}


};

