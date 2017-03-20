#include "Account.h"

using namespace std;

namespace ict{ 
	
	// constructor   
	Account::Account(double amount) {
		balance = amount;
	}

	// credit (add) an amount to the account balance
	void Account::credit(double amount) {
		balance += amount;
	}
	
	// debit (subtract) an amount from the account balance return bool 
	bool Account::debit(double wdrawAmt) {
		bool ret = true;

		if (balance < wdrawAmt) {
			ret = false;
		}
		else
			balance -= wdrawAmt;

		return ret;

	}

	double Account::getBalance() const
	{
		return balance;
	} 

	void Account::setBalance( double newBalance )
	{
		balance = newBalance;
	} 
}