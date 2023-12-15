#include "Arches.h"

Arch::Arch(Node firstNode, Node secondNode, int cost)
{
	m_firstNode = firstNode;
	m_secondNode = secondNode;
	m_cost = cost;
}

void Arch::SetFirstNode(Node firstNode)
{
	m_firstNode = firstNode;
}

void Arch::SetSecondNode(Node secondNode)
{
	m_secondNode = secondNode;
}

void Arch::SetCost(int cost)
{
	m_cost = cost;
}

Node Arch::GetFirstNode() const
{
	return m_firstNode;
}

Node Arch::GetSecondNode() const
{
	return m_secondNode;
}

int Arch::GetCost() const
{
	return m_cost;
}
