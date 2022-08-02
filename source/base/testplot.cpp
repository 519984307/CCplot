#include "testplot.h"
#include <QtMath>>

TestPlot::TestPlot(QWidget* parent):
    CCPlot(parent)
{

}

void TestPlot::makeGraph()
{
    //1.标题
    TitleProp t(QString::fromLocal8Bit("测试标题"),
                QFont("Microsoft YaHei", 12, QFont::Bold));
    addTitle(t);

    //2.坐标轴
    AxisProp xAxis(QString::fromLocal8Bit("x轴"),
                   RangeProp(0, 100));
    setAxis(xAxis, axisPosition::atDown);

    AxisProp yAxis(QString::fromLocal8Bit("y轴(位移[m]) [单位]"),
                   RangeProp(0, 100));
    setAxis(yAxis, axisPosition::atLeft);


    AxisProp xAxis2(QString::fromLocal8Bit("x轴2"),
                    RangeProp(0, 100));
    setAxis(xAxis2, axisPosition::atTop);

    AxisProp yAxis2(QString::fromLocal8Bit("y轴2(角度[°]) [单位]"),
                    RangeProp(0, 100));
    setAxis(yAxis2, axisPosition::atRight);

    useTwoAxisSystem = true;


    showMainAxis(true);
    showSubAxis(true);

    //3.图例
    showLegend(true);

    //4.播放区
    showPlayWidgets(true);

//    connect(canvas, &QCustomPlot::customContextMenuRequested, this, [&](QPoint pos){
//        menu->setAttribute(Qt::WA_DeleteOnClose);
//        menu->addAction(QString::fromLocal8Bit("计算平均值"), this, [&](){
//            qDebug()<<selected_Y_avg;
//        });
//        menu->popup(canvas->mapToGlobal(pos));
//    });
}

void TestPlot::update()
{
    CurveProp C1(QString::fromLocal8Bit("曲线1"), QColor(255, 0, 0));

    C1.lineStyle = QCPGraph::LineStyle::lsLine;
    C1.scatterStyle = QCPScatterStyle(static_cast<QCPScatterStyle::ScatterShape>(2), 5);

    for (size_t i = 0; i < 100; i++)
    {
        C1.xx.append(i);
        C1.yy.append(20 * sin(0.1 * i));
    }

    addCurve(C1, whichAxis::man, ReplotPolicy::justUpdate);
    adjustAxisFullCanvas();
}

void TestPlot::timingUpdate()
{
    static int start = 0;

    start++;

    setPlayWidgetsLabel(QString::number(start));

    QVector<double> xx1, yy1;

    for (size_t i = start; i < start + 100; i++)
    {
        xx1.append(i);
        yy1.append(20 * sin(0.1 * i));
    }
    updateCurve(0, xx1, yy1, ReplotPolicy::fullCanvas);
}

void TestPlot::otherAction(QMenu *menu)
{
    menu->addAction(QString::fromLocal8Bit("计算平均值"), this, [&](){
        qDebug()<<selected_Y_avg;
    });
}
