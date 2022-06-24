#include "ccplotbendmoment.h"


CCPlotBendMoment::CCPlotBendMoment(QWidget* parent):
  PlotBase(parent) {

}

void CCPlotBendMoment::makeGraph() {
  //1.标题
  TitleProp t(QString::fromLocal8Bit("冰弯矩"),
              QFont("Microsoft YaHei", 12, QFont::Bold));
  addTitle(t);

  //2.坐标轴
  AxisProp xAxis(QString::fromLocal8Bit("时间步"),
                 RangeProp(0, 100));
  setAxis(xAxis, axisPosition::atDown);

  AxisProp yAxis(QString::fromLocal8Bit("弯矩 [KN.m]"),
                 RangeProp(0, 100));
  setAxis(yAxis, axisPosition::atLeft);

  showMainAxis(true);
  showSubAxis(true);

  //3.图例
  showLegend(true);
}

void CCPlotBendMoment::update(const QMap<QString, bool>& updateFlags) {
  //0.clear graph
  removeAllGraph();

  //1.get matrix from mat file
  Eigen::MatrixXd F_glo;
//  auto matFilePath = ProjectMaster::GetInstance()->getResultMatPath();
  auto matFilePath = R"(C:\Users\dwb\Desktop\result.mat)";

  auto paramName = "F_glo";
  //  auto flag = MatFileUtil::GetInstance()->getParam(matFilePath, paramName, F_glo);
  auto flag = QMatlab::MatUtil::getMatrix(matFilePath, paramName, F_glo);

  if (!flag) {
    auto msg = QString::fromLocal8Bit("未找到变量") + paramName;
    QMessageBox::warning(this, QString::fromLocal8Bit("警告"), msg);
    return;
  }

  //2.prepare curves
  auto M_yz = F_glo.col(3);
  auto M_xz = F_glo.col(4);
  auto M_xy = F_glo.col(5);

  auto makePoints = [&](Eigen::MatrixXd m, CurveProp & C) {
    for (int i = 0; i < m.rows(); i++) {
      C.xx.append(i);
      C.yy.append(m(i, 0));
    }
  };

  CurveProp C1(QString::fromLocal8Bit("M_yz"), QColor(255, 0, 0));
  CurveProp C2(QString::fromLocal8Bit("M_xz"), QColor(0, 255, 0));
  CurveProp C3(QString::fromLocal8Bit("M_xy"), QColor(0, 0, 255));

  if (updateFlags[C1.name]) {
    makePoints(M_yz, C1);
    addCurve(C1, ReplotPolicy::justUpdate);
  }

  if (updateFlags[C2.name]) {
    makePoints(M_xz, C2);
    addCurve(C2, ReplotPolicy::justUpdate);
  }

  if (updateFlags[C3.name]) {
    makePoints(M_xy, C3);
    addCurve(C3, ReplotPolicy::justUpdate);
  }

  //3.show full canvas
  adjustAxisFullCanvas();
}
