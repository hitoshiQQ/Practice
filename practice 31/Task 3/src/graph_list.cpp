#include "graph_list.h"

GraphList::GraphList() : IGraph() {
	list = new std::map<int, std::vector<int>>;
	for (int j = 0; j < *vertices; ++j) {
		list->insert(std::pair<int, std::vector<int>>(j, {}));
	}
}

GraphList::GraphList(int _vertices) : GraphList() {
	*vertices = _vertices;
}

GraphList::GraphList(IGraph* _oth) : IGraph(_oth) {
	list = new std::map<int, std::vector<int>>;
	for (int j = 0; j < *vertices; ++j) {
		std::vector<int> tmp_vec;
		_oth->getNextVertices(j, tmp_vec);
		list->insert(std::pair<int, std::vector<int>>(j, tmp_vec));
	}
}

GraphList::~GraphList() {
	delete vertices;
	delete list;
}

void GraphList::addEdge(int from, int to) {
	std::map<int, std::vector<int>>::iterator iter = list->find(from);
	if (iter != list->end()) {
		iter->second.push_back(to);
	}else {
		list->insert(std::pair<int, std::vector<int>>(from, { to }));
	}
}

void GraphList::getNextVertices(int vertex, std::vector<int>& vertices_vec) {
	std::map<int, std::vector<int>>::iterator iter = list->find(vertex);
	for (int j = 0; j < iter->second.size(); ++j) {
		vertices_vec.push_back(iter->second[j]);
	}
}

void GraphList::getPreviousVertices(int vertex, std::vector<int>& vertices_vec) {
	for (int j = 0; j < *vertices; ++j) {
		std::map<int, std::vector<int>>::iterator iter = list->find(j);
		for (int i = 0; i < iter->second.size(); ++i) {
			if (iter->second[i] == vertex) {
				vertices_vec.push_back(iter->second[j]);
				break;
			}
		}
	}
}