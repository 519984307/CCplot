#ifndef CCPLOTWATERLINE_H
#define CCPLOTWATERLINE_H

#include "plotbase.h"
#include "point.h"

using points = QVector<Point>;
using line = QVector<Point>;
using waterlines = QVector<line>;

class CCPlotWaterline : public PlotBase {
 public:
  CCPlotWaterline(QWidget* parent);

  virtual void makeGraph();

  virtual void update();

 public:
  void setWaterline(int graphIndex, const line& line);

 private:
  QVector<double> xx, yy;

  int graphIndex;

};

#endif // CCPLOTWATERLINE_H
