#pragma once
#include <qpainter.h>
class Node
{
public:
	Node();
	Node(int value, QPoint coordiantes);
	Node(int value, int x, int y);

	void SetValue(int value);
	void SetCoordinates(QPoint coordinates);
	void SetCoordinates(int x, int y);
	void SetX(int x);
	void SetY(int y);
	bool operator==(const Node&) const;
	QPoint GetCoordinates() const;
	int GetX() const;
	int GetY() const;
	int GetValue() const;



private:
	int m_value;
	QPoint m_coordinates;
};

