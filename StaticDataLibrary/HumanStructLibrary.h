#pragma once

#include <iostream>
#include <vector>
#include <string_view>
#include <string>
#include <array>
#include <cassert>

namespace StaticDataLibrary {
	// === Constants ===
	const int MAX_SIZE = 10;


	// === Enumerations ===
	enum class Gender {
		MALE = 0,
		FEMALE = 1,
	};

	// === Neccessary structs ===
	struct Human {
		std::array<char, MAX_SIZE> name;
		int age;
		Gender gender;
	};

	// === Prototypes of functions ===
	std::vector<Human> createHumans();
	void printHumanInfo(const Human& human);

}