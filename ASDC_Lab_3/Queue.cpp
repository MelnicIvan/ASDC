//#include<iostream>
//#include <array>
//#include <iomanip>
// #include "Shared.h"
//
//const int MAX_SIZE = 10;
//
//enum class Gender {
//	MALE = 0,
//	FEMALE = 1,
//};
//
//struct Human {
//	std::array<char, MAX_SIZE> name;
//	int age;
//	Gender gender;
//};
//
//struct Node {
//	Human human;
//	struct Node* next;
//};
//
//struct Queue {
//	Node* first;
//	Node* last;
//	int countOfNodesInQueue = 0;
//};
//
//void enqueue(Queue* queue, Human human);
//Node* dequeue(Queue* queue);
//bool isEmpty(Queue* queue);
//void printQueue(Queue* queue);
//void printHumanInfo(Human human);
//
//
//int main() {
//	Human human{
//				"John",
//				30,
//				Gender::MALE,
//	};
//
//	Human human_1{
//		"Jessy",
//		28,
//		Gender::FEMALE,
//	};
//
//	Human human_2{
//	"Bob",
//	15,
//	Gender::MALE,
//	};
//
//	Human human_3{
//		"Marilin",
//		25,
//		Gender::FEMALE,
//	};
//
//	Human human_4{
//		"Robert",
//		45,
//		Gender::MALE,
//	};
//
//	Human human_5{
//		"Edward",
//		50,
//		Gender::MALE,
//	};
//
//	Human human_6{
//	"Ivan",
//	20,
//	Gender::MALE,
//	};
//
//	Queue* queue = new Queue;
//	queue->first = nullptr;
//	queue->last = nullptr;
//
//	enqueue(queue, human);
//	enqueue(queue, human_1);
//	enqueue(queue, human_2);
//	enqueue(queue, human_3);
//	enqueue(queue, human_4);
//
//	printQueue(queue);
//	Node* queueNode = dequeue(queue);
//	std::cout << "First person from Queue: \n";
//	printHumanInfo(queueNode->human);
//	delete queueNode;
//
//	printQueue(queue);
//
//	return 0;
//}
//
////Добавляет элемент в конец очереди
//void enqueue(Queue* queue, Human human) {
//	Node* tempPtr = new Node;
//	tempPtr->human = human;
//	tempPtr->next = nullptr;
//
//	if (isEmpty(queue)) {
//		queue->first = tempPtr;
//		queue->last = tempPtr;
//		queue->countOfNodesInQueue++;
//		return;
//	}
//
//	Node* currentPtr = queue->first;
//
//	while (currentPtr) {
//		if (currentPtr->next == nullptr) {
//			tempPtr->next = nullptr;
//			queue->last = tempPtr;
//			currentPtr->next = tempPtr;
//			queue->countOfNodesInQueue++;
//			return;
//		}
//		currentPtr = currentPtr->next;
//	}
//}
//
////Удаляет элемент из начала очереди и возвращает его
//Node* dequeue(Queue* queue) {
//	if (isEmpty(queue)) {
//		std::cout << "Queue is empty!!!" << std::endl;
//		return nullptr;
//	}
//	if (queue == nullptr || queue->first == nullptr) {
//		return nullptr; 
//	}
//	Node* resultNode = queue->first;
//	queue->first = resultNode->next;
//	return resultNode;
//}
//
////Возвращает true если очередь пуста, иначе false
//bool isEmpty(Queue* queue) {
//	return queue->first == nullptr;
//}
//
//void printQueue(Queue* queue) {
//	if (isEmpty(queue)) {
//		std::cout << "Queue is empty!!!" << std::endl;
//		return;
//	}
//	int count = 1;
//
//	Node* currentNode = queue->first;
//
//	std::cout << std::left << std::setw(3) << "#" << std::setw(10) << "Name" << std::setw(7) << "Age" << std::setw(2) << "Gender" << std::endl;
//	while (currentNode) {
//		std::string_view humanName{ currentNode->human.name.data() };
//		std::string gender = static_cast<int>(currentNode->human.gender) ? "FEMALE" : "MALE";
//		std::cout << std::setw(3) << count++ << std::setw(10) << humanName << std::setw(7) << currentNode->human.age << std::setw(4) << gender << std::endl;
//		currentNode = currentNode->next;
//	}
//}
//
//void printHumanInfo(Human human) {
//	//Как проверить, если human не содержит мусор
//	std::string_view humanName{ human.name.data() };
//	std::string gender = static_cast<int>(human.gender) ? "FEMALE" : "MALE";
//	std::cout << "Name: " << humanName << "\nAge: " << human.age << "\nGender: " << gender << std::endl;
//}