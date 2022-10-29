#include "bank.h"
//----------------------------------------------------------------------------------------------------------
clint::clint(string N , string A  , string P, double B,int id){
    Name= N ;
    Address = A;
    phone = P;
    account.set_balance(B);
    account.set_ID(ID(id));
    Saving_account.set_minimumBalance(0);
}
//----------------------------------------------------------------------------------------------------------

clint::clint(string N , string A  , string P, double B , double min,int id){
    Name= N ;
    Address = A;
    phone = P;
    account.set_balance(B);
    account.set_ID(ID(id));
    Saving_account.set_minimumBalance(min);

}
//----------------------------------------------------------------------------------------------------------
clint::clint(){
    Name = "None";
    Address = "None";
    phone = "None";
    account.set_balance(0);
    Saving_account.set_minimumBalance(0);
    
}
//----------------------------------------------------------------------------------------------------------

void clint::set_name(string N){
    Name = N;
}
//----------------------------------------------------------------------------------------------------------

void clint::set_address(string A){
    Address= A ;
}
//----------------------------------------------------------------------------------------------------------

void clint::set_phone(string P){
    phone = P;
}
//----------------------------------------------------------------------------------------------------------

string clint::get_name(){
    return Name;
}
//----------------------------------------------------------------------------------------------------------

string clint::get_address(){
    return Address;
}
//----------------------------------------------------------------------------------------------------------

string clint::get_phone(){
    return phone;
}
//----------------------------------------------------------------------------------------------------------

BankAccount clint::get_bankAccount(){
    return account;
}
//----------------------------------------------------------------------------------------------------------

SavingBankAccount clint::get_SavingAcount(){
    return Saving_account;
}
//----------------------------------------------------------------------------------------------------------
// function to write the new clint into file
void clint::write_to(ostream & output){
    
    output<<Name<<endl;
    output<<Address<<endl;
    output<<phone<<endl;
    output<<account.get_ID()<<endl;
    output<<account.get_balance()<<endl;
    output<<Saving_account.get_minimumBalance()<<endl;

}
//----------------------------------------------------------------------------------------------------------

vector<clint> loadClints(fstream &file){
    file.open("users_data.txt", ios::out | ios::in | ios::app);
    string N ,A , P , line;
    double balance , minB;
    int id;
    double num=0;
    SavingBankAccount S;
    // vector to load from the file in it
    vector <clint> clints;

    int x=1;
    while(getline(file, line)){
        if(x==1){
            // x=1 that mean this line is name
            N= line;
        }
        if(x==2){
            // x =2 that mean this line is address
            A = line;
        }
        if(x==3){
            // x=3 that mean this line is phone
            P=line;
        }
        if(x==4){
            // x= 4 that mean this line is string id

            string new_id="";
            // this line to get the string number id in FCAI-000 
            // we need 000
            new_id=new_id+line[6]+line[7]+line[8];
            // this to convert string 000 to integer  0
            stringstream geek(new_id);
            geek>> num;
            id=num;
        }
        if(x==5){
            // x=5 that mean this line is balance
            // convert string balance to integer balance
            stringstream geek(line);
            geek>> num;
            balance=num;
        }
        if(x==6){
            // x=6 that mean this line is minimum balance
            // convert string min balance to integer min balance
            stringstream geek(line);
            geek>> num;
            minB = num;
            // push all data in the vector
            clints.push_back(clint(N , A ,P , balance, minB,id));
            //to read the next clint
            x=0;
        }

        x++;

    }

    file.close();
   
    return clints;
   
}
//---------------------------------------------------------------------------------------------------------
BankAccount::BankAccount(){
    account_ID= "FCAI-000";
    balance=0;
}
//---------------------------------------------------------------------------------------------------------

BankAccount::BankAccount(double B, int id){

    account_ID = ID(id);
    balance=B;    
}
//---------------------------------------------------------------------------------------------------------

void BankAccount::set_balance(double B){
    balance= B;
}
//---------------------------------------------------------------------------------------------------------

void BankAccount::set_ID(string ID){
    account_ID=ID;
}
//---------------------------------------------------------------------------------------------------------

string BankAccount::get_ID(){
    return account_ID;
}
//---------------------------------------------------------------------------------------------------------

double BankAccount::get_balance(){
    return balance;
}
//---------------------------------------------------------------------------------------------------------

void BankAccount::withdraw(double money){
    while (money>balance){
        cout<<"Sorry. This is more than what you can withdraw"<<endl;
        cout<<"Please Enter The Amount to Withdraw"<<endl;
        cin>>money;
    }
    balance= balance - money;
}
//---------------------------------------------------------------------------------------------------------

void BankAccount::deposit(double money){
    balance = balance + money;
}
//---------------------------------------------------------------------------------------------------------

SavingBankAccount::SavingBankAccount(double B ,int id, double min) : BankAccount(B,id){
    if(B<min){
        cout<<"Sorry initial balance should be >= min Balance";
        set_balance(0);
        return;
    }
    
    minimumBalance = min;
}
//---------------------------------------------------------------------------------------------------------

SavingBankAccount::SavingBankAccount(): BankAccount(){
    minimumBalance=1000;
}
//---------------------------------------------------------------------------------------------------------

void SavingBankAccount::set_minimumBalance(double min){
    minimumBalance = min;
}
//---------------------------------------------------------------------------------------------------------


