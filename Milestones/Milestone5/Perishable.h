#ifndef ICT_PERISHABLE_H__
#define ICT_PERISHABLE_H__

#include <iostream>
#include "NonPerishable.h"
#include "Date.h"

namespace ict {
	class Perishable : public NonPerishable {
		Date m_expiry;
	protected:
		char signature()const;
	public:
		Perishable();
		fstream& save(fstream& file)const;
		fstream& load(fstream& file);
		ostream& write(ostream& os, bool linear)const;
		istream& read(istream& istr);
	};

}

#endif
