#ifndef __Timer_H__
#define __Timer_H__

#include <chrono>
#include <iostream>

namespace Utility {
	class Timer {
	public:
		Timer() : m_StartTimePoint{ std::chrono::high_resolution_clock::now()} {}

		void showTime() {
			auto endTimePoint = std::chrono::high_resolution_clock::now();
			auto nanoDuration = endTimePoint - m_StartTimePoint;
			auto milliDuration = std::chrono::duration_cast<std::chrono::milliseconds>(nanoDuration);
			std::cout << milliDuration.count() << " milliseconds\n";
		}

		~Timer() {
			showTime();
		}
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
	};
}
#endif