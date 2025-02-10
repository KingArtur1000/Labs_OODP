﻿#pragma once

#include "GiftItem.h"


class Toy : public GiftItem {
private:
    string typeToy;


public:
    Toy() : GiftItem(), typeToy("") {}


    Toy(const string& name, int quantity, double price, const string& type)
        : GiftItem(name, quantity, price), typeToy(type) {}


    void getInformation() override {
        GiftItem::getInformation();
        cout << "Тип игрушки: " << typeToy << '\n';
    }


    void updateInfo(string name, unsigned int quantity, double price, string typeToy) override {
        GiftItem::updateInfo(name, quantity, price, typeToy);
        this->typeToy = typeToy;
    }
};