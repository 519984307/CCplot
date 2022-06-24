#include <QApplication>
#include "ccplot.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CCPlot p(nullptr);
    p.show();
    return a.exec();
}
