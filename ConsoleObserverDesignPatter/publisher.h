#pragma once

#include "observer.h"
#include <vector>
#include <memory>

using namespace std;

class Publisher {
public:
	void attach(shared_ptr<Observer> observer);
	void detach(shared_ptr<Observer> observer);
	void notify(bool isInside);

private:
	vector<shared_ptr<Observer>> observers;
};