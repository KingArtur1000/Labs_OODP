#include "Lab_2.h"


int main() {
    setlocale(0, "");


    GiftStorage giftStorage;

    giftStorage.addGift(new Toy("Мишка", 10, 500.0, "Мягкая игрушка"));
    giftStorage.addGift(new Toy("Конструктор", 15, 1200.0, "Развивающая игрушка"));
    giftStorage.addGift(new Toy("Кукла", 8, 800.0, "Кукла"));
    giftStorage.addGift(new GiftSet("Детский набор", 5, 1500.0, "Шоколад, игрушка, книга"));
    giftStorage.addGift(new GiftSet("Сладкий набор", 7, 1000.0, "Конфеты, мягкая игрушка"));




    cout << "\tПервоначальный список подарков:\n";
    giftStorage.showAllGiftItems();

    cout << "\tИТОГО: Общее кол-во подарков: " << GiftItem::getTotalItems() << "\n";




    giftStorage.updateGiftInfo(2, "Робот", 12, 1500.0, "Электронная игрушка");

    giftStorage.updateGiftQuantityByIndex(0, 5);
    giftStorage.updateGiftQuantityByIndex(2, 3);

    cout << "\n\tОбновленный список подарков:\n";
    giftStorage.showAllGiftItems();

    cout << "\tИТОГО: Общее кол-во подарков: " << GiftItem::getTotalItems() << "\n";




    giftStorage.updateGiftQuantityByIndex(4, 2);

    cout << "\n\tФинальный список подарков:\n";
    giftStorage.showAllGiftItems();

    cout << "\tИТОГО: Общее кол-во подарков: " << GiftItem::getTotalItems() << "\n";




    cout << "\n\n\t\tDLC - Лабораторная работа №2:\n\n";
    cout << "\t\tПоиск подарка по имени:\n";
    giftStorage.findGiftByName("Чика");
    giftStorage.findGiftByName("Робот");


    cout << "\n\t\tСортировка подарков по имени:\n";
    giftStorage.sortGiftsByName();
    giftStorage.showAllGiftItems();



    cout << "\n\t\t\t*** НОВАЯ РУБРИКА - ИТОГИ ЛАБОРАТОРНОЙ №2:\n\n";
    cout << "• Был добавлен \"Центр подарков\", где осуществляется взаимодействие с подарками разных типов\n";
    cout << "(ранее, требовалось вручную работать с каждым подарком через индекс вектора)\n";
    cout << "• Добавлен итератор для поиска подарка с помощью std::find_if;\n";
    cout << "• Применен алгоритм STL std::sort для сортировки списка подарков;\n";
    cout << "• Применен алгоритм STL std::find_if для поиска подарка по имени;\n";

    cout << "\t\tBy KingArtur1000 :)\n";

    return 0;
}