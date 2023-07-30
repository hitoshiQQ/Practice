#include "graph.h"

IGraph::IGraph() : vertices(new int) {
	*vertices = 10;
}

IGraph::IGraph(IGraph* _oth) : IGraph() {
	*vertices = *_oth->vertices;
}

IGraph::~IGraph() {}

int IGraph::verticesCount() {
	return *vertices;
}