#ifndef __Log_H_
#define __Log_H_

#include "./Date.h"
#include "./String.h"
using Type::String;

namespace Logging {
	class Log {
	public:
		enum class Level {
			Debug, Info, Warning, Error, Critical
		};

	private:
		Level m_LogLevel;
		Utility::Date m_Date;

	public:
		explicit Log() : m_LogLevel{ Level::Warning }, m_Date{ 05,02,2024 } {}

		void setLogLevel(const Log::Level& level) {
			m_LogLevel = level;
		}

		Level getLogLevel() const {
			return m_LogLevel;
		}

		void setDate(int dd, int mm, int yy) {
			m_Date.setDate(dd, mm, yy);
		}

		String getLevelStr(Log::Level level) const;

		void print() const {
			std::cout << std::endl;
		}

		template<typename T, typename... Args>
		void print(T arg, Args&&... args) const;

		template<typename... Args>
		void log(Level level, const String& message, Args&&... args) const;

		template<typename... Args>
		void debug(const String& message, Args&&... args) const;

		template<typename... Args>
		void info(const String& message, Args&&... args) const;

		template<typename... Args>
		void warning(const String& message, Args&&... args) const;

		template<typename... Args>
		void error(const String& message, Args&&... args) const;

		template<typename... Args>
		void critical(const String& message, Args&&... args) const;
	};

	template<typename T, typename... Args>
	void Log::print(T arg, Args&&... args) const {
		std::cout << arg << " ";
		print(args...);
	}

	String Log::getLevelStr(Log::Level level) const {
		String resultString;
		switch (level) {
			case Level::Debug:
				resultString = "Debug";
				break;
			case Level::Info:
				resultString = "Info";
				break;
			case Level::Warning:
				resultString = "Warning";
				break;
			case Level::Error:
				resultString = "Error";
				break;
			case Level::Critical:
				resultString = "Critical";
				break;
		}
		return resultString;
	}

	template<typename... Args>
	void Log::log(Level level, const String& message, Args&&... args) const {
		std::cout << m_Date.getStrDate() <<" : [" << getLevelStr(level) << "] : " << message << " ";
		print(args...);
	}

	template<typename... Args>
	void Log::debug(const String& message, Args&&... args) const {
		if (m_LogLevel <= Level::Debug) {
			log(Level::Debug, message, args...);
		}
	}

	template<typename... Args>
	void Log::info(const String& message, Args&&... args) const {
		if (m_LogLevel <= Level::Info) {
			log(Level::Info, message, args...);
		}
	}

	template<typename... Args>
	void Log::warning(const String& message, Args&&... args) const {
		if (m_LogLevel <= Level::Warning) {
			log(Level::Warning, message, args...);
		}
	}

	template<typename... Args>
	void Log::error(const String& message, Args&&... args) const {
		if (m_LogLevel <= Level::Error) {
			log(Level::Error, message, args...);
		}
	}

	template<typename... Args>
	void Log::critical(const String& message, Args&&... args) const {
		if (m_LogLevel <= Level::Critical) {
			log(Level::Critical, message, args...);
		}
	}
}

#endif