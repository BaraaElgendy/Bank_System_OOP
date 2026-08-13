#pragma once
#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"
#include"Global.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 2, AddNewMode = 3 };
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    double _AccountBalance;
    bool _MarkForDelete = false;


    static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#") {

        vector<string> vClientData;

        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
            vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#") {
        string DataLine = "";
        DataLine += Client.FirstName() + Seperator;
        DataLine += Client.LastName() + Seperator;
        DataLine += Client.Email() + Seperator;
        DataLine += Client.Phone() + Seperator;
        DataLine += Client.AccountNumber() + Seperator;
        DataLine += Client.PinCode() + Seperator;
        DataLine += to_string(Client.AccountBalance());


        return DataLine;

    };


    static vector <clsBankClient> _LoadClientsDataFromFile() {

        fstream MyFile;
        vector <clsBankClient> vClients;

        MyFile.open("Clients.txt", ios::in); //read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                vClients.push_back(_ConvertLineToClientObject(Line));


            }

            MyFile.close();



        }

        return vClients;
    }

    static void _SaveClientsDataToFile(vector <clsBankClient> vClients) {

        fstream MyFile;

        string DataLine;

        MyFile.open("Clients.txt", ios::out); //Write Mode

        if (MyFile.is_open()) {

            for (clsBankClient C : vClients) {

                if (C._MarkForDelete == false) {
                    DataLine = _ConvertClientObjectToLine(C);

                    MyFile << DataLine << endl;
                }
            };



            MyFile.close();
        }

    }

    static void _AddDataLineToFile(string DataLine) {

        fstream MyFile;

        MyFile.open("Clients.txt", ios::out | ios::app); //append Mode

        if (MyFile.is_open()) {

            MyFile << DataLine << endl;


            MyFile.close();
        }
    }

    void _AddNew() {

        _AddDataLineToFile(_ConvertClientObjectToLine(*this));

    }

    void _Update() {

        vector<clsBankClient> vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : vClients) {

            if (C.AccountNumber() == AccountNumber()) {
                C = *this;
                break;
            }

        }

        _SaveClientsDataToFile(vClients);
    }


    static clsBankClient _GetEmptyClientObject() {

        return clsBankClient(enMode::EmptyMode, " ", " ", " ", " ", " ", " ", 0);

    }

    string _PrepareTransferLogDataLine(double Amount, clsBankClient DestenationClient, string Seperator = "#//#") {

        string DataLine = clsDate::GetSystemDateTime() + Seperator;
        DataLine += _AccountNumber + Seperator;
        DataLine += DestenationClient.AccountNumber() + Seperator;
        DataLine += to_string(Amount) + Seperator;
        DataLine += to_string(_AccountBalance) + Seperator;
        DataLine += to_string(DestenationClient.AccountBalance()) + Seperator;
        DataLine += CurrentUser.UserName();

        return DataLine;
    }

    void _RegisterTransfer(double Amount, clsBankClient DestenationClient) {

        fstream MyFile;

        string DataLine = _PrepareTransferLogDataLine(Amount, DestenationClient);

        MyFile.open("TransferLog.txt", ios::out | ios::app); //append Mode

        if (MyFile.is_open()) {

            MyFile << DataLine << endl;

            MyFile.close();


        }
    }

    struct stTransferInfo;

    static stTransferInfo _ConvertLineToTransferInfo(string Line, string Seperator = "#//#") {

        vector<string> vClientData;

        stTransferInfo Info;

        vClientData = clsString::Split(Line, Seperator);

        Info.DateTime = vClientData[0];
        Info.SourceAccount = vClientData[1];
        Info.DestenationAccount = vClientData[2];
        Info.Amount = stod(vClientData[3]);
        Info.SourceBalance = stod(vClientData[4]);
        Info.DestenationBalance = stod(vClientData[5]);
        Info.User = vClientData[6];

        return Info;

    }



public:

    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode, double AccountBalance)
        :clsPerson(FirstName, LastName, Email, Phone) {

        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
        _Mode = Mode;
    }

    struct stTransferInfo {
        string DateTime, SourceAccount, DestenationAccount, User;
        double Amount = 0, SourceBalance = 0, DestenationBalance = 0;
    };

    bool IsEmpty() {
        return(enMode::EmptyMode == _Mode);
    }


    string AccountNumber() {
        return _AccountNumber;
    }

    void setPinCode(string PinCode) {
        _PinCode = PinCode;
    }

    string PinCode() {
        return _PinCode;
    }

    void setAccountBalance(double AccountBalance) {
        _AccountBalance = AccountBalance;
    }

    double AccountBalance() {
        return _AccountBalance;
    }



    static clsBankClient Find(string AccountNumber) {

        fstream MyFile;

        MyFile.open("Clients.txt", ios::in); //read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber) {

                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();

        }

        return _GetEmptyClientObject();

    };

    static clsBankClient Find(string AccountNumber, string PinCode) {

        fstream MyFile;

        MyFile.open("Clients.txt", ios::in); //read Mode

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                if (Client.AccountNumber() == AccountNumber && Client.PinCode() == PinCode) {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    };

    enum enSaveResults { svSaveFailedEmptyObject = 0, svSaveDone, svFailedClientExist };

    enSaveResults Save() {

        switch (_Mode) {

        case enMode::EmptyMode:


            return svSaveFailedEmptyObject;


        case enMode::UpdateMode:

            _Update();
            return svSaveDone;

        case enMode::AddNewMode:

            if (IsClientExist(_AccountNumber)) {
                return svFailedClientExist;
            }

            _AddNew();

            _Mode = UpdateMode;
            return svSaveDone;

        }

    }

    bool Delete() {
        vector<clsBankClient> vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : vClients) {
            if (C.AccountNumber() == _AccountNumber) {

                C._MarkForDelete = true;
                break;

            }

        }

        _SaveClientsDataToFile(vClients);
        *this = _GetEmptyClientObject();
        return true;
    }

    static bool IsClientExist(string AccountNumber) {


        return !Find(AccountNumber).IsEmpty();

    }

    static clsBankClient GetAddNewClientObject(string AccountNumber) {

        return clsBankClient(enMode::AddNewMode, " ", " ", " ", " ", AccountNumber, " ", 0);

    }


    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances() {
        vector<clsBankClient> vClients = _LoadClientsDataFromFile();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients) {
            TotalBalances += Client.AccountBalance();
        }
        return TotalBalances;
    }


    void Deposit(double Amount) {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount) {

        if (Amount > _AccountBalance) {
            return false;
        }
        else {


            _AccountBalance -= Amount;
            Save();

        }
    }

    bool Transfer(double Amount, clsBankClient& DestenationClient) {
        if (Amount > _AccountBalance) {
            return false;
        }

        Withdraw(Amount);
        DestenationClient.Deposit(Amount);
        _RegisterTransfer(Amount, DestenationClient);
        return true;

    }


    static vector<stTransferInfo> GetTransferLogInfo() {

        fstream MyFile;

        vector<stTransferInfo> TransferLogInfo;

        stTransferInfo InfoStruct;

        MyFile.open("TransferLog.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;
            while (getline(MyFile, Line))
            {

                InfoStruct = _ConvertLineToTransferInfo(Line);
                TransferLogInfo.push_back(InfoStruct);

            }

            MyFile.close();

        }

        return TransferLogInfo;

    };
};