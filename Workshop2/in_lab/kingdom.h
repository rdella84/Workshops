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


// TODO: header safeguards
#ifndef westeros_KINGDOM_H_
#define westeros_KINGDOM_H_
#define n_chars 32

// TODO: westeros namespace
namespace westeros {

	// TODO: define the class Kingdom in the westeros namespace
	struct Kingdom {
		char m_name[n_chars];
		int m_population;
	};

	// TODO: add the declaration for the function display(...),
	//         also in the westeros namespace
	void display(Kingdom& KDNam);
	void display(Kingdom KDMnam[], int size);
//	void display(Kingdom KDMary[], int size, int minPpl);
//	void display(Kingdom KDMary[], int size, char KDMnam[n_chars]);
}

#endif