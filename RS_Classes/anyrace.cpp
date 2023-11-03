#include "anyrace.h"
#include "vehicle.h"

#include <string>
#include <stdexcept>

AnyRace::AnyRace() {
	typeRace = "Гонка для наземного и воздушного транспорта";
	countRegVehicles = 0;
	distance = 0;
}

void AnyRace::setDistance(int distance) {
	if (distance <= 0) throw std::out_of_range("Введена неверная дистанция (должна быть положительна)");
	this->distance = distance;
}

int AnyRace::getDistance() { return distance; }
std::string AnyRace::getTypeRace() { return typeRace; }

void AnyRace::registerVehicle(Vehicle* vehicle) {
	// метод регистрации на гонку ТС, будет дополняться для наземных и воздушных гонок дополнительными исключениями
	if (vehicle == nullptr) throw std::domain_error("Транспортное средство не определено!");
	if (countRegVehicles == MAX_VEHICLES) throw std::domain_error("Превышено допустимое кол-во участников на гонке!");
	if (isRegistered(vehicle)) throw std::domain_error(vehicle->getName() + " уже зарегистрирован!");

	regVehicles[countRegVehicles++] = vehicle;
}

int AnyRace::getCountVehicles() {
	// возвращает кол-во зарегистрированных на гонку ТС
	return countRegVehicles;
}

std::string AnyRace::getListVehicles() {
	// возвращает список зарегистрированных ТС в одну строку
	std::string str = "";
	for (int i = 0; i < countRegVehicles; i++) {
		str += regVehicles[i]->getName();
		if (i < countRegVehicles - 1) str += ", ";
	}
	return str;
}

void AnyRace::startRace() {
	// метод старта симуляции гонки
	for (int i = 0; i < countRegVehicles; i++)
		regVehicles[i]->raceTimeCalculation(distance);
	sortListVehicles();
}

Vehicle* AnyRace::getVehicle(int number) {
	// возвращает указатель на ТС по номеру count из списка
	if (number > countRegVehicles) return nullptr;
	return regVehicles[number];
}


void AnyRace::deleteAllVehicles() {
	// удаляет все ТС из списка с освобождением памяти
	for (int i = 0; i < countRegVehicles; i++) delete regVehicles[i];
	countRegVehicles = 0;
}

bool AnyRace::isRegistered(Vehicle* vehicle) {
	// проверка повторной регистрации ТС
	for (int i = 0; i < countRegVehicles; i++)
		if (regVehicles[i]->getName() == vehicle->getName()) return true;
	return false;
}

void AnyRace::sortListVehicles() {
	// сортировка перечня ТС по времени финиширования
	Vehicle* temp;
	for (int i = 0; i < countRegVehicles; i++)
		for (int j = 0; j < countRegVehicles - i - 1; j++) {
			if (regVehicles[j]->getRaceTime() > regVehicles[j + 1]->getRaceTime()) {
				temp = regVehicles[j];
				regVehicles[j] = regVehicles[j + 1];
				regVehicles[j + 1] = temp;
			}
		}
}

AnyRace::~AnyRace() {
	// деструктор - удаляет гонку вместе со всеми ТС и освобождает память от них
	deleteAllVehicles();
}