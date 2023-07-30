#include <iostream>
#include "graph_list.h"
#include "graph_matrix.h"
#include "graph_print.h"

int main() {
	GraphList* list_a = new GraphList(10);
	list_a->addEdge(1, 2);
	list_a->addEdge(1, 7);
	list_a->addEdge(3, 6);
	list_a->addEdge(6, 8);

	GraphMatrix* matrix_a = new GraphMatrix(list_a);

	GraphList* list_b = new GraphList(list_a);
	GraphMatrix* matrix_b = new GraphMatrix(matrix_a);
    std::vector<int> vec;

	list_a->getNextVertices(1, vec);
	print(vec);
	matrix_a->getNextVertices(1, vec);
	print(vec);

	list_b->getNextVertices(1, vec);
	print(vec);
	matrix_b->getNextVertices(1, vec);
	print(vec);

	return 0;
}

