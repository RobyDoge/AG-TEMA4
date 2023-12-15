#include "KruskalAlgorithm.h"
#include <ranges>
#include <stack>

Graph KruskalAlgorithm::CreateNewLowestCostGraph(const Graph& baseGraph)
{
	Graph lowestCostGraph{};
	std::vector<Arch> sortedArches{baseGraph.GetArches()};
	std::ranges::sort(sortedArches, [&](const Arch& first, const Arch& second)
	{
		return first.GetCost() < second.GetCost();
	});

	for(const auto& arch : sortedArches)
	{
		if(!CreatesCycles(lowestCostGraph,arch))
		{
			lowestCostGraph.AddArch(arch);
		}
	}
	return lowestCostGraph;
}

bool KruskalAlgorithm::CreatesCycles(const Graph& graph, const Arch& arch)
{
	Graph auxGraph{ graph };
	auxGraph.AddArch(arch);
	auto adjacencyList{ auxGraph.GetAdjacencyList() };
	std::vector<int> visited;
	std::unordered_map<int, int> parents;
	std::stack<int> nodesStack;

	for (const auto& node : adjacencyList | std::views::keys)
	{
		visited[node] = 0;
	}

	for (const auto& firstNode : adjacencyList | std::views::keys)
	{
		if (visited[firstNode] == 0)
		{
			nodesStack.push(firstNode);
			visited[firstNode] = 1;

			while (!nodesStack.empty())
			{
				const int currentNode = nodesStack.top();
				bool hasUnvisitedNeighbor = false;

				for (const auto& secondNode : adjacencyList[currentNode])
				{
					if (visited[secondNode] == 1 && parents[currentNode]!=secondNode)
					{
						return true;
					}
					if (visited[secondNode] == 0)
					{
						nodesStack.push(secondNode);
						visited[secondNode] = 1;
						parents[secondNode] = currentNode;
						hasUnvisitedNeighbor = true;
						break;
					}
				}

				if (!hasUnvisitedNeighbor)
				{
					visited[currentNode] = 2;
					nodesStack.pop();
				}
			}
		}
	}

	return false;

}


