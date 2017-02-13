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

	// TODO: add the default constructor here
	Passenger::Passenger() {
		strcpy(m_name, "");
		strcpy(m_destination, "");
		m_departureYear = 0;
		m_departureMonth = 0;
		m_departureDay = 0;
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
			strcpy(m_name, "");
			strcpy(m_destination, "");
			m_departureYear = 0;
			m_departureMonth = 0;
			m_departureDay = 0;
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