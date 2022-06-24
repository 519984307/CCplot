#include "ccplotforcez.h"


CCPlotForceZ::CCPlotForceZ(QWidget* parent):
  PlotBase(parent) {

}

void CCPlotForceZ::makeGraph() {
  // 1.标题
  TitleProp t(QString::fromLocal8Bit("冰力(Z轴)"),
              QFont("Microsoft YaHei", 12, QFont::Bold));
  addTitle(t);

  // 2.坐标轴
  AxisProp xAxis(QString::fromLocal8Bit("X [m]"), RangeProp(0, 100));
  setAxis(xAxis, axisPosition::atDown);

  AxisProp yAxis(QString::fromLocal8Bit("Y [m]"), RangeProp(0, 100));
  setAxis(yAxis, axisPosition::atLeft);

  showMainAxis(true);
  showSubAxis(true);

  // 3.图例
  showLegend(false);

  CurveProp ice_force_z(QString::fromLocal8Bit("hull_curve"),
                        QColor(0, 0, 240));
  ice_force_z.lineStyle = (QCPGraph::LineStyle)1;
  ice_force_z.scatterStyle =
      QCPScatterStyle((QCPScatterStyle::ScatterShape)4, 6);

  addCurve(ice_force_z, ReplotPolicy::justUpdate);

  //  canvas->replot();
  adjustAxisKeepRatio();

  showPlayWidgets(true);

  //
  loadHullForceXYZ();

  // 7.get steps
  setPlayWidgetsSliderRanger(0, steps - 1);
}

void CCPlotForceZ::timingUpdate() {
  getHullForceZ(nowStep);

  auto g = canvas->graph(0);

  if (g == nullptr)
    return;

  g->setData(xValue, force_z);

  //  canvas->replot();
  adjustAxisFullCanvas();
}

void CCPlotForceZ::slider_playWidgets_valueChanged(int value) {
  nowStep = value;
  qDebug() << nowStep;
  timingUpdate();
}

void CCPlotForceZ::loadHullForceXYZ() {
  //    auto matFilePath = ProjectMaster::GetInstance()->getResultMatPath();
  auto matFilePath = R"(C:\Users\dwb\Desktop\result.mat)";

  QMatlab::MatUtil::getCell(matFilePath, "F_hull", cell);

  if (cell.rows() <= 0)
    return;
  if (cell(0, 0).rows() <= 0)
    return;

  steps = cell(0, 0).rows();
}

void CCPlotForceZ::getHullForceZ(int step) {
  xValue.clear();
  force_z.clear();

  for (int i = 0; i < cell.rows(); i++) {
    force_z.append(cell(i, 0)(step, 0));
    xValue.append(i);
  }
}
