#include "Graph.h"

Graph::Graph()
= default;

std::vector<Node> Graph::GetNodes() const
{
    return m_nodes;
}

std::vector<Arch> Graph::GetArches() const
{
    return m_arches;
}


std::unordered_map<int, std::vector<int>>& Graph::GetAdjacencyList()
{
    return m_adjacencyList;
}

void Graph::AddNode(const Node node)
{
    m_nodes.push_back(node);
}

void Graph::AddNode(const QPoint coordinate)
{
    Node node;
    node.SetValue(m_nodes.size());
    node.SetCoordinates(coordinate);
    m_nodes.push_back(node);
}

bool Graph::AddArch(const Arch& arch, const bool typeOfGraph)
{
    if (typeOfGraph&&ValidateDirectedArch(arch))
    {
        m_arches.push_back(arch);
        CreateNewDirectedArch(arch);
        AddNodes(arch);
        return true;
    }
    else if(!typeOfGraph && ValidateNonDirectedArch(arch))
    {
        m_arches.push_back(arch);
        CreateNewNonDirectedArch(arch);
        AddNodes(arch);
        return true;
    }
    return false;
    
}


bool Graph::AddArch(const Node firstNode, const Node secondNode,const int cost, const bool typeOfGraph)
{
	if (const Arch arch(firstNode, secondNode,cost); typeOfGraph && ValidateDirectedArch(arch))
    {
        m_arches.push_back(arch);
        CreateNewDirectedArch(arch);
        AddNodes(arch);
        return true;
    }
    else if (!typeOfGraph && ValidateNonDirectedArch(arch))
    {
        m_arches.push_back(arch);
        CreateNewNonDirectedArch(arch);
        AddNodes(arch);
        return true;
    }
    return false;
}


void Graph::CreateNewNonDirectedArch(const Arch& arch)
{
    if (!m_adjacencyList.contains(arch.GetFirstNode().GetValue())) 
    {
        std::vector<int> newVector;
        newVector.push_back(arch.GetSecondNode().GetValue());
        m_adjacencyList[arch.GetFirstNode().GetValue()] = newVector;
    }
    else 
    {
        m_adjacencyList[arch.GetFirstNode().GetValue()].push_back(arch.GetSecondNode().GetValue());
    }

    if (!m_adjacencyList.contains(arch.GetSecondNode().GetValue()))
    {
        std::vector<int> newVector;
        newVector.push_back(arch.GetFirstNode().GetValue());
        m_adjacencyList[arch.GetSecondNode().GetValue()] = newVector;
    }
    else 
    {
        m_adjacencyList[arch.GetSecondNode().GetValue()].push_back(arch.GetFirstNode().GetValue());
    }
}

void Graph::AddNodes(const Arch& arch)
{
    if(std::ranges::find(m_nodes,arch.GetFirstNode())==m_nodes.end())
    {
        m_nodes.push_back(arch.GetFirstNode());
    }
    if (std::ranges::find(m_nodes, arch.GetSecondNode()) == m_nodes.end())
    {
        m_nodes.push_back(arch.GetSecondNode());
    }

}


void Graph::CreateNewDirectedArch(const Arch& arch)
{
    if (!m_adjacencyList.contains(arch.GetFirstNode().GetValue()))
    {
        std::vector<int> newVector;
        newVector.push_back(arch.GetSecondNode().GetValue());
        m_adjacencyList[arch.GetFirstNode().GetValue()] = newVector;
    }
    else 
    {
        m_adjacencyList[arch.GetFirstNode().GetValue()].push_back(arch.GetSecondNode().GetValue());
    }

}

bool Graph::ValidateDirectedArch(const Arch& arch) const
{
    for (auto aux : m_arches)
    {
        if (aux.GetFirstNode().GetValue() == arch.GetFirstNode().GetValue()
            && aux.GetSecondNode().GetValue() == arch.GetSecondNode().GetValue())
        {
            return false;
        }
    }
    return true;
}
bool Graph::ValidateNonDirectedArch(const Arch& arch) const
{
    for (auto aux : m_arches)
    {
        if ((aux.GetFirstNode().GetValue() == arch.GetFirstNode().GetValue()
            && aux.GetSecondNode().GetValue() == arch.GetSecondNode().GetValue())
            || (aux.GetFirstNode().GetValue() == arch.GetSecondNode().GetValue()
            && aux.GetSecondNode().GetValue() == arch.GetFirstNode().GetValue()))
            return false;
    }
    if(arch.GetFirstNode().GetValue()== arch.GetSecondNode().GetValue())
    {
        return false;
    }
    return true;
}
