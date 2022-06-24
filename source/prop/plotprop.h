#ifndef PLOTPROP_H
#define PLOTPROP_H

#include "animationprop.h"
#include "axisprop.h"
#include "curveprop.h"
#include "titleprop.h"

struct PlotProp
{
  AxisProp xaxisProp;
  AxisProp yaxisProp;
  QList<CurveProp> curveProps;
  TitleProp titleProp;
  AnimationProp animationProp;

  bool showMainAxis = true;
  bool showSubAxis = true;
  bool showTitle = true;
  bool showLegend = true;

  PlotProp();

  PlotProp(const AxisProp& _xaxisProp,
           const AxisProp& _yaxisProp,
           const QList<CurveProp>& _curveProps,
           const TitleProp& _titleProp);

  PlotProp(const AxisProp& _xaxisProp,
           const AxisProp& _yaxisProp,
           const QList<CurveProp>& _curveProps,
           const TitleProp& _titleProp,
           const AnimationProp& _animationProp);
};

#endif // PLOTPROP_H
