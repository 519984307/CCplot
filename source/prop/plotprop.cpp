#include "plotprop.h"

PlotProp::PlotProp() {}

PlotProp::PlotProp(const AxisProp& _xaxisProp,
                   const AxisProp& _yaxisProp,
                   const QList<CurveProp>& _curveProps,
                   const TitleProp& _titleProp)
  : xaxisProp(_xaxisProp)
  , yaxisProp(_yaxisProp)
  , curveProps(_curveProps)
  , titleProp(_titleProp)
{}

PlotProp::PlotProp(const AxisProp& _xaxisProp,
                   const AxisProp& _yaxisProp,
                   const QList<CurveProp>& _curveProps,
                   const TitleProp& _titleProp,
                   const AnimationProp& _animationProp)
  : xaxisProp(_xaxisProp)
  , yaxisProp(_yaxisProp)
  , curveProps(_curveProps)
  , titleProp(_titleProp)
  , animationProp(_animationProp)
{}
