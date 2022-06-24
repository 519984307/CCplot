#ifndef CCPLOTBENDMOMENT_H
#define CCPLOTBENDMOMENT_H

#include "plotbase.h"

class CCPlotBendMoment : public PlotBase {
 public:
  CCPlotBendMoment(QWidget* parent);

  virtual void makeGraph();

  virtual void update(const QMap<QString, bool>& updateFlags);
};

#endif // CCPLOTBENDMOMENT_H
