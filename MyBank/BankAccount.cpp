#include "BankAccount.h"
#include"utlis.h"
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<limits>
#include <ctime>
using namespace std;
void BankAccount::CreateAccount() {
	system("cls");
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\t\t\t     CREATE ACCOUNT\n";
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\tUsername: ";
	getline(cin, username);
	cout << "\t\t\tPassword: ";
	cin >> Password;
	cout << "\t\t\tCurrency ($/EGP): ";
	cin >> Currency;

	AccountNumber = Accountnumber();
	SaveToFile();
	cout << "\n\t\t\tAccount created successfully!\n";
	cout << "\t\t\taccount number is: " << AccountNumber << "\n";
	system("pause");
	system("cls");

}
//Create account num
string BankAccount::Accountnumber() {
	int Anum = 1000;
	string line;
	string lastLine;

	ifstream file("account.txt");

	while (getline(file, line)) {
		lastLine = line;
	}
	if (lastLine.empty())return to_string(Anum);
	file.close();
	size_t pos = lastLine.find("|");
	Anum = stoi(lastLine.substr(0, pos)) + 1;

	return to_string(Anum);

}
//Save file
void BankAccount::SaveToFile() {
	ofstream file("account.txt", ios::app);//append
	if (file.is_open()) {
		file << AccountNumber << "|"
			<< username << "|"
			<< Password << "|"
			<< Currency << "|"
			<< to_string(balance) << endl;
		file.close();
	}

}
//Login
bool BankAccount::Login() {
	string line;
	bool check = false;

	cout << "\t\t\tEnter Username: ";
	getline(cin, username);
	cout << "\t\t\tEnter Password: ";
	getline(cin, Password);
	ifstream file("account.txt");
	while (getline(file, line)) {
		size_t start = line.find("|");
		size_t second = line.find("|", start + 1);//بدور من بعد اول علامه علي علاممه تانيه
		size_t third = line.find("|", second + 1);
		size_t fourth = line.find("|", third + 1);
		if (username == line.substr(start + 1, second - start - 1) && Password == line.substr(second + 1, third - second - 1))//substr(start,length)
		{
			AccountNumber = line.substr(0, start);
			Currency = line.substr(third + 1, fourth - third - 1);
			balance = stoi(line.substr(fourth + 1));
			check = true;break;
		}

	}
	file.close();
	return check;
}


//Deposit
void BankAccount::Deposit() {
	system("cls");
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\t\t\t    CUSTOMER DEPOSIT\n";
	cout << "\t\t\t===========================================================\n";
	long long amount;	
	cout << "\t\t\tEnter amount to deposit: ";
	cin >> amount;
	balance += amount;
	UpdateAccountFile();
	cout << "\t\t\tDeposit successful! New balance:" << balance << Currency << "\n";
	SaveTransaction("Deposit",amount);

}



//Withdraw
void BankAccount::Withdraw() {
	system("cls");	
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\t\t\t    CUSTOMER WITHDRAW\n";
	cout << "\t\t\t===========================================================\n";
	long long amount;
	cout << "\t\t\tEnter amount to withdraw: ";
	cin >> amount;
	if (amount > balance) { cout << "\t\t\tInsufficient balance\n";return; }
	balance -= amount;
	UpdateAccountFile();
	cout << "\t\t\tWithdraw successful! New balance:" << balance << Currency << "\n";
	SaveTransaction("Withdraw",amount);

}


//Checkaccount
void BankAccount::CheckAccount() {
	system("cls");
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\t\t\t    CHECK ACCOUNT\n";
	cout << "\t\t\t===========================================================\n";
	vector<string> myline = UpdateAccountFile();
	cout << "\t\t\tAccount Number: " << myline[0]<<"\n";
	cout << "\t\t\tUsername: " << myline[1] << "\n";
	cout << "\t\t\tBalance: " << myline[4]<<myline[3]<<"\n";


}


//Update
void BankAccount::Update() {
	system("cls");
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\t\t\t    CUSTOMER UPDATE\n";
	cout << "\t\t\t===========================================================\n";
	int choose;
	cout << "\t\t\t Account: \n";
	cout << "\t\t\t1.Change Username \n\t\t\t2.Change Password \n\t\t\t3.Change Currency\n\t\t\t4.Back\n";
	cout << "\t\t\tChoose from item(1-4):";
	cin >> choose;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("cls");
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\t\t\t    CUSTOMER UPDATE\n";
	cout << "\t\t\t===========================================================\n";
	switch (choose) {
	case 1:cout << "\t\t\tEnter new Username: ";
		getline(cin, username);
		UpdateAccountFile();
		break;
	case 2: {
		string oldpass;
		bool c = false;
		int q = 3;
		while (q--) {
			cout << "\t\t\tEnter old password: ";
			cin >> oldpass;
			if (oldpass != Password) { cout << "\t\t\tIncorrect old password!\n"; }
			else {
				c = true;
				break; }
		}
		if (!c) 
			return;
		
		cout << "\t\t\tEnter new password: ";
		cin >> Password;
		UpdateAccountFile();
		break;
	}
	case 3: {
		do {
			cout << "\t\t\tEnter new Currency($ or EGP): ";
			cin >> Currency;
			if (Currency != "$" && Currency != "EGP") { cout << "\t\t\tInvalid currency!Try again.\n"; }

		} while (Currency != "$" && Currency != "EGP");
		UpdateAccountFile();

		break;
	}
	case 4:return;//برجع للشاشه الدخول الي فيها update

	}
	cout << "\t\t\tupdate successfully!\n";	system("pause");
}
//Delete
void BankAccount::DeleteAccount() {
	system("cls");
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\t\t\t    DELETE ACCOUNT\n";
	cout << "\t\t\t===========================================================\n";
	char confirm;
	cout << "\t\t\tAre you sure you want to delete your account?(y/n):";
	cin >> confirm;
	if (confirm != 'y' && confirm != 'Y') {
		cout << "\t\t\tAccount deletion canceled.\n";return;
	}
		string line;
		vector<string>l;
		ifstream file("account.txt");
		while (getline(file, line)) {
			l.push_back(line);
		}
		file.close();

		for (auto i = l.begin();i != l.end();++i) {
			size_t pos =i->find("|");
			string accnum = i->substr(0, pos);
			if (accnum == AccountNumber) { l.erase(i);break; }
		}
		ofstream f("account.txt");//overwite
		if (f.is_open()) {
			for (const string& line : l) {
				f << line << endl;

			}
		}f.close();
		cout << "\t\t\tAccount delete successfully!\n";
	}



//بغير فيه واحفظه تاني
vector<string> BankAccount::UpdateAccountFile() {
	vector<string> part;
	vector<string>accounts;
	string line;
	ifstream file("account.txt");
	while (getline(file, line)) {
		 vector<string>parts = split(line, '|');
		 if (parts[0] == AccountNumber) {
			 parts[1] = username;
			 parts[2] = Password;
			 parts[3] = Currency;
			 parts[4] = to_string(balance);
			 line = parts[0] + "|" + parts[1] + "|" + parts[2] + "|" + parts[3] + "|" + parts[4];
			 part = parts;
		 }

		accounts.push_back(line);
	}
	file.close();

	ofstream f("account.txt");//overwite
	if (f.is_open()) {
		for (const string& line : accounts) {
			f << line << endl;

		}
	}f.close();
	return part;
}

//تحويل فلوس
void BankAccount::Transfer() {
	system("cls");
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\t\t\t    TRANSFER MONEY\n";
	cout << "\t\t\t===========================================================\n";
	bool c = false;
	string toaccnum,toname;
	long long amount, tobalance;
	cout << "\t\t\tEnter account number to transfer to: ";
	cin >> toaccnum;
	string line;
	ifstream file("account.txt");
	while (getline(file, line)) {
		size_t start = line.find("|");
		size_t second = line.find("|", start + 1);//بدور من بعد اول علامه علي علاممه تانيه
		size_t third = line.find("|", second + 1);
		size_t fourth = line.find("|", third + 1);
		if (toaccnum == line.substr(0, start) )//substr(start,length)
		{
			toname = line.substr(start + 1, second - start - 1);
			tobalance = stoi(line.substr(fourth + 1));
			
			c = true;
		}

	}
	if (!c) {
		cout << "\t\t\tThis account number not exist.\n";return;
	}
	file.close();
	cout << "\t\t\tThe amount to transfer: ";
	cin >> amount;
	if (amount > balance) {
		cout << "\t\t\tInsufficient balance! you only have " << balance << Currency << "\n";
		return;
	}
	balance -= amount;
	tobalance += amount;
	UpdateAnyAccount(AccountNumber, balance);
	UpdateAnyAccount(toaccnum, tobalance);
		cout << "\t\t\tTransfer successful! New balance:" << balance << Currency << "\n";
		SaveTransaction("Transfer",amount);


}
//اغير اي حساب فلوس
void BankAccount::UpdateAnyAccount(const string& acountnum, long long newbalance) {
	string line;
	vector<string>l;
	ifstream file("account.txt");
	while (getline(file, line)) {
		l.push_back(line);
	}
	file.close();
	for (auto& line : l) {
		size_t pos = line.find("|");
		string accnum = line.substr(0, pos);
		if (accnum == acountnum) {
			vector<string>parts;
			parts = split(line, '|');
			line = parts[0] + "|" + parts[1] + "|" + parts[2] + "|" + parts[3] + "|" + to_string(newbalance);;
			break;
		}
	}
	ofstream f("account.txt");//overwite
	if (f.is_open()) {
		for (const string& line : l) 
			f << line << endl;
		
	}f.close();
}

//عرض المعاملات
void BankAccount::TransactionHistory() {
	system("cls");
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\t\t\t    TRANSACTION HISTORY\n";
	cout << "\t\t\t===========================================================\n";
	string line;
	vector<string>l;
	ifstream file("transaction.txt");
	while (getline(file, line)) {
		l.push_back(line);
	}
	file.close();
	for (auto i = l.begin();i != l.end();) {
		size_t pos = i->find("|");
		string accnum = i->substr(0, pos);
		if (accnum == AccountNumber) {
			vector<string>parts = split(*i, '|');
			if (parts.size() >= 4) {
				cout << "\t\t\tAccount Number: " << parts[0] << "\n"
					<< "\t\t\tType of Transaction: " << parts[1] << "\n"
					<< "\t\t\tAmount: " << parts[2] << "\n"
					<< "\t\t\tTime/Date: " << parts[3] << "\n"
					<< "\t\t\t----------------------------------------------------------\n";
			}
			i = l.erase(i);//يشير للي بعده
		}
		else ++i;//لو ممسحتش نزود بقي
		

	}
}
//Save tranaction
void BankAccount::SaveTransaction(string typetrans, long long amount) {
	time_t now = time(0);//ياخد الوقت الحالي
	char dt[26];              // مصفوفة كافية لتخزين النص يحوله لسلسلة نصية (مثل "Fri Nov 15 12:34:56 2025\n")
	ctime_s(dt, sizeof(dt), &now);   
	ofstream file("transaction.txt", ios::app);
	if (file.is_open()) {
		file << AccountNumber << "|"
			<< typetrans << "|"
			<< amount << "|"
			<<  dt;
		file.close();
	}

}


