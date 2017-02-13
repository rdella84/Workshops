//TODO: add header guards here
#ifndef HOLIDAY_PASSENGER_H_
#define HOLIDAY_PASSENGER_H_
//Regio Della
//ID: 109324160

// TODO: holiday namespace here
namespace holiday {

		// TODO: declare the class Passenger here
	class Passenger {
	private:
		//create setEmpty for constructor

		char m_name[32];
		char m_destination[32];
		int m_departureYear;
		int m_departureMonth;
		int m_departureDay;
	
	public:
		// TODO: add the class the attributes,
		//       the member function already provided,
		//       and the member functions that you must implement
		Passenger();
		Passenger(const char* Name, const char* destination);
		void display(bool onlyNames = false) const;
		bool canTravelWith(const Passenger&) const;
		bool isEmpty() const;
	};

}
#endif 