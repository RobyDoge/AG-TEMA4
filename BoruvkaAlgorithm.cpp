#include "BoruvkaAlgorithm.h"
#include <list>
#include <map>
#include <ranges>

Graph BoruvkaAlgorithm::CreateNewLowestCostGraph(const Graph& baseGraph)
{
	Graph lowestCostGraph{};
	std::vector<Arch> A;
	std::set<std::set<Node,HashNodes>, InnerSetHash> M;
	auto adjacencyList = CreateAdjacencyList(baseGraph);
	for(const auto& aux: baseGraph.GetNodes())
	{
		M.insert({ aux });
	}

	//while(A.size()< baseGraph.GetNodes().size()-1)
	//{
	//	int y;
	//	for(const auto& ni : M)
	//	{
	//		Node firsNode;
	//		int lowestCost;
	//		for (auto node : ni)
	//		{
	//			for (auto secondNode : adjacencyList.at(node.GetValue()))
	//			{
	//				if (ni.contains(std::))
	//			}
	//		}
	//		;
	//		Arch minim{ FindLowestCostArch(ni, adjacencyList, M) };
	//		A.push_back(minim);
	//	}
	//}



	return  lowestCostGraph;
}

std::unordered_map<int, std::vector<Node>> BoruvkaAlgorithm::CreateAdjacencyList(const Graph& graph)
{
	Graph copy{ graph };
	for(auto &[firstNodeValue, secondNodesValue]: copy.GetAdjacencyList())
	{
		auto firstNodeIterator= std::find_if(copy.GetNodes().begin(), copy.GetNodes().end(), [&](const Node& node) {
			return node.GetValue() == firstNodeValue; });
		Node firstNode = *firstNodeIterator;

		std::ranges::sort(secondNodesValue, [&](const int& secondNodeValue1, const int& secondNodeValue2)
		{
			const Node secondNode1 = *std::find_if(copy.GetNodes().begin(), copy.GetNodes().end(), [&](const Node& node) {
				return node.GetValue() == secondNodeValue1; });
			const Node secondNode2 = *std::find_if(copy.GetNodes().begin(), copy.GetNodes().end(), [&](const Node& node) {
				return node.GetValue() == secondNodeValue2; });

			const Arch arch1{ *std::find_if(copy.GetArches().begin(), copy.GetArches().end(), [&](const Arch& arch)
			{
				return arch.GetFirstNode() == firstNode && arch.GetSecondNode() == secondNode1;
			}) };

			const Arch arch2{ *std::find_if(copy.GetArches().begin(), copy.GetArches().end(), [&](const Arch& arch)
			{
				return arch.GetFirstNode() == firstNode && arch.GetSecondNode() == secondNode2;
			}) };

			return arch1.GetCost() < arch2.GetCost();
		});
	}
	std::unordered_map<int, std::vector<Node>> adjacencyList;
	for(auto [node,adjancentNodes] : copy.GetAdjacencyList())
	{
		std::vector<Node> newNodes;
		for(auto adjancentNode : adjancentNodes)
		{
			newNodes.push_back({ *std::find_if(copy.GetNodes().begin(),copy.GetNodes().end(),[&](const Node& nodeToFind)
			{
				return nodeToFind.GetValue() == adjancentNode;
			})
				});
		}
		adjacencyList[node] = newNodes;
	}
	return adjacencyList;
}

Arch BoruvkaAlgorithm::FindLowestCostArch(const std::set<Node>& ni,
	const std::unordered_map<int, std::vector<int>>& adjacencyList, const std::set<std::set<Node>>& M)
{
	

	return{};
}
