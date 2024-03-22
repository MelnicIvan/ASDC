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


