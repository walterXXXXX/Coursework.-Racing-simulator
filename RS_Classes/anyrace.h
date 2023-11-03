#pragma once

#include <string>

#include "vehicle.h"

// Класс, описывающий универсальный вид гонок для наземных и воздушных ТС
// Является родительским для классов наземной и воздушной гонки

class AnyRace {

#define MAX_VEHICLES 7 // максимальное кол-во ТС на гонке

public:
	AnyRace(); // конструктор

	void setDistance(int distance); // установить дистанцию гонки

	int getDistance(); // вернуть дистанцию гонки

	std::string getTypeRace(); // вернуть тип гонки

	virtual void registerVehicle(Vehicle* vehicle); // метод регистрации на гонку ТС, будет отличаться для разных видов гонок
	
	int getCountVehicles(); // возвращает кол-во зарегистрированных на гонку ТС

	std::string getListVehicles(); // возвращает список зарегистрированных ТС в одну строку

	void startRace(); // метод старта симуляции гонки

	Vehicle* getVehicle(int number); // возвращает указатель на ТС по номеру в списке 

	void deleteAllVehicles(); // удаляет все ТС из списка с освобождением памяти

	~AnyRace(); // деструктор - удаляет гонку вместе со всеми ТС и освобождает память от них

protected:

	std::string typeRace; // тип рейса

	int distance; // дистанция

	Vehicle* regVehicles[MAX_VEHICLES]; // массив указателей на зарегистрированные на гонку ТС

	int countRegVehicles; // кол-во зарегистрированных на гонку ТС

	bool isRegistered(Vehicle* vehicle); // проверка повторной регистрации ТС

	void sortListVehicles(); // сортировка перечня ТС по времени финиширования

};