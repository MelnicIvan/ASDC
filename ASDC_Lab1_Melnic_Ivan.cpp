#include <iostream>
#include <array>
#include <string_view>
#include <optional>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <span>
#include <chrono>

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

enum class ValidationResultKind {
	Valid = 0,
	HumanName_Empty = 1,
	HumanAge_NegativeOrTooLarge = 2,
	HumanGender_Empty = 3,
};

struct Branch {
	Human human;
	Branch* LeftBranch;
	Branch* RightBranch;
};

ValidationResultKind validateHuman(const Human& human);
bool serialize(std::ostream& out, const Human& human);
bool deserialize(std::istream& in, Human& human);
void printHumanCharacteristics(const Human& human);

int LinearSearchInUnsortedArray(std::span<Human> users, std::string_view name);
int BinarySearch(std::span<Human> users, std::string_view name);
int InterpolationSearch(std::span<Human> users, int age);
Branch* BinaryTreeSearch(Branch* aBranch, int age);

void Add(Human human, Branch*& aBranch);
void print(Branch* aBranch);
void FreeTree(Branch* aBranch);


using Func = int(*)(std::span<Human>, std::string_view);
using Func_ = int(*)(std::span<Human>, int age);
using Func__= Branch*(*)(Branch*, int age);


double functionExecutionTime(std::span<Human> people, std::string_view name, Func f);
double functionExecutionTime(std::span<Human> people, int age, Func_ f);
double functionExecutionTime(Branch* root, int age, Func__ f);

int main() {
	Human human{
		"John",
		30,
		Gender::MALE,
	};

	Human human_1{
		"Jessy",
		28,
		Gender::FEMALE,
	};

	Human human_3{
	"Bob",
	15,
	Gender::MALE,
	};

	Human human_4{
		"Marilin",
		25,
		Gender::FEMALE,
	};

	Human human_5{
		"Robert",
		45,
		Gender::MALE,
	};

	Human human_6{
		"Edward",
		50,
		Gender::MALE,
	};

	std::vector<Human> personalities;
	personalities.push_back(human);
	personalities.push_back(human_1);
	personalities.push_back(human_3);
	personalities.push_back(human_4);
	personalities.push_back(human_5);
	personalities.push_back(human_6);

	std::ofstream _file;
	_file.open("test.txt");

	if (_file.is_open()) {
		for (int i = 0; i < personalities.size(); i++) {
			if (!serialize(_file, personalities[i])) {
				std::cout << "An error uccured during serialization!" << std::endl;
				return -1;
			}
		}
	}
	else {
		std::cout << "File doesn't open!";
	}

	_file.close();

	std::vector<Human> people;
	Human human_;
	std::ifstream file;
	file.open("test.txt");
	if (file.is_open()) {
		while (deserialize(file, human_)) {
			printHumanCharacteristics(human_);
			people.push_back(human_);
		}
	}
	else {
		std::cout << "File doesn't open!";
	}

	file.close();

	//Algorithms for searching an unsorted array
	//Linear search in unsorted array
	std::cout << "\nWe search for a user with the name Marilin" << std::endl;
	std::string name = "Marilin";
	int indexOfUser = LinearSearchInUnsortedArray(people, name);
	if (indexOfUser == -1) {
		std::cout << "User " << name << " is not found!" << std::endl;
	}
	else {
		std::cout << "Index of user " << name << " is " << indexOfUser << std::endl;
	}

	//BinaryTree Search
	Branch* Root = 0;
	for (int i = 0; i < people.size(); i++) {
		Add(people[i], Root);
	}
	std::cout << std::endl;
	//print(Root);

	int _searchAge = 45;
	Branch* answerBranch = BinaryTreeSearch(Root, _searchAge);
	if(answerBranch != NULL){
		std::cout << "\Name of user with age " << answerBranch->human.age << " is " << std::string_view{ answerBranch->human.name.data() };
	}
	else {
		std::cout << "\nUser with age " << _searchAge << " is missing from the binary tree\n";
	}
	//FreeTree(Root);
	std::cout << std::endl;
	//==========================================//


	//Algorithms for searching in sorted array
	//BinarySearch
	std::sort(people.begin(), people.end(), [](const Human& a, const Human& b) {
		return a.name < b.name; });

	std::string_view _name{ "Edward" };

	int _indexOfUser = BinarySearch(people, _name);
	if (_indexOfUser == -1) {
		std::cout << "User " << _name << " is not found!" << std::endl;
	}
	else {
		std::cout << "\nIndex of user " << _name << " is " << _indexOfUser << std::endl;
	}


	//Interpolation Search
	std::sort(people.begin(), people.end(), [](const Human& a, const Human& b) {
		return a.age < b.age; });

	int searchAge = 28;
	int indexOfUser_ = InterpolationSearch(people, searchAge);

	if (indexOfUser_ == -1) {
		std::cout << "User with age " << searchAge << " is not found!" << std::endl;
	}
	else {
		std::cout << "\nIndex of user with age " << searchAge << " is " << indexOfUser_ << std::endl;
	}
	//==========================================//

	printf("\nTime for execution for function BinarySearch in sorted array: %.7f", functionExecutionTime(people, "Marilin", &BinarySearch));
	
	printf("\nTime for execution for function LinearSearch in unsorted array: %.7f", functionExecutionTime(people, "Marilin", &LinearSearchInUnsortedArray));
	printf("\nTime for execution for function InterpolationSearch in sorted array: %.7f", functionExecutionTime(people, 45, &InterpolationSearch));
	printf("\nTime for execution for function BinaryTreeSearch in unsorted array: %.7f", functionExecutionTime(Root, 28, &BinaryTreeSearch));


	FreeTree(Root);
	return 0;
}

void printHumanCharacteristics(const Human& human) {
	std::string human_gender;
	switch (human.gender) {
	case Gender::MALE:
		human_gender = "MALE";
		break;
	case Gender::FEMALE:
		human_gender = "FEMALE";
		break;
	default:
		std::cout << "Oops, an error has occurred in function printHumanCharacteristics";
	}
	std::cout << "\nHuman characteristics:\nName: " << std::string(human.name.data())
		<< "\nAge: " << human.age << "\nGender: " << human_gender << std::endl;
}

bool serialize(std::ostream& out, const Human& human) {
	//Проверка, если все поля объекта соответствуют условиям и нет никаких ошибок
	ValidationResultKind result = validateHuman(human);
	switch (result) {
	case ValidationResultKind::Valid:
		break;
	case ValidationResultKind::HumanName_Empty:
		std::cout << "String with name is empty!";
		return false;
	case ValidationResultKind::HumanAge_NegativeOrTooLarge:
		std::cout << "Age of human is incorrect!";
		return false;
	case ValidationResultKind::HumanGender_Empty:
		std::cout << "Human doesn't have gender!";
		return false;
	default:
		std::cout << "Some other error has occured";
		return false;
	}

	//Запись объекта в переданный поток
	for (auto elem : human.name) {
		if (elem == ',')
			return false;
	}

	std::string_view _name{ &human.name[0] };
	out << _name;
	out << ",";
	out << human.age;
	out << ",";
	out << static_cast<int>(human.gender);
	out << "\n";

	return true;
}

bool deserialize(std::istream& in, Human& human) {
	try {
		//Десериализуем поля объекта из заданного потока
		std::array<char, MAX_SIZE> str{};
		in.getline(str.data(), str.size(), ',');
		human.name = str;

		std::string token;
		std::getline(in, token, ',');
		human.age = std::stoi(token);

		std::string c;
		std::getline(in, c, '\n');
		char* gender(c.data());

		switch (*gender) {
		case '0':
			human.gender = Gender::MALE;
			break;
		case '1':
			human.gender = Gender::FEMALE;
			break;
		default:
			std::cout << "Invalid gender value";
			return false;
		}

		//Валидация десериализованных объектов из файла
		ValidationResultKind result = validateHuman(human);
		switch (result) {
		case ValidationResultKind::Valid:
			return true;
		case ValidationResultKind::HumanName_Empty:
			std::cout << "String with name is empty!";
			return false;
		case ValidationResultKind::HumanAge_NegativeOrTooLarge:
			std::cout << "Age of human is incorrect!";
			return false;
		case ValidationResultKind::HumanGender_Empty:
			std::cout << "Human doesn't have gender!";
			return false;
		default:
			std::cout << "Some other error has occured";
			return false;
		}
	}
	catch (std::exception e) {
		return false;
	}
	return true;
}


ValidationResultKind validateHuman(const Human& human) {
	//Проверка полей объекта Human
	if (human.name.empty()) {
		return ValidationResultKind::HumanName_Empty;
	}
	if (human.age < 0 || human.age > 120) {
		return ValidationResultKind::HumanAge_NegativeOrTooLarge;
	}
	if (human.gender != Gender::MALE && human.gender != Gender::FEMALE) {
		return ValidationResultKind::HumanGender_Empty;
	}
	return ValidationResultKind::Valid;
}

//Программирование методов поиска в неотсортированных массивах(линейный, бинарное дерево поиска)
//Программирование методов поиска в отсортированных массивах(бинарный, и один другой на выбор)
//Запись времени выполнения алгоритмов в зависимости от размера массива и расположения элементов 
//(в сортированном порядке, в порядке обратным этому, в слуайном порядке).


int LinearSearchInUnsortedArray(std::span<Human> users, std::string_view name) {
	int index = -1;
	for (int i = 0; i < users.size(); i++) {
		std::string_view nameOfUser{ &users[i].name[0] };
		if (nameOfUser == name) {
			index = i;
			return index;
		}
	}
	return index;
}

int BinarySearch(std::span<Human> users, std::string_view name) {
	int midd;
	int left = 0, right = users.size()-2;

	while (true) {
		midd = (left + right) / 2;
		std::string_view _name{ users[midd].name.data() };
		if (name < _name) {
			right = midd - 1;
		}
		else if (name > _name) {
			left = midd + 1;
		}
		else {
			return midd;
		}
		if (left > right)
			return -1;
	}

}

int InterpolationSearch(std::span<Human> users, int age) {
	int x = 0;
	int a = 0;
	int b = users.size() - 1;
	bool found;

	for (found = false; (users[a].age < age) && (users[b].age > age) && !found;) {
		int ageOffset = (age - users[a].age);
		int ageRange = (users[b].age - users[a].age);
		int indexRange = (b - a);

		int indexOffset = ageOffset * indexRange / ageRange;
		int projectedIndex = a + indexOffset;

		x = projectedIndex;
		if (users[x].age < age)
			a = x + 1;
		else if (users[x].age > age)
			b = x - 1;
		else
			found = true;
	}
	if (users[a].age == age)
		return a;
	else if (users[b].age == age)
		return b;
	else
		return -1;
}

void Add(Human human, Branch*& aBranch) {
	if (!aBranch) {
		aBranch = new Branch;
		aBranch->human = human;
		aBranch->LeftBranch = 0;
		aBranch->RightBranch = 0;
		return;
	}
	else {
		if (aBranch->human.age > human.age) {
			Add(human, aBranch->LeftBranch);
		}
		else {
			Add(human, aBranch->RightBranch);
		}
	}
}

int tabs = 0;
void print(Branch* aBranch) {
	if (!aBranch) return;
	tabs++;

	print(aBranch->LeftBranch);
	for (int i = 0; i < tabs; i++) std::cout << " ";
	std::cout << aBranch->human.age << std::endl;

	print(aBranch->RightBranch);
	tabs--;
	return;
}

void FreeTree(Branch* aBranch) {
	if (!aBranch) return;
	FreeTree(aBranch->LeftBranch);
	FreeTree(aBranch->RightBranch);
	delete aBranch;
	return;
}

Branch* BinaryTreeSearch(Branch* aBranch, int age) {
	if (aBranch == NULL) return NULL;
	if (aBranch->human.age == age) return aBranch;
	if (age < aBranch->human.age) return BinaryTreeSearch(aBranch->LeftBranch, age);
	else return BinaryTreeSearch(aBranch->RightBranch, age);
}

double functionExecutionTime(std::span<Human> people, std::string_view name, Func f) {
	clock_t start = clock();
	
	for(int i = 0; i < 100000; i++)
	f(people,name);

	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;

	return seconds;
}

double functionExecutionTime(std::span<Human> people, int age, Func_ f) {
	clock_t start = clock();

	for (int i = 0; i < 100000; i++)
		f(people, age);

	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;

	return seconds;
}


double functionExecutionTime(Branch* root, int age, Func__ f) {
	clock_t start = clock();

	for (int i = 0; i < 100000; i++)
		f(root, age);

	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;

	return seconds;
}