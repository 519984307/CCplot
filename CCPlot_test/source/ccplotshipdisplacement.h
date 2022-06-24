#ifndef CCPLOTSHIPDISPLACEMENT_H
#define CCPLOTSHIPDISPLACEMENT_H

#include "plotbase.h"

class CCPlotShipDisplacement : public PlotBase {
 public:
  CCPlotShipDisplacement(QWidget* parent);

  virtual void makeGraph();

  virtual void update(const QMap<QString, bool>& updateFlags);
};

#endif // CCPLOTSHIPDISPLACEMENT_H
