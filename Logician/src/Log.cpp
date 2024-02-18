#include "../include/Log.h"

using Logging::Log;

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

void Log::logToFile(const String& fileName) {
	m_IsFileSink = true;
	m_FileName = fileName;
}

void Log::print() const {
	if (m_OutStream) {
		m_OutStream << std::endl;
	}
	std::cout << std::endl;
}