#include <cstring>
#include <iostream>
#include "String.h"


using namespace std;

namespace sict{
    
    
    //////////////////////////////////////////////////////
    //
    // Default Constructor
    // String::String();
    //
    // initialize the string to ""
    //
    // 
    String::String(){
       // initialize the string to ""
		m_pString[0] = '\0';
    }


    //////////////////////////////////////////////////////
    //
    // String::String(const char* p);
    //
    // Construct a String from a char array
    // You may assume the input string pSource 
    // has a length of < 50, and the internal buffer has enough
    // space to hold it.
    //
    // 
    String::String(const char* pSource)
	{
		strcpy(m_pString, pSource);
    }

    //////////////////////////////////////////////////////
    //
    // String::String(const String &s, int capacity);
    //
    // Copy constructor
    //
    // Construct a String from another String
    //
    // 
    String::String(const String& other)
	{
		strcpy(m_pString, other.m_pString);
    }

    
    //////////////////////////////////////////////////////
    //
    // String::operator=(const String& other)
    // 
    // Assignment operator
    // copy string "other" to this object
    //   
    //     
    String& String::operator=(const String& other)
    {
		//if (this != &other) {
		//	if (empty() == false) {
		strcpy(m_pString, other.m_pString);
		//	}
		//}
		return *this;
    }

    //////////////////////////////////////////////////////
    //
    // String::~String
    // 
    // destructor
    // 
    // clean up the internal string buffer  
    // 
    String::~String()
    {
		m_pString[0] = '\0';
    }


    //////////////////////////////////////////////////////
    //
    // String::length()
    // 
    // return the length of the string
    // 
    // 
    int String::length() const
    {
		return strlen(this->m_pString);
    }

    //////////////////////////////////////////////////////
    //
    // String::operator const char*() const
    // 
    // convert the String to a char*
    // 
    // 
    String::operator const char *() const
    {
		return m_pString;
    }

    //////////////////////////////////////////////////////
    //
    // String::empty()
    // 
    // 
    // returns true if the string is empty
    // i.e. either the first char is \0, or 
    // length is 0.
    bool String::empty() const
    {
		return length() == 0;
    }

    //////////////////////////////////////////////////////
    //
    // String::operator bool()
    // 
    // same as empty(), just wrapped in an operator
    // 
    //         
    String::operator bool() const
    {
		return !empty();
    }
     
     
    //////////////////////////////////////////////////////
    //
    // String::operator==(const String& s2) const
    // 
    // returns true if *this == s2.
    // You can use the strcmp function to check if 
    // two strings are equal, or write your own
    // treating the string as a char-array
    //           
    bool String::operator==(const String& s2) const
    {
		return strcmp(m_pString, s2) == 0;
    }
        
        
    //////////////////////////////////////////////////////
    //
    // String::operator+=(const String& s2)
    // 
    // Concatenates s2 to the end of *this
    //
    // implements *this = (*this + s2)
    // return *this
    // 
    //         
    String& String::operator+=(const String& s2)
    {
		*this = (*this + s2);
		return *this;
    }
    
    //////////////////////////////////////////////////////
    //
    // String::operator+(const String& s2) const
    // 
    // implements the operator (*this + s2)
    // returns the expression
    // DOES NOT MODIFY *this
    // 
    //     
    String String::operator+(const String& s2) const
    {
		//int size = strlen(s2.m_pString) + 1;

		char tempC[STRING_BUFFERSIZE];
		strcpy(tempC, m_pString);
		strcat(tempC, s2.m_pString);

		return tempC;
    }
      
    //////////////////////////////////////////////////////
    //
    // String::operator+=(char c)
    // 
    // Adds a single char c to the end of the string in *this
    // 
    //        
    String& String::operator+= (char c)
    {
		
		//this->m_pString[size] = c;
		//this->m_pString[size + 1] = '\0';

		char tempC[2];
		tempC[0] = c;
		tempC[1] = '\0';
		strcat(m_pString, tempC);

		return *this;
    }
 
	const char* String::pString() const {
		return m_pString;
	}
    
    //////////////////////////////////////////////////////
    //
    // operator<<
    // 
    // Print the string to the output stream
    // 
    // clean up the internal string buffer  
    //     
    std::ostream& operator<<(std::ostream& ostream, const String &s)
    {
		ostream << s.pString();
		ostream.clear();
		return ostream;
    }


    //////////////////////////////////////////////////////
    //
    // operator>>
    // 
    // Input a string from an input stream into the String s
    // 
    // Note: the input can be ANY length in character. You will need to 
    // read it one char at a time. 
    // 
    std::istream& operator>>(std::istream& istream, String &s)
    {
        s = "";
        char tempC = 0;
        do
        {
            tempC = istream.get();
            if (tempC != '\n')
            {
                s += tempC;
            }
            else
                break;
        } while(1);
        return istream;
    }

  
}
