#pragma once

#include "vehicle.h"

// ������������ ����� ��� �������� ��

class GroundVehicle : public Vehicle {
public:
	GroundVehicle();

	void raceTimeCalculation(int distance) override; // ������� ������� ����������� ��������� �������� ��, ����� ���������� ��� ���� �������� ��

protected:
	double firstRestTime; // ������������ ������ ������ ���
	double secondRestTime; // ������������ ������ ������ ���
	double otherRestTime; // ������������ ������ ��� ����������� ����
	double beforeRestTime; // ����� �������� �� ������
};