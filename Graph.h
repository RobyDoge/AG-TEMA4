#pragma once
#include <vector>
#include "Arches.h"
#include <fstream>
#include <unordered_map>
class Graph
{
public:
	Graph();
	
	std::vector<Node> GetNodes() const;
	std::vector<Arch> GetArches() const;
	std::unordered_map<int, std::vector<int>>& GetAdjacencyList();

	void AddNode(Node node);
	void AddNode(QPoint coordinate);
	bool AddArch(const Arch& arch, const bool typeOfGraph = false);

	bool AddArch(const Node firstNode, const Node secondNode, const int cost, const bool typeOfGraph = false);
	void CreateNewDirectedArch(const Arch& arch);
	void CreateNewNonDirectedArch(const Arch& arch);
	

private:
	void AddNodes(const Arch& arch);
	bool ValidateDirectedArch(const Arch& arch) const;
	bool ValidateNonDirectedArch(const Arch& arch) const;

	std::vector<Node> m_nodes;
	std::vector<Arch> m_arches;
	std::unordered_map<int, std::vector<int>> m_adjacencyList;
};

