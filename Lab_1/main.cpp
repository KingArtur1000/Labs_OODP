#include "Lab_1.h"


int main() {
    setlocale(0, "");


    vector<GiftItem*> gifts;

    gifts.push_back(new Toy("Мишка", 10, 500.0, "Мягкая игрушка"));
    gifts.push_back(new Toy("Конструктор", 15, 1200.0, "Развивающая игрушка"));
    gifts.push_back(new Toy("Кукла", 8, 800.0, "Кукла"));
    gifts.push_back(new GiftSet("Детский набор", 5, 1500.0, "Шоколад, игрушка, книга"));
    gifts.push_back(new GiftSet("Сладкий набор", 7, 1000.0, "Конфеты, мягкая игрушка"));


    cout << "\tПервоначальный список подарков:\n";
    for (auto* gift : gifts) {
        gift->getInformation();
        cout << "-----------------\n";
    }

    cout << "\tИТОГО: Общее кол-во подарков: " << GiftItem::getTotalItems() << "\n";


    delete gifts.at(2);
    gifts.at(2) = new Toy("Робот", 12, 1500.0, "Электронная игрушка");

    gifts.at(0)->updateQuantity(5);
    gifts.at(2)->updateQuantity(3);

    cout << "\n\tОбновленный список подарков:\n";
    for (auto* gift : gifts) {
        gift->getInformation();
        cout << "-----------------\n";
    }

    cout << "\tИТОГО: Общее кол-во подарков: " << GiftItem::getTotalItems() << "\n";


    gifts.at(4)->updateQuantity(2);

    cout << "\n\tФинальный список подарков:\n";
    for (auto* gift : gifts) {
        gift->getInformation();
        cout << "-----------------\n";
    }


    cout << "\tИТОГО: Общее кол-во подарков: " << GiftItem::getTotalItems() << "\n";


    for (auto* gift : gifts) {
        delete gift;
    }


    cout << "\t\tBy KingArtur1000 :)\n";

    return 0;
}