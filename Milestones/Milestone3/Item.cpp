#define _CRT_SECURE_NO_WARNINGS  
// Lib includes
#include <iostream>
#include <iomanip>
#include <cstring>
// inlcude Item and POS header files
#include "Item.h"
#include "POS.h"
using namespace std;
namespace ict{
  // class Item implementaion
	Item::Item() {
		sku("");
		m_name = nullptr;
		m_price = 0.0;
		m_quantity = 0;
	}

	Item::Item(const char sku[MAX_SKU_LEN], const char * name, double price, bool tax)
	{
		this->sku(sku);
		m_name = new char[strlen(name) + 1];
		this->name(name);
		quantity(0);
		this->price(price);
		taxed(tax);

	}

	Item::~Item() {
		delete[] m_name;
	}
/*
	void Item::cpyConstructor(const char * sku, const char * name, double price, bool tax) {

		strcpy(m_sku, sku);
		m_name = new char[sizeof(name) + 1];
		strcpy(m_name, name);
		m_quantity = 0;
		m_price = price;
		m_taxed = tax;
	}
*/

	const Item& Item::operator=(const Item& eq) {
		delete[] m_name;
		m_name = nullptr;
		if (isEmpty() == false) {
			sku(eq.m_sku);
			m_name = new char[strlen(eq.m_name) + 1];
			name(eq.m_name);
			m_quantity = 0;
			price(eq.m_price);
			taxed(eq.m_taxed);
		}
		
		return *this;
	}


	/****************************   Setters   ***************************/
	void Item::sku(const char * sku) {
		strcpy(m_sku, sku);
	}
	void Item::name(const char * name) {
		strcpy(m_name, name);
	}
	
	void Item::price(double price) {
		m_price = price;
	}
	void Item::taxed(bool tax) {
		m_taxed = tax;
	}
	void Item::quantity(int quantity) {
		m_quantity = quantity;
	}

	/****************************   Getters   ***************************/
	const char* Item::sku()const {
		return m_sku;
	}
	const char* Item::name()const {
		return m_name;
	}
	const double Item::price()const {
		return m_price;
	}
	const bool Item::taxed()const {
		return m_taxed;
	}
	const int Item::quantity()const {
		return m_quantity;
	}

	const double Item::cost()const{
		double cost = 0.0;
		if (taxed())
			cost = m_price + (m_price * TAX);
		else
			cost = m_price;

		return cost;
	}

	const bool Item::isEmpty()const {
		return m_sku[0] == 0 && m_name == nullptr && m_price == 0 && m_quantity == 0;
	}

	bool Item::operator==(const char* sku)const {
		return strcmp(m_sku, sku);
	}

	int Item::operator+=(int quantity)const {
		int sum = m_quantity;
		sum += quantity;

		return sum;
	}

	int Item::operator-=(int quantity)const {
		int sum = m_quantity;
		sum -= quantity;

		return sum;
	}

	double operator+=(double& Loper, const Item& Roper) {
		return Loper += Roper.cost() * Roper.quantity();
	}

	std::ostream& operator<<(std::ostream& ostr, const Item& ct) {
		ct.write(ostr,true);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Item& cn) {
		cn.read(istr);
		return istr;
	}
}