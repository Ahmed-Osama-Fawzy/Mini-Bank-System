#ifndef BANKAPPLICATION_H
#define BANKAPPLICATION_H
#include <iostream>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Client;

class BankAccount {

private:
	string accountID;
	double balance;
	//make a pointer that points to the client that owns the account
	Client* owner;

public:

	BankAccount();

	BankAccount(string accountID, double balance);

	int Deposit(double amount);

	int Withdraw(double amount);

	void DisplayAccountDetails();

	void setID(string newID);

	string getID();

	void setBalance(double newBalance);

	double getBalance();

	void setOwner(Client* newOwner);

	Client* getOwner();


};

class SavingBankAccount : protected BankAccount {

private:
	double minimumBalance;
public:
	SavingBankAccount();
	SavingBankAccount(string accountID, double balance, double minimumBalance);
	void setMinimumBalance(double newMinimumBalance);
	double getMinimumBalance();
	int deposit(double amount); // amount > 100
	int Withdraw(double amount); // not below the min balance
	void DisplayAccountDetails();

};

class Client {

private:
	string name;
	string address;
	string phoneNumber;
	//create a pointer that points to the bank account that the client owns
	BankAccount* account;

public:
	Client();
	Client(string name, string address, string phoneNumber);
	string getName();
	string getAddress();
	string getPhoneNumber();
	void setName(string newName);
	void setAddress(string newAddress);
	void setPhoneNumber(string newPhoneNumber);
	void setAccount(BankAccount* newAccount);
	BankAccount* getAccount();

	bool operator==(const Client& other);
};




class BankApplication {

	vector<Client> Clients;
	vector<BankAccount> Accounts;

public:
	BankApplication();

	bool addClient();

	void ListAvailableBankAccounts();

	void WithdrawMoney();

	void DepositMoney();

};

#endif
