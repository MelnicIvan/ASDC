#include <iostream>
#include <assert.h>
#include "HumanStructLibrary.h"


struct Stack {
	StaticDataLibrary::Human* arr;
	size_t maxElementCount;
	size_t currentIndex;
};

Stack createDynamicStack(size_t maxElementCount);
bool isEmpty(const Stack* stack);
void push(Stack* stack, StaticDataLibrary::Human* human);
StaticDataLibrary::Human* getLastElement(Stack* stack);
StaticDataLibrary::Human* pop(Stack* stack);
size_t getElementCount(Stack* stack);
void destroyDynamicStack(Stack* stack);


void push(Stack* stack, StaticDataLibrary::Human* human) {
	size_t maxElementCount = stack->maxElementCount;
	assert(stack->currentIndex < maxElementCount);

	stack->arr[stack->currentIndex] = *human;
	stack->currentIndex = stack->currentIndex + 1;
}

size_t getElementCount(Stack* stack) {
	return stack->currentIndex;
}

StaticDataLibrary::Human* pop(Stack* stack) {
	assert(getElementCount(stack) > 0);
	size_t newCurrentIndex = stack->currentIndex - 1;
	StaticDataLibrary::Human* human = &stack->arr[newCurrentIndex];
	stack->currentIndex = newCurrentIndex;
	return human;
}

bool isEmpty(const Stack* stack) {
	if (stack->currentIndex > 0)
		return true;
	return false;
}

StaticDataLibrary::Human* getLastElement(Stack* stack) {
	if (isEmpty(stack))
		std::cout << "Stack is empty!" << std::endl;

	return &stack->arr[stack->currentIndex];
}

void destroyDynamicStack(Stack* stack) {
	free(stack->arr);
}

Stack createDynamicStack(size_t maxElementCount) {
	void* memoryBlock = malloc(maxElementCount * sizeof(StaticDataLibrary::Human));
	StaticDataLibrary::Human* arr = (StaticDataLibrary::Human*)memoryBlock;

	Stack stack;
	stack.arr = arr;
	stack.maxElementCount = maxElementCount;
	stack.currentIndex = 0;

	return stack;
}
