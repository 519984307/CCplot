#include "ccplotforcexy.h"

CCPlotForceXY::CCPlotForceXY(QWidget* parent):
  PlotBase(parent) {
}


void CCPlotForceXY::makeGraph() {
  // 1.标题
  TitleProp t(QString::fromLocal8Bit("冰力(xy面内)"),
              QFont("Microsoft YaHei", 12, QFont::Bold));
  addTitle(t);

  // 2.坐标轴
  AxisProp xAxis(QString::fromLocal8Bit("X [m]"), RangeProp(0, 100));
  setAxis(xAxis, axisPosition::atDown);

  AxisProp yAxis(QString::fromLocal8Bit("Y [m]"), RangeProp(0, 100));
  setAxis(yAxis, axisPosition::atLeft);

  showMainAxis(false);
  showSubAxis(false);

  // 3.图例   getHullfor
  showLegend(false);

  // 4.显示播放区域
  showPlayWidgets(true);

  // 5.加载船节点
  loadHullGraph();

  // 6.加载xyz冰力
  loadHullForceXYZ();
}


void CCPlotForceXY::timingUpdate() {
  qDebug() << "123";

  canvas->clearItems();

  getHullForceXY(nowStep);

  for (size_t i = 0; i < arrow_start_x.length(); i++) {
    QCPItemCurve* arrow = new QCPItemCurve(canvas);
    arrow->start->setCoords(arrow_start_x[i], arrow_strat_y[i]);
    arrow->startDir->setCoords(arrow_end_x[i], arrow_end_y[i]);

    arrow->end->setCoords(arrow_end_x[i], arrow_end_y[i]);
    arrow->endDir->setCoords(arrow_start_x[i], arrow_strat_y[i]);
    arrow->setHead(QCPLineEnding::esSpikeArrow);
  }

  canvas->replot();
}


void CCPlotForceXY::slider_playWidgets_valueChanged(int value) {
  nowStep = value;
  qDebug() << nowStep;
  timingUpdate();
}


void CCPlotForceXY::loadHullGraph() {
  CurveProp hull_curve(QString::fromLocal8Bit("hull_curve"), QColor(0, 0, 240));
  hull_curve.lineStyle = (QCPGraph::LineStyle)0;
  hull_curve.scatterStyle =
      QCPScatterStyle((QCPScatterStyle::ScatterShape)4, 6);

  addCurve(hull_curve, ReplotPolicy::justUpdate);

  hull_x.clear();
  hull_y.clear();

//  auto matFilePath = ProjectMaster::GetInstance()->getResultMatPath();
  auto matFilePath = R"(C:\Users\dwb\Desktop\result.mat)";

  Eigen::MatrixXd hull;
  auto flag1 = QMatlab::MatUtil::getMatrix(matFilePath, "hull", hull);

  if (!flag1) {
    auto msg = QString::fromLocal8Bit("未找到变量");
    QMessageBox::warning(this, QString::fromLocal8Bit("警告"), msg);
    return;
  }

  if (hull.cols() != 2) {
    return;
  }

  for (size_t i = 0; i < hull.rows(); i++) {
    hull_x.append(hull(i, 0));
    hull_y.append(hull(i, 1));
  }

  // set hull curve
  auto g = canvas->graph(0);
  if (g == nullptr) {
    return;
  }
  g->setData(hull_x, hull_y);


  adjustAxisKeepRatio();
}


void CCPlotForceXY::loadHullForceXYZ() {
//    auto matFilePath = ProjectMaster::GetInstance()->getResultMatPath();
  auto matFilePath = R"(C:\Users\dwb\Desktop\result.mat)";

  QMatlab::MatUtil::getCell(matFilePath, "F_hull", cell);

  if (cell.rows() <= 0)
    return;
  if (cell(0, 0).rows() <= 0)
    return;

  steps = cell(0, 0).rows();
}


void CCPlotForceXY::getHullForceXY(int step) {
  arrow_start_x.clear();
  arrow_strat_y.clear();
  arrow_end_x.clear();
  arrow_end_y.clear();

  QVector<HullForce> hullForces;

  for (size_t r = 0; r < cell.rows(); r++) {
    auto fx = cell(r, 0)(step, 0);
    auto fy = cell(r, 0)(step, 1);
    auto fz = cell(r, 0)(step, 2);
    hullForces.append(HullForce(fx, fy, fz));
  }

  if (hull_x.length() != hullForces.length()) {
    return;
  }

  for (int i = 0; i < hullForces.length(); i++) {

    if (hullForces[i].fx == 0 && hullForces[i].fy == 0)
      continue;

    double p_x = hull_x[i];
    double p_y = hull_y[i];

    double l_x = scale * hullForces[i].fx;
    double l_y = scale * hullForces[i].fy;

    arrow_start_x.append(p_x);
    arrow_strat_y.append(p_y);
    arrow_end_x.append(p_x + l_x);
    arrow_end_y.append(p_y + l_y);
  }
}
