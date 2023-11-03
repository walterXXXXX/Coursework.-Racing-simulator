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
	std::cout << "����� ���������� � �������� ���������!" << std::endl;

	Vehicle* vehicle = nullptr; 
	AnyRace* race = nullptr; 

	enum class Menu {
		CHOISE_RACE_TYPE, // ���� ������ ���� �����
		INSERT_DISTANCE, // ���� ����� ���������
		START_RACE, // ���� ������ ������ ����� ��� ����������� ���. ��
		REGISTER_VEHICLE, // ���� ����������� ��������������� ��
		RESULT_RACE, // ���� ����������� ����������� ����� � ������ ����������/�����
		FINISH // ����� �� ����
	};

	Menu menu = Menu::CHOISE_RACE_TYPE;
	bool exitMenu = false;

	while (!exitMenu) {
		int distance = 0;
		int choice = 0;

		switch (menu) {

		// ���� ������ ���� �����
		case Menu::CHOISE_RACE_TYPE:
			std::cout << "1. ����� ��� ��������� ����������" << std::endl;
			std::cout << "2. ����� ��� ���������� ����������" << std::endl;
			std::cout << "3. ����� ��� ��������� � ���������� ����������" << std::endl;
			std::cout << "�������� ��� �����: ";
			std::cin >> choice;

			if (race != nullptr) delete race;
			if ((choice >= 1) && (choice <= 3)) {
				if (choice == 1) race = new GroundRace;
				if (choice == 2) race = new AirRace;
				if (choice == 3) race = new AnyRace;
				menu = Menu::INSERT_DISTANCE;
			}
			else
				std::cout << "�������� ����";
			std::cout << std::endl << std::endl;
		break;

		// ���� ����� ���������
		case Menu::INSERT_DISTANCE:
			std::cout << "������� ����� ��������� (������ ���� ������������): ";
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

		// ���� ������ ������ ����� ��� ����������� ���. ��
		case Menu::START_RACE:
			if (race->getCountVehicles() < 2)
				std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������" << std::endl;
			std::cout << "1. ���������������� ���������" << std::endl;
			if (race->getCountVehicles() >= 2) std::cout << "2. ������ �����" << std::endl;
			std::cout << "�������� ��������: ";
			std::cin >> choice;
			if (choice == 1) menu = Menu::REGISTER_VEHICLE; else
				if ((choice == 2) && (race->getCountVehicles() >= 2)) menu = Menu::RESULT_RACE; else
					std::cout << "������, �������� ����. ���������";
			std::cout << std::endl << std::endl;
		break;

		// ���� ����������� �� �� �����
		case Menu::REGISTER_VEHICLE:
			//����� ���������� � �����
			std::cout << race->getTypeRace() << ". ����������: " << race->getDistance() << std::endl;
			if (race->getCountVehicles() > 0) std::cout << "������������������ ������������ ��������: " << race->getListVehicles() << std::endl;

			std::cout << "1. �������-���������" << std::endl;
			std::cout << "2. �����" << std::endl;
			std::cout << "3. �������" << std::endl;
			std::cout << "4. �������" << std::endl;
			std::cout << "5. ����" << std::endl;
			std::cout << "6. �������-���������" << std::endl;
			std::cout << "7. ����-������" << std::endl;
			std::cout << "0. ��������� �����������" << std::endl;
			std::cout << "�������� �������� ��� 0 ��� ��������� �������� �����������: ";
			std::cin >> choice;
			std::cout << std::endl << std::endl;

			if ((choice < 0) || (choice > 7)) std::cout << "������, �������� ����. ���������" << std::endl;
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
					std::cout << vehicle->getName() << " ������� ���������������!" << std::endl;
				}
				catch (const std::domain_error ex) {
					std::cout << ex.what() << std::endl;
					delete vehicle;
				}
			}

		break;

		// ���� ����������� ����������� ����� � ������ ����������/�����
		case Menu::RESULT_RACE:
			std::cout << "���������� �����:" << std::endl;
			race->startRace();
			for (int i = 0; i < race->getCountVehicles(); i++) {
				std::cout << (i + 1) << ". " << race->getVehicle(i)->getName() << ". �����: " << race->getVehicle(i)->getRaceTime() << std::endl;
			}
			std::cout << std::endl;

			delete race;
			race = nullptr;
			vehicle = nullptr;

			while (1) {
				std::cout << "1. �������� ��� ���� �����" << std::endl;
				std::cout << "2. �����" << std::endl;
				std::cout << "�������� ��������: ";
				std::cin >> choice;
				if (choice == 1) { menu = Menu::CHOISE_RACE_TYPE; std::cout << std::endl << std::endl;  break; }
				if (choice == 2) { exitMenu = true; break; }
				std::cout << "������, �������� ����. ���������!" << std::endl;
			}
		break;
		}
	}
	return 0;
}