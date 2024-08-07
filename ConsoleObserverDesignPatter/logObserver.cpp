#include "logObserver.h"
#include <chrono>
#include <iomanip>
#include <iostream>

using namespace std;

LogObserver::LogObserver(const string& path) : logFile(path) {}

void LogObserver::update(bool isInside) {
	try {
		auto now = chrono::system_clock::now();
		time_t t = chrono::system_clock::to_time_t(now);
		tm local_time;
		localtime_s(&local_time, &t);

		logFile << put_time(&local_time, "%Y-%m-%d %H:%M:%S") << " " << (isInside ? "Enter\n" : "Leave\n");
	}
	catch (const exception& e) {
		cerr << "Log update error: " << e.what() << '\n';
	}
}