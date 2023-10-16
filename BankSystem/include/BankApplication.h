#ifndef BANKAPPLICATION_H
#define BANKAPPLICATION_H
#include <iostream>
#include <vector>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;


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
