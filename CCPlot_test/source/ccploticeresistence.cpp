#include "ccploticeresistence.h"


CCPlotIceResistence::CCPlotIceResistence(QWidget* parent):
  PlotBase(parent) {

}

void CCPlotIceResistence::makeGraph() {
  //1.标题
  TitleProp t(QString::fromLocal8Bit("冰阻力"),
              QFont("Microsoft YaHei", 12, QFont::Bold));
  addTitle(t);

  //2.坐标轴
  AxisProp xAxis(QString::fromLocal8Bit("时间步"),
                 RangeProp(0, 100));
  setAxis(xAxis, axisPosition::atDown);

  AxisProp yAxis(QString::fromLocal8Bit("阻力 [KN]"),
                 RangeProp(0, 100));
  setAxis(yAxis, axisPosition::atLeft);

  showMainAxis(true);
  showSubAxis(true);

  //3.图例
  showLegend(true);

}

void CCPlotIceResistence::update(const QMap<QString, bool>& updateFlags) {
  //0.clear graph
  removeAllGraph();

  //1.get matrix from mat file
  Eigen::MatrixXd F_glo, F_SUB;
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

  auto paramName2 = "F_SUB";
  //  auto flag2 = MatFileUtil::GetInstance()->getParam(matFilePath, paramName2, F_SUB);
  auto flag2 = QMatlab::MatUtil::getMatrix(matFilePath, paramName2, F_SUB);

  if (!flag2) {
    auto msg = QString::fromLocal8Bit("未找到变量") + paramName2;
    QMessageBox::warning(this, QString::fromLocal8Bit("警告"), msg);
    return;
  }

  //2.prepare curves
  auto r_zongxiang = F_glo.col(0);
  auto r_hengxiang = F_glo.col(1);
  auto r_chuixiang = F_glo.col(2);

  CurveProp C1(QString::fromLocal8Bit("纵向"), QColor(255, 0, 0));
  CurveProp C2(QString::fromLocal8Bit("横向"), QColor(0, 255, 0));
  CurveProp C3(QString::fromLocal8Bit("垂向"), QColor(0, 0, 255));

  auto makePoints = [&](Eigen::MatrixXd m, CurveProp & C) {
    for (int i = 0; i < m.rows(); i++) {
      C.xx.append(i);
      C.yy.append(m(i, 0));
    }
  };

  if (updateFlags[C1.name]) {
    makePoints(r_zongxiang, C1);
    addCurve(C1, ReplotPolicy::justUpdate);
  }

  if (updateFlags[C2.name]) {
    makePoints(r_hengxiang, C2);
    addCurve(C2, ReplotPolicy::justUpdate);
  }

  if (updateFlags[C1.name]) {
    makePoints(r_chuixiang, C3);
    addCurve(C3, ReplotPolicy::justUpdate);
  }

  //3.show full canvas
  adjustAxisFullCanvas();
}
