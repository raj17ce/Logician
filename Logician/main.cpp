#include <iostream>
#include "./include/Logician.h"
using Logician::Log;
using Logician::Level;

int main() {
	Log log{"MyLogger"};

	Logician::getDefaultLogger()->logToFile("./logs/default.log");
	Logician::getDefaultLogger()->setLevel(Level::Debug);

	Logician::debug("Debug log", "Some debug info");
	Logician::info("Info log!", 15, "Info");
	Logician::warning("Warning log!", 28, 500, 17.4f);
	Logician::error("Stop!", "Hello");
	Logician::critical("Critical Log!");

	log.logToFile("./logs/main.log");

	log.setLevel(Level::Debug);
	log.debug("Debug log", "Some debug info");
	log.info("Info log!",15,"Info");
	log.warning("Warning log!",28,500,17.4f);
	log.error("Stop!", "Hello");
	log.critical("Critical Log!");
}	