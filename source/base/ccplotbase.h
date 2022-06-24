#ifndef CCPLOTBASE_H
#define CCPLOTBASE_H

#include <QWidget>
#include "qcustomplot.h"

class CCPlotBase : public QWidget
{
    Q_OBJECT
public:
    explicit CCPlotBase(QWidget *parent = nullptr);
    ~CCPlotBase();

signals:

};

#endif // CCPLOTBASE_H
