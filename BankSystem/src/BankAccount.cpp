#include "BankAccount.h"

BankAccount::BankAccount() {
	balance = 0;
}

BankAccount::BankAccount(string accountID, double balance) {
	this->accountID = accountID;
	this->balance = balance;
}

int BankAccount::Deposit(double amount) {
	if (amount < 0)
		return 0;
	balance += amount;
	return 1;
}

int BankAccount::Withdraw(double amount) {
	if (amount < 0)
	{
		cout << "Please Enter an amount of money" << endl;
		return 0;
	}

	if (amount > balance)
	{
		cout << "You don't have enough money" << endl;
		return 0;
	}

	balance -= amount;
	return 1;
}

void BankAccount::DisplayAccountDetails() {
	cout << "Account ID: " << accountID << endl;
	cout << "Balance: " << balance << endl;
	cout << "Owner: " << owner->getName() << endl;
}

void BankAccount::setID(string newID) {
	accountID = newID;
}

string BankAccount::getID() {
	return accountID;
}

void BankAccount::setBalance(double newBalance) {
	balance = newBalance;
}

double BankAccount::getBalance() {
	return balance;
}

void BankAccount::setOwner(Client* newOwner) {
	owner = newOwner;
}

Client* BankAccount::getOwner() {
	return owner;
}

///////////////////////////////////////////////////////////////////////////////

SavingBankAccount::SavingBankAccount() {
	minimumBalance = 0;
}

SavingBankAccount::SavingBankAccount(string accountID, double balance, double minimumBalance) {
	setID(accountID);
	//Initial balance >= min balance
	setBalance(balance);
	this->minimumBalance = minimumBalance;
}

void SavingBankAccount::DisplayAccountDetails() {
	cout << "Account ID: " << getID() << endl;
	cout << "Balance: " << getBalance() << endl;
	cout << "Owner: " << getOwner()->getName() << endl;
	cout << "Minimum Balance: " << minimumBalance << endl;
}

void SavingBankAccount::setMinimumBalance(double newMinimumBalance) {
	minimumBalance = newMinimumBalance;
}

double SavingBankAccount::getMinimumBalance() {
	return minimumBalance;
}

int SavingBankAccount::deposit(double amount) {
	if (amount < 100)
	{
		cout << "Please enter an amount of money greater than 100" << endl;
		return 0;
	}

	Deposit(amount);
	return 1;
}

int SavingBankAccount::Withdraw(double amount) {
	if (amount < 0)
	{
		cout << "Please Enter an amount of money" << endl;
		return 0;
	}

	if (amount > getBalance())
	{
		cout << "You don't have enough money" << endl;
		return 0;
	}

	if (getBalance() - amount < minimumBalance)
	{
		cout << "You can't withdraw this amount of money" << endl;
		return 0;
	}

	Withdraw(amount);
	return 1;
}

