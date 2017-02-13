// OOP244 Workshop 02: At Home
// File kingdom.cpp
// Version 1.0
// Date Jan 28, 2017
// Author Regio Della
// Description
// Contains all the definitions of all the display functions
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////


// TODO: include the necessary headers
#include <iostream>
#include "kingdom.h"
#include <string>


// TODO: the westeros namespace
using namespace std;
namespace westeros {

	// TODO:definition for display(...) 
	char KDNam;
	void display(Kingdom& KDMnam) {
		cout << KDMnam.m_name << ", population " << KDMnam.m_population << endl;
	}

	//Function: display
	//Parameters: Kingdom array and array size
	//Purpose: displays all the kingdoms, its population and total population
	void display(Kingdom KDMary[], int size) {
		cout << "------------------------------" << endl;
		cout << "Kingdoms of Westeros" << endl;
		cout << "------------------------------" << endl;

		int i, count = 1, ttlPopulation = 0;

		for (i = 0; i < size; i++) {
			cout << count++ << ". " << KDMary[i].m_name << ", population " << KDMary[i].m_population << endl;
			ttlPopulation += KDMary[i].m_population;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of Westeros : " << ttlPopulation << endl;
		cout << "------------------------------" << endl;

	}
	//Function: display
	//Parameters: Kingdom array and array size and minimum people in a kingdom
	//Purpose: displays all the kingdoms that are equal or higher than the minimum population
	void display(Kingdom KDMary[], int size, int minPpl) {
		cout << "------------------------------" << endl;
		cout << "Kingdoms of Westeros with more than " << minPpl << " people" << endl;
		cout << "------------------------------" << endl;

		int i;

		for (i = 0; i < size; i++) {
			if (KDMary[i].m_population >= minPpl) {
				cout << KDMary[i].m_name << ", population " << KDMary[i].m_population << endl;

			}

		}
		cout << "------------------------------" << endl;
	}

	//Function: display
	//Parameters: Kingdom array and array size and a kingdom name
	//Purpose: displays the kingdom that matches the kingdom name in the third parameter
	//		   and if it does not match it gives a helpful message
	void display(Kingdom KDMary[], int size, const char* KDMnam) {
		cout << "------------------------------" << endl;
		cout << "Searching for kingdom " << KDMnam << " in Westeros" << endl;
		cout << "------------------------------" << endl;

		int i;
		bool match = false;
		std::string kdom_name;
		for (i = 0; i < size; i++) {
			kdom_name = KDMary[i].m_name;
			if (kdom_name == KDMnam) {
				match = true;
				if (match == true)
					cout << KDMary[i].m_name << ", population " << KDMary[i].m_population << endl;

				else
					match = false;
			}
		}
		if(match == false)
			cout << KDMnam << " is not part of Westeros." << endl;
		
		cout << "------------------------------" << endl;
	}
}