#include "graph_matrix.h"

GraphMatrix::GraphMatrix(int _vertices) : IGraph() {
	*vertices = _vertices;
	matrix = new bool[_vertices * _vertices];
	for (int j = 0; j < sizeof(matrix); ++j) {
		matrix[j] = 0;
	}
}

GraphMatrix::GraphMatrix(IGraph* _oth) {
	matrix = new bool[(*vertices) * (*vertices)];
	for (int j = 0; j < *vertices; ++j) {
		std::vector<int> tmp_vec;
		_oth->getNextVertices(j, tmp_vec);
		for (int i = 0; i < tmp_vec.size(); ++i) {
			matrix[j * (*vertices) + i] = 1;
		}
	}
}

GraphMatrix::~GraphMatrix() {
	delete matrix;
}


void GraphMatrix::addEdge(int from, int to) {
	matrix[from * (*vertices) + to] = 1;
}

void GraphMatrix::getNextVertices(int vertex, std::vector<int>& vertices_vec) {
	for (int j = 0; j < *vertices; ++j) {
		if (matrix[vertex * (*vertices) + j] == 1) {
			vertices_vec.push_back(j);
		}
	}
}

void GraphMatrix::getPreviousVertices(int vertex, std::vector<int>& vertices_vec) {
	for (int j = 0; j < *vertices; ++j) {
		if (matrix[j * (*vertices) + vertex] == 1) {
			vertices_vec.push_back(j);
		}
	}
}