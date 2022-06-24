#include <QApplication>
#include "testplot.h"

int main(int argc, char* argv[]) {
  QApplication a(argc, argv);
  TestPlot p(nullptr);
  p.show();
  p.makeGraph();
  p.update();
  return a.exec();
}
