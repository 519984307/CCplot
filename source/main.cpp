#include <QApplication>
#include "testplot.h"
#include "testplot2.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    TestPlot p(nullptr);
    p.show();
    p.makeGraph();
    p.update();

//    TestPlot2 tp2;
//    tp2.show();

    return a.exec();
}
