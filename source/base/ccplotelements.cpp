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
  switch (posi) {
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
CCPlotElements::adjustAxisKeepRatio()
{
  auto width = canvas->width();
  auto heigth = canvas->height();

  double a = 0.3;
  double b = 0.3;

  canvas->xAxis->setRange(-a * width, a * width);
  canvas->yAxis->setRange(-b * heigth, b * heigth);

  canvas->replot();
}

void
CCPlotElements::adjustAxisFullCanvas()
{
  canvas->rescaleAxes();
  canvas->replot();
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
  if (canvas->plotLayout()->elementCount() > 1) {
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
  if (canvas->plotLayout()->elementCount() > 1) {
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
  switch (rp) {
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
  for (int i = 0; i < canvas->graphCount(); i++) {
    auto g = canvas->graph(i);

    if (g == nullptr)
      continue;

    if (g->name() == curveProp.name) {
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

  g->data().clear();
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

  if (g == nullptr) {
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

void
CCPlotElements::print(const PrintProp& printProp)
{
  auto width = canvas->width();
  auto heigth = canvas->height();
  auto scale = printProp.scale;
  auto quality = printProp.quality;
  auto resl = printProp.resolution;

  auto temPath = printProp.savePath + "/" + printProp.saveName;

  switch (printProp.format) {
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

  if (printProp.isOpenOutputFolder == true) {
    QDesktopServices::openUrl(QUrl(printProp.savePath, QUrl::TolerantMode));
  }
}
