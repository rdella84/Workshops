// OOP244 Workshop 02: At Home
// File w2_at_home.cpp
// Version 1.0
// Date Jan 28, 2017
// Author Regio Della
// Description
// Main function that calls the display function which displays all the kingdoms of westeros using overloading functions
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////

#include <iostream>
#include "kingdom.h"

using namespace std;
using namespace westeros;

int main(void)
{
	int count = 0; // the number of kingdoms in the array
	
	// TODO: declare the pKingdoms pointer here (don't forget to initialize it)
	Kingdom* pKingdoms = nullptr;

	cout << "==========" << endl
		 << "Input data" << endl
		 << "==========" << endl
		 << "Enter the number of kingdoms: ";
	cin >> count;
	cin.ignore();

	// TODO: allocate dynamic memory here for the pKingdoms pointer
	pKingdoms = new Kingdom[count];

	for (int i = 0; i < count; ++i)
	{
		// TODO: add code to accept user input for the pKingdoms array
		int num = i + 1;
		cout << "Enter the name for kingdom #" << num << ": ";
		cin >> pKingdoms[i].m_name;
		cout << "Enter the number of people living in " << pKingdoms[i].m_name << ": ";
		cin >> pKingdoms[i].m_population;
	}
	cout << "==========" << endl << endl;


	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The first kingdom of Westeros" << endl
		<< "------------------------------" << endl;
	display(pKingdoms[0]);
	cout << "------------------------------" << endl << endl;


	// testing that the first overload of "display(...)" works
	display(pKingdoms, count);
	cout << endl;


	// testing that the second overload of "display(...)" works
	display(pKingdoms, count, 345678);
	cout << endl;


	// testing that the third overload of "display(...)" works
	display(pKingdoms, count, "Mordor");
	cout << endl;

	display(pKingdoms, count, "The_Vale");
	cout << endl;

	//TODO: deallocate the dynamic memory here
	delete[] pKingdoms;

	return 0;
}
