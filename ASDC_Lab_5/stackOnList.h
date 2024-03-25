#include "HumanStructLibrary.h"
#include <ListLibrary.h>

struct Node {
	StaticDataLibrary::Human human;
	Node* next;
};

struct Stack {
	Node* firstNode;
};

bool isEmpty(const Stack* stack);
void push(Stack* stack, StaticDataLibrary::Human human);
StaticDataLibrary::Human* getLastElement(Stack* stack);
StaticDataLibrary::Human* pop(Stack* stack);

void push(Stack* stack, StaticDataLibrary::Human human) {
	Node* node = new Node;
	node->human = human;
	node->next = stack->firstNode;

	stack->firstNode = node;
}

StaticDataLibrary::Human* pop(Stack* stack) {
	Node* firstNode = stack->firstNode;
	stack->firstNode = firstNode->next;
	StaticDataLibrary::Human result = firstNode->human;
	delete firstNode;
	return &result;
}

bool isEmpty(const Stack* stack) {
	return stack->firstNode == nullptr;
}

StaticDataLibrary::Human* getLastElement(Stack* stack) {
	assert(!isEmpty(stack));

	return &stack->firstNode->human;
	//Node* currentNode = stack->firstNode;
	//while (currentNode->next != nullptr) {
	//	if(currentNode->next == nullptr) 
	//		return &currentNode->human;
	//	currentNode = currentNode->next;
	//}
	//return &currentNode->human;
}


