#include "groundrace.h"

GroundRace::GroundRace() {
	typeRace = "Гонка для наземного транспорта";
}

void GroundRace::registerVehicle(Vehicle* vehicle) {
	if (vehicle->getType() != VehicleTypes::GOUND_VEHICLE) 
		throw std::domain_error("Попытка зарегистрировать неправильный тип транспортного средства!");
	AnyRace::registerVehicle(vehicle);
}