#include "ccplotangularvelocity.h"

#include <QMatlab.h>

CCPlotAngularVelocity::CCPlotAngularVelocity(QWidget* parent):
  PlotBase(parent) {
}

void CCPlotAngularVelocity::makeGraph() {
  //1.标题
  TitleProp t(QString::fromLocal8Bit("船角速度"),
              QFont("Microsoft YaHei", 12, QFont::Bold));
  addTitle(t);

  //2.坐标轴
  AxisProp xAxis(QString::fromLocal8Bit("时间步"), RangeProp(0, 100));
  setAxis(xAxis, axisPosition::atDown);

  AxisProp yAxis(QString::fromLocal8Bit("角速度 [rad/s]"), RangeProp(0, 100));
  setAxis(yAxis, axisPosition::atLeft);

  showMainAxis(true);
  showSubAxis(true);

  //3.图例
  showLegend(true);
}

void CCPlotAngularVelocity::update(const QMap<QString, bool>& updateFlags) {
  //0.clear graph
  removeAllGraph();

  //1.get matrix from mat file
  Eigen::MatrixXd Motion;
//  auto matFilePath = ProjectMaster::GetInstance()->getResultMatPath();
  auto matFilePath = R"(C:\Users\dwb\Desktop\result.mat)";

  auto paramName = "Motion";
  auto flag = QMatlab::MatUtil::getMatrix(matFilePath, paramName, Motion);

  if (!flag) {
    auto msg = QString::fromLocal8Bit("未找到变量 ") + paramName;
    QMessageBox::warning(this, QString::fromLocal8Bit("警告 "), msg);
    return;
  }

  //2.prepare curves
  auto a_v_hengyao = Motion.col(9);
  auto a_v_zongyao = Motion.col(10);
  auto a_v_shouyao = Motion.col(11);

  auto makePoints = [&](Eigen::MatrixXd m, CurveProp & C) {
    for (int i = 0; i < m.rows(); i++) {
      C.xx.append(i);
      C.yy.append(m(i, 0));
    }
  };

  CurveProp C1(QString::fromLocal8Bit("横摇"), QColor(255, 0, 0));
  CurveProp C2(QString::fromLocal8Bit("纵摇"), QColor(0, 255, 0));
  CurveProp C3(QString::fromLocal8Bit("艏摇"), QColor(0, 0, 255));

  if (updateFlags[C1.name]) {
    makePoints(a_v_hengyao, C1);
    addCurve(C1, ReplotPolicy::justUpdate);
  }

  if (updateFlags[C2.name]) {
    makePoints(a_v_zongyao, C2);
    addCurve(C2, ReplotPolicy::justUpdate);
  }

  if (updateFlags[C3.name]) {
    makePoints(a_v_shouyao, C3);
    addCurve(C3, ReplotPolicy::justUpdate);
  }


  //3.show full canvas
  adjustAxisFullCanvas();
}
