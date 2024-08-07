#include "consoleObserver.h"
#include <windows.h>

using namespace std;

void ConsoleObserver::update(bool isInside) {
	isInside ? SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4) : SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}