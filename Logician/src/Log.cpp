#include "../include/Log.h"
using Logician::Log;
using Logician::Level;

String Log::getLevelString(const Level& level) {
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

String Log::getLevelStringColored(const Level& level) {
	String resultString;
	switch (level) {
	case Level::Debug:
		resultString = "\x1B[35mDebug\033[0m";
		break;
	case Level::Info:
		resultString = "\x1B[36mInfo\033[0m";
		break;
	case Level::Warning:
		resultString = "\x1B[33mWarning\033[0m";
		break;
	case Level::Error:
		resultString = "\x1B[91mError\033[0m";
		break;
	case Level::Critical:
		resultString = "\x1B[31mCritical\033[0m";
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