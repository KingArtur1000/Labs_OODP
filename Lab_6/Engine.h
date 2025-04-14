#pragma once
#include "includes.h"


class Engine
{
private:
	float m_torque;
	float m_power;
	float m_fuel;
	bool m_engineType;

public:
	Engine(float torque = 0.0f, float power = 0.0f, float fuel = 0.0f, bool engineType = true) :
		m_torque{ torque },
		m_power{ power },
		m_fuel{ fuel },
		m_engineType{ engineType }
	{

	}

	bool getType() {
		return m_engineType;
	}

	void torque_control(float adj)
	{
		m_torque += adj;
	}

	void power_control(float adj)
	{
		m_power += adj;
		cout << "Обороты увеличены на " << adj << '\n';
		cout << "Показания тахометра: " << m_power << '\n';

	}

	void fuel_control(float adj)
	{
		m_fuel += adj;
	}

	void start(float adj)
	{
		cout << "Двигатель запущен!\n";
		power_control(adj);
	}

	void stop() {
		m_power = 800;

		cout << "Остановка при оборотах " << m_power << "\n\n";

		m_power = 0;
		cout << "Двигатель остановлен!\n";
	}
};