#ifndef __Log_H_
#define __Log_H_

#include <fstream>
#include "./Date.h"
#include "./String.h"
using Type::String;
using Utility::Date;

namespace Logician {
	enum class Level {
		Debug, Info, Warning, Error, Critical
	};
	class Log {
	public:
		explicit Log(String name, Level level = Level::Warning) : m_Name{name}, m_LogLevel{level}, m_IsFileSink{false} {}
		explicit Log(String name, Level level, String fileName) : m_Name{name}, m_LogLevel{level}, m_FileName{fileName}, m_IsFileSink{true} {}

		void setLevel(const Level& level) {
			m_LogLevel = level;
		}

		Level getLevel() const {
			return m_LogLevel;
		}

		void logToFile(const String& fileName);

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

	private:
		Level m_LogLevel;
		String m_Name;
		String m_FileName;
		mutable std::ofstream m_OutStream;
		bool m_IsFileSink;

		static String getLevelString(const Level& level);
		static String getLevelStringColored(const Level& level);

		void print() const;

		template<typename T, typename... Args>
		void print(T arg, Args&&... args) const;

		template<typename... Args>
		void log(Level level, const String& message, Args&&... args) const;
	};

	template<typename T, typename... Args>
	void Log::print(T arg, Args&&... args) const {
		if (m_OutStream) {
			m_OutStream << arg << " ";
		}
		std::cout << arg << " ";
		print(args...);
	}

	template<typename... Args>
	void Log::log(Level level, const String& message, Args&&... args) const {
		if (m_IsFileSink) {
			m_OutStream.open(m_FileName.getRaw(), std::ios::app);
			if (m_OutStream) {
				m_OutStream << Date::getCurrentDate().getStrDate() << " : [" << m_Name << "] : [" << getLevelString(level) << "] : " << message << " ";
			}
		}
		std::cout << Date::getCurrentDate().getStrDate() << " : [" << m_Name << "] : [" << getLevelStringColored(level) << "] : " << message << " ";
		print(args...);
		if (m_OutStream.is_open()) {
			m_OutStream.close();
		}
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