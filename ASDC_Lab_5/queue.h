#include "HumanStructLibrary.h"
#include "ListLibrary.h"

struct Queue {
	StaticDataLibrary::LinkedList list;
};

void enqueue(Queue* queue, StaticDataLibrary::Human* human) {
	addNodeToEnd(&queue->list,human);
}

StaticDataLibrary::Human* dequeue(Queue* queue) {
	StaticDataLibrary::Human* result = StaticDataLibrary::removeFromStart(&queue->list);
	return result;
}

bool isEmpty(const Queue* queue) {
	return isEmpty(&queue->list);
}

StaticDataLibrary::Node* front(Queue* queue) {
	StaticDataLibrary::Node* result = queue->list.first;
	return result;
}