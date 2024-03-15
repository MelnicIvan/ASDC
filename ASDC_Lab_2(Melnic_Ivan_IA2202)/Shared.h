#pragma once
#include <vector>

const int MAX_SIZE = 10;

enum class Gender {
	MALE = 0,
	FEMALE = 1,
};

struct Human {
	std::array<char, MAX_SIZE> name;
	int age;
	Gender gender;
};

struct Node {
	Human human;
	struct Node* next;
};

struct LinkedList {
	Node* first;
	Node* last;
	int countOfNodesInList = 0;
};

struct FindNodeResult {
	Node* resultNode;
	Node* previousNode;
};

static std::vector<Human> createHumans()
{
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