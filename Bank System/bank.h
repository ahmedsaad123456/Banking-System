#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
//------------------------------------------------------------------------------------------------------------
class BankAccount {
  
    string account_ID;
    double balance;
    public:
        BankAccount(double B, int id);
        BankAccount();
        void set_balance(double B);
        void set_ID(string ID);
        string get_ID();
        double get_balance();
        bool withdraw(double money);
        bool deposit(double money);
};
//-----------------------------------------------------------------------------------------------------------
class SavingBankAccount : public BankAccount 
{   
    double minimumBalance;

    public:
        SavingBankAccount(double B ,int id,  double min);
        SavingBankAccount();
        void set_minimumBalance(double min);
        double get_minimumBalance();
        bool withdraw(double money);
        bool deposit(double money);
};
//----------------------------------------------------------------------------------------------------------
class clint
{
    string Name;
    string Address;
    string phone;
    BankAccount account;
    SavingBankAccount Saving_account;

    public:
        clint(string N , string A  , string P, double B,int id);
        clint(string N , string A  , string P, double B , double min,int id);
        clint();
        void set_name(string N);
        void set_address(string A);
        void set_phone(string P);
        string get_name();
        string get_address();
        string get_phone();
        BankAccount get_bankAccount();
        SavingBankAccount get_SavingAcount();
        void write_to(ostream &output) ;
};
//--------------------------------------------------------------------------------------------------------
class BankApplication 

{
    public:
        void Run();
        bool add_Clint(clint& new_clint, vector<clint> ALL_Clints);
        void listOfClints(vector<clint> ALL_Clints);
        
};
//----------------------------------------------------------------------------------------------------------
//function to load the data from the file
vector<clint> loadClints(fstream &file);

// function to convert the integer id (2) to string id (FCAI-002)
string ID (int id);

//function to get the last id in the file
int last_ID(vector<clint> clints);

