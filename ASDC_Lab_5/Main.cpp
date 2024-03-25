#define ARRAY_IMPL false
#if ARRAY_IMPL
#include "stackOnArray.h"
#else
#include "stackOnList.h"
#endif

#include "queue.h"


int main() {
	Stack stack{};
	auto humans = StaticDataLibrary::createHumans();
	push(&stack, humans[0]);
	push(&stack, humans[1]);
	push(&stack, humans[2]);


	StaticDataLibrary::Human* hmn = getLastElement(&stack);
	//StaticDataLibrary::printHumanInfo(*hmn);

	push(&stack, humans[3]);

	assert(!isEmpty(&stack));
	pop(&stack);

	assert(!isEmpty(&stack));



	//   === Queue ===   //

	Queue queue{};

	for (auto elem : humans) {
		enqueue(&queue, &elem);
	}

	std::cout << "First element from Queue: \n";
	StaticDataLibrary::Node* frontHuman = front(&queue);
	StaticDataLibrary::printHumanInfo(frontHuman->human);

	std::cout << std::endl;
	std::cout << "All elements from Queue: \n";
	while (!isEmpty(&queue)) {
		StaticDataLibrary::Human* human = dequeue(&queue);
		StaticDataLibrary::printHumanInfo(*human);
		std::cout << std::endl;
	}
}