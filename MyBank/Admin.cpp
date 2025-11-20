#include"utlis.h"
#include "Admin.h"
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
bool Admin::Login() {
	bool ch = false;
	string line;
	cout << "\t\t\tEnter Username: ";
	getline(cin, username);
	cout << "\t\t\tEnter Password: ";
	getline(cin, Password);
	ifstream file("admin.txt");
	if (file.is_open()) {
		getline(file, line);
		size_t pos = line.find("|");
		if (username == line.substr(0, pos) && Password == line.substr(pos + 1))
		{
			ch = true;
		}
	}
	file.close();

	return ch;
}
//show all accounts
void Admin::ShowAccounts()
{
	system("cls");
	string line;
	ifstream file("account.txt");
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\t\t\t        ALL ACCOUNTS\n";
	cout << "\t\t\t===========================================================\n";
	if (file.is_open()) {
		while (getline(file, line)) {
			vector<string>parts = split(line, '|');
			cout << "\t\t\t-----------------------------------------------------------\n";
			cout << "\t\t\tAccount Number: " << parts[0] << "\n";
			cout << "\t\t\tUsername: " << parts[1] << "\n";
			cout << "\t\t\tPassword: " << parts[2] << "\n";
			cout << "\t\t\tCurrency: " << parts[3] << "\n";
			cout << "\t\t\tBalance: " << parts[4] << "\n";
			cout << "\t\t\t-------------------------------------------------------------\n";


		}
	}
	file.close();
	
}

//delete account
void Admin::DeleteAccount() {
	system("cls");
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\t\t\t   DELETE ACCOUNTS\n";
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\tEnter account number to delete: ";
	string accnum;
	cin >> accnum;
	string line;
	vector<string>l;
	bool found = false;
	ifstream file("account.txt");
	while (getline(file, line)) {
		if (accnum == line.substr(0, line.find("|"))) { found = true; }
		l.push_back(line);	
	}
	file.close();
	if(!found){ cout << "\t\t\tInavalid account number!\n";return; }
	for (auto i = l.begin();i != l.end();++i) {
		size_t pos = i->find("|");
		if (accnum == i->substr(0, pos)) { l.erase(i);break; }
	}
	ofstream f("account.txt");//overwite
	if (f.is_open()) {
		for (const string& line : l) {
			f << line << endl;

		}
	}f.close();
	cout << "\t\t\tAccount delete successfully!\n";
}

//show all transaction
void Admin::ShowTransaction() {
	system("cls");
	string line;
	ifstream file("transaction.txt");
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\t\t\t    ALL TRANSACTION\n";
	cout << "\t\t\t===========================================================\n";
	if (file.is_open()) {
		while (getline(file, line)) {
			vector<string>parts = split(line, '|');
			if (parts.size() < 4)continue;
			cout << "\t\t\tAccount Number: " << parts[0] << "\n"
				<< "\t\t\tType of Transaction: " << parts[1] << "\n"
				<< "\t\t\tAmount: " << parts[2] << "\n"
				<< "\t\t\tTime/Date: " << parts[3] << "\n"
			<< "\t\t\t-----------------------------------------------------------\n";

		}
	}
}
void Admin::FindAccount() {
	system("cls");
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\t\t\t\tFIND ACCOUNT\n";
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\tEnter Account Number : ";
	string accountNumber;
	cin >> accountNumber;
	string line;
	bool found = false;
	ifstream file("account.txt");
	while (getline(file, line)) {
		vector<string>parts = split(line, '|');
		if (parts[0] == accountNumber) {
			found = true;
			cout << "\t\t\tAccount Number: " << parts[0] << "\n";
			cout << "\t\t\tUsername: " << parts[1] << "\n";
			cout << "\t\t\tPassword: " << parts[2] << "\n";
			cout << "\t\t\tBalance: " << parts[4] << "\n";
			cout << "\t\t\tCurrency: " << parts[3] << "\n";
			break;
		}

	}
	file.close();
	if (!found)cout << "\t\t\tAccount not found!\n ";

}

