#pragma once
#include "includes.h"


enum class GearboxType
{
	MANUAL = 0,
	AUTOMATIC
};


class Transmission
{
private:
	GearboxType m_gearbox;
	unsigned short int m_gears;
	int m_currentGear;

public:
	Transmission(GearboxType gearbox = GearboxType::MANUAL, unsigned short int gears = 5, int currentGear = 0) :
		m_gearbox{ gearbox },
		m_gears{ gears },
		m_currentGear{ currentGear }

	{

	}

	void transmission_control(int ChangeGears)
	{
		m_currentGear += ChangeGears;

		//cout << "Текущая передача: " << m_currentGear << "\n";
	}
};