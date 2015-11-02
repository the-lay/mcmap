#pragma once
#include <chrono>

using namespace std::chrono;

class Timer {
public:
	typedef high_resolution_clock Clock;
	void start() {
		epoch = Clock::now();
	}
	Clock::duration time_elapsed() const {
		return Clock::now() - epoch;
	}
	void reset() {
		start();
	}
	milliseconds print_ms() {
		return std::chrono::duration_cast<milliseconds>(time_elapsed());
	}
private:
	Clock::time_point epoch;
};