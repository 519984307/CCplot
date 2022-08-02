#include "ccplotelements.h"

CCPlotElements::CCPlotElements(QWidget* parent)
    : CCPlotLayout(parent)
{
    _title = new QCPTextElement(canvas);
}

CCPlotElements::~CCPlotElements() {}

void
CCPlotElements::showMainAxis(bool flag)
{
    canvas->xAxis->setVisible(flag);
    canvas->yAxis->setVisible(flag);

    canvas->replot();
}

void
CCPlotElements::showSubAxis(bool flag)
{
    canvas->xAxis2->setVisible(flag);
    canvas->yAxis2->setVisible(flag);

    canvas->replot();
}

void
CCPlotElements::setAxis(const AxisProp& axis, const axisPosition& posi)
{
    QCPAxis* selectedAxis = nullptr;
    switch (posi)
    {
        case axisPosition::atLeft:
            selectedAxis = canvas->yAxis;
            break;

        case axisPosition::atDown:
            selectedAxis = canvas->xAxis;
            break;

        case axisPosition::atRight:
            selectedAxis = canvas->yAxis2;
            break;

        case axisPosition::atTop:
            selectedAxis = canvas->xAxis2;

        default:
            break;
    }

    setAxis(axis, selectedAxis);
}

void
CCPlotElements::setAxis(const AxisProp& axis, QCPAxis* selectedAxis)
{
    if (selectedAxis == nullptr)
        return;

    selectedAxis->setLabel(axis.label);
    selectedAxis->setRange(axis.range.min, axis.range.max);

    canvas->replot();
}

void
CCPlotElements::adjustAxisKeepRatio(int center_x, int center_y)
{
    auto width = canvas->width();
    auto heigth = canvas->height();

    double a = 0.25;
    double b = 0.25;

    canvas->xAxis->setRange(-a * width + center_x, a * width + center_x);
    canvas->yAxis->setRange(-b * heigth + center_y, b * heigth + center_y);

    canvas->replot();
}

void CCPlotElements::adjustAxisKeepRatio()
{
    auto g = canvas->graph(0);

    if (g == nullptr)
        return;

    auto data = g->data();
    QVector<double> xx, yy;

    for (auto it = data->begin(); it != data->end(); it++)
    {
        xx.append(it->key);
        yy.append(it->value);
    }

    auto [min, max] = std::minmax_element(xx.begin(), xx.end());
    auto center_x = (*min + *max) / 2;

    auto [min2, max2] = std::minmax_element(yy.begin(), yy.end());
    auto center_y = (*min2 + *max2) / 2;

    adjustAxisKeepRatio(center_x, center_y);
}

void
CCPlotElements::adjustAxisFullCanvas()
{
    if (!useTwoAxisSystem)
    {
        canvas->rescaleAxes();
    }
    else
    {
        this->adjustTwoAxisSystem();
    }
    canvas->replot();
}

void CCPlotElements::adjustTwoAxisSystem()
{
    if (canvas->graphCount() == 0)
        return;

    //1.设置x轴范围
    auto data = canvas->graph(0)->data();
    QVector<double> xx;

    for (auto it = data->begin(); it != data->end(); it++)
    {
        xx.append(it->key);
    }
    auto [xmin, xmax] = std::minmax_element(xx.begin(), xx.end());
    canvas->xAxis->setRange(*xmin, *xmax);


    //2.设置yAxis1范围
    QVector<double> yy;
    for (size_t i = 0; i < canvas->graphCount(); i++)
    {
        auto g = canvas->graph(i);
        if (g->valueAxis() != canvas->yAxis)
            continue;

        auto data = g->data();
        for (auto it = data->begin(); it != data->end(); it++)
        {
            yy.append(it->value);
        }
    }
    auto [ymin1, ymax1] = std::minmax_element(yy.begin(), yy.end());
    canvas->yAxis->setRange(*ymin1, *ymax1);


    //2.设置yAxis2范围
    QVector<double> yy2;
    for (size_t i = 0; i < canvas->graphCount(); i++)
    {
        auto g = canvas->graph(i);
        if (g->valueAxis() != canvas->yAxis2)
            continue;

        auto data = g->data();
        for (auto it = data->begin(); it != data->end(); it++)
        {
            yy2.append(it->value);
        }
    }
    auto [ymin2, ymax2] = std::minmax_element(yy2.begin(), yy2.end());
    canvas->yAxis2->setRange(*ymin2, *ymax2);
}

void
CCPlotElements::showLegend(bool flag)
{
    canvas->legend->setVisible(flag);
    canvas->replot();
}

void
CCPlotElements::removeTitle()
{
    //元素仅一个的时候，是绘图区域，不能移除
    if (canvas->plotLayout()->elementCount() > 1)
    {
        canvas->plotLayout()->removeAt(canvas->plotLayout()->rowColToIndex(0, 0));
        canvas->plotLayout()->simplify();
        canvas->replot();
    }
}

