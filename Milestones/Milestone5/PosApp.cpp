#define _CRT_SECURE_NO_WARNINGS
#include "PosApp.h"
#include <fstream>
#include <iomanip>
#include <string>

namespace ict{
	PosApp::PosApp(const char* filename, const char* billfname) {
		strcpy(m_filename, filename);
		strcpy(m_billfname, billfname);
		m_noOfItems = 0;
	}
	int PosApp::menu() {
		int input = 0;
		cout << "The Sene-Store" << endl;
		cout << "1- List items" << endl;
		cout << "2- Add Perishable item" << endl;
		cout << "3- Add Non-Perishable item" << endl;
		cout << "4- Update item quantity" << endl;
		cout << "5- Show Item" << endl;
		cout << "6- POS" << endl;
		cout << "0- exit program" << endl;
		cout << "> ";
		cin >> input;
		if (input < 0 || input > 6)
			input = -1;
		cout << endl;
		return input;
	}

	void PosApp::deallocateItems() {
		for(int i = 0; i < m_noOfItems; i++)
			delete m_items[i];
		m_noOfItems = 0;
	}

	void PosApp::loadRecs() {

		char temp[2];

		deallocateItems();
		fstream file;
		file.open(m_filename, ios::in);
		if (file.fail()) {
			file.clear();
			file.close();
			file.open(m_filename, ios::out);
		}
		else {
			int i = 0;

			while (!EOF) {
				temp[1] = '\0';
				file.get() >> temp[0];
				file.ignore(1);
				if (temp[0] == 'P') {
					m_items[m_noOfItems] = new Perishable();
					//m_items[m_noOfItems++]->load(file);
					file >> *m_items[m_noOfItems++];
				}
				else if (temp[0] == 'N') {
					m_items[m_noOfItems] = new NonPerishable();
					//m_items[m_noOfItems++]->load(file);
					file >> *m_items[m_noOfItems++];
				}
				/*else {
					Item* fItem;
					fItem->load(file);
					m_noOfItems++;
				}*/
			}
		} 
		file.close();
	}

	void PosApp::saveRecs() {
		fstream file;
		file.open(m_filename, ios::out);
		//if file.bad()

		for (int i = 0; i < m_noOfItems; i++) {
			if (m_items[i]->quantity() > 0) {
				m_items[i]->save(file);
			}
		}
		file.close();
		loadRecs();
	}

	int PosApp::searchItems(const char* sku)const {
		int index = -1;
		for (int i = 0; i < m_noOfItems; i++) {
			if (m_items[i]->sku() == sku) {
				index = i;
			}
		}
		return index;
	}

	void PosApp::updateQty() {
		char sku[MAX_SKU_LEN];
		cout << "Please enter the SKU: ";
		cin >> sku;

		int ret = 0;
		int qnty = 0;

		ret = searchItems(sku);
		if (ret == -1)
			cout << "Not Found" << endl;
		else {
			m_items[ret]->write(cout, false);
			/////-------Might not be inside else--------//////
			cout << "Please enter the number of purchased items: ";
			cin >> qnty;
			// use operator += and saveRecs
			m_items[ret] += qnty;
			saveRecs();
			cout << "Updated" << endl;
		}
	}

	void PosApp::addItem(bool isPerishable) {
		// adds an item to the m_items array and saves the array in the data file
		cout << m_noOfItems;
		if (isPerishable) {
			m_items[m_noOfItems] = new Perishable();
			if (cin.fail()) {
				cin.clear();
				cout << m_items[m_noOfItems];
			}
			else {
				// Save the item
				m_items[m_noOfItems++]->read(cin); // adds 1 after this statement is done
				saveRecs();
				cout << "Item Added." << endl;
			}
		}
		else {
			m_items[m_noOfItems] = new NonPerishable();
			if (cin.fail()) {
				cin.clear();
				cout << m_items[m_noOfItems];
			}
			else {
				// Save the item
				m_items[m_noOfItems++]->read(cin);
				saveRecs();
				cout << "Item Added." << endl;
			}
		}
	}

