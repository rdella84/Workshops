#include "SavingsAccount.h"

using namespace std;

namespace ict{ 
	
	// TODO: Implement SavingsAccount member functions here
	SavingsAccount::SavingsAccount(double bal = 0, double interRate): Acount {

		if (interestRate < 0)
			interestRate = 0;
		else
		interestRate = interRate;
	}
}