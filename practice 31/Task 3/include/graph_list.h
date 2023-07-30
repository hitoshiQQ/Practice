#pragma once
#include "graph.h"
#include "graph_matrix.h"
#include <map>


class GraphList : public IGraph {
private:
	std::map<int, std::vector<int>>* list;

public:
	GraphList();
	GraphList(int _vertices);
	GraphList(IGraph* _oth);
	~GraphList();

	void addEdge(int from, int to);
	void getNextVertices(int vertex, std::vector<int>& vertices_vec);
	void getPreviousVertices(int vertex, std::vector<int>& vertices_vec);
};