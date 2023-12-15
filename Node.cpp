#include "Node.h"

Node::Node()
{
}

Node::Node(const int value, const QPoint coordiantes)
{
    m_value = value;
    m_coordinates = coordiantes;
}

Node::Node(const int value, const int x, const int y)
{
    m_value = value;
    m_coordinates.setX(x);
    m_coordinates.setY(y);
}

void Node::SetValue(const int value)
{
    m_value = value;
}

void Node::SetCoordinates(const QPoint coordinates)
{
    m_coordinates = coordinates;
}

void Node::SetCoordinates(const int x, const int y)
{
    m_coordinates.setX(x);
    m_coordinates.setY(y);
}

void Node::SetX(const int x)
{
    m_coordinates.setX(x);
}

void Node::SetY(const int y)
{
    m_coordinates.setY(y);
}

bool Node::operator==(const Node& node) const
{
    return m_value == node.m_value;
}

QPoint Node::GetCoordinates() const
{
    return m_coordinates;
}

int Node::GetX() const
{
    return m_coordinates.x();
}

int Node::GetY() const
{
    return m_coordinates.y();
}

int Node::GetValue() const
{
    return m_value;
}
