#ifndef __Log_H_
#define __Log_H_

#include <fstream>
#include "./Date.h"
#include "./String.h"
using Type::String;

namespace Logging {
	class Log {
	public:
		enum class Level {
			Debug, Info, Warning, Error, Critical
		};

		explicit Log() : m_LogLevel{ Level::Warning }, m_Date{ 05,02,2024 }, m_IsFileSink{ false } {}

		void setLogLevel(const Log::Level& level) {
			m_LogLevel = level;
		}

		Level getLogLevel() const {
			return m_LogLevel;
		}

		void setDate(int dd, int mm, int yy) {
			m_Date.setDate(dd, mm, yy);
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
		Utility::Date m_Date;
		String m_FileName;
		mutable std::ofstream m_OutStream;
		bool m_IsFileSink;

		static String getLevelString(const Log::Level& level);
		static String getLevelStringColored(const Log::Level& level);

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
				m_OutStream << m_Date.getStrDate() << " : [" << getLevelString(level) << "] : " << message << " ";
			}
		}
		std::cout << m_Date.getStrDate() <<" : [" << getLevelStringColored(level) << "] : " << message << " ";
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