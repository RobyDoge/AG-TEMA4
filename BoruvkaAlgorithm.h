#pragma once
#include <set>

#include "Graph.h"
class BoruvkaAlgorithm
{
public:
	struct HashNodes
	{
		bool operator()(const Node& a, const Node& b) const {
			return a.GetValue()<b.GetValue(); // Sort by string length
		}
	};
	struct InnerSetHash {
		std::size_t operator()(const std::set<Node, HashNodes>& a, const std::set<Node, HashNodes>& b) const {
			if (!a.empty()&&!b.empty()) 
				return (*a.begin()).GetValue() < (*b.begin()).GetValue();
			if(!a.empty())
				return std::hash<int>{}((*a.begin()).GetValue());
			return std::hash<int>{}((*b.begin()).GetValue());
		}
	};

	static Graph CreateNewLowestCostGraph(const Graph& baseGraph);


private:
	static std::unordered_map<int, std::vector<Node>> CreateAdjacencyList(const Graph& graph);

	static Arch FindLowestCostArch(const std::set<Node>& ni,
	                               const std::unordered_map<int, std::vector<int>>& adjacencyList, const std::set<std::set<Node>>& M);

};

