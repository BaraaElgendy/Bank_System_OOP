#include"clsLoginScreen.h"
#include"clsUtil.h"
using namespace std;

int main() {

	while (true) {

		if (!clsLoginScreen::ShowLoginScreen()) {

			break;
		}


	}

	//cout<<clsUtil::EncryptText("1234", 4);
}
