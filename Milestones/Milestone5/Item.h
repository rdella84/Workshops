#ifndef ICT_ITEM_H__
#define ICT_ITEM_H__
// inlcude PosIO and POS header files
#include "PosIO.h"
#include "POS.h"
namespace ict {
	// class Item
	class Item : public PosIO {

	private:
		char m_sku[MAX_SKU_LEN + 1];
		char * m_name;
		double m_price;
		bool m_taxed;
		int m_quantity;
	public:
		Item();
		Item(const char sku[MAX_SKU_LEN], const char * name, double price, bool tax = true);
		virtual ~Item();
		const Item& operator=(const Item& m) ;
		Item(const Item&);
		//void cpyConstructor(const char * sku, const char * name, double price, bool tax = true);

		//Setters
		void sku(const char * sku);
		void name(const char * name);
		void price(double price);
		void taxed(bool tax);
		void quantity(int quantity);

		//Getters
		const char* sku()const;
		const char* name()const;
		const double price()const;
		const bool taxed()const;
		const int quantity()const;

		const double cost()const;
		const bool isEmpty()const;

		bool operator==(const char* sku)const;
		int operator+=(int quantity)const;
		int operator-=(int quantity)const;

	};

	// end class Item
	// operator += 
	double operator+=(double& Loper, const Item& Roper);
	// operator << and operator >>
	std::ostream& operator<<(std::ostream& ostr, const Item& ct);
	std::istream& operator>>(std::istream& istr, Item& k);
}

#endif