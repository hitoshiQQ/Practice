#pragma once
#include "graph_list.h"
#include "graph_matrix.h"

void print(std::vector<int>& res) {
	for (int j = 0; j < res.size(); ++j) {
		std::cout << res[j] << "\n";
	}
}