#ifndef CCPLOTFORCEXY_H
#define CCPLOTFORCEXY_H

#include "plotbase.h"

struct HullForce {
  double fx;
  double fy;
  double fz;

  HullForce():
    fx(0), fy(0), fz(0) {}

  HullForce(double _fx, double _fy, double _fz):
    fx(_fx), fy(_fy), fz(_fz) {}
};


class CCPlotForceXY : public PlotBase {
 public:
  CCPlotForceXY(QWidget* parent);

  virtual void makeGraph();

  virtual void timingUpdate();

  virtual void slider_playWidgets_valueChanged(int value);


 private:
  double scale = 0.0003;

  QVector<double> hull_x, hull_y;

  QVector<double> arrow_start_x, arrow_strat_y, arrow_end_x, arrow_end_y;

  QMatlab::MatUtil::Cell cell;

  int steps = 0;

  int nowStep = 0;

  void loadHullGraph();

  void loadHullForceXYZ();

  void getHullForceXY(int step = 0);


};

#endif // CCPLOTFORCEXY_H
