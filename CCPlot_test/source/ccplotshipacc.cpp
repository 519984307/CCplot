#include "ccplotshipacc.h"

CCPlotShipAcc::CCPlotShipAcc(QWidget* parent):
  PlotBase(parent) {

}

void CCPlotShipAcc::makeGraph() {
  //1.标题
  TitleProp t(QString::fromLocal8Bit("船加速度"),
              QFont("Microsoft YaHei", 12, QFont::Bold));
  addTitle(t);

  //2.坐标轴
  AxisProp xAxis(QString::fromLocal8Bit("时间步"),
                 RangeProp(0, 100));
  setAxis(xAxis, axisPosition::atDown);

  AxisProp yAxis(QString::fromLocal8Bit("加速度 [m/s^2]"),
                 RangeProp(0, 100));
  setAxis(yAxis, axisPosition::atLeft);

  showMainAxis(true);
  showSubAxis(true);

  //3.图例
  showLegend(true);
}

void CCPlotShipAcc::update(const QMap<QString, bool>& updateFlags) {
  //0.clear graph
  removeAllGraph();

  //1.get matrix from mat file
  Eigen::MatrixXd acc;
//  auto matFilePath = ProjectMaster::GetInstance()->getResultMatPath();
  auto matFilePath = R"(C:\Users\dwb\Desktop\result.mat)";

  auto paramName = "ACCELARATION";
  auto flag = QMatlab::MatUtil::getMatrix(matFilePath, paramName, acc);

  if (!flag) {
    auto msg = QString::fromLocal8Bit("未找到变量") + paramName;
    QMessageBox::warning(this, QString::fromLocal8Bit("警告"), msg);
    return;
  }

  //2.prepare curves
  auto surge = acc.col(0);
  auto sway = acc.col(1);
  auto heave = acc.col(2);
  auto roll = acc.col(3);
  auto pitch = acc.col(4);
  auto yaw = acc.col(5);

  auto makePoints = [&](Eigen::MatrixXd m, CurveProp & C) {
    for (int i = 0; i < m.rows(); i++) {
      C.xx.append(i);
      C.yy.append(m(i, 0));
    }

  };

  CurveProp C1(QString::fromLocal8Bit("surge"), QColor(255, 0, 0));
  CurveProp C2(QString::fromLocal8Bit("sway"), QColor(0, 255, 0));
  CurveProp C3(QString::fromLocal8Bit("heave"), QColor(0, 0, 255));
  CurveProp C4(QString::fromLocal8Bit("roll"), QColor(255, 0, 255));
  CurveProp C5(QString::fromLocal8Bit("pitch"), QColor(0, 255, 255));
  CurveProp C6(QString::fromLocal8Bit("yaw"), QColor(255, 255, 0));

  if (updateFlags[C1.name]) {
    makePoints(surge, C1);
    addCurve(C1, ReplotPolicy::justUpdate);
  }

  if (updateFlags[C2.name]) {
    makePoints(sway, C2);
    addCurve(C2, ReplotPolicy::justUpdate);
  }

  if (updateFlags[C3.name]) {
    makePoints(heave, C3);
    addCurve(C3, ReplotPolicy::justUpdate);
  }

  if (updateFlags[C4.name]) {
    makePoints(roll, C4);
    addCurve(C4, ReplotPolicy::justUpdate);
  }

  if (updateFlags[C5.name]) {
    makePoints(pitch, C5);
    addCurve(C5, ReplotPolicy::justUpdate);
  }

  if (updateFlags[C6.name]) {
    makePoints(yaw, C6);
    addCurve(C6, ReplotPolicy::justUpdate);
  }


  //3.show full canvas
  adjustAxisFullCanvas();
}
