#ifndef __Log_H_
#define __Log_H_

#include "./Date.h"
#include "./String.h"
using Type::String;

namespace Logging {
	class Log {
	public:
		enum class Level {
			LevelError, LevelWarning, LevelInfo
		};

	private:
		Level m_LogLevel;
		Utility::Date m_Date;

	public:
		explicit Log() : m_LogLevel{ Level::LevelWarning }, m_Date{05,02,2024} {}

		void setLogLevel(const Log::Level& level) {
			m_LogLevel = level;
		}

		Level getLogLevel() const {
			return m_LogLevel;
		}

		void setDate(int dd, int mm, int yy) {
			m_Date.setDate(dd, mm, yy);
		}

		void print() const {
			std::cout << std::endl;
		}

		template<typename T, typename... Args>
		void print(T arg, Args&&... args) const;

		template<typename... Args>
		void error(const String& message, Args&&... args) const;

		template<typename... Args>
		void warning(const String& message, Args&&... args) const;

		template<typename... Args>
		void info(const String& message, Args&&... args) const;
	};

	template<typename T, typename... Args>
	void Log::print(T arg, Args&&... args) const{
		std::cout << arg << " ";
		print(args...);
	}

	template<typename... Args>
	void Log::error(const String& message, Args&&... args) const {
		if (m_LogLevel >= Level::LevelError) {
			std::cout << m_Date.getStrDate() << ": [Error]: " << message << " ";
			print(args...);
		}
	}

	template<typename... Args>
	void Log::warning(const String& message, Args&&... args) const {
		if (m_LogLevel >= Level::LevelWarning) {
			std::cout << m_Date.getStrDate() << ": [Warning]: " << message << " ";
			print(args...);
		}
	}

	template<typename... Args>
	void Log::info(const String& message, Args&&... args) const {
		if (m_LogLevel >= Level::LevelInfo) {
			std::cout << m_Date.getStrDate() << ": [Info]: " << message << " ";
			print(args...);
		}
	}
}

#endif