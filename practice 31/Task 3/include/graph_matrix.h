#pragma once
#include "graph.h"
#include "graph_list.h"

class GraphMatrix : public IGraph {
private:
	bool* matrix;
	
public:
	GraphMatrix() {};
	GraphMatrix(int _vertices);
	GraphMatrix(IGraph* _oth);
	~GraphMatrix();

	void addEdge(int from, int to);
	void getNextVertices(int vertex, std::vector<int>& vertices_vec);
	void getPreviousVertices(int vertex, std::vector<int>& vertices_vec);
};