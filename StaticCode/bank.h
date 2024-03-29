// FCAI - Obejct-Oriented Programming 1 - 2022 - Assignment 2
// Program Name : Bank System
// Last Modification 4/11/2022
// Author1 and ID and Group: Ahmed Saad Ahmed          ID: 20210020  S9&S10    
// Author2 and ID and Group: Maryam Osama Mohamed      ID: 20211090  S9&S10
// Author3 and ID and Group: Shahd Osama  Hamed        ID: 20211052  S9&S10
#ifndef BANK_H
#define BANK_H

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
        double withdraw(double money);
        double deposit(double money);
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
        double withdraw(double money);
        double deposit(double money);
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

// function to convert id from string to int
int id(string i);

#endif
