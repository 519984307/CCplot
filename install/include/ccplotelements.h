﻿#ifndef PLOTELEMENTS_H
#define PLOTELEMENTS_H

#include "axisprop.h"
#include "curveprop.h"
#include "ccplotlayout.h"
#include "printprop.h"
#include "titleprop.h"

enum ReplotPolicy
{
  justUpdate,
  fullCanvas,
  keepRatio
};

class CCPlotElements : public CCPlotLayout
{
public:
  CCPlotElements(QWidget* parent = nullptr);

  virtual ~CCPlotElements();

protected:
  /*---------坐标轴设置-----------*/
  /**
   * @brief showMainAxis 是否显示主坐标轴
   * @param flag
   */
  void showMainAxis(bool flag);

  /**
   * @brief showSubAxis 是否显示次坐标
   * @param flag
   */
  void showSubAxis(bool flag);

  /**
   * @brief setAxis 设置坐标轴属性
   * @param axis 属性
   * @param posi 哪个坐标轴
   */
  void setAxis(const AxisProp& axis, const axisPosition& posi);

  /**
   * @brief setAxis
   * @param axis
   * @param axis
   */
  void setAxis(const AxisProp& axis, QCPAxis* selectedAxis);

  /**
   * @brief adjeustAxisKeepRatio 调整坐标轴保持比例
   */
  void adjustAxisKeepRatio();

  /**
   * @brief adjustAxisFullCanvas 调整坐标轴填满绘图区域
   */
  void adjustAxisFullCanvas();

  /*---------图例设置-----------*/
  /**
   * @brief showLegend 是否显示图例
   * @param flag
   */
  void showLegend(bool flag);

  /*---------标题设置-----------*/
  /**
   * @brief removeTitle 移除标题
   */
  void removeTitle();

  /**
   * @brief showTitle 添加标题
   * @param title
   */
  void addTitle(
    const TitleProp& title = TitleProp(QString::fromLocal8Bit("新标题"),
                                       QFont("sans", 12, QFont::Bold)));

  /**
   * @brief addDefaultTitle 添加默认标题
   */
  void addDefaultTitle();

  /**
   * @brief setTitle 设置标题
   * @param titleProp
   */
  void setTitle(const TitleProp& titleProp);

  /*---------图层曲线设置-----------*/
  /**
   * @brief removeAllGraph 移除所有图层
   */
  void removeAllGraph();

  /**
   * @brief removeGraph 移除某一图层
   * @param graphIndex 图层id
   */
  void removeGraph(int graphIndex);

  /**
   * @brief removeGraph 移除某一图层
   * @param graph 图层地址
   */
  void removeGraph(QCPGraph* graph);

  /**
   * @brief policedReplot 策略更新
   * @param rp
   */
  void policedReplot(ReplotPolicy rp);

  /**
   * @brief setCurve 设置曲线属性
   * @param curveProp
   */
  void setCurve(QCPGraph* g, const CurveProp& curveProp, ReplotPolicy rp);

  /**
   * @brief setCurve 按曲线名设置曲线
   * @param curveName
   * @param curveProp
   */
  void setCurve(const QString& curveName,
                const CurveProp& curveProp,
                ReplotPolicy rp);

  /**
   * @brief setCurve 按图层id设置曲线
   * @param graphIndex
   * @param curveProp
   */
  void setCurve(int graphIndex, const CurveProp& curveProp, ReplotPolicy rp);

  /**
   * @brief updateCurve 更新曲线数据点
   * @param g
   * @param xx
   * @param yy
   */
  void updateCurve(QCPGraph* g,
                   const QVector<double>& xx,
                   const QVector<double>& yy,
                   ReplotPolicy rp);

  /**
   * @brief updateCurve 更新曲线数据点
   * @param graphIndex
   * @param xx
   * @param yy
   */
  void updateCurve(int graphIndex,
                   const QVector<double>& xx,
                   const QVector<double>& yy,
                   ReplotPolicy rp);

  /**
   * @brief addCurve 添加曲线
   * @param curveProp
   */
  void addCurve(const CurveProp& curveProp, ReplotPolicy rp);

  /*---------打印设置-----------*/
  void print(const PrintProp& printProp);

protected:
  QCPTextElement* _title;

  int playInterval = 200;
};

#endif // PLOTELEMENTS_H
