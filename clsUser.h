#pragma once
#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"
#include"clsDate.h"
#include"clsUtil.h"
class clsUser : public clsPerson
{

private:
    enum enMode { EmptyMode = 0, UpdateMode = 2, AddNewMode = 3 };
    enMode _Mode;

    string _UserName;
    string _Password;
    int _Permessions;
    bool _MarkForDelete = false;

    struct stLoginRegisterRecord;

    static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#") {

        vector<string> vUserData;

        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3],
            vUserData[4], clsUtil::DecryptText(vUserData[5], 4), stod(vUserData[6]));
    }

    static stLoginRegisterRecord _ConvertLineToLoginStruct(string Line, string Seperator = "#//#") {

        stLoginRegisterRecord Record;

        vector<string> vUserData;

        vUserData = clsString::Split(Line, Seperator);

        Record.DateTime = vUserData[0];
        Record.UserName = vUserData[1];
        Record.Password = clsUtil::DecryptText(vUserData[2], 4);
        Record.Permessions = stoi(vUserData[3]);

        return Record;
    };



    static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#") {
        string DataLine = "";
        DataLine += User.FirstName() + Seperator;
        DataLine += User.LastName() + Seperator;
        DataLine += User.Email() + Seperator;
        DataLine += User.Phone() + Seperator;
        DataLine += User.UserName() + Seperator;
        DataLine += clsUtil::EncryptText(User.Password(), 4) + Seperator;
        DataLine += to_string(User.Permessions());


        return DataLine;

    };


    static vector <clsUser> _LoadUsersDataFromFile() {

        fstream MyFile;
        vector <clsUser> vUsers;

        MyFile.open("Users.txt", ios::in); //read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                vUsers.push_back(_ConvertLineToUserObject(Line));


            }

            MyFile.close();



        }

        return vUsers;
    }


    static void _SaveUsersDataToFile(vector <clsUser> vUsers) {

        fstream MyFile;

        string DataLine;

        MyFile.open("Users.txt", ios::out); //Write Mode

        if (MyFile.is_open()) {

            for (clsUser C : vUsers) {

                if (C._MarkForDelete == false) {
                    DataLine = _ConvertUserObjectToLine(C);

                    MyFile << DataLine << endl;
                }
            };



            MyFile.close();
        }

    }

    static void _AddDataLineToFile(string DataLine) {

        fstream MyFile;

        MyFile.open("Users.txt", ios::out | ios::app); //append Mode

        if (MyFile.is_open()) {

            MyFile << DataLine << endl;


            MyFile.close();
        }
    }

    void _AddNew() {

        _AddDataLineToFile(_ConvertUserObjectToLine(*this));

    }

    void _Update() {

        vector<clsUser> vUsers = _LoadUsersDataFromFile();

        for (clsUser& C : vUsers) {

            if (C.UserName() == _UserName) {
                C = *this;
                break;
            }

        }

        _SaveUsersDataToFile(vUsers);
    }


    static clsUser _GetEmptyUserObject() {

        return clsUser(enMode::EmptyMode, " ", " ", " ", " ", " ", " ", 0);

    }


    string _PrepareLogDataLine(string Seperator = "#//#") {
        string Line = "";
        Line += clsDate::GetSystemDateTime() + Seperator;
        Line += UserName() + Seperator;
        Line += clsUtil::EncryptText(Password(), 4) + Seperator;
        Line += to_string(Permessions());
        return Line;

    }

public:


    struct stLoginRegisterRecord {
        string DateTime;
        string UserName;
        string Password;
        int Permessions;

    };

    enum enPermessions {
        eAll = -1, pListClients = 1, pAddClient = 2, pDeleteClient = 4, pUpdateClient = 8,
        pFindClient = 16, pTransactionsMenu = 32, pManageUsers = 64, pLoginRegister = 128
    };


    clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password, int Permessions)
        :clsPerson(FirstName, LastName, Email, Phone) {

        _UserName = UserName;
        _Password = Password;
        _Permessions = Permessions;
        _Mode = Mode;
    }


    bool IsEmpty() {
        return(enMode::EmptyMode == _Mode);
    }

    void setUserName(string Username) {
        _UserName = Username;
    }

    string UserName() {
        return _UserName;
    }


    void setPassword(string Password) {
        _Password = Password;
    }

    string Password() {
        return _Password;
    }


    void setPermessions(int Permessions) {
        _Permessions = Permessions;
    }

    int Permessions() {
        return _Permessions;
    }


    static clsUser Find(string UserName) {

        fstream MyFile;

        MyFile.open("Users.txt", ios::in); //read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.UserName() == UserName) {

                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();

    };

    static clsUser Find(string UserName, string Password) {

        fstream MyFile;

        MyFile.open("Users.txt", ios::in); //read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);

                if (User.UserName() == UserName && User.Password() == Password) {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    };

    enum enSaveResults { svSaveFailedEmptyObject = 0, svSaveDone, svFailedUserExist };

    enSaveResults Save() {

        switch (_Mode) {

        case enMode::EmptyMode:


            return svSaveFailedEmptyObject;


        case enMode::UpdateMode:

            _Update();
            return svSaveDone;

        case enMode::AddNewMode:

            if (IsUserExist(_UserName)) {
                return svFailedUserExist;
            }

            _AddNew();

            _Mode = UpdateMode;
            return svSaveDone;

        }

    }

    bool Delete() {
        vector<clsUser> vUsers = _LoadUsersDataFromFile();

        for (clsUser& C : vUsers) {
            if (C.UserName() == _UserName && C.Permessions() != -1) {

                C._MarkForDelete = true;
                break;

            };

        }

        _SaveUsersDataToFile(vUsers);
        *this = _GetEmptyUserObject();
        return true;
    }

    static bool IsUserExist(string UserName) {


        return !Find(UserName).IsEmpty();

    }

    static clsUser GetAddNewUserObject(string UserName) {

        return clsUser(enMode::AddNewMode, " ", " ", " ", " ", UserName, " ", 0);

    }


    static vector<clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    bool CheckPermessionAccess(enPermessions Permession) {

        if (Permession == enPermessions::eAll) {
            return true;
        }

        if ((Permession & _Permessions) == Permession) {
            return true;
        }
        else {
            return false;
        }


    }


    void RegisterLogin() {

        fstream MyFile;

        string DataLine = _PrepareLogDataLine();

        MyFile.open("LoginRegister.txt", ios::out | ios::app); //append Mode

        if (MyFile.is_open()) {

            MyFile << DataLine << endl;

            MyFile.close();


        }

    }

    static vector<stLoginRegisterRecord> GetLoginRegisterLine() {

        fstream MyFile;

        vector<stLoginRegisterRecord> vLoginRegister;
     
        stLoginRegisterRecord LoginRegisterRecord;

        MyFile.open("LoginRegister.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {
                LoginRegisterRecord = _ConvertLineToLoginStruct(Line);
                vLoginRegister.push_back(LoginRegisterRecord);

            }

            MyFile.close();

        }

        return vLoginRegister;
    }

};

