#ifndef CCPLOTSHIPVELOCITY_H
#define CCPLOTSHIPVELOCITY_H

#include "plotbase.h"

class CCPlotShipVelocity : public PlotBase {
 public:
  CCPlotShipVelocity(QWidget* parent);

  virtual void makeGraph();

  virtual void update(const QMap<QString, bool>& updateFlags);

};

#endif // CCPLOTSHIPVELOCITY_H
