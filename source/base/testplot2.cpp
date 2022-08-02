#include "testplot2.h"

TestPlot2::TestPlot2()
{
    auto customPlot = canvas;

    QPen pen;
    pen.setColor(QColor(255, 0, 0));
    pen.setWidth(10);
    customPlot->addGraph();
    customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    //取消点与点之间的连线
    customPlot->graph(0)->setPen(pen);
    customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 8));
    //设置散点为圆点
    QVector<double> x(10), y(10);
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    for (int i = 0; i < 10; i++)
    {
        x[i] = i;
        y[i] = i + qrand() % 20;
    }

    customPlot->graph(0)->setData(x, y);
    customPlot->graph(0)->rescaleAxes();

    customPlot->graph(0)->setSelectable(QCP::stMultipleDataRanges);
    customPlot->setSelectionRectMode(QCP::SelectionRectMode::srmSelect);
    customPlot->setMultiSelectModifier(Qt::KeyboardModifier::ControlModifier);
    //在设置选择多个点的时候首先要设置绘图板是可选择的(QCP::iSelectPlottables)，然后再设置可选择多个物体(QCP::iMultiSelect)
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables | QCP::iMultiSelect);
    customPlot->replot();
}

void TestPlot2::btn_moveCanvas_clicked(bool isChecked)
{

}

void TestPlot2::btn_property_clicked()
{

}

void TestPlot2::btn_fullView_clicked()
{

}

void TestPlot2::btn_ratioView_clicked()
{

}

void TestPlot2::btn_print_clicked()
{

}
