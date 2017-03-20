#include "SavingsAccount.h"

using namespace std;

namespace ict{ 
	
	// TODO: Implement SavingsAccount member functions here
	SavingsAccount::SavingsAccount(double bal, double interRate): Account(bal) {

			interestRate = interRate;
			if (interestRate < 0)
				interestRate = 0;
	}
	double SavingsAccount::calculateInterest()const {
		return interestRate * getBalance();
	}

	void SavingsAccount::display(ostream& d)const {

		d << "Account type: Saving" << endl;
		d.precision(2);
		d.setf(ios::fixed);
		d << "Balance: $ " << getBalance() << endl;
		d << "Interest Rate (%): " << interestRate * 100 << endl;
	}
}