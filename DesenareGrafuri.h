#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_DesenareGrafuri.h"

#include "Graph.h"
#include <QMouseEvent>
#include <qpainter.h>
#include <qradiobutton.h>
#include <QTextBrowser>

class DesenareGrafuri : public QMainWindow
{
    Q_OBJECT

public:
    DesenareGrafuri(QWidget *parent = nullptr);
    ~DesenareGrafuri() override = default;

    
    void mouseReleaseEvent(QMouseEvent* e) override;
    void paintEvent(QPaintEvent* e) override;


private:
    static constexpr int UI_CHAT_Y{ 350 };
    static constexpr int UI_CHAT_X{ 150 };

    static constexpr int UI_BUTTONS_X{ 400 };
    static constexpr int UI_BUTTONS_Y{ 40 };

    
    

private:
	void EdgeCost(int& cost);
    void KruskalButtonClicked();
    void BoruvkaButtonClicked();
    void GetOriginalGraphBackButton();
    bool ValidatePosition(QMouseEvent* e) const;

private:
    QColor m_edgeColor{Qt::black};
    Ui::DesenareGrafuriClass ui;
    Graph m_graph;
    Graph m_originalGraphCopy{};
    Node m_firstNode;};
