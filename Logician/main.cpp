#include <iostream>
#include "./include/Log.h"
#include "./include/String.h"
#include "./include/Exception.h"
#include <thread>
using Logging::Log;
using Type::String;

#include "./include/Date.h"
using Utility::Date;

int main() {
	Log log;

	log.setLogLevel(Log::Level::Debug);
	log.debug("Debug log", "Some debug info");
	log.info("Info log!",15,"Infooo");
	log.warning("Warning log!",28,500,17.4f);
	log.error("Stop!", std::this_thread::get_id(), "Hello");
	log.critical("Critical Log!");	
}