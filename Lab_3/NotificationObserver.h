#pragma once

#include <iostream>
#include "IObserver.h"


using std::cout;


class NotificationObserver : public IObserver {
private:


public:
    virtual ~NotificationObserver() {}

    void Update(const string& msg_from_subject) override {
        cout << "��������� �� ��������: " << msg_from_subject << "\n\n";
    }

};
