#include "CreditCard.h"
#include <iostream>
#include <cstring>


using namespace std;
namespace sict {
	void CreditCard::name(const char cardHolderName[]){
		strcpy(m_cardHolderName, cardHolderName);
	}

	void CreditCard::initialize(unsigned long long creditCardNumber, int instCode, int expiryYear, int expiryMonth, int numberInTheBack) {
		m_cardNumber = creditCardNumber;
		m_institutionCode = instCode;
		m_expiryYear = expiryYear;
		m_expiryMonth = expiryMonth;
		m_numberInTheBack = numberInTheBack;
	}

	bool CreditCard::isValid()const {
		bool ret = false;
		if (strlen(m_cardHolderName) >= 1 && (m_cardNumber >= MIN_CARD_NUMBER && m_cardNumber <= MAX_CARD_NUMBER) &&
			(m_institutionCode >= MIN_INST_NUMBER && m_institutionCode <= MAX_INST_NUMBER) &&
			(m_expiryYear >= MIN_EXP_YEAR && m_expiryYear <= MAX_EXP_YEAR) &&
			(m_expiryMonth >= 1 && m_expiryMonth <= 12))
			ret = true;

		return ret;
	}

	void CreditCard::write() const {
		bool result = isValid();
		if (result == true) {
			cout << "Cardholder: " << m_cardHolderName << endl
				<< "Card Number: " << m_cardNumber << endl
				<< "Institution: " << m_institutionCode << endl
				<< "Expires: " << m_expiryMonth << "/" << m_expiryYear << endl
				<< "Number at the back: " << m_numberInTheBack << endl;
		}
	}
}
