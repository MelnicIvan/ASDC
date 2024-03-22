//#include <iostream>
//#include <array>
//#include <iomanip>
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
//	Node* next;
//	Node* prev;
//};
//
//struct LinkedList {
//	Node* first;
//	Node* last;
//	int countOfNodesInList = 0;
//};
//
//Node* insertAfter(LinkedList* list, Node* node, Human human);
//Node* insertBefore(LinkedList* list, Node* node, Human human);
//Node* find(LinkedList* list, Human human);
//void remove(LinkedList* list, Node* node);
//void assertNoCycles(LinkedList* list);
//void printList(LinkedList* list);
//int numberOfNodesInTheList(LinkedList* list);
//
//
//int main() {
//	Human human{
//	"John",
//	30,
//	Gender::MALE,
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
//	LinkedList* doubleLinkedList = new LinkedList;
//	doubleLinkedList->first = doubleLinkedList->last = nullptr;
//
//	insertAfter(doubleLinkedList, nullptr, human);
//	insertAfter(doubleLinkedList, nullptr, human_1);
//	insertAfter(doubleLinkedList, nullptr, human_2);
//	insertAfter(doubleLinkedList, nullptr, human_3);
//	insertBefore(doubleLinkedList, nullptr, human_4);
//	insertBefore(doubleLinkedList, doubleLinkedList->first->next, human_5);
//	insertBefore(doubleLinkedList, doubleLinkedList->first->next, human_6);
//	remove(doubleLinkedList, doubleLinkedList->first->next);
//	printList(doubleLinkedList);
//	assertNoCycles(doubleLinkedList);
//
//	return 0;
//}
//
//bool isEmpty(LinkedList* list) {
//	return list->first == nullptr;
//}
//
//Node* insertAfter(LinkedList* list, Node* node, Human human) {
//	Node* tempPtr = new Node;
//	tempPtr->human = human;
//	tempPtr->next = nullptr;
//	tempPtr->prev = nullptr;
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
//		tempPtr->prev = nullptr;
//		list->first = tempPtr;
//		list->countOfNodesInList++;
//		return list->first;
//	}
//
//	//Нужно ли тут при помощи while добираться до заданного нода?
//	tempPtr->next = node->next;
//	tempPtr->prev = node;
//	node->next = tempPtr;
//	list->countOfNodesInList++;
//	return node->next;
//}
//
//Node* insertBefore(LinkedList* list, Node* node, Human human) {
//	Node* tempPtr = new Node;
//	tempPtr->human = human;
//
//	if (isEmpty(list)) {
//		list->first = tempPtr;
//		list->last = tempPtr;
//		tempPtr->next = tempPtr->prev = nullptr;
//		list->countOfNodesInList++;
//		return list->first;
//	}
//	if (node == nullptr) {
//		tempPtr->next = list->first;
//		tempPtr->prev = nullptr;
//		list->first = tempPtr;
//		list->countOfNodesInList++;
//		return list->first;
//	}
//
//	Node* currentNode = list->first;
//	Node* previousNode = nullptr;
//	while (currentNode) {
//		if (currentNode == node) {
//			previousNode->next = tempPtr;
//			tempPtr->prev = previousNode;
//			tempPtr->next = currentNode;
//			currentNode->prev = tempPtr;
//			list->countOfNodesInList++;
//			return tempPtr;
//		}
//		previousNode = currentNode;
//		currentNode = currentNode->next;
//	}
//}
//
//	void remove(LinkedList * list, Node * node) {
//		Node* nodeForRemove = node;
//		Node* currentNode = list->first;
//		Node* previousNode = nullptr;
//
//		if (isEmpty(list)) {
//			std::cout << "List is empty!!!" << std::endl;
//			return;
//		}
//
//		if (node == nullptr || node == list->first) {
//			nodeForRemove = list->first;
//			list->first = nodeForRemove->next;
//			list->first->prev = nullptr;
//			delete nodeForRemove;
//			list->countOfNodesInList--;
//			return;
//		}
//		Node* nextAfterCurrentNode;
//		while (currentNode) {
//			if (currentNode == nodeForRemove) {
//				previousNode->next = nodeForRemove->next;
//				nextAfterCurrentNode = nodeForRemove->next;
//				nextAfterCurrentNode->prev = previousNode;
//				delete nodeForRemove;
//				list->countOfNodesInList--;
//				return;
//			}
//			previousNode = currentNode;
//			currentNode = currentNode->next;
//		}
//	}
//
//	void assertNoCycles(LinkedList * list) {
//		if (numberOfNodesInTheList(list) != list->countOfNodesInList) {
//			std::cout << "The list contains a loop!!!" << std::endl;
//		}
//		else {
//			std::cout << "The list don't contains a loop." << std::endl;
//		}
//	}
//
//	int numberOfNodesInTheList(LinkedList * list) {
//		Node* currentNode = list->first;
//		int numberOfNodes = 0;
//		while (currentNode) {
//			numberOfNodes++;
//			currentNode = currentNode->next;
//		}
//		return numberOfNodes;
//	}
//
//	void printList(LinkedList * list) {
//		if (isEmpty(list)) {
//			std::cout << "List is empty!!!" << std::endl;
//			return;
//		}
//		int count = 1;
//
//		Node* currentNode = list->first;
//
//		std::cout << std::left << std::setw(3) << "#" << std::setw(10) << "Name" << std::setw(7) << "Age" << std::setw(2) << "Gender" << std::endl;
//		while (currentNode) {
//			std::string_view humanName{ currentNode->human.name.data() };
//			std::string gender = static_cast<int>(currentNode->human.gender) ? "FEMALE" : "MALE";
//			std::cout << std::setw(3) << count++ << std::setw(10) << humanName << std::setw(7) << currentNode->human.age << std::setw(4) << gender << std::endl;
//			currentNode = currentNode->next;
//		}
//	}