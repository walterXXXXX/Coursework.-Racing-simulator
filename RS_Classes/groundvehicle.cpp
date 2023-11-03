#include "groundvehicle.h"

GroundVehicle::GroundVehicle() {
	type = VehicleTypes::GOUND_VEHICLE; // класс для наземных ТС
	firstRestTime = 0;
	secondRestTime = 0;
	otherRestTime = 0;
	beforeRestTime = 0;
}

void GroundVehicle::raceTimeCalculation(int distance) {
	raceTime = distance / velocoty; // определяем время движения без учета отдыха
	int stopsCount = raceTime / beforeRestTime; // кол-во остановок для отдыха на всей дистанции
	if ((raceTime / beforeRestTime) == stopsCount) stopsCount--; // если последняя остановка пришлась на точку финиша, то последний отдых не считается 
	// расчитаем общее время, затраченное на отдых
	double restTime = 0;
	for (int i = 0; i < stopsCount; i++) {
		if (i == 0) restTime += firstRestTime;
		if (i == 1) restTime += secondRestTime;
		if (i > 1) restTime += otherRestTime;
	}

	raceTime += restTime; // итоговое время прохождения дистанции с учетом отдыха
}