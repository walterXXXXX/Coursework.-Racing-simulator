#include "groundvehicle.h"

GroundVehicle::GroundVehicle() {
	type = VehicleTypes::GOUND_VEHICLE; // ����� ��� �������� ��
	firstRestTime = 0;
	secondRestTime = 0;
	otherRestTime = 0;
	beforeRestTime = 0;
}

void GroundVehicle::raceTimeCalculation(int distance) {
	raceTime = distance / velocoty; // ���������� ����� �������� ��� ����� ������
	int stopsCount = raceTime / beforeRestTime; // ���-�� ��������� ��� ������ �� ���� ���������
	if ((raceTime / beforeRestTime) == stopsCount) stopsCount--; // ���� ��������� ��������� �������� �� ����� ������, �� ��������� ����� �� ��������� 
	// ��������� ����� �����, ����������� �� �����
	double restTime = 0;
	for (int i = 0; i < stopsCount; i++) {
		if (i == 0) restTime += firstRestTime;
		if (i == 1) restTime += secondRestTime;
		if (i > 1) restTime += otherRestTime;
	}

	raceTime += restTime; // �������� ����� ����������� ��������� � ������ ������
}