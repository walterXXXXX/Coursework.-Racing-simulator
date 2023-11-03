#include "anyrace.h"
#include "vehicle.h"

#include <string>
#include <stdexcept>

AnyRace::AnyRace() {
	typeRace = "����� ��� ��������� � ���������� ����������";
	countRegVehicles = 0;
	distance = 0;
}

void AnyRace::setDistance(int distance) {
	if (distance <= 0) throw std::out_of_range("������� �������� ��������� (������ ���� ������������)");
	this->distance = distance;
}

int AnyRace::getDistance() { return distance; }
std::string AnyRace::getTypeRace() { return typeRace; }

void AnyRace::registerVehicle(Vehicle* vehicle) {
	// ����� ����������� �� ����� ��, ����� ����������� ��� �������� � ��������� ����� ��������������� ������������
	if (vehicle == nullptr) throw std::domain_error("������������ �������� �� ����������!");
	if (countRegVehicles == MAX_VEHICLES) throw std::domain_error("��������� ���������� ���-�� ���������� �� �����!");
	if (isRegistered(vehicle)) throw std::domain_error(vehicle->getName() + " ��� ���������������!");

	regVehicles[countRegVehicles++] = vehicle;
}

int AnyRace::getCountVehicles() {
	// ���������� ���-�� ������������������ �� ����� ��
	return countRegVehicles;
}

std::string AnyRace::getListVehicles() {
	// ���������� ������ ������������������ �� � ���� ������
	std::string str = "";
	for (int i = 0; i < countRegVehicles; i++) {
		str += regVehicles[i]->getName();
		if (i < countRegVehicles - 1) str += ", ";
	}
	return str;
}

void AnyRace::startRace() {
	// ����� ������ ��������� �����
	for (int i = 0; i < countRegVehicles; i++)
		regVehicles[i]->raceTimeCalculation(distance);
	sortListVehicles();
}

Vehicle* AnyRace::getVehicle(int number) {
	// ���������� ��������� �� �� �� ������ count �� ������
	if (number > countRegVehicles) return nullptr;
	return regVehicles[number];
}


void AnyRace::deleteAllVehicles() {
	// ������� ��� �� �� ������ � ������������� ������
	for (int i = 0; i < countRegVehicles; i++) delete regVehicles[i];
	countRegVehicles = 0;
}

bool AnyRace::isRegistered(Vehicle* vehicle) {
	// �������� ��������� ����������� ��
	for (int i = 0; i < countRegVehicles; i++)
		if (regVehicles[i]->getName() == vehicle->getName()) return true;
	return false;
}

void AnyRace::sortListVehicles() {
	// ���������� ������� �� �� ������� �������������
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
	// ���������� - ������� ����� ������ �� ����� �� � ����������� ������ �� ���
	deleteAllVehicles();
}