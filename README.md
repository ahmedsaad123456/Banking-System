# Banking System
The Banking System is a model, design, and implementation of a banking application
that allows bank employees to create bank accounts for specific clients, list all available bank accounts, 
display account details, withdraw money, and deposit money. 
There are two types of bank accounts in this system: BankAccount and SavingsBankAccount.

# Program Structure 

descriptions for the key classes used in the Banking System program.

## `BankAccount` Class

The `BankAccount` class represents a basic bank account. It holds the following data:
- Account ID
- Balance
This class provides methods to set and get the account balance and ID.
And It allows for withdrawing an amount of money from the account if the balance is sufficient.
And depositing an amount of money into the account.


## `SavingBankAccount` Class

The `SavingBankAccount` class is a specialized type of bank account that extends the basic `BankAccount`. It has the following additional data field:
- Minimum Balance (default value: 1000 L.E.)
It allow withdrawing money, but the balance cannot fall below the minimum balance.
And It enables depositing an amount of money into the account, but only if the amount is greater than or equal to 100 L.E.


## `Client` Class

The `Client` class holds basic client information, including name, address, and phone number. It maintains a reference to two types of bank accounts:
- `BankAccount`
- `SavingBankAccount`

## `BankApplication` Class

The `BankApplication` class is responsible for running the main application. It displays a menu and handles user interaction, including adding clients and listing clients.


# Usage

To use this Banking System:

1. Compile and run the main program (`BankApplication` class).
2. Program displays some choices and you must enter the number of the choice
3. Then Follow the on-screen prompts


# Contributors

We would like to thank the following contributors to this project:

- [Ahmed Saad](https://github.com/ahmedsaad123456)
- [Shahd Osama](https://github.com/shahdosama10)
- [Maryam Osama](https://github.com/maryamosama33)

Special thanks to everyone who has helped make this project better.