void
CCPlotElements::addTitle(const TitleProp& title)
{
    canvas->plotLayout()->insertRow(0);

    _title = new QCPTextElement(canvas);
    _title->setText(title.text);
    _title->setFont(title.font);
    canvas->plotLayout()->addElement(0, 0, _title);
    canvas->replot();
}

void
CCPlotElements::addDefaultTitle()
{
    addTitle();
}

void
CCPlotElements::setTitle(const TitleProp& titleProp)
{
    if (canvas->plotLayout()->elementCount() > 1)
    {
        removeTitle();
    }
    addTitle(titleProp);
}

void
CCPlotElements::removeAllGraph()
{
    canvas->clearGraphs();
    canvas->replot();
}

void
CCPlotElements::removeGraph(int graphIndex)
{
    auto g = canvas->graph(graphIndex);

    if (g == nullptr)
        return;

    removeGraph(g);
}

void
CCPlotElements::removeGraph(QCPGraph* graph)
{
    if (graph == nullptr)
        return;

    canvas->removeGraph(graph);
}

void
CCPlotElements::policedReplot(ReplotPolicy rp)
{
    switch (rp)
    {
        case ReplotPolicy::justUpdate:
            canvas->replot();
            break;
        case ReplotPolicy::fullCanvas:
            canvas->replot();
            adjustAxisFullCanvas();
            break;
        case ReplotPolicy::keepRatio:
            canvas->replot();
            adjustAxisKeepRatio();
            break;
        default:
            break;
    };
}

void
CCPlotElements::setCurve(QCPGraph* g, const CurveProp& curveProp, ReplotPolicy rp)
{
    if (g == nullptr)
        return;

    g->setName(curveProp.name);
    g->setPen(curveProp.pen);
    g->setLineStyle(curveProp.lineStyle);
    g->setScatterStyle(curveProp.scatterStyle);

    policedReplot(rp);
}

void
CCPlotElements::setCurve(const QString& curveName,
                         const CurveProp& curveProp,
                         ReplotPolicy rp)
{
    for (int i = 0; i < canvas->graphCount(); i++)
    {
        auto g = canvas->graph(i);

        if (g == nullptr)
            continue;

        if (g->name() == curveProp.name)
        {
            setCurve(g, curveProp, rp);
            return;
        }
    }
}

void
CCPlotElements::setCurve(int graphIndex,
                         const CurveProp& curveProp,
                         ReplotPolicy rp)
{
    auto g = canvas->graph(graphIndex);

    if (g == nullptr)
        return;

    setCurve(g, curveProp, rp);
}

void
CCPlotElements::updateCurve(QCPGraph* g,
                            const QVector<double>& xx,
                            const QVector<double>& yy,
                            ReplotPolicy rp)
{
    if (g == nullptr)
        return;

//  g->data().clear();
    g->setData(xx, yy);

    policedReplot(rp);
}

void
CCPlotElements::updateCurve(int graphIndex,
                            const QVector<double>& xx,
                            const QVector<double>& yy,
                            ReplotPolicy rp)
{
    auto g = canvas->graph(graphIndex);

    if (g == nullptr)
    {
        return;
    }

    updateCurve(g, xx, yy, rp);
}

void
CCPlotElements::addCurve(const CurveProp& curveProp, ReplotPolicy rp)
{
    auto g = canvas->addGraph();

    setCurve(g, curveProp, rp);

    updateCurve(g, curveProp.xx, curveProp.yy, rp);
}

void CCPlotElements::addCurve(const CurveProp& curveProp, whichAxis wa, ReplotPolicy rp)
{
    QCPGraph* g = nullptr;

    wa == whichAxis::man ?
    g = canvas->addGraph(canvas->xAxis, canvas->yAxis) : g = canvas->addGraph(canvas->xAxis2, canvas->yAxis2);

    setCurve(g, curveProp, rp);

    updateCurve(g, curveProp.xx, curveProp.yy, rp);
}

void
CCPlotElements::print(const PrintProp& printProp)
{
    auto width = canvas->width();
    auto heigth = canvas->height();
    auto scale = printProp.scale;
    auto quality = printProp.quality;
    auto resl = printProp.resolution;

    auto temPath = printProp.savePath + "/" + printProp.saveName;

    switch (printProp.format)
    {
        case PrintFormat::BMP:
            canvas->saveBmp(temPath + ".bmp", width, heigth, scale, resl);
            break;
        case PrintFormat::JPG:
            canvas->saveJpg(temPath + ".jpg", width, heigth, scale, quality, resl);
            break;

        case PrintFormat::PNG:
            canvas->savePng(temPath + ".png", width, heigth, scale, quality, resl);
            break;
        default:
            break;
    }

    if (printProp.isOpenOutputFolder == true)
    {
        QDesktopServices::openUrl(QUrl(printProp.savePath, QUrl::TolerantMode));
    }
}
