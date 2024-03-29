#pragma once
#include "HumanStructLibrary.h"


namespace StaticDataLibrary {
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

	Node* insertAfter(LinkedList* list, Node* node, Human human);
	FindNodeResult findByName(LinkedList* list, std::array<char, MAX_SIZE> name);
	Human* removeFromStart(LinkedList* list);
	void removeAfter(LinkedList* list, Node* node);
	void assertNoCycles(LinkedList* list);
	int numberOfNodesInTheList(LinkedList* list);
	void printList(LinkedList* list);
	bool isEmpty(const LinkedList* list);
	Node* addNodeToStart(LinkedList* list, Human* human);
	Node* addNodeToEnd(LinkedList* list, Human* human);
}