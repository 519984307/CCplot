#ifndef CCPLOTSHIPACC_H
#define CCPLOTSHIPACC_H

#include "plotbase.h"

class CCPlotShipAcc : public PlotBase {
 public:
  CCPlotShipAcc(QWidget* parent);

  virtual void makeGraph();

  virtual void update(const QMap<QString, bool>& updateFlags);
};

#endif // CCPLOTSHIPACC_H
