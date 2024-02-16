#ifndef __String_H_
#define __String_H_

#include <iostream>
#include <cstring>


namespace Type {
	class String {
	private:
		std::unique_ptr<char[]> m_Buffer;
		unsigned int m_Size;
	public:
		String(); //default constructor

		String(const char*); //parameterized constructor

		String(const String&); //copy constructor

		String& operator=(const String&); //copy assignment

		String(String&&) noexcept; //move constructor

		String& operator=(String&&) noexcept; //move assignment

		~String() = default;

		int length() const{
			return m_Size;
		}

		char& operator[](const unsigned int&) const;

		static unsigned int getLength(const char*);
		static String toString(const int&);

		String& toLowerCase();
		String& toUpperCase();
		String& append(const String&);

		friend bool operator==(const String&, const String&);
		friend std::ostream& operator<<(std::ostream& stream, const String& string);
		friend String operator+(const String&, const String&);
	};
}
#endif  