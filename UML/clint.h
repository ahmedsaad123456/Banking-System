#ifndef CLINT_H
#define CLINT_H

class clint {

private:
	string Name;
	string Address;
	string phone;
	BankAccount account;
	SavingBankAccount Saving_account;

public:
	clint();

	clint(string N, string A, string P, double B, int id);

	clint(string N, string A, string P, double B, double min, int id);

	void set_name(string N);

	void set_address(string A);

	void set_phone(string P);

	string get_name();

	string get_address();

	string get_phone();

	BankAccount get_bankAccount();

	SavingBankAccount get_SavingAcount();

	void write_to(ostream& output);
};

#endif
