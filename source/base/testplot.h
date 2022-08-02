#ifndef TESTPLOT_H
#define TESTPLOT_H

#include "ccplot.h"

class TestPlot : public CCPlot {
 public:
  TestPlot(QWidget* parent = nullptr);

  virtual void makeGraph();

  virtual void update();

  virtual void timingUpdate();

  virtual void otherAction(QMenu* menu) override;
};

#endif // TESTPLOT_H
