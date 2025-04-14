#include "CoolingSystem.h"
#include "Transmission.h"
#include "Engine.h"
#include "Auto.h"

int main()
{
    setlocale(0, "");


    Engine engineDVS;
    CoolingSystem coolingSystem;
    Transmission transmission;


    Auto carDVS(&engineDVS, &transmission, &coolingSystem);

    std::cout << "���:\n";
    carDVS.StartCar(800);
    carDVS.AdjustPower(1100);
    carDVS.ChangeGear(1);
    carDVS.StopCar();

    std::cout << "\n\n";


    Engine engineEL(0, 0, 0, false); // ���������������� (engineType = false)
    Auto carEL(&engineEL, &transmission, &coolingSystem);

    std::cout << "����������:\n";
    carEL.StartCar(800);
    carEL.AdjustPower(1000);
    carEL.StopCar();

    return 0;
}