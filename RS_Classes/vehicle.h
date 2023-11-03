#pragma once

#include <iostream>

// ������������ ����� ������������ �������
enum class VehicleTypes {
	UNKNOWN_VEHICLE, // �� ��������, ����������
	GOUND_VEHICLE, // �������� ��
	AIR_VEHICLE // ��������� ��
};

// ������������ �����, ����������� ��������� �������� "������������ ��������"

class Vehicle {
public:
	Vehicle(); // ��� ����������� �����������, � ������� ����� �������������� �������������� ������ �� � �������-��������

	std::string getName(); // ������ �������� ��
	VehicleTypes getType(); // ������ ���� ��
	double getRaceTime(); // ������ ������������ ������� ����������� ��������� ��� ���������� � ������

	virtual void raceTimeCalculation(int distance); // � ����� ������� ������� ����������� ���������, ��� ������� �� - ����� ���� ����������

protected:
	int velocoty; // ��������
	std::string name; // �������� ��
	VehicleTypes type; // ��� �� (��������, ���������)
	double raceTime; // ��������� ����� ����������� ���������
};

