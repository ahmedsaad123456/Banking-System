#ifndef SAVINGBANKACCOUNT_H
#define SAVINGBANKACCOUNT_H

class SavingBankAccount : BankAccount {

public:
	double minimumBalance;

	SavingBankAccount();

	SavingBankAccount(double B, int id, double min);

	void set_minimumBalance(double min);

	double get_minimumBalance();

	double withdraw(double money);

	double deposit(double money);
};

#endif
