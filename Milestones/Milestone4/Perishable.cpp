#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include "Perishable.h"
#include <iostream>


using namespace std;
namespace ict {
	char Perishable::signature()const {
		return 'P';
	}

	Perishable::Perishable() {
		m_expiry.dateOnly(true);
	}

	fstream& Perishable::save(fstream& file)const {
		NonPerishable::save(file) << ',' << m_expiry;
		
		return file;
	}

	fstream& Perishable::load(fstream& file) {
		NonPerishable::load(file);
		cin.ignore();
		file >> m_expiry;
		
		return file;
	}

	ostream& Perishable::write(ostream& os, bool linear)const {
		NonPerishable::write(os, linear);
		if (ok() && !linear)
			os << "Expiry date: " << m_expiry << endl;

		return os;
	}

	istream& Perishable::read(istream& istr) {

		cout << "Perishable ";
		NonPerishable::read(istr);
		cout << "Expiry Date: ";

		istr >> m_expiry;

		if (m_expiry.bad()) {
			if (m_expiry.errCode() == CIN_FAILED) {
				error("Invalid Date Entry");
				istr.setstate(ios::failbit);
			}
			else if (m_expiry.errCode() == YEAR_ERROR) {
				error("Invalid Year in Date Entry");
				istr.setstate(ios::failbit);
			}
			else if (m_expiry.errCode() == MON_ERROR) {
				error("Invalid Month in Date Entry");
				istr.setstate(ios::failbit);
			}
			else if (m_expiry.errCode() == DAY_ERROR){
				error("Invalid Day in Date Entry");
				istr.setstate(ios::failbit);
			}
		}

		return istr;
	}
}
