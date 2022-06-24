#include "ccplotwaterline.h"

CCPlotWaterline::CCPlotWaterline(QWidget* parent):
  PlotBase(parent) {

}

void CCPlotWaterline::makeGraph() {
  TitleProp t(QString::fromLocal8Bit("型线显示"), QFont("Microsoft YaHei", 12, QFont::Bold));
  addTitle(t);

  //2.坐标轴
  AxisProp xAxis(QString::fromLocal8Bit("X [m]"), RangeProp(0, 100));
  setAxis(xAxis, axisPosition::atDown);

  AxisProp yAxis(QString::fromLocal8Bit("Y [m]"), RangeProp(0, 100));
  setAxis(yAxis, axisPosition::atLeft);

  showMainAxis(true);
  showSubAxis(true);

  //3.图例
  showLegend(false);

  CurveProp C1(QString::fromLocal8Bit("down"), QColor(255, 0, 0));
  CurveProp C2(QString::fromLocal8Bit("center"), QColor(0, 255, 0));
  CurveProp C3(QString::fromLocal8Bit("up"), QColor(0, 0, 255));

  addCurve(C1, ReplotPolicy::justUpdate);
  addCurve(C2, ReplotPolicy::justUpdate);
  addCurve(C3, ReplotPolicy::justUpdate);
}

void CCPlotWaterline::update() {
  updateCurve(graphIndex, xx, yy, ReplotPolicy::fullCanvas);
}

void CCPlotWaterline::setWaterline(int graphIndex, const line& line) {
  QVector<double> xx, yy;

  for (int i = 0; i < line.length(); i++) {
    xx.append(line[i].x);
    yy.append(line[i].y);
  }
}
