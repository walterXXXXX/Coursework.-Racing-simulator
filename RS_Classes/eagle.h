#pragma once

#include "airvehicle.h"

class Eagle : public AirVehicle {
public:
	Eagle();

	void raceTimeCalculation(int distance) override; // ������ ������� ����������� ��������� �� ���� "����"
};