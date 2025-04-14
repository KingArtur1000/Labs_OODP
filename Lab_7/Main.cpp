#include "builder.h"

int main() {
    setlocale(0, "");

    Director director;


    // ������ ���������� ����������
    SportsCarBuilder sportsBuilder;
    director.setBuilder(&sportsBuilder);
    auto sportsCar = director.constructCar();
    sportsCar->printInfo();
    std::cout << '\n';


    // ������ �������� ����������
    FamilyCarBuilder familyBuilder;
    director.setBuilder(&familyBuilder);
    auto familyCar = director.constructCar();
    familyCar->printInfo();

    return 0;
}
