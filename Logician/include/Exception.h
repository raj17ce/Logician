#ifndef __Exception_H_
#define __Exception_H_

#include "./String.h"
using Type::String;

namespace Exception {
	class MyException {
	protected:
		String m_Message;
	public:
		MyException(const String& txt="Something went wrong") : m_Message{txt} {};

		virtual String getMessage() const {
			return m_Message;
		};

		virtual ~MyException() = default;
	};

	class IndexOutOfBoundException : public MyException {
	public:
		IndexOutOfBoundException(const String& txt="") : MyException(txt) {};

		String getMessage() const override {
			return "[IndexOutOfBoundException] : " + m_Message;
		}
	};

	class InvalidDateException : public MyException {
	public:
		InvalidDateException(const String& txt = "") : MyException(txt) {};

		String getMessage() const override {
			return "[InvalidDateException] : " + m_Message;
		}
	};
}
#endif