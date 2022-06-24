#include "testplot.h"
#include <QtMath>>

TestPlot::TestPlot(QWidget* parent):
  CCPlot(parent) {

}

void TestPlot::makeGraph() {
  //1.标题
  TitleProp t(QString::fromLocal8Bit("测试标题"),
              QFont("Microsoft YaHei", 12, QFont::Bold));
  addTitle(t);

  //2.坐标轴
  AxisProp xAxis(QString::fromLocal8Bit("x轴"),
                 RangeProp(0, 100));
  setAxis(xAxis, axisPosition::atDown);

  AxisProp yAxis(QString::fromLocal8Bit("y轴 [单位]"),
                 RangeProp(0, 100));
  setAxis(yAxis, axisPosition::atLeft);

  showMainAxis(true);
  showSubAxis(true);

  //3.图例
  showLegend(true);

  //4.播放区
  showPlayWidgets(true);
}

void TestPlot::update() {
  CurveProp C1(QString::fromLocal8Bit("曲线1"), QColor(255, 0, 0));
  CurveProp C2(QString::fromLocal8Bit("曲线2"), QColor(0, 255, 0));
  CurveProp C3(QString::fromLocal8Bit("曲线3"), QColor(0, 0, 255));

  for (size_t i = 0; i < 100; i++) {
    C1.xx.append(i);
    C2.xx.append(i);
    C3.xx.append(i);

    C1.yy.append(20 * sin(0.1 * i));
    C2.yy.append(50 * sin(0.2 * i));
    C3.yy.append(80 * sin(0.5 * i));
  }

  addCurve(C1, ReplotPolicy::fullCanvas);
  addCurve(C2, ReplotPolicy::fullCanvas);
  addCurve(C3, ReplotPolicy::fullCanvas);

}

void TestPlot::timingUpdate() {
  static int start = 0;

  start++;

  setPlayWidgetsLabel(QString::number(start));

  QVector<double> xx1, yy1;
  QVector<double> xx2, yy2;
  QVector<double> xx3, yy3;

  for (size_t i = start; i < start + 100; i++) {
    xx1.append(i);
    xx2.append(i);
    xx3.append(i);

    yy1.append(20 * sin(0.1 * i));
    yy2.append(50 * sin(0.2 * i));
    yy3.append(80 * sin(0.5 * i));
  }

  updateCurve(0, xx1, yy1, ReplotPolicy::fullCanvas);
  updateCurve(1, xx2, yy2, ReplotPolicy::fullCanvas);
  updateCurve(2, xx3, yy3, ReplotPolicy::fullCanvas);
}
