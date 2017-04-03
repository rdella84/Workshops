#define _CRT_SECURE_NO_WARNINGS
// lib includes
#include <iostream>
#include <iomanip>
#include "NonPerishable.h"
#define comma ','

using namespace std;
namespace ict {

	/*******           Protected        *********/

	bool NonPerishable::ok()const {
		// return m_err is clear and has no error
		return m_err.isClear();
	}
	void NonPerishable::error(const char* message) {
		m_err.message(message);
	}
	char NonPerishable::signature()const {
		return 'N';
	}

	/*******            Public         *********/

	fstream& NonPerishable::save(std::fstream& file)const {
		//file.open("244_ms4.txt", ios::out);
		if(file.is_open())
			file << signature() << comma << sku() << comma << name() << comma << price() << comma << taxed() << comma << quantity();
		return file;
	}

	fstream& NonPerishable::load(std::fstream& file) {
		//file.open("244_ms4.txt", ios::in);
		if (ok()) {
			char tempC[MAX_NO_ITEMS];
			double tempD;
			int tempI;

			file.getline(tempC, MAX_NO_ITEMS, comma); // sku
			sku(tempC);

			file.getline(tempC, MAX_NO_ITEMS, comma); // name
			name(tempC);

			file >> tempD;  // price
			file.ignore();
			price(tempD);

			file >> tempI;   // taxed
			file.ignore();
			if (tempI)
				taxed(true);
			else
				taxed(false);

			file >> tempI;
			file.ignore();  // quantity
			quantity(tempI);

			//file.close();
		}
		else {
			file << m_err;
			return file;
		}
		return file;
	}

	ostream& NonPerishable::write(ostream& ostr, bool linear)const {
		if (ok()) {
			if (linear) {
				ostr.setf(ios::left); ostr.width(MAX_SKU_LEN);
				ostr << sku() << '|';
				ostr.width(20);
				ostr << name() << '|';
				ostr.unsetf(ios::left);
				ostr.setf(ios::right); ostr.width(7);
				ostr.setf(ios::fixed); ostr.precision(2);
				ostr << price() << '|';
				ostr.width(2);
				if (taxed())
					ostr << " T" << signature() << '|';
				else
					ostr << " " << signature() << '|';
				ostr.unsetf(ios::right); ostr.unsetf(ios::fixed); ostr.width(4);
				ostr << quantity() << '|';
				ostr.setf(ios::fixed);  ostr.precision(2); ostr.width(9);
				ostr << ttlCost() << '|';
				ostr.unsetf(ios::right);
			}
			else {
				if (taxed()) {
					ostr << "Name:" << endl;
					ostr.setf(ios::left); ostr.width(80);
					ostr << name() << endl;
					ostr << "Sku: " << sku() << endl;
					ostr << "Price: ";
					ostr.setf(ios::fixed); ostr.precision(2);
					ostr << price() << endl;
					ostr << "Price after tax: ";
					ostr.precision(2);
					ostr << cost() << endl;
					ostr << "Quantity: " << quantity() << endl;
					ostr << "Total Cost: ";
					ostr.precision(2);
					ostr << ttlCost() << endl;
					ostr.unsetf(ios::left); ostr.unsetf(ios::fixed);
				}
				else {
					//ostr.width(80);
					ostr << "Name:" << endl;
					ostr.setf(ios::left); ostr.width(80);
					ostr << name() << endl;
					ostr << "Sku: " << sku() << endl;
					ostr << "Price: ";
					ostr.setf(ios::fixed); ostr.precision(2);
					ostr << price() << endl;
					ostr << "Price after tax: N/A";
					ostr << "Quantity: " << quantity() << endl;
					ostr << "Total Cost: ";
					ostr.precision(2);
					ostr << ttlCost() << endl;
					ostr.unsetf(ios::left); ostr.unsetf(ios::fixed);
				}
			}
		}
		else
			ostr << m_err;

		return ostr;
	}

	istream& NonPerishable::read(std::istream& is) {
		
		// Returns is if is in a fail state other wise it reads the data
		if (is.fail()) {
			return is;
		}
		else {
			char tempC[MAX_NO_ITEMS];
			double tempD;
			int tempI;
			bool tempB;
			m_err.clear();

			cout << "Item Entry: " << endl;
			cout << "Sku: ";
			is >> tempC;
			if (is.fail())
				m_err.message("Invalid SKU Entry");
			else
				sku(tempC);
			
			cout << "Name:" << endl;
			is >> tempC;
			if (is.fail())
				m_err.message("Invalid Name Entry");
			else
				name(tempC);

			cout << "Price: ";
			is >> tempD;
			if (is.fail())
				m_err.message("Invalid Price Entry");
			else
				price(tempD);
			if (m_err.isClear()) {
				cout << "Taxed: ";
				is >> tempC;
				if (tempC[0] != 'Y' && tempC[0] != 'y' && tempC[0] != 'N' && tempC[0] != 'n') {
					m_err.message("Invalid Taxed Entry, (y)es or (n)o");
					is.setstate(ios::failbit);
				}
				else
					taxed(true);
			}

			if (m_err.isClear()) {
				cout << "Quantity: ";
				is >> tempI;
				if (is.fail())
					m_err.message("Invalid Quantity Entry");
				else
					quantity(tempI);
			}
		}
	}


	// Tax calculator

	const double NonPerishable::ttlCost()const {
		double sum = quantity() * cost();
		return sum;
	}
}
