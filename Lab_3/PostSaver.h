#pragma once

#include <list>
#include "IPublisher.h"
#include "IObserver.h"



using std::list;
using std::cout;


class PostSaver : public IPublisher {
private:
	list<IObserver*> observers;


public:
    virtual ~PostSaver() {
        cout << "����, � ��� ��������� :)\n";
    }


    // ������ ��� �������� ���������� ������������ ��� ��� ������� 
    void Add(IObserver* observer) override {
        observers.push_back(observer);
    }


    void Remove(IObserver* observer) override {
        observers.remove(observer);
    }


    // ����� ��� �������� ��������� ���� ����������� ������������
    void Send(string &msg) override {
        for (IObserver *observer : observers) {
            observer->Update(msg);
        }
    }

};

