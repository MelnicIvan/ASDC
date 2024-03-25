#include "HumanStructLibrary.h"

namespace StaticDataLibrary {

	//Данные для функции(Объекты Human)
	// createHumans() возвращает вектор объектов
	std::vector<Human> createHumans() {
		std::vector<Human> result;
		result.push_back({
			"John",
			30,
			Gender::MALE,
			});

		result.push_back({
			"Jessy",
			28,
			Gender::FEMALE,
			});

		result.push_back({
		"Bob",
		15,
		Gender::MALE,
			});

		result.push_back({
		"Marilin",
			25,
			Gender::FEMALE,
			}
		);

		result.push_back({
			"Robert",
			45,
			Gender::MALE,
			});

		result.push_back({
			"Edward",
			50,
			Gender::MALE,
			});

		result.push_back({
		"Ivan",
		20,
		Gender::MALE,
			});

		return result;
	}


	//Функция для печати информации объекта Human
	void printHumanInfo(const Human& human) {
		std::string_view humanName{ human.name.data() };
		std::string gender = static_cast<int>(human.gender) ? "FEMALE" : "MALE";
		std::cout << "Name: " << humanName << "\nAge: " << human.age << "\nGender: " << gender << std::endl;
	}


}