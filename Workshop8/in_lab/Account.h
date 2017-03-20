#ifndef ICT_ACCOUNT_H__
#define ICT_ACCOUNT_H__

#include <iostream>

using namespace std;

namespace ict{

	class Account{
		private:
			double balance; // data member that stores the balance

		protected:
			double getBalance() const; // return the account balance
			void setBalance( double ); // sets the account balance

   		public:
			// TODO: Write a prototype for constructor which initializes balance
			Account(double amount);
			// TODDO: Write a function prototype for the virtual function credit
			virtual void credit(double amount);
			// TODO: Write a function prototype for the virtual function debit
			virtual bool debit(double withdraw);
			// TODO: Write a function prototype for the virtual function display
			virtual void display(ostream& d)const = 0;
   };
};
#endif
