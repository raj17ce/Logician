#ifndef __Exception_H_
#define __Exception_H_

#include <string>

namespace Exception {
	class MyException {
	public:
		MyException(const std::string& txt="Something went wrong") : m_Message{txt} {};

		virtual std::string getMessage() const {
			return m_Message;
		};

		virtual ~MyException() = default;

	protected:
		std::string m_Message;
	};

	class IndexOutOfBoundException : public MyException {
	public:
		IndexOutOfBoundException(const std::string& txt="") : MyException(txt) {};

		std::string getMessage() const override {
			return "[IndexOutOfBoundException] : " + m_Message;
		}
	};

	class InvalidDateException : public MyException {
	public:
		InvalidDateException(const std::string& txt = "") : MyException(txt) {};

		std::string getMessage() const override {
			return "[InvalidDateException] : " + m_Message;
		}
	};
}
#endif