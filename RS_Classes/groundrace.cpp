#include "groundrace.h"

GroundRace::GroundRace() {
	typeRace = "����� ��� ��������� ����������";
}

void GroundRace::registerVehicle(Vehicle* vehicle) {
	if (vehicle->getType() != VehicleTypes::GOUND_VEHICLE) 
		throw std::domain_error("������� ���������������� ������������ ��� ������������� ��������!");
	AnyRace::registerVehicle(vehicle);
}