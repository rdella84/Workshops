// OOP244 Workshop 3: Compound types and privacy
// File	CreditCard.h
// Version 1.0
// Date	2017/02/05
// Author	Regio Della
// Description
// This file is the header of CreditCard.cpp and contains all the prototypes,
// namespace sict and class CreditCard
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		          Reason
// 
///////////////////////////////////////////////////////////


#ifndef SICT_CREDITCARD_H_
#define SICT_CREDITCARD_H_

namespace sict {

	const int MAX_NAME_LENGTH = 40;
	const int MIN_INST_NUMBER = 100;
	const int MAX_INST_NUMBER = 999;
	const int MIN_EXP_YEAR = 2017;
	const int MAX_EXP_YEAR = 2037;
	const unsigned long long MIN_CARD_NUMBER = 4000000000000000;
	const unsigned long long MAX_CARD_NUMBER = 4000999999999999;

	class CreditCard {
	private:
		char m_cardHolderName[MAX_NAME_LENGTH];
		unsigned long long m_cardNumber;
		int m_institutionCode;
		int m_expiryYear;
		int m_expiryMonth;
		int m_numberInTheBack;
		void writeName()const;
		void writeCardInfo()const;
	public:
		void name(const char cardHolderName[]);
		void initialize(unsigned long long creditCardNumber, int instCode, int expiryYear, int expiryMonth, int numberInTheBack);
		void write(bool displayName = true, bool displayCardInfo = true) const;
		bool isValid() const;
	};
}

#endif
