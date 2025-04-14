#pragma once
#include "includes.h"


enum class CoolingType
{
	AIR = 0,
	LIQUID,
	OIL
};


class CoolingSystem
{
private:
	CoolingType m_type;

public:
	CoolingSystem(CoolingType type = CoolingType::AIR) :
		m_type{ type }
	{

	}

	void cooling_control(bool engineType)
	{
		if (engineType) {
			cout << "Система охлаждения доступна!\n";
		}
		else {
			cout << "У тебя ЭЛЕКТРОКАР, проснись!\n";
		}
	}

};