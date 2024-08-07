#pragma once
#include "observer.h"
#include <chrono>
#include <fstream>

using namespace std;

class LogObserver : public Observer {
public:
	LogObserver(const string& path);
	void update(bool isInside) override;

private:
	ofstream logFile;
};