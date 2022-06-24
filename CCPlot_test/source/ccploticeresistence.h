#ifndef CCPLOTICERESISTENCE_H
#define CCPLOTICERESISTENCE_H

#include "plotbase.h"

class CCPlotIceResistence : public PlotBase {
 public:
  CCPlotIceResistence(QWidget* parent);

  virtual void makeGraph();

  virtual void update(const QMap<QString, bool>& updateFlags);
};

#endif // CCPLOTICERESISTENCE_H
