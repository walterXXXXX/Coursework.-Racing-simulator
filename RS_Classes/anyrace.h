#pragma once

#include <string>

#include "vehicle.h"

// �����, ����������� ������������� ��� ����� ��� �������� � ��������� ��
// �������� ������������ ��� ������� �������� � ��������� �����

class AnyRace {

#define MAX_VEHICLES 7 // ������������ ���-�� �� �� �����

public:
	AnyRace(); // �����������

	void setDistance(int distance); // ���������� ��������� �����

	int getDistance(); // ������� ��������� �����

	std::string getTypeRace(); // ������� ��� �����

	virtual void registerVehicle(Vehicle* vehicle); // ����� ����������� �� ����� ��, ����� ���������� ��� ������ ����� �����
	
	int getCountVehicles(); // ���������� ���-�� ������������������ �� ����� ��

	std::string getListVehicles(); // ���������� ������ ������������������ �� � ���� ������

	void startRace(); // ����� ������ ��������� �����

	Vehicle* getVehicle(int number); // ���������� ��������� �� �� �� ������ � ������ 

	void deleteAllVehicles(); // ������� ��� �� �� ������ � ������������� ������

	~AnyRace(); // ���������� - ������� ����� ������ �� ����� �� � ����������� ������ �� ���

protected:

	std::string typeRace; // ��� �����

	int distance; // ���������

	Vehicle* regVehicles[MAX_VEHICLES]; // ������ ���������� �� ������������������ �� ����� ��

	int countRegVehicles; // ���-�� ������������������ �� ����� ��

	bool isRegistered(Vehicle* vehicle); // �������� ��������� ����������� ��

	void sortListVehicles(); // ���������� ������� �� �� ������� �������������

};