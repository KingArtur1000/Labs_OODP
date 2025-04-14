#pragma once
#include "includes.h"
#include "Engine.h"
#include "Transmission.h"
#include "CoolingSystem.h"

class Auto
{
private:
    Engine* m_pEngine;
    Transmission* m_pTransmission;
    CoolingSystem* m_pCoolingSystem;

public:
    Auto(Engine* pEngine, Transmission* pTransmission, CoolingSystem* pCoolingSystem) :
        m_pEngine(pEngine),
        m_pTransmission(pTransmission),
        m_pCoolingSystem(pCoolingSystem)
    {
    }

   
    void StartCar(float initialPower) {
        std::cout << "Запуск автомобиля...\n";
        m_pEngine->start(initialPower);
        m_pCoolingSystem->cooling_control(m_pEngine->getType());
        m_pTransmission->transmission_control(1);
        std::cout << "Автомобиль готов к движению!\n";
    }

    void StopCar() {
        std::cout << "Остановка автомобиля...\n";
        m_pTransmission->transmission_control(-1);
        m_pEngine->stop();
        std::cout << "Автомобиль остановлен!\n";
    }

    void AdjustPower(float adj) {
        m_pEngine->power_control(adj);
    }

    void ChangeGear(int gearChange) {
        m_pTransmission->transmission_control(gearChange);
    }
};