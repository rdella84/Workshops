// OOP244 Workshop ??: ??????????
// File ???????
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
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

	// Definition for display(...) Array
	void display(Kingdom KDMary[], int size) {
		cout << "------------------------------" << endl;
		cout << "Kingdoms of Westeros" << endl;
		cout << "------------------------------" << endl;
		
		int i, ttlPopulation;

		for (i = 0; i < size; i++) {
			cout << i << "." << KDMary[i].m_name << ", " << KDMary[i].m_population << endl;
			ttlPopulation += ttlPopulation;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of Westeros : " << ttlPopulation << endl;
		cout << "------------------------------" << endl;

	}

