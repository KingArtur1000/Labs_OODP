#pragma once

#include "IObserver.h"


class IPublisher {
public:
	virtual ~IPublisher() {};

	virtual void Add(IObserver* observer) = 0;
	virtual void Remove(IObserver* observer) = 0;
	virtual void Send(string &msg) = 0;


};