#ifndef BANKAPPLICATION_H
#define BANKAPPLICATION_H
#include <iostream>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

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

#endif
