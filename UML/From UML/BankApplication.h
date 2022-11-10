#ifndef BANKAPPLICATION_H
#define BANKAPPLICATION_H

class BankApplication {

public:
	void Run();

	boolean add_Clint(clint new_clint, vector<clint>& ALL_Clints);

	void listOfClints(vector<clint> ALL_Clints);
};

#endif
