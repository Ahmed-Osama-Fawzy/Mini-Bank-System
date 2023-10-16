#include "BankAccount.h"

Client::Client()
{
	this->name = "";
	this->address = "";
	this->phoneNumber = "";
}

Client::Client(string name, string address, string phoneNumber) {
	this->name = name;
	this->address = address;
	this->phoneNumber = phoneNumber;
}

string Client::getName() {
	return name;
}

void Client::setName(string newName) {
	name = newName;
}

string Client::getAddress() {
	return address;
}

void Client::setAddress(string newAddress) {
	address = newAddress;
}

string Client::getPhoneNumber() {
	return phoneNumber;
}

void Client::setPhoneNumber(string newPhoneNumber) {
	phoneNumber = newPhoneNumber;
}

void Client::setAccount(BankAccount* newAccount) {
	account = newAccount;
}

BankAccount* Client::getAccount() {
	return account;
}

bool Client::operator==(const Client& other)
{
	if (this->name != other.name)
		return false;
	if (this->address != other.address)
		return false;
	if (this->phoneNumber != other.phoneNumber)
		return false;
	return true;
}
