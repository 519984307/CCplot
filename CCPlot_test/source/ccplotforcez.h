#ifndef CCPLOTFORCEZ_H
#define CCPLOTFORCEZ_H

#include "plotbase.h"

class CCPlotForceZ : public PlotBase {
 public:
  CCPlotForceZ(QWidget* parent);

  virtual void makeGraph();

  virtual void timingUpdate();

  virtual void slider_playWidgets_valueChanged(int value);

 private:
  QMatlab::MatUtil::Cell cell;

  QVector<double> xValue;

  QVector<double> force_z;

  int steps = 0;

  int nowStep = 0;

  void loadHullForceXYZ();

  void getHullForceZ(int step = 0);
};

#endif // CCPLOTFORCEZ_H
