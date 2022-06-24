#include "ccplot.h"

CCPlot::CCPlot(QWidget* parent):
  CCPlotInterication(parent) {
  timer = new QTimer(this);
  timer->setInterval(100);//10Hz
  connect(timer, &QTimer::timeout, this, &CCPlot::timingUpdate);
  connect(timer, &QTimer::timeout, this, [&]() {
    auto nextStep = getPlayWidgetsSliderValue() + 1;

    int start, end;
    getPlayWidgetsSliderRanger(start, end);

    if (nextStep > end - 1) {
      timer->stop();
      setPlayWidgetsSliderValue(0);
    } else {
      setPlayWidgetsSliderValue(nextStep);
    }
  });

  showPlayWidgets(true);
}

CCPlot::~CCPlot() {

}

void CCPlot::makeGraph() {
  //pass
}

void CCPlot::update() {
  //pass
}

void CCPlot::update(const QMap<QString, bool>& updateFlags) {
  //pass
}

void CCPlot::timingUpdate() {
  //pass
}