double SavingBankAccount::get_minimumBalance(){
    return minimumBalance;
}
//---------------------------------------------------------------------------------------------------------

void SavingBankAccount::withdraw(double money){
    if(get_balance()-money <minimumBalance ){
        cout<<"the Balance will be less than minimum Balance"<<endl;
        cout<<"your Balance is "<< get_balance()<<endl;
        cout<<"Please Enter the money to withdraw"<<endl;
        cin>>money;

    }

    withdraw(money);
}
//---------------------------------------------------------------------------------------------------------

void SavingBankAccount::deposit(double money){
    while (money<100){
        cout<<"Sorry the money should be >=100"<<endl;
        cout<<"Please Enter the money again"<<endl;
        cin>>money;
    }

    deposit(money);
}
//---------------------------------------------------------------------------------------------------------

string ID (int id){
    string new_ID;
    
    if (id>9){
        new_ID= "FCAI-0" + to_string(id);
    }
    if(id>99){
        new_ID = "FCAI-" + to_string(id);
    }
    if (id<10){
        new_ID = "FCAI-00" + to_string(id);
    }

    return new_ID;

}
//---------------------------------------------------------------------------------------------------------

int last_ID(vector<clint> clints){

    //get the last element in th vector and get from it the last id 
    string last_ID= clints[clints.size()-1].get_bankAccount().get_ID();
    // convert the string id to int id
    string new_id="";
    new_id= new_id + last_ID[6]+last_ID[7]+last_ID[8];
    stringstream geek(new_id);
    int id=0;

    geek>>id;

    return id;
}
//---------------------------------------------------------------------------------------------------------
// the main Function to Run the App
void BankApplication::Run(){
    fstream file;
    int choice, type_of_account;
    string name , address , phone;
    double balance , money , minimum_Balance;
    // load the data form the file and push it into vector
    vector<clint>ALL_Clints= loadClints(file);
    
    cout<<"Welcome to FCAI Banking Application"<<endl;
    cout<<"1. Create a New Account "<<endl;
    cout<<"2. List Clinets and Accounts"<<endl;
    cout<<"3. Withdraw Money"<<endl;
    cout<<"4. Deposit Money"<<endl;
    cout<<"Please Enter Choice"<<endl;
    cin >> choice;
    cin.clear();  // this two line to slove the problem in next getline
    cin.sync();
    if(choice==1){
        cout<<"Please Enter Clint Name"<<endl;
        getline(cin , name);
        
        cout<<"Please Enter Clint Address"<<endl;
        cin>>address;
        cout<<"please Enter Clint phone"<<endl;
        cin>>phone;
        cout<<"what type of account Do you Like? (1) Basic (2) Saving - Type 1 or 2"<<endl;
        cin>>type_of_account;
        file.open("users_data.txt", ios::out | ios::in | ios::app);
        if(type_of_account==1){
            cout<<"please Enter the Starting Balance "<<endl;
            cin>>balance;
            clint new_clint(name , address , phone , balance,last_ID(ALL_Clints)+1);
            cout<<"An account was created with ID "<<new_clint.get_bankAccount().get_ID()
            << " and Starting Balance "<<new_clint.get_bankAccount().get_balance()<<" L.E."<<endl;
            // write the new clint into the file
            new_clint.write_to(file);
        }
        if(type_of_account==2){
            cout<<"please Enter the Starting Balance "<<endl;
            cin>>balance;
            cout<<"please Enter the minimum Balance "<<endl;
            cin>>minimum_Balance;
            clint new_clint(name , address , phone , balance, minimum_Balance, last_ID(ALL_Clints)+1);
            cout<<"An account was created with ID "<<new_clint.get_bankAccount().get_ID()
             << " and Starting Balance "<<new_clint.get_bankAccount().get_balance()<<" L.E."
             <<" and minimum balance "<<new_clint.get_SavingAcount().get_minimumBalance()<<" L.E. "<<endl;
            // write the new clint into the file
            new_clint.write_to(file);
        }
        file.close();
        }
    if (choice ==2){
        // to know type of Account basic or saving
        bool type_Account;
        // print all clint from the file
        for (int i=0 ; i<ALL_Clints.size(); i++){
            if(ALL_Clints[i].get_SavingAcount().get_minimumBalance()==0)
            type_Account=true;
            else
            type_Account= false;
            cout<<"----------------- "<<ALL_Clints[i].get_name()<<" -----------------"<<endl;
            cout<<"Address: "<<ALL_Clints[i].get_address()<<" phone: "<<ALL_Clints[i].get_phone()<<endl;
            if(type_Account){
                cout<<"Account ID: "<<ALL_Clints[i].get_bankAccount().get_ID()<<" (Basic)"<<endl;
                cout<<"Balance: "<<ALL_Clints[i].get_bankAccount().get_balance()<<endl;
            }
            else
            {
                cout<<"Account ID: "<<ALL_Clints[i].get_bankAccount().get_ID()<<" (Saving)"<<endl;
                cout<<"Balance: "<<ALL_Clints[i].get_bankAccount().get_balance()<<endl;
                cout<<"minimum Balance: "<<ALL_Clints[i].get_SavingAcount().get_minimumBalance()<<endl;
            }





        }

    }
    if(choice== 3){

    }
    if(choice == 4){

    }
}