#pragma once

#include "vehicle.h"

// ������������ ����� ��� ��������� ��

class AirVehicle : public Vehicle {
public:
	AirVehicle();

	// �.�. ���������� ������ ������� ����������� ��������� ����� ���������� ��� ������ ��,
	// ���������� ��� ��������������� � �������-�������� ��� ���������� ��
	// void raceTimeCalculation(int distance) override;
	
protected:
	int distanceReductionFactor; // ����������� ���������� ���������, � %

};