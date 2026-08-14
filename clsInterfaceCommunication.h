#pragma once
#include<iostream>
#include<string>
using namespace std;

class clsInterfaceCommunication
{
	
public:
	virtual  void SendEmail(string Subject, string Body) = 0;
	virtual void SendSMS(string Subject, string Body) = 0;
	virtual void SendFax(string Subject, string Body) = 0;
};

