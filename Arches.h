#pragma once
#include "Node.h"
class Arch
{
public:
	Arch() = default;
	Arch(Node firstNode, Node secondNode, int cost);

	void SetFirstNode(Node firstNode);
	void SetSecondNode(Node secondNode);
	void SetCost(int cost);

	Node GetFirstNode() const;
	Node GetSecondNode() const;
	int GetCost() const;

private:
	Node m_firstNode;
	Node m_secondNode;
	int m_cost;
};

