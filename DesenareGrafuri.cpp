#include "DesenareGrafuri.h"
#include <QInputDialog>
#include "KruskalAlgorithm.h"
#include "BoruvkaAlgorithm.h"

DesenareGrafuri::DesenareGrafuri(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_firstNode.SetValue(-1);
	connect(ui.m_KruskalButton, &QPushButton::clicked, this, &DesenareGrafuri::KruskalButtonClicked);
	connect(ui.m_BarukvaButton, &QPushButton::clicked, this, &DesenareGrafuri::BoruvkaButtonClicked);
	connect(ui.m_getOriginalGraph, &QPushButton::clicked, this, &DesenareGrafuri::GetOriginalGraphBackButton);
}


void DesenareGrafuri::mouseReleaseEvent(QMouseEvent* e)
{
	if (e->button() == Qt::RightButton)
	{
		if (ValidatePosition(e))
		{
			m_graph.AddNode(e->pos());
			update();
		}
	}
	else if (e->button() == Qt::LeftButton)
	{
		std::vector<Node> nodes = m_graph.GetNodes();
		for (Node& n : nodes)
		{
			if (fabs(e->pos().x() - n.GetX()) < 10 &&
				fabs(e->pos().y() - n.GetY()) < 10)
			{
				if (m_firstNode.GetValue() == -1)
					m_firstNode = n;
				else
				{
					int cost = 0;
					EdgeCost(cost);
					if(m_graph.AddArch(Arch(m_firstNode, n, cost)))
					{
						QString edge;
						edge.append("(").append(QString::number(m_firstNode.GetValue())).append(" , ").append(QString::number(n.GetValue())).
							append(") => ").append(QString::number(cost));
						ui.m_edgeDisplayBox->append(edge);
						m_firstNode.SetValue(-1);
					}
				}
				update();
				break;
			}
		}
	}
}


void DesenareGrafuri::paintEvent(QPaintEvent* e)
{
	QPainter p(this);
	std::vector<Node> noduri = m_graph.GetNodes();
	for (Node& n : noduri)
	{
		QRect r(n.GetX() - 10, n.GetY() - 10, 20, 20);
		p.drawEllipse(r);
		QString s;
		s.setNum(n.GetValue());
		p.drawText(r, Qt::AlignCenter, s);
	}
	QPen aux;
	aux.setColor(m_edgeColor);
	p.setPen(aux);
	std::vector<Arch> arches = m_graph.GetArches();
	for (Arch& a : arches)
	{
		p.drawLine(a.GetFirstNode().GetX(), a.GetFirstNode().GetY(),
		           a.GetSecondNode().GetX(), a.GetSecondNode().GetY());
	}

	if (m_firstNode.GetValue() >= 0)
	{
		const QRect r(m_firstNode.GetX() - 10, m_firstNode.GetY() - 10, 20, 20);
		QPen pen;
		pen.setColor(Qt::red);
		pen.setWidth(2);
		p.setPen(pen);
		p.drawEllipse(r);
		QString s;
		s.setNum(m_firstNode.GetValue());
		p.drawText(r, Qt::AlignCenter, s);
	}
}

void DesenareGrafuri::EdgeCost(int& cost) {
	bool ok;
	const int input = QInputDialog::getInt(this, tr("Enter Edge Cost"), tr("Cost:"), 0, -10000, 10000, 1, &ok);

	if (ok) 
	{
		cost = input;
	}
	else {
		cost = 0; 
	}
}


void DesenareGrafuri::KruskalButtonClicked()
{
	m_originalGraphCopy = m_graph ;
	m_graph =  KruskalAlgorithm::CreateNewLowestCostGraph(m_graph) ;
	m_edgeColor = Qt::red;
	update();
}

void DesenareGrafuri::BoruvkaButtonClicked()
{
	m_originalGraphCopy = m_graph;
	m_graph = BoruvkaAlgorithm::CreateNewLowestCostGraph(m_graph);
	m_edgeColor = Qt::green;
	update();
}

void DesenareGrafuri::GetOriginalGraphBackButton()
{
	m_graph = m_originalGraphCopy;
	m_edgeColor = Qt::black;
	update();
}


bool DesenareGrafuri::ValidatePosition(QMouseEvent* e) const
{
	if (e->pos().y() <= UI_CHAT_Y&&e->pos().x() <= UI_CHAT_X)
		return false;

	if (e->pos().y() <= UI_BUTTONS_Y && e->pos().x() <= UI_BUTTONS_X)
		return false;

	std::vector<Node> nodes = m_graph.GetNodes();
	for (auto node : nodes)
	{
		const int dx = e->pos().x() - node.GetX();
		const int dy = e->pos().y() - node.GetY();
		const int distance = std::sqrt(dx * dx + dy * dy);

		if (constexpr int minDistance = 20; distance < minDistance)
		{
			return false;
		}
	}

	return true;
}
