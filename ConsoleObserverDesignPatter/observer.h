#pragma once

class Observer {
public:
	virtual void update(bool isInside) = 0;
};