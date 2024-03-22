#define ARRAY_IMPL true
#if ARRAY_IMPL
#include "stackOnArray.h"
#else
#include "stackOnList.h"
#endif

int main() {
	std::cout << "Enter the number of elements" << std::endl;
	size_t maxElementCount;
	std::cin >> maxElementCount;
	Stack stack = createDynamicStack(maxElementCount);

	auto humans = StaticDataLibrary::createHumans();
	//StaticDataLibrary::printHumanInfo(humans[0]);

	for (int i = 0; i < maxElementCount; i++) {
		push(&stack, &humans[i]);
	}

	size_t elementCount = getElementCount(&stack);
	for (size_t i = 0; i < elementCount; i++) {
		StaticDataLibrary::Human* topElement = pop(&stack);
		StaticDataLibrary::printHumanInfo(*topElement);
	}


	destroyDynamicStack(&stack);
}