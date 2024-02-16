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

	log.setLogLevel(Log::Level::LevelInfo);
	log.error("Stop!");
	log.warning("Careful!");
	log.info("Fine!");
}