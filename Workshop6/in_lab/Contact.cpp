#include "Contact.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace communication {
	
	Contact::Contact() {
		m_name[0] = "";
		m_phoneNumbers = 0;
		m_noOfPhoneNumbers = 0;
	}
	Contact::Contact(const char* name, long long* pNumber, int size) {
		size = new int size;
		bool valid = m_phoneNumbers == 11 || m_phoneNumbers == 12 && m_phoneNumbers[2] != 0 && m_phoneNumbers[6] != 0;
		for (int i = 0; i < size; i++) {
			if (valid) {
				this.m_phoneNumbers = pNumber;
			}
		}
	}

	bool Contact::isEmpty() const{
		return this->m_name == "" && this->m_phoneNumbers = 0 && this->m_noOfPhoneNumbers = 0;
	}

	void Contact::display() const {
		if (this.isEmpty())
			cout << "Empty Contact!" << endl;
		else {
			cout << this.m_name << endl;
		}
	}








}