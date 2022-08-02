#ifndef TESTPLOT2_H
#define TESTPLOT2_H

#include "ccplot.h"

class TestPlot2 : public CCPlot
{
public:
    TestPlot2();



    // CCPlotLayout interface
protected:
    void btn_moveCanvas_clicked(bool isChecked);
    void btn_property_clicked();
    void btn_fullView_clicked();
    void btn_ratioView_clicked();
    void btn_print_clicked();
};

#endif // TESTPLOT2_H
