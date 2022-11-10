#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount {

private:
	string account_ID;
	double balance;

public:
	BankAccount();

	BankAccount(double B, int id);

	void set_balance(double B);

	void set_ID(string id);

	string get_ID();

	double get_balance();

	double withdraw(double money);

	double deposit(double money);
};

#endif
