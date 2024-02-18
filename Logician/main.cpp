#include <iostream>
#include "./include/Log.h"
#include "./include/String.h"
#include "./include/Exception.h"
#include "./include/Date.h"
#include <thread>
using Logging::Log;
using Type::String;
using Utility::Date;

int main() {
	Log log;

	log.logToFile("./logs/main.log");

	log.setLogLevel(Log::Level::Debug);
	log.debug("Debug log", "Some debug info");
	log.info("Info log!",15,"Info");
	log.warning("Warning log!",28,500,17.4f);
	log.error("Stop!", "Hello");
	log.critical("Critical Log!");
}