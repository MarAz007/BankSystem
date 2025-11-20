#pragma once
using namespace std;
#include<iostream>
#include<vector>
#include<string>
class BankAccount
{
	string username, Password, Currency, AccountNumber;
	long long balance=0;
public:
	//انشاء حساب
	void CreateAccount();

	//تسجيل الدخول
	bool Login();

	//العمليات
	void Deposit();
	void Withdraw();
	void Transfer();
	void CheckAccount();
	void TransactionHistory();

	//تعديل الحساب
	void Update();
	void DeleteAccount();
	//دوال مساعده
	string Accountnumber();//توليد رقم حساب جديد تلقائي
	void SaveToFile();
	void SaveTransaction(string typetrans, long long amount);
	void UpdateAnyAccount(const string&acountnum,long long newbalance);
	vector<string> UpdateAccountFile();//تحديث البيانات في الملف

};

