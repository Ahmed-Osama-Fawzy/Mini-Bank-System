#include "BankAccount.h"

int PrintMenuReturnChoice()
{
	int choice;
	cout << "Welcome to FCAI Banking Application\n1. Create a New Account\n2. List Clients and Accounts";
	"3. Withdraw Money\n4. Deposit Money\nPlease Enter Choice =========> ";
	cin >> choice;

	if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
	{
		cout << "Please Enter a Number From 1 to 4" << endl;
		return 0;
	}

	return choice;
}

BankApplication::BankApplication() {

	int choice = PrintMenuReturnChoice();
	if (!choice)
		exit(1);

	if (choice == 1)
	{
		if(addClient())
			cout << "Client Added Successfully" << endl;
		else
			cout << "Client Not Added" << endl;
	}

	if (choice == 2)
	{
		ListAvailableBankAccounts();
	}

	if (choice == 3)
	{
		WithdrawMoney();
	}

	if (choice == 4)
	{
		DepositMoney();
	}

}


void getClientData(Client &input)
{
	string name, address, phoneNumber;

	cout << "Please Enter Client Name =========>";
	cin >> name;

	cout << "Please Enter Client Address =========>";
	cin.ignore();
	cin >> address;

	cout << "Please Enter Client Phone =========>";
	cin >> phoneNumber;

	input.setName(name);
	input.setAddress(address);
	input.setPhoneNumber(phoneNumber);

}

bool isFound(Client input, vector <Client> Clients)
{

	for(Client client: Clients)
	{
		if (input == client)
			return true;
	}

	return false;
}

bool BankApplication::addClient() {

	Client input;

	getClientData(input);


	if (isFound(input, Clients))
	{
		cout << "This Client data already exists" << endl;
		return false;
	}

	else
	{
		BankAccount account;
		account.setOwner(&input);
		input.setAccount(&account);
		Clients.push_back(input);
		Accounts.push_back(account);
		return true;
	}
}

void BankApplication::ListAvailableBankAccounts() {
	// TODO - implement BankApplication::ListAvailableBankAccounts
	throw "Not yet implemented";
}

void BankApplication::WithdrawMoney() {
	// TODO - implement BankApplication::WithdrawMoney
	throw "Not yet implemented";
}

void BankApplication::DepositMoney() {
	// TODO - implement BankApplication::DepositMoney
	throw "Not yet implemented";
}
