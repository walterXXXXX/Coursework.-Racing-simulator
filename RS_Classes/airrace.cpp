#include "airrace.h"

AirRace::AirRace() {
	typeRace = "Гонка для воздушного транспорта";
}

void AirRace::registerVehicle(Vehicle* vehicle) {
	if (vehicle->getType() != VehicleTypes::AIR_VEHICLE)
		throw std::domain_error("Попытка зарегистрировать неправильный тип транспортного средства!");
	AnyRace::registerVehicle(vehicle);
}