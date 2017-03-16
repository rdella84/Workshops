#define _CRT_SECURE_NO_WARNINGS 

#include "Error.h"

namespace ict{
  
	Error::Error() {
		m_message = nullptr;
	}
	Error::Error(const char* errorMessage) {
		m_message = nullptr;
		message(errorMessage);
	}

	Error::~Error() {
		clear();
	}

	void Error::message(const char* value) {
		delete[] m_message;
		m_message = new char[strlen(value) + 1];
		strcpy(m_message, value);
	}

	Error::operator const char*() const {
		return m_message;
	}

	Error::operator bool()const {
		return m_message == nullptr;
	}
	
	void Error::operator=(const char* errorMessage) {
		clear();
		message(errorMessage);
	}

	void Error::clear() {
		delete[] m_message;
		m_message = nullptr;
	}

	bool Error::isClear()const {
		return this->m_message == nullptr;
	}

	const char* Error::value()const {
		return m_message;
	}

	std::ostream& operator<<(std::ostream& os, const Error& ct) {
		if (ct.isClear() == false)
			os << ct.value();
		return os;
	}
}