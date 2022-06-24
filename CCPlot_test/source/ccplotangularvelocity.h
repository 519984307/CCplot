#ifndef CCPLOTANGULARVELOCITY_H
#define CCPLOTANGULARVELOCITY_H

#include "plotbase.h"

class CCPlotAngularVelocity : public PlotBase {
 public:
  CCPlotAngularVelocity(QWidget* parent);

  virtual void makeGraph();

  virtual void update(const QMap<QString, bool>& updateFlags);
};

#endif // CCPLOTANGULARVELOCITY_H
