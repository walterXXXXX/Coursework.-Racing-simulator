#include <iostream>
#include <string>
#include <stdexcept>

#include "RS_Classes/anyrace.h"
#include "RS_Classes/groundrace.h"
#include "RS_Classes/airrace.h"

#include "RS_Classes/vehicle.h"

#include "RS_Classes/groundvehicle.h"
#include "RS_Classes/camel.h"
#include "RS_Classes/hs_camel.h"
#include "RS_Classes/centaur.h"
#include "RS_Classes/at_boots.h"

#include "RS_Classes/airvehicle.h"
#include "RS_Classes/eagle.h"
#include "RS_Classes/carpetplane.h"
#include "RS_Classes/broom.h"

int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;

	Vehicle* vehicle = nullptr; 
	AnyRace* race = nullptr; 

	enum class Menu {
		CHOISE_RACE_TYPE, // меню выбора типа гонки
		INSERT_DISTANCE, // меню ввода дистанции
		START_RACE, // меню выбора старта гонки или регистрации доп. ТС
		REGISTER_VEHICLE, // меню регистрации дополнительного ТС
		RESULT_RACE, // меню отображения результатов гонки и выбора продолжить/выйти
		FINISH // выход из меню
	};

	Menu menu = Menu::CHOISE_RACE_TYPE;
	bool exitMenu = false;

	while (!exitMenu) {
		int distance = 0;
		int choice = 0;

		switch (menu) {

		// меню выбора типа гонки
		case Menu::CHOISE_RACE_TYPE:
			std::cout << "1. Гонка для наземного транспорта" << std::endl;
			std::cout << "2. Гонка для воздушного транспорта" << std::endl;
			std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
			std::cout << "Выберите тип гонки: ";
			std::cin >> choice;

			if (race != nullptr) delete race;
			if ((choice >= 1) && (choice <= 3)) {
				if (choice == 1) race = new GroundRace;
				if (choice == 2) race = new AirRace;
				if (choice == 3) race = new AnyRace;
				menu = Menu::INSERT_DISTANCE;
			}
			else
				std::cout << "Неверный ввод";
			std::cout << std::endl << std::endl;
		break;

		// меню ввода дистанции
		case Menu::INSERT_DISTANCE:
			std::cout << "Укажите длину дистанции (должна быть положительна): ";
			std::cin >> distance;
			try {
				race->setDistance(distance);
				menu = Menu::START_RACE;
			}
			catch (const std::out_of_range& ex) {
				std::cout << ex.what() << std::endl;
			}
			std::cout << std::endl << std::endl;
		break;

		// меню выбора старта гонки или регистрации доп. ТС
		case Menu::START_RACE:
			if (race->getCountVehicles() < 2)
				std::cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << std::endl;
			std::cout << "1. Зарегистрировать транспорт" << std::endl;
			if (race->getCountVehicles() >= 2) std::cout << "2. Начать гонку" << std::endl;
			std::cout << "Выберите действие: ";
			std::cin >> choice;
			if (choice == 1) menu = Menu::REGISTER_VEHICLE; else
				if ((choice == 2) && (race->getCountVehicles() >= 2)) menu = Menu::RESULT_RACE; else
					std::cout << "Ошибка, неверный ввод. Повторите";
			std::cout << std::endl << std::endl;
		break;

		// меню регистрации ТС на гонку
		case Menu::REGISTER_VEHICLE:
			//Вывод информации о гонке
			std::cout << race->getTypeRace() << ". Расстояние: " << race->getDistance() << std::endl;
			if (race->getCountVehicles() > 0) std::cout << "Зарегистрированные транспортные средства: " << race->getListVehicles() << std::endl;

			std::cout << "1. Ботинки-вездеходы" << std::endl;
			std::cout << "2. Метла" << std::endl;
			std::cout << "3. Верблюд" << std::endl;
			std::cout << "4. Кентавр" << std::endl;
			std::cout << "5. Орел" << std::endl;
			std::cout << "6. Верблюд-быстроход" << std::endl;
			std::cout << "7. Ковёр-самолёт" << std::endl;
			std::cout << "0. Закончить регистрацию" << std::endl;
			std::cout << "Выберите траспорт или 0 для окончания процесса регистрации: ";
			std::cin >> choice;
			std::cout << std::endl << std::endl;

			if ((choice < 0) || (choice > 7)) std::cout << "Ошибка, неверный ввод. Повторите" << std::endl;
			else if (choice == 0) menu = Menu::START_RACE;
			else {
				if (choice == 1) vehicle = new AT_Boots;
				if (choice == 2) vehicle = new Broom;
				if (choice == 3) vehicle = new Camel;
				if (choice == 4) vehicle = new Centaur;
				if (choice == 5) vehicle = new Eagle;
				if (choice == 6) vehicle = new HS_Camel;
				if (choice == 7) vehicle = new CarpetPlane;
				try {
					race->registerVehicle(vehicle);
					std::cout << vehicle->getName() << " успешно зарегистрирован!" << std::endl;
				}
				catch (const std::domain_error ex) {
					std::cout << ex.what() << std::endl;
					delete vehicle;
				}
			}

		break;

		// меню отображения результатов гонки и выбора продолжить/выйти
		case Menu::RESULT_RACE:
			std::cout << "Результаты гонки:" << std::endl;
			race->startRace();
			for (int i = 0; i < race->getCountVehicles(); i++) {
				std::cout << (i + 1) << ". " << race->getVehicle(i)->getName() << ". Время: " << race->getVehicle(i)->getRaceTime() << std::endl;
			}
			std::cout << std::endl;

			delete race;
			race = nullptr;
			vehicle = nullptr;

			while (1) {
				std::cout << "1. Провести еще одну гонку" << std::endl;
				std::cout << "2. Выйти" << std::endl;
				std::cout << "Выберите действие: ";
				std::cin >> choice;
				if (choice == 1) { menu = Menu::CHOISE_RACE_TYPE; std::cout << std::endl << std::endl;  break; }
				if (choice == 2) { exitMenu = true; break; }
				std::cout << "Ошибка, неверный ввод. Повторите!" << std::endl;
			}
		break;
		}
	}
	return 0;
}