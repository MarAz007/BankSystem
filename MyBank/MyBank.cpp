using namespace std;
#include <iostream>
#include "BankAccount.h"
#include "Admin.h"
void AdminMenu() {
	bool loggedin = false;
	Admin a;
	system("cls");
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\t\t\t\tADMIN LOGIN\n";
	cout << "\t\t\t===========================================================\n";
	while (!loggedin) {
		if (a.Login())loggedin = true;
		else
			cout << "\t\t\tLogin failed! Try again.\n\n";

	}
	while (loggedin) {
		system("cls");
		int ch;
		cout << "\t\t\t===========================================================\n";
		cout << "\t\t\t\t\t\tADMIN PANEL\n";
		cout << "\t\t\t===========================================================\n";
		cout << "\t\t\t1.Show all accounts\n\t\t\t2.Delet account\n\t\t\t3.Show all transaction\n\t\t\t4.Find Account\n\t\t\t5.logout\n";
		cout << "\t\t\tChoose from item(1-5):";
		cin >> ch;
		switch (ch) {

		case 1:a.ShowAccounts();system("pause");break;
		case 2: a.DeleteAccount();system("pause");break;
		case 3:a.ShowTransaction();system("pause");break;
		case 4:a.FindAccount();system("pause");break;
		case 5:loggedin = false;
			cout << "\t\t\t\t   Loggedout Successsfully!\n"; system("pause");
			break;
		default:cout << "\t\t\tInvalid choice.\n\t\t\t"; system("pause");

		}
	}
}
void CustomerMenu() {
	BankAccount b;
	bool runing = true;
	bool loggedin = false;
	int ch;
	//بكرر الشاشه الرئيسيه
	while (runing) {
		system("cls");
		cout << "\t\t\t===========================================================\n";
		cout << "\t\t\t\t\t      WELCOM CUSTOMER\n";
		cout << "\t\t\t===========================================================\n";
		cout << "\t\t\t1.Create Account\n\t\t\t2.Login\n\t\t\t3.back\n";
		cout << "\t\t\tChoose from item(1-3):";
		cin >> ch;
		cin.ignore();//عشان getline لما بعملها متحسبش enter
		switch (ch) {
		case 1: {
			b.CreateAccount();break;
		}
		case 2: {
			system("cls");
			cout << "\t\t\t===========================================================\n";
			cout << "\t\t\t\t\t    CUSTOMER LOGIN\n";
			cout << "\t\t\t===========================================================\n";
			//بكرر الدحول لو غلط
			while (!loggedin) {
				if (b.Login()) {
					loggedin = true;
				}
				else
				{
					cout << "\t\t\tLogin failed! Try again.\n";

				}
			}//بكرر ظهور اختيارات الدخول
			while (loggedin) {
				system("cls");
				cout << "\t\t\t===========================================================\n";
				cout << "\t\t\t\t\t    CUSTOMER PANEL\n";
				cout << "\t\t\t===========================================================\n";
				cout << "\t\t\t1.Deposit\n\t\t\t2.Withdraw\n\t\t\t3.CheckAccount\n\t\t\t4.Update Account\n\t\t\t5.Delete Account\n\t\t\t6.Transfer\n\t\t\t7.Transaction History\n\t\t\t8.Back\n";
				cout << "\t\t\tChoose from item(1-8):";
				cin >> ch;
				switch (ch) {
				case 1: {
					b.Deposit();
					system("pause");
					break;
				}
				case 2: {
					b.Withdraw();
					system("pause");
					break;
				}
				case 3: {
					b.CheckAccount();
					system("pause");
					break;
				}
				case 4: {
					b.Update();
					break;
				}
				case 5: {
					b.DeleteAccount();
					system("pause");
					loggedin = false;
					break;
				}
				case 6: {
					b.Transfer();
					system("pause");
					break;

				}
				case 7: {
					b.TransactionHistory();
					system("pause");
					break;
				}
				case 8:loggedin = false;break;//بيظهر ليا تاني بقي الشاشه الرئيسه عشان يعتبر خرجت من case 2
				default:cout << "\t\t\tInvalid choice.\n"; system("pause");

				}
			}
			break;
		}
		case 3:
			runing = false;break;
		default:
			cout << "\t\t\tInvalid choice Try again.\n";
		}
	}

}
int main()
{

	bool running = true;
	while (running) {
		system("cls");
	cout << "\t\t\t===========================================================\n";
	cout << "\t\t\t\t\t   WELCOM TO BANK SYSTEM\n";
	cout << "\t\t\t===========================================================\n";
	int choose;
		cout << "\t\t\t1.Admin\n\t\t\t2.Customer\n\t\t\t3.Exit\n";
		cout << "\t\t\tChoose from item(1-3):";
		cin >> choose;
		cin.ignore();
		switch (choose) {
		case 1: {
			AdminMenu();
			break;
		}
		case 2: {
			CustomerMenu();		
			break;
		}

		case 3:
			cout << "\n\t\t\t\t   Thank you for using the bank System!\n";running = false;
			break;
		default:
			cout << "\t\t\tInvalid choice Try again.\n";system("pause");

		}
	}



}


