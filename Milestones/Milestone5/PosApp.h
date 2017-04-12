#pragma once
#ifndef ICT_POSAPP_H_
#define ICT_POSAPP_H_

#include <iostream>
#include "Item.h"
#include "Perishable.h"
#include "NonPerishable.h"

namespace ict {
	class PosApp {
		char m_filename[128];
		char m_billfname[128];
		Item* m_items[MAX_NO_ITEMS];
		int m_noOfItems;
		int menu();
		void deallocateItems();
		void loadRecs();
		void saveRecs();
		int searchItems(const char* sku)const;
		void updateQty();
		void addItem(bool isPerishable);
		void listItems()const;
		void truncateBillFile();
		void showBill();
		void addToBill(Item& I);
		void POS();
	public:
		PosApp(const char* filename, const char* billfname);
		void run();
	};
}


#endif