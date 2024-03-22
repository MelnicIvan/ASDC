#include <iostream>
#include <array>
#include <queue>
#include <vector>
#include <span>
//#include "../StaticLibrary/Header.h"


struct GraphNode {
	int value;
	std::array<GraphNode*, 3> neighbors;
	bool visited;
};

void printValuesOfNeighborsOfNeighbors(GraphNode* node);
int calculateTheSumOfNeighborsValues(GraphNode* node);
void BFS(GraphNode* node);
void DFS(GraphNode* node);
void resetAttendanceStatus(std::span<GraphNode*> nodeVector);

int main() {
	//Create nodes of Graph
	GraphNode* n1 = new GraphNode{};
	n1->neighbors = {};
	n1->value = 1;
	n1->visited = false;

	GraphNode* n2 = new GraphNode{};
	n2->neighbors = {};
	n2->value = 2;
	n2->visited = false;

	GraphNode* n3 = new GraphNode{};
	n3->neighbors = {};
	n3->value = 3;
	n3->visited = false;

	GraphNode* n4 = new GraphNode{};
	n4->neighbors = {};
	n4->value = 4;
	n4->visited = false;

	std::vector<GraphNode*> nodeVector;
	nodeVector.push_back(n1);
	nodeVector.push_back(n2);
	nodeVector.push_back(n3);
	nodeVector.push_back(n4);

	//Established connections between neighbors
	n1->neighbors[0] = n2;

	n2->neighbors[0] = n3;
	n2->neighbors[1] = n4;

	n3->neighbors[0] = n4;

	n4->neighbors[0] = n1;
	n4->neighbors[1] = n2;

	printValuesOfNeighborsOfNeighbors(n2);
	std::cout << "Sum of neighbors of n2 is equal " << calculateTheSumOfNeighborsValues(n2) << std::endl;

	std::cout << "\nBFS Algorithm: " << std::endl;
	BFS(n1);
	std::cout << std::endl;

	resetAttendanceStatus(nodeVector);

	std::cout << "DFS Algorithm: " << std::endl;
	DFS(n3);


	return 0;
}

void printValuesOfNeighborsOfNeighbors(GraphNode* node) {
	for (size_t i = 0; i < node->neighbors.size(); i++) {
		GraphNode* neighbor = node->neighbors[i];
		if (neighbor == nullptr) {
			break;
		}

		for (size_t j = 0; j < neighbor->neighbors.size(); j++) {
			GraphNode* neighborsNeighbor = neighbor->neighbors[j];

			if (neighborsNeighbor == nullptr) {
				break;
			}

			std::cout << neighborsNeighbor->value << std::endl;
		}
	}
}

int calculateTheSumOfNeighborsValues(GraphNode* node) {
	int sum = 0;
	GraphNode* currentNode;
	for (size_t i = 0; i < node->neighbors.size(); i++) {
		currentNode = node->neighbors[i];
		if (currentNode == nullptr)
			break;
		sum += currentNode->value;
	}
	return sum;
}

void BFS(GraphNode* node) {
	if (node == nullptr)
		return;

	std::queue<GraphNode*> queue;
	node->visited = true;
	queue.push(node);
	while (!empty(queue)) {
		GraphNode* currentNode = queue.front();
		std::cout << currentNode->value << std::endl;
		queue.pop();
		for (int i = 0; i < currentNode->neighbors.size(); i++) {
			GraphNode* currentNeighbor = currentNode->neighbors[i];
			if (currentNeighbor == nullptr) continue;
			if (!currentNeighbor->visited) {
				queue.push(currentNeighbor);
				currentNeighbor->visited = true;
			}
		}
	}
}

void DFS(GraphNode* node) {
	if (node->visited) {
		return;
	}
	node->visited = true;
	std::cout << node->value << std::endl;
	for (int i = 0; i < node->neighbors.size(); i++) {
		if (node->neighbors[i] == nullptr) continue;
		DFS(node->neighbors[i]);
	}
}

void resetAttendanceStatus(std::span<GraphNode*> nodeVector) {
	for (int i = 0; i < nodeVector.size(); i++) {
		nodeVector[i]->visited = false;
	}
}
