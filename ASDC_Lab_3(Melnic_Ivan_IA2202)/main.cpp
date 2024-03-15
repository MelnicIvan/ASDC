//ѕо поводу sln дл€ нескольких проектов.
//—оздать новый проект и в его решение добавить все лабы, при этом удалив все sln файлы из 
//проектов с этими лабами или как-нибудь по-другому, но если удалить sln файлы из проектов, 
//то не смогу запускать их по отдельности


#include <iostream>
#include <array>

struct GraphNode {
	int value;
	std::array<GraphNode*, 3> neighbors;
};

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


int main() {
	GraphNode* n1 = new GraphNode{};
	n1->value = 1;

	GraphNode* n2 = new GraphNode{};
	n2->value = 2;

	GraphNode* n3 = new GraphNode{};
	n3->value = 3;

	GraphNode* n4 = new GraphNode{};
	n4->value = 4;

	n1->neighbors[0] = n2;
	n1->neighbors[1] = n3;
	n1->neighbors[2] = n4;

	n2->neighbors[0] = n1;
	n2->neighbors[1] = n3;
	n2->neighbors[2] = n4;

	n4->neighbors[0] = n3;

	printValuesOfNeighborsOfNeighbors(n2);

	return 0;
}