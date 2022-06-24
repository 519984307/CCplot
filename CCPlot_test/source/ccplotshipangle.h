#ifndef CCPLOTSHIPANGLE_H
#define CCPLOTSHIPANGLE_H

#include "plotbase.h"

class CCPlotShipAngle : public PlotBase {
 public:
  CCPlotShipAngle(QWidget* parent);

  virtual void makeGraph();

  virtual void update(const QMap<QString, bool>& updateFlags);
};

#endif // CCPLOTSHIPANGLE_H
