#include <iostream>
#include <assert.h>
#include <vector>
#include "HumanStructLibrary.h"


struct Stack {
	std::vector<StaticDataLibrary::Human*> underlyingArray;
};

bool isEmpty(const Stack* stack);
void push(Stack* stack, StaticDataLibrary::Human* human);
StaticDataLibrary::Human* getLastElement(Stack* stack);
StaticDataLibrary::Human* pop(Stack* stack);


void push(Stack* stack, StaticDataLibrary::Human human) {
	stack->underlyingArray.push_back(&human);
}



StaticDataLibrary::Human* pop(Stack* stack) {
	assert(!isEmpty(stack));
	size_t lastIndex = stack->underlyingArray.size() - 1;
	StaticDataLibrary::Human* lastElement = stack->underlyingArray[lastIndex];
	stack->underlyingArray.resize(lastIndex);
	return lastElement;
}

bool isEmpty(const Stack* stack) {
	return stack->underlyingArray.size() == 0;
}

StaticDataLibrary::Human* getLastElement(Stack* stack) {
	int lastIndex = stack->underlyingArray.size() - 1;
	return stack->underlyingArray[lastIndex];
}

