#pragma once

#include <string>
#include <iostream>

#include "IGift.h"


class GiftItem : public IGift {
private:
    string name;
    unsigned int quantity;
    double price;
    static int totalItems;


public:
    GiftItem() : name(""), quantity(0), price(0.0) { }


    GiftItem(const string& n, int q, double p)
        : name(n), quantity(q), price(p) {
        totalItems += q;
    }


    void getInformation() override {
        std::cout << "Название: " << name << '\n';
        std::cout << "Количество: " << quantity << '\n';
        std::cout << "Цена: " << price << '\n';
    }


    string getName() const { return name; }
    unsigned int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    void setName(string name) { this->name = name; }
    void setQuantity(unsigned int quantity) { this->quantity = quantity; }
    void setPrice(double price) { this->price = price; }


    virtual void updateInfo(string name, unsigned int quantity, double price, string extraInfo) {
        setName(name);
        setQuantity(quantity);
        setPrice(price);
    };


    void updateQuantity(int amount) {
        quantity += amount;
        totalItems += amount;
    }


    static int getTotalItems() {
        return totalItems;
    }


    ~GiftItem() {
        totalItems -= this->getQuantity();
    }
};


int GiftItem::totalItems = 0;