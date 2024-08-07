#include "publisher.h"
#include <iostream>

void Publisher::attach(shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

void Publisher::detach(shared_ptr<Observer> observer) {
    auto it = find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

void Publisher::notify(bool isInside) {
    for (shared_ptr<Observer> observer : observers) {
        try {
            observer->update(isInside);
        }
        catch (const exception& e) {
            cerr << "Notify error: " << e.what() << '\n';
        }
    }
}