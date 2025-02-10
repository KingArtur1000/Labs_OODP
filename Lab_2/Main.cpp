#include "Lab_2.h"


int main() {
    setlocale(0, "");


    vector<GiftItem*> gifts;

    gifts.push_back(new Toy("�����", 10, 500.0, "������ �������"));
    gifts.push_back(new Toy("�����������", 15, 1200.0, "����������� �������"));
    gifts.push_back(new Toy("�����", 8, 800.0, "�����"));
    gifts.push_back(new GiftSet("������� �����", 5, 1500.0, "�������, �������, �����"));
    gifts.push_back(new GiftSet("������� �����", 7, 1000.0, "�������, ������ �������"));


    cout << "\t�������������� ������ ��������:\n";
    for (auto* gift : gifts) {
        gift->getInformation();
        cout << "-----------------\n";
    }

    cout << "\t�����: ����� ���-�� ��������: " << GiftItem::getTotalItems() << "\n";


    delete gifts.at(2);
    gifts.at(2) = new Toy("�����", 12, 1500.0, "����������� �������");

    gifts.at(0)->updateQuantity(5);
    gifts.at(2)->updateQuantity(3);

    cout << "\n\t����������� ������ ��������:\n";
    for (auto* gift : gifts) {
        gift->getInformation();
        cout << "-----------------\n";
    }

    cout << "\t�����: ����� ���-�� ��������: " << GiftItem::getTotalItems() << "\n";


    gifts.at(4)->updateQuantity(2);

    cout << "\n\t��������� ������ ��������:\n";
    for (auto* gift : gifts) {
        gift->getInformation();
        cout << "-----------------\n";
    }


    cout << "\t�����: ����� ���-�� ��������: " << GiftItem::getTotalItems() << "\n";



    cout << "\n\n\t\tDLC - ������������ ������ �2:\n\n";

    

    for (auto* gift : gifts) {
        delete gift;
    }


    cout << "\t\tBy KingArtur1000 :)\n";

    return 0;
}