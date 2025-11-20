#pragma once
using namespace std;
#include<iostream>
#include<vector>
#include<string>
class Admin
{
	string username, Password;
public:
	bool Login();
	void ShowAccounts();
	void ShowTransaction();
	void DeleteAccount();
	void FindAccount();

};

