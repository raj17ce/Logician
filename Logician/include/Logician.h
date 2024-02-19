#ifndef __DefaultLogger_H__
#define __DefaultLogger_H__

#include "./Log.h"
using Logician::Log;

namespace Logician {

	static auto defaultLogger = std::make_shared<Log>("defaultLogger", Level::Debug);

	std::shared_ptr<Log> getDefaultLogger() {
		return defaultLogger;
	}

	void setDefaultLogger(std::shared_ptr<Log> ptr) {
		defaultLogger = ptr;
	}

	template<typename... Args>
	void debug(String message, Args&&... args) {
		defaultLogger->debug(message, args...);
	}

	template<typename... Args>
	void info(const String& message, Args&&... args) {
		defaultLogger->info(message, args...);
	}

	template<typename... Args>
	void warning(const String& message, Args&&... args) {
		defaultLogger->warning(message, args...);
	}

	template<typename... Args>
	void error(const String& message, Args&&... args) {
		defaultLogger->error(message, args...);
	}

	template<typename... Args>
	void critical(String message, Args&&... args) {
		defaultLogger->critical(message, args...);
	}
}

#endif