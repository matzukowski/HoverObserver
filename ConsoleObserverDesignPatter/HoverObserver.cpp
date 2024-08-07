#include "consoleObserver.h"
#include "logObserver.h"
#include "publisher.h"
#include "utilities.h"
#include <iostream>

using namespace std;

int main() {
    Publisher publisher;

    shared_ptr<ConsoleObserver> consoleObserver = make_shared<ConsoleObserver>();
    shared_ptr<LogObserver> logObserver = make_shared<LogObserver>("log.txt");

    publisher.attach(consoleObserver);
    publisher.attach(logObserver);

    bool isInside = isMouseInsideConsole();

    cout << "Console app checking if mouse hover over console window and utilizing the observer pattern to log entry and exit timestamps to a file.\n\n";

    publisher.notify(isInside);

    cout << "Hello world!";

    while (true) {
        if (isInside != isMouseInsideConsole()) {
            isInside = !isInside;

            publisher.notify(isInside);

            cout << "\rHello world! ";
        }

        Sleep(100);
    }
    
    return 0;
}