#pragma once

#include "airvehicle.h"

class Broom : public AirVehicle {
public:
	Broom();

	void raceTimeCalculation(int distance) override; // ������ ������� ����������� ��������� �� ���� "�����"
};