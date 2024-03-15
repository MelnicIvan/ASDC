//#include <iostream>
//#include <array>
//#include <string_view>
//#include <iomanip>
//#include <cassert>
//#include "Shared.h"
//
//
//Node* insertAfter(LinkedList* list, Node* node, Human human);
//FindNodeResult findByName(LinkedList* list, std::array<char, MAX_SIZE> name);
//void removeAfter(LinkedList* list, Node* node);
//void assertNoCycles(LinkedList* list);
//int numberOfNodesInTheList(LinkedList* list);
//void printList(LinkedList* list);
//bool isEmpty(LinkedList* list);
//void printHumanInfo(const Human& human);
//
//int main() {
//	auto humans = createHumans();
//
//	LinkedList list{};
//	list.first = nullptr;
//	list.last = nullptr;
//
//	for (size_t i = 0; i < humans.size(); i++)
//	{
//		insertAfter(&list, nullptr, humans[i]);
//	}
//
//	printList(&list);
//
//	std::array<char, MAX_SIZE> name("John");
//	FindNodeResult userJohn = findByName(&list, name);
//	if (userJohn.resultNode != nullptr) {
//		if (userJohn.previousNode != nullptr) {
//			std::cout << std::endl;
//			printHumanInfo(userJohn.resultNode->human);
//			std::cout << "User in list before John:\n";
//			printHumanInfo(userJohn.previousNode->human);
//		}
//		else {
//			printHumanInfo(userJohn.resultNode->human);
//			std::cout << "User is the first person in list!";
//		}
//	}
//	else {
//		std::cout << "The user with given name is not in the list!!!" << std::endl;
//	}
//	insertAfter(&list, userJohn.previousNode, humans[5]);
//	removeAfter(&list, userJohn.previousNode);
//	printList(&list);
//
//	std::cout << std::endl;
//	assertNoCycles(&list);
//	return 0;
//}
//
//bool isEmpty(LinkedList* list) {
//	return list->first == nullptr;
//}
//
//
////Cоздает новый нод и добавл€ет его после данного нода. 
//// ¬ случае если node == nullptr, нод добавл€етс€ в начало списка. 
//// ¬озвращает указатель на созданный нод;
//Node* insertAfter(LinkedList* list, Node* node, Human human) {
//	Node* tempPtr = new Node;
//	tempPtr->human = human;
//	tempPtr->next = nullptr;
//
//	if (isEmpty(list)) {
//		list->first = tempPtr;
//		list->last = tempPtr;
//		list->countOfNodesInList++;
//		return list->first;
//	}
//
//	if (node == nullptr) {
//		tempPtr->next = list->first;
//		list->first = tempPtr;
//		list->countOfNodesInList++;
//		return list->first;
//	}
//
//	//Ќужно ли тут при помощи while добиратьс€ до заданного нода?
//	tempPtr->next = node->next;
//	node->next = tempPtr;
//	list->countOfNodesInList++;
//	return node->next;
//}
//
//void printList(LinkedList* list) {
//	if (isEmpty(list)) {
//		std::cout << "List is empty!!!" << std::endl;
//		return;
//	}
//	int count = 1;
//
//	Node* currentNode = list->first;
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
//
////»щет нод до нода с заданным значением в списке; 
//// ¬озвращает нод с этим значением, а также нод до него.
//FindNodeResult findByName(LinkedList* list, std::array<char, MAX_SIZE> name) {
//	Node* currentNode = list->first;
//	Node* previousNode = nullptr;
//
//	if (isEmpty(list)) {
//		std::cout << "List is empty!!!" << std::endl;
//	}
//
//	while (currentNode) {
//		if (currentNode->human.name == name && currentNode == list->first) {
//			return FindNodeResult(currentNode, nullptr);
//		}
//		if (currentNode->human.name == name) {
//			return FindNodeResult(currentNode, previousNode);
//		}
//
//		previousNode = currentNode;
//		currentNode = currentNode->next;
//	}
//
//	return FindNodeResult(nullptr, nullptr);
//}
//
////”дал€ет нод следующий данному ноду из списка
//void removeAfter(LinkedList* list, Node* node) {
//	if (isEmpty(list)) {
//		std::cout << "List is empty!!!" << std::endl;
//		return;
//	}
//
//	Node* nodeForRemove;
//	if (node == nullptr || node == list->first) {
//		nodeForRemove = list->first;
//		list->first = nodeForRemove->next;
//		delete nodeForRemove;
//		list->countOfNodesInList--;
//		return;
//	}
//	else {
//		Node* currentNode = list->first;
//		Node* previousNode = nullptr;
//		while (currentNode) {
//			if (currentNode == node) {
//				nodeForRemove = currentNode;
//				previousNode->next = currentNode->next;
//				delete nodeForRemove;
//				list->countOfNodesInList--;
//				//”точнить по поводу return 
//				return;
//			}
//			previousNode = currentNode;
//			currentNode = currentNode->next;
//		}
//	}
//}
//
////ѕровер€ет, чтобы в списке не было циклов
//void assertNoCycles(LinkedList* list) {
//	Node* currentNode = list->first;
//	int currentNumberOfNodes = 0;
//	while (currentNode) {
//		assert(!(currentNumberOfNodes > list->countOfNodesInList));
//		currentNumberOfNodes++;
//		currentNode = currentNode->next;
//	}
//}
//
//void printHumanInfo(const Human& human) {
//	std::string_view humanName{ human.name.data() };
//	std::string gender = static_cast<int>(human.gender) ? "FEMALE" : "MALE";
//	std::cout << "Name: " << humanName << "\nAge: " << human.age << "\nGender: " << gender << std::endl;
//}
//
