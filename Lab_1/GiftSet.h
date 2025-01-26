#pragma once

#include "GiftItem.h"


class GiftSet : public GiftItem {
private:
    string contents;


public:
    GiftSet() : GiftItem(), contents("") {}


    GiftSet(const string& name, int quantity, double price, const string& cont)
        : GiftItem(name, quantity, price), contents(cont) {}


    void getInformation() override {
        GiftItem::getInformation();
        cout << "Содержимое набора: " << contents << '\n';
    }
};