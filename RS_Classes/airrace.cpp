#include "airrace.h"

AirRace::AirRace() {
	typeRace = "����� ��� ���������� ����������";
}

void AirRace::registerVehicle(Vehicle* vehicle) {
	if (vehicle->getType() != VehicleTypes::AIR_VEHICLE)
		throw std::domain_error("������� ���������������� ������������ ��� ������������� ��������!");
	AnyRace::registerVehicle(vehicle);
}