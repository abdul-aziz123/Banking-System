#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Bank
{
	const string name = "RBMA";

protected:
	long int number;
	string address;
	int branch_no;

public:
	Bank(long int number, string address, int branch_no) : number(number), address(address), branch_no(branch_no) {}

	void Print_Heading();

	// void setName(string);

	string getName();

	void setNumber(long int num)
	{
		number = num;
	}

	double getNumber();

	void setAddress(string);

	string getAddress();

	void setBranchNo(int);

	int getBranchNo();

	void Print_Details();
};

class Person
{
private:
	int accountNumber;
	string name;
	string address;
	string email;

public:
	Person(int account, string name, string address, string email) : accountNumber(account), name(name), address(address), email(email) {}
};

class Account
{
private:
	double balance;
	string creation_time;
	string creation_date;

public:
	Account(double balance) : balance(balance)
	{
		creation_time = __TIME__;
		creation_date = __DATE__;
	}

	string get_creationtime();

	string get_creationdate();

	void Bill_Payment()
	{
		long int billno, billAmount, amountPaid, a, acc_number;
		cout << "Enter Account Number: " << endl;
		cin >> acc_number;

		cout << "Enter Bill Number : " << endl;
		cin >> billno;

		cout << "Enter Bill Amount : " << endl;
		cin >> billAmount;

		cout << "Enter Amount Paid To Cashier : " << endl;
		cin >> amountPaid;

		a = amountPaid - billAmount;

		cout << "Your bill has been paid ." << endl;
		cout << " Amount Returned : " << a << endl;
	}

	void Cash_Withdrawl()
	{
		double x, y;

		cout << "Enter Withdarwal Amount : " << endl;
		cin >> x;

		if (x > balance)
		{
			cout << "Withdarwal amount exceeds current balance." << endl;
			cout << "Re-enter Amount." << endl;
		}

		else
		{
			y = balance - x;

			cout << "Amount Withdarwal Successful." << endl;
			cout << "Updated Balance : " << y << endl;
		}
	}

	void Cash_Deposit()
	{
		double x, y;

		cout << "Enter Deposit Amount : " << endl;
		cin >> x;

		y = x + balance;

		cout << "Deposit Successful." << endl;
		cout << "Updated Balance : " << y << endl;
	}

	void Funds_Transfer()
	{
		long int x;
		double y, z;

		cout << "Enter the transfer account number : " << endl;
		cin >> x;

		cout << "Enter Transfer Amount : " << endl;
		cin >> y;

		z = balance - y;

		cout << "Transfer Successful." << endl;
		cout << "Updated Balance : " << z << endl;
	}

	// void Pay_Order();
};

class Customer : public Person
{
private:
	Account account;

public:
	Customer(int account, string name, string address, string email, double balance) : Person(account, name, address, email), account(balance)
	{
	}

	Account get_account()
	{
		return account;
	}
};

int main()
{
	int choice = 0, choice2 = 0, temp, acc_number;
	string name, address, email;
	double balance = 0;
	Bank bank(03030573702, "R-184 Sec15A1 Bufferzone, Karachi", 5);
	Customer customer(0, "Unknown", "Unknown", "Unknown", 0.00);
	Account account(500000);

	while (1)
	{
		bank.Print_Heading();
		cout << endl
			 << endl
			 << endl;
		cout << "     ________________________" << endl;
		cout << "    |                        |" << endl;
		cout << "    |  1.Account Creation.   |" << endl;
		cout << "    |                        |" << endl;
		cout << "    |  2.Bill Payment.       |" << endl;
		cout << "    |                        |" << endl;
		cout << "    |  3.Cash Withdrawl.     |" << endl;
		cout << "    |                        |" << endl;
		cout << "    |  4.Cash Deposit.       |" << endl;
		cout << "    |                        |" << endl;
		cout << "    |  5.Funds Transfer.     |" << endl;
		cout << "    |                        |" << endl;
		cout << "    |  6.Pay Order.          |" << endl;
		cout << "    |                        |" << endl;
		cout << "    |  7.Bank Details.       |" << endl;
		cout << "    |                        |" << endl;
		cout << "    |  0.Exit.               |" << endl;
		cout << "    |________________________|" << endl
			 << endl;
		cout << "      Enter your choice: ";
		cin >> choice;

		switch (choice)
		{

		case 0: // Case-> Exit. //
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
				 << endl
				 << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t     Thank You! \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
				 << endl
				 << endl;
			exit(0);
			break;

		case 1: // Case-> Account_Creation. //

			system("cls");
			cout << "\n\n    Account Creation:- " << endl;
			cout << "  ----------------------" << endl
				 << endl;
			cout << "    Enter your name: ";
			fflush(stdin);
			// getline(cin, name);
			cin >> name;
			cout << endl
				 << "   Enter Your Account Number: ";
			fflush(stdin);
			cin >> acc_number;
			cout << endl
				 << "    Enter your address: ";
			fflush(stdin);
			// getline(cin, address);
			cin >> address;
			cout << endl
				 << "    Enter your email: ";
			fflush(stdin);
			// getline(cin, email);
			cin >> email;
			cout << endl
				 << "    Enter depositing amount: ";
			cin >> balance;
			if (balance >= 500)
			{
				customer = Customer(acc_number, name, address, email, balance);
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					 << endl
					 << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t Congrats! Your account has been created!";
				Sleep(2500);
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					 << endl
					 << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t Sorry: Your account is not created! (Balance should be greater than/equal to 500)";
				Sleep(25000);
			}
			break;

		case 2: // Case-> Bill_Payment. //

			account.Bill_Payment(); // in line no 76
			Sleep(2500);

			break;

		case 3: // Case-> Cash_Withdrawl. //

			account.Cash_Withdrawl();

			break;

		case 4: // Case-> Cash_Deposit. //

			account.Cash_Deposit();

			break;

		case 5: // Case-> Funds_Transfer. //

			account.Funds_Transfer();

			break;

		case 6: // Case-> Pay_Order. //

			break;

		case 7: // Case-> Bank_Details. //
			system("cls");
			cout << "\t\t\t\t\t            _________________________________________________________________________________________________________________________________" << endl
				 << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t Bank Details " << endl;
			cout << "\t\t\t\t\t            _________________________________________________________________________________________________________________________________" << endl
				 << endl;
			cout << endl
				 << endl;
			cout << "     _______________________" << endl;
			cout << "    |                       |" << endl;
			cout << "    |  1. Bank Info.        |" << endl;
			cout << "    |                       |" << endl;
			cout << "    |  2. Update Details.   |" << endl;
			cout << "    |                       |" << endl;
			cout << "    |  3. No of customers   |" << endl;
			cout << "    |                       |" << endl;
			cout << "    |  0. Go Back.          |" << endl;
			cout << "    |_______________________|" << endl;
			cout << "       Enter your choice: ";
			cin >> choice2;

			switch (choice2)
			{

			case 0:
				break;

			case 1:
				bank.Print_Details();
				break;

			case 2:
				system("cls");
				cout << "\t\t\t\t\t            _________________________________________________________________________________________________________________________________" << endl
					 << endl;
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t Update Details " << endl;
				cout << "\t\t\t\t\t            _________________________________________________________________________________________________________________________________" << endl
					 << endl;
				cout << endl
					 << endl;
				cout << "     _____________________" << endl;
				cout << "    |                     |" << endl;
				cout << "    |  1. Set Name.       |" << endl;
				cout << "    |                     |" << endl;
				cout << "    |  2. Set Number.     |" << endl;
				cout << "    |                     |" << endl;
				cout << "    |  3. Set Address.    |" << endl;
				cout << "    |                     |" << endl;
				cout << "    |  4. Set Branch No.  |" << endl;
				cout << "    |                     |" << endl;
				cout << "    |  0. Go Back.        |" << endl;
				cout << "    |_____________________|" << endl;
				cout << "       Enter your choice: ";
				cin >> choice2;

				switch (choice2)
				{

				case 0:
					break;

				case 1:
					system("cls");
					cout << endl
						 << "  Enter new name of bank: ";
					fflush(stdin);
					getline(cin, name);
					// bank.setName(name);
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << "\t\t\t\t\t\t\t\t\t\t\t      _____________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t     |                                             |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t     |  Bank name has been updated successfully !  |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t     |_____________________________________________|";
					Sleep(3000);
					break;

				case 2:

					cout << "Enter new number of bank: ";
					cin >> temp;
					bank.setNumber(temp);
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << "\t\t\t\t\t\t\t\t\t\t\t      _____________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t     |                                             |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t     |  Bank no. has been updated successfully !   |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t     |_____________________________________________|";
					Sleep(3000);
					break;

				case 3:

					break;

				case 4:

					break;

				default:
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t      __________________________ " << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t     |                          |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t     |  Error: [Invalid Input]  |" << endl;
					cout << "\t\t\t\t\t\t\t\t\t\t\t\t     |__________________________|";
					Sleep(2500);
				}
				break;

			case 3:
				system("cls");
				cout << endl
					 << "    Number of Customers:- " << endl;
				cout << "  -------------------------" << endl;
				cout << endl
					 << "  Today: " << endl;
				cout << "  From beginning: " << endl
					 << "  ";
				system("pause");
				break;
			}

			break;

		default:
			system("cls");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
				 << endl
				 << endl;
			cout << "\t\t\t\t\t\t\t\t\t\t\t\t Error: Invalid Input";
			Sleep(2500);
		}

		system("cls");
	}

	return 0;
}

string Bank::getName()
{
	return name;
}

// void Bank::setNumber(double number)
//{
//	this->number = number;
// }

double Bank::getNumber()
{
	return number;
}

void Bank::setAddress(string address)
{
	this->address = address;
}

string Bank::getAddress()
{
	return address;
}

void Bank::setBranchNo(int branch_no)
{
	this->branch_no = branch_no;
}

int Bank::getBranchNo()
{
	return branch_no;
}

void Bank::Print_Details()
{
	system("cls");
	cout << endl
		 << endl
		 << "  Bank Name: " << name << endl;
	cout << "  Number:    " << number << endl;
	cout << "  Address:   " << address << endl;
	cout << "  Branch No: " << branch_no << endl
		 << "  ";
	system("pause");
}

void Bank::Print_Heading()
{
	system("cls");
	cout << "\t\t\t\t\t            _________________________________________________________________________________________________________________________________" << endl
		 << endl;
	cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t " << name << " Banking System" << endl;
	cout << "\t\t\t\t\t            _________________________________________________________________________________________________________________________________" << endl
		 << endl;
}

string Account::get_creationtime()
{
	return creation_time;
}

string Account::get_creationdate()
{
	return creation_date;
}