	void PosApp::listItems()const {
		double sum = 0.0;
		cout << " Row | SKU    | Item Name          | Price |TX |Qty | Total |" << endl;
		cout << "-----|--------|--------------------|-------|---|----|---------|" << endl;
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i]->write(cout, true);
			sum += m_items[i]->quantity() * m_items[i]->cost(); // add tax
		}
		cout << "-----^--------^--------------------^-------^---^----^---------^" << endl;
		cout << "Total Asset: $";
		cout << "|";
		cout.precision(2);
		cout << sum << endl;
		cout << "-----------------------------------------------^--------------^" << endl;
	}

	void PosApp::truncateBillFile() {
		fstream file;
		file.open(m_billfname, ios::out | ios::trunc);
		file.close();
	}
	
	void PosApp::showBill() {
		fstream file;
		file.open(m_billfname, ios::in);
		while (!EOF) {
			
		}
	}
	void PosApp::addToBill(Item& I) {
		int tempQty = I.quantity();
		fstream file;
		file.open(m_billfname, ios::out | ios::app);
		I.quantity(1);
		I.save(file);
		I.quantity(tempQty - 1);
		saveRecs();
	}

	void PosApp::POS() {
		bool done = true;
		char sku[MAX_SKU_LEN];
		int i = 0;
		while (!done) {
			cin >> sku;
			if (sku == "")
				showBill();
			else if (m_items[i]->sku() == sku) {
				cout << m_items[i]->name() << endl;
				addToBill(*m_items[i]);
			}
			else
				cout << "Not found!" << endl;
		}
	}

	void PosApp::run() {
		bool done = false;
		char tempSKU[MAX_SKU_LEN] = "";
		int index = 0;
		while (!done) {
			switch (menu()) {
			case 1: listItems(); break;
			case 2: addItem(true); break;
			case 3: addItem(false); break;
			case 4: updateQty(); break;
			case 5: 
				cout << "Please enter the SKU: ";
				cin >> tempSKU;
				index = searchItems(tempSKU);
				if(index != -1)
					m_items[index]->write(cout, false);
				else
					cout << "Not found" << endl;
				break;
			case 6: POS(); break;
			case 0: 
				cout << "Goodbye!" << endl; 
				done = true;
				break;
			default: cout << "===Invalid Selection, try again===" << endl;
			}
		}
	}
}



/*
ouputs:
-------------------------------------
update:
Please enter the SKU: 1313
Name:
Paper Tissue
Sku: 1313
Price: 1.22
Price after tax: 1.38
Quantity: 194
Total Cost: 267.45

Please enter the number of purchased items: 12
Updated!

------------------------------
Please enter the SKU: 3434
Not found!

-------------------------------------
add item:
Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 1200/10/12
Invalid Year in Date Entry

Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 2017/5/15
Item added.

--------------------------------------------
list item:
 Row | SKU    | Item Name          | Price |TX |Qty |   Total |
-----|--------|--------------------|-------|---|----|---------|
   1 | 1234   |Milk                |   3.99|  P|   2|     7.98|
   2 | 3456   |Paper Cups          |   5.99| TN|  38|   257.21|
   3 | 4567   |Butter              |   4.56| TP|   9|    46.38|
   4 | 1212   |Salted Butter       |   5.99|  P| 111|   664.89|
   5 | 1313   |Paper Tissue        |   1.22| TN| 206|   283.99|
   6 | 5656   |Honey               |  12.99| TP|  12|   176.14|
-----^--------^--------------------^-------^---^----^---------^
                               Total Asset: $  |       1436.59|
-----------------------------------------------^--------------^


--------------------------------------
printbill:
v--------------------------------------------------------v
| 2017/04/02, 12:42                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         22.05|
^-----------------------------------------^--------------^

-------------------------------------------------------
POS:
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1313
v------------------->
| Paper Tissue
^------------------->
Sku: 1234
v------------------->
| Milk
^------------------->
Sku: 7654
Not found!
Sku: 5656
v------------------->
| Honey
^------------------->
Sku:
v--------------------------------------------------------v
| 2017/04/02, 12:58                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 1234   |Milk                |   3.99|  P|   1|     3.99|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         32.03|
^-----------------------------------------^--------------^

------------------------------------------------------
run:
The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 5656
v-----------------------------------v
Name:
Honey
Sku: 5656
Price: 12.99
Price after tax: 14.68
Quantity: 10
Total Cost: 146.79
Expiry date: 2017/05/15
^-----------------------------------^

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5

Please enter the SKU: 12345
Not found!

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> five

===Invalid Selection, try again===

The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 0

Goodbye!

*/