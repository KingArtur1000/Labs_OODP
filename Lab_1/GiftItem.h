#pragma once

#include <string>
#include <iostream>

#include "IGift.h"


class GiftItem : public IGift {
private:
    string name;
    int quantity;
    double price;
    static int totalItems;


protected:
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }


public:
    GiftItem() : name(""), quantity(0), price(0.0) { }


    GiftItem(const string& n, int q, double p)
        : name(n), quantity(q), price(p) {
        totalItems += q;
    }


    ~GiftItem() {
        totalItems -= this->getQuantity();
    }


    void getInformation() override {
        std::cout << "Название: " << name << '\n';
        std::cout << "Количество: " << quantity << '\n';
        std::cout << "Цена: " << price << '\n';
    }


    void updateQuantity(int amount) {
        quantity += amount;
        totalItems += amount;
    }


    static int getTotalItems() {
        return totalItems;
    }
};


int GiftItem::totalItems = 0;