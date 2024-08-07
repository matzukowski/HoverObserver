#pragma once
#include "observer.h"

using namespace std;

class ConsoleObserver : public Observer {
public:
    void update(bool isInside) override;
};