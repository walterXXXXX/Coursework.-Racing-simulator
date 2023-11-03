#pragma once

#include <iostream>

// перечисление типов транспортных средств
enum class VehicleTypes {
	UNKNOWN_VEHICLE, // не известно, абстракция
	GOUND_VEHICLE, // наземное ТС
	AIR_VEHICLE // воздушное ТС
};

// родительский класс, описывающий интерфейс сущности "Транспортное Средство"

class Vehicle {
public:
	Vehicle(); // нам потребуется конструктор, в котором будем переопределять характеристики разных ТС в классах-потомках

	std::string getName(); // геттер названия ТС
	VehicleTypes getType(); // геттер типа ТС
	double getRaceTime(); // геттер расчитанного времени прохождения дистанции для сортировки и вывода

	virtual void raceTimeCalculation(int distance); // и метод расчета времени прохождения дистанции, для каждого ТС - будет своя реализация

protected:
	int velocoty; // скорость
	std::string name; // название ТС
	VehicleTypes type; // тип ТС (наземное, воздушное)
	double raceTime; // расчетное время прохождения дистанции
};

