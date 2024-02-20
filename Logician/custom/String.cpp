#include "../include/String.h"
#include "../include/Exception.h"
using Exception::InvalidDateException;
using Type::String;

char& String::operator[](const unsigned int& index) const {
	if (index < 0 || index >= m_Size) {
		throw InvalidDateException{ "String index " + std::to_string(index) + " is invalid" };
	}
	return m_Buffer.get()[index];
}

unsigned int String::getLength(const char* str) {
	auto size{ 0U };

	while (str[size] != '\0') {
		size++;
	}

	return size;
}

String String::toString(const int& num) {
	auto temp{num};
	auto size{ 0U };
	auto isNegative{ (num < 0) };

	while (temp != 0) {
		temp /= 10;
		size++;
	}

	if (isNegative) temp = num * -1;
	else temp = num;

	if (isNegative)	size++;

	auto tempStr = std::make_unique<char[]>(size + 1);
	tempStr[size] = '\0';

	if (isNegative) {
		tempStr[0] = '-';
	}

	for (auto i = size - 1 ; i >= 0 && temp != 0; i--) {
		auto digit = temp % 10;
		temp /= 10;
		tempStr[i] = digit + '0';
	}

	return String{tempStr.get()};
};

String::String() {
	m_Size = 0;
	m_Buffer = std::make_unique<char[]>(m_Size + 1);
	m_Buffer[m_Size] = '\0';
}

String::String(const char* str) {
	m_Size = getLength(str);
	m_Buffer = std::make_unique<char[]>(m_Size + 1);
	memcpy(m_Buffer.get(), str, m_Size);
	m_Buffer[m_Size] = '\0';
}

String::String(const String& str) {
	m_Size = str.m_Size;
	m_Buffer = std::make_unique<char[]>(m_Size + 1);
	memcpy(m_Buffer.get(), str.m_Buffer.get(), m_Size);
	m_Buffer[m_Size] = '\0';
}

String& String::operator=(const String& str) {
	if (this != &str) {
		m_Size = str.m_Size;
		m_Buffer = std::make_unique<char[]>(m_Size + 1);
		memcpy(m_Buffer.get(), str.m_Buffer.get(), m_Size);
		m_Buffer[m_Size] = '\0';
	}

	return *this;
}

String::String(String&& str) noexcept {
	m_Size = std::move(str.m_Size);
	m_Buffer = std::move(str.m_Buffer);
	//Very Important
	str.m_Size = 0;
}

String& String::operator=(String&& str) noexcept {
	if (this != &str) {
		m_Size = std::move(str.m_Size);
		m_Buffer = std::move(str.m_Buffer);
		//Very Important
		str.m_Size = 0;
	}

	return *this;
}

String& String::toLowerCase() {
	for (auto i = 0U; i < m_Size; i++) {
		if (m_Buffer[i] >= 65 && m_Buffer[i] <= 90) {
			m_Buffer[i] += 32;
		}
	}

	return *this;
};

String& String::toUpperCase(){
	for (auto i = 0U; i < m_Size; i++) {
		if (m_Buffer[i] >= 97 && m_Buffer[i] <= 122) {
			m_Buffer[i] -= 32;
		}
	}

	return *this;
};

String& String::append(const String& str) {
	auto newBuffer = std::make_unique<char[]>(m_Size + str.m_Size + 1);
	memcpy(newBuffer.get(), m_Buffer.get(), m_Size);
	memcpy(newBuffer.get() + m_Size, str.m_Buffer.get(), str.m_Size + 1);
	m_Size = m_Size + str.m_Size;
	m_Buffer = std::move(newBuffer);
	return *this;
}

bool Type::operator==(const String& str1, const String& str2) { //done
	if (str1.m_Size != str2.m_Size) return false;

	for (auto i = 0U; i < str1.m_Size; i++) {
		if (str1[i] != str2[i]) return false;
	}

	return true;
}

std::ostream& Type::operator<<(std::ostream& stream, const String& string) { //done
	stream << string.m_Buffer.get();
	return stream;
}

String Type::operator+(const String& str1, const String& str2) {
	auto newBuffer = std::make_unique<char[]>(str1.m_Size + str2.m_Size + 1);
	memcpy(newBuffer.get(), str1.m_Buffer.get(), str1.m_Size);
	memcpy(newBuffer.get() + str1.m_Size, str2.m_Buffer.get(), str2.m_Size + 1);

	String tempStr{ newBuffer.get()};

	return tempStr; 
}; 