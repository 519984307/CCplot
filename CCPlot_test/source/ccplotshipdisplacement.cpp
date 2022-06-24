﻿#include "ccplotshipdisplacement.h"


CCPlotShipDisplacement::CCPlotShipDisplacement(QWidget* parent):
  PlotBase(parent) {

}

void CCPlotShipDisplacement::makeGraph() {
  //1.标题
  TitleProp t(QString::fromLocal8Bit("船位移"),
              QFont("Microsoft YaHei", 12, QFont::Bold));
  addTitle(t);

  //2.坐标轴
  AxisProp xAxis(QString::fromLocal8Bit("时间步"),
                 RangeProp(0, 100));
  setAxis(xAxis, axisPosition::atDown);

  AxisProp yAxis(QString::fromLocal8Bit("位移 [m]"),
                 RangeProp(0, 100));
  setAxis(yAxis, axisPosition::atLeft);

  showMainAxis(true);
  showSubAxis(true);

  //3.图例
  showLegend(true);
}

void CCPlotShipDisplacement::update(const QMap<QString, bool>& updateFlags) {
  //0.clear graph
  removeAllGraph();

  //1.get matrix from mat file
  Eigen::MatrixXd Motion;
//  auto matFilePath = ProjectMaster::GetInstance()->getResultMatPath();
  auto matFilePath = R"(C:\Users\dwb\Desktop\result.mat)";

  auto paramName = "Motion";
  auto flag = QMatlab::MatUtil::getMatrix(matFilePath, paramName, Motion);

  if (!flag) {
    auto msg = QString::fromLocal8Bit("未找到变量") + paramName;
    QMessageBox::warning(this, QString::fromLocal8Bit("警告"), msg);
    return;
  }


  //2.prepare curves
  auto zongXiang = Motion.col(0);
  auto hengXiang = Motion.col(1);
  auto chuiXiang = Motion.col(2);

  auto makePoints = [&](Eigen::MatrixXd m, CurveProp & C) {
    for (int i = 0; i < m.rows(); i++) {
      C.xx.append(i);
      C.yy.append(m(i, 0));
    }
  };

  CurveProp C1(QString::fromLocal8Bit("纵向"), QColor(255, 0, 0));
  CurveProp C2(QString::fromLocal8Bit("横向"), QColor(0, 255, 0));
  CurveProp C3(QString::fromLocal8Bit("垂向"), QColor(0, 0, 255));

  if (updateFlags[C1.name]) {
    makePoints(zongXiang, C1);
    addCurve(C1, ReplotPolicy::justUpdate);
  }

  if (updateFlags[C2.name]) {
    makePoints(hengXiang, C2);
    addCurve(C2, ReplotPolicy::justUpdate);
  }

  if (updateFlags[C3.name]) {
    makePoints(chuiXiang, C3);
    addCurve(C3, ReplotPolicy::justUpdate);
  }

  //3.show full canvas
  adjustAxisFullCanvas();
}