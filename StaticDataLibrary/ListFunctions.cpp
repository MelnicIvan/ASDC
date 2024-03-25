#include "ListLibrary.h"
#include <iomanip>
#include <assert.h>

namespace StaticDataLibrary {

	bool isEmpty(const LinkedList* list) {
		return list->first == nullptr;
	}

	//C������ ����� ��� � ��������� ��� ����� ������� ����. 
	// � ������ ���� node == nullptr, ��� ����������� � ������ ������. 
	// ���������� ��������� �� ��������� ���;
	Node* insertAfter(LinkedList* list, Node* node, Human human) {
		Node* tempPtr = new Node;
		tempPtr->human = human;
		tempPtr->next = nullptr;

		if (isEmpty(list)) {
			list->first = tempPtr;
			list->last = tempPtr;
			list->countOfNodesInList++;
			return list->first;
		}

		if (node == nullptr) {
			tempPtr->next = list->first;
			list->first = tempPtr;
			list->countOfNodesInList++;
			return list->first;
		}

		//����� �� ��� ��� ������ while ���������� �� ��������� ����?
		tempPtr->next = node->next;
		node->next = tempPtr;
		list->countOfNodesInList++;
		return node->next;
	}

	void printList(LinkedList* list) {
		if (isEmpty(list)) {
			std::cout << "List is empty!!!" << std::endl;
			return;
		}
		int count = 1;

		Node* currentNode = list->first;

		std::cout << std::left << std::setw(3) << "#" << std::setw(10) << "Name" << std::setw(7) << "Age" << std::setw(2) << "Gender" << std::endl;
		while (currentNode) {
			std::string_view humanName{ currentNode->human.name.data() };
			std::string gender = static_cast<int>(currentNode->human.gender) ? "FEMALE" : "MALE";
			std::cout << std::setw(3) << count++ << std::setw(10) << humanName << std::setw(7) << currentNode->human.age << std::setw(4) << gender << std::endl;
			currentNode = currentNode->next;
		}
	}


	//���� ��� �� ���� � �������� ��������� � ������; 
	// ���������� ��� � ���� ���������, � ����� ��� �� ����.
	FindNodeResult findByName(LinkedList* list, std::array<char, MAX_SIZE> name) {
		Node* currentNode = list->first;
		Node* previousNode = nullptr;

		if (isEmpty(list)) {
			std::cout << "List is empty!!!" << std::endl;
		}

		while (currentNode) {
			if (currentNode->human.name == name && currentNode == list->first) {
				return FindNodeResult(currentNode, nullptr);
			}
			if (currentNode->human.name == name) {
				return FindNodeResult(currentNode, previousNode);
			}

			previousNode = currentNode;
			currentNode = currentNode->next;
		}

		return FindNodeResult(nullptr, nullptr);
	}

	Human* removeFromStart(LinkedList* list) {
		assert(list->first != nullptr);

		Node* firstNode = list->first;
		Node* secondNode = firstNode->next;

		if (firstNode == list->last) {
			list->last = nullptr;
		}

		list->first = secondNode;

		Human human = firstNode->human;
		delete firstNode;
		return &human;
	}

	//������� ��� ��������� ������� ���� �� ������
	void removeAfter(LinkedList* list, Node* node) {
		if (isEmpty(list)) {
			std::cout << "List is empty!!!" << std::endl;
			return;
		}

		Node* nodeForRemove;
		if (node == nullptr || node == list->first) {
			nodeForRemove = list->first;
			list->first = nodeForRemove->next;
			delete nodeForRemove;
			list->countOfNodesInList--;
			return;
		}
		else {
			Node* currentNode = list->first;
			Node* previousNode = nullptr;
			while (currentNode) {
				if (currentNode == node) {
					nodeForRemove = currentNode;
					previousNode->next = currentNode->next;
					delete nodeForRemove;
					list->countOfNodesInList--;
					//�������� �� ������ return 
					return;
				}
				previousNode = currentNode;
				currentNode = currentNode->next;
			}
		}
	}

	//���������, ����� � ������ �� ���� ������
	void assertNoCycles(LinkedList* list) {
		Node* currentNode = list->first;
		int currentNumberOfNodes = 0;
		while (currentNode) {
			assert(!(currentNumberOfNodes > list->countOfNodesInList));
			currentNumberOfNodes++;
			currentNode = currentNode->next;
		}
	}

	Node* addNodeToStart(LinkedList* list, Human* human) {
		Node* newNode = new Node;
		newNode->next = list->first;
		newNode->human = *human;

		list->first = newNode;

		if (list->last == nullptr) {
			list->last = newNode;
		}

		return newNode;
	}

	Node* addNodeToEnd(LinkedList* list, Human* human) {
		Node* newNode = new Node;
		newNode->next = nullptr;
		newNode->human = *human;

		if (list->last != nullptr) {
			list->last->next = newNode;
		}

		list->last = newNode;

		if (list->first == nullptr) {
			list->first = newNode;
		}

		return newNode;
	}
}
