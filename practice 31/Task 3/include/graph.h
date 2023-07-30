#pragma once
#include <vector>

class IGraph {
protected:
	int* vertices;

public:
	IGraph();
	IGraph(IGraph* _oth) ;
	virtual ~IGraph() ;

	int verticesCount();

	virtual void addEdge(int from, int to) = 0;
	virtual void getNextVertices(int vertex, std::vector<int>& vertices) = 0;
	virtual void getPreviousVertices(int vertex, std::vector<int>& vertices) = 0;
};