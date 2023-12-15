#pragma once
#include "Graph.h"
class KruskalAlgorithm
{
public:
	static Graph CreateNewLowestCostGraph(const Graph& baseGraph);

private:
	static bool CreatesCycles(const Graph& graph, const Arch& arch);
};

