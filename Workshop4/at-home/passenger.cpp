//Regio Della
//ID: 109324160

// TODO: add your headers here
#include "passenger.h"
#include <iostream>
#include <cstring>

// TODO: add the namespaces that you will be using here
using namespace std;

// TODO: holiday namespace here
namespace holiday {

	//Sets constructor into safe empty state
	void Passenger::setEmpty() {
		m_name[0] = 0;
		m_destination[0] = 0;
		m_departureYear = 0;
		m_departureMonth = 0;
		m_departureDay = 0;
	}

	// TODO: add the default constructor here
	Passenger::Passenger() {
		setEmpty();
	}

	// TODO: add the constructor with 2 parameters here
	Passenger::Passenger(const char* Name, const char* destination) {
		bool valid = Name != nullptr && destination != nullptr && strcmp(Name, "") != 0 && strcmp(destination, "") != 0;

		if (valid) {
			strcpy(m_name, Name);
			strcpy(m_destination, destination);
			m_departureMonth = 7;
			m_departureDay = 1;
			m_departureYear = 2017;
		}
		else {
			setEmpty();
		}
	}
	
	// Passenger with 5 parameters
	Passenger::Passenger(const char* Name, const char* destination, int year, int month, int day) {
		bool valid = Name != nullptr && destination != nullptr && strcmp(Name, "") != 0 && strcmp(destination, "") != 0 &&
			year >= 2017 && year <= 2020 && month >= 1 && month <= 12 && day >= 1 && day <= 31;

		if (valid) {
			strcpy(m_name, Name);
			strcpy(m_destination, destination);
			m_departureMonth = month;
			m_departureDay = day;
			m_departureYear = year;
		}
		else {
			setEmpty();
		}

	}

	// TODO: add the canTravelWith(...) function here
	bool Passenger::canTravelWith(const Passenger& psnger) const {
		bool ret = false;
		if ((strcmp(m_destination, psnger.m_destination) == 0 ) && (m_departureYear == psnger.m_departureYear) &&
			(m_departureMonth == psnger.m_departureMonth) && (m_departureDay && psnger.m_departureDay)) {
			ret = true;
		}

		return ret;
	}

	void Passenger::travelWith(const Passenger* arrPassengers, int size) {

		//Use display and canTravelWith
		bool valid = arrPassengers != nullptr && arrPassengers != 0 && size != 0;
		bool ret = false;
		int i, cnt = 0;
		if (valid) {
			for (i = 0; i < size; i++) {
				if (this->canTravelWith(arrPassengers[i])) {
					cnt++;
				}
			}

			if (cnt == size) {
				cout << "Everybody can join " << m_name << " on vacation!" << endl;
				cout << m_name << " will be accompanied by ";
				for (i = 0; i < size; i++) {
					if (i != 0)
						cout << ", ";
					arrPassengers[i].display(m_name);
				}
				cout << "." << endl;
			}
			
			else if (cnt != size) {
				cout << m_name << " will be accompanied by ";
								
				for (i = 0; i < size; i++) {
					if (this->canTravelWith(arrPassengers[i])) {
						if (i != 0)
							cout << ", ";
						arrPassengers[i].display(m_name);
					}
				}
				cout << "." << endl;
			}
		}

		else
			cout << "Nobody can join " << m_name << " on vacation!" << endl;	
	}

	
	// TODO: add the isEmpty() function here
	bool Passenger::isEmpty() const {
		bool ret = false;

		if (strcmp(m_name, "") == 0 && strcmp(m_destination, "") == 0 &&  m_departureYear == 0 && m_departureMonth == 0 && m_departureDay == 0) {
			ret = true;
		}

		return ret;
	}


	// below is the member function already provided
	// TODO: read it and understand how it accomplishes its task
	void Passenger::display(bool nameOnly) const
	{
		if (false == this->isEmpty())
		{
			cout << this->m_name;
			if (false == nameOnly)
			{
				cout << " will travel to " << this->m_destination << ". "
					<< "The journey will start on "
					<< this->m_departureYear << "-"
					<< this->m_departureMonth << "-"
					<< this->m_departureDay
					<< "." << endl;
			}
		}

		else
		{
			cout << "Invalid passenger!" << endl;
		}

	}
}