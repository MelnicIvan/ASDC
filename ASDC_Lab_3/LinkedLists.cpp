#include <iostream>
#include <array>
#include <string_view>
#include <iomanip>
#include <cassert>
#include "ListLibrary.h"

using namespace StaticDataLibrary;


int main() {
	auto humans = createHumans();

	LinkedList list{};
	list.first = nullptr;
	list.last = nullptr;

	for (size_t i = 0; i < humans.size(); i++)
	{
		insertAfter(&list, nullptr, humans[i]);
	}

	printList(&list);

	std::array<char, MAX_SIZE> name("John");
	FindNodeResult userJohn = findByName(&list, name);
	if (userJohn.resultNode != nullptr) {
		if (userJohn.previousNode != nullptr) {
			std::cout << std::endl;
			printHumanInfo(userJohn.resultNode->human);
			std::cout << "User in list before John:\n";
			printHumanInfo(userJohn.previousNode->human);
		}
		else {
			printHumanInfo(userJohn.resultNode->human);
			std::cout << "User is the first person in list!";
		}
	}
	else {
		std::cout << "The user with given name is not in the list!!!" << std::endl;
	}
	insertAfter(&list, userJohn.previousNode, humans[5]);
	removeAfter(&list, userJohn.previousNode);
	printList(&list);

	std::cout << std::endl;
	assertNoCycles(&list);
	return 0;
}

