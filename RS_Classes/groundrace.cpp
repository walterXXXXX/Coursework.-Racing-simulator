#include "groundrace.h"

GroundRace::GroundRace() {
	typeRace = "√онка дл€ наземного транспорта";
}

void GroundRace::registerVehicle(Vehicle* vehicle) {
	if (vehicle->getType() != VehicleTypes::GOUND_VEHICLE) 
		throw std::domain_error("ѕопытка зарегистрировать неправильный тип транспортного средства!");
	AnyRace::registerVehicle(vehicle);
}