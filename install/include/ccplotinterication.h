#ifndef CCPlotInterication_H
#define CCPlotInterication_H

#include "ccplotelements.h"

enum InterctWay
{
    none,
    whole,
    single,
    range,
    multiRange
};


class CCPlotInterication : public CCPlotElements
{
    Q_OBJECT;

public:
    CCPlotInterication(QWidget* parent = nullptr);

    /**
     * @brief setConnections 设置所有的信号槽连接
     */
    void setConnections();

    /**
     * @brief setInterication 设置交互方式
     * @param graph
     * @param interctWay
     */
    void setInterication(QCPGraph* graph, QCP::SelectionType st);

    /**
     * @brief setInterication 设置交互方式
     * @param graphId
     * @param interctWay
     */
    void setInterication(uint graphId, QCP::SelectionType st);

    /**
     * @brief titleDoubleClick 双击了标题
     * @param event
     */
    void titleDoubleClick(QMouseEvent* event);

    /**
     * @brief axisLabelDoubleClick 双击了坐标轴
     * @param axis
     * @param part
     */
    void axisLabelDoubleClick(QCPAxis* axis, QCPAxis::SelectablePart part);

    /**
     * @brief legendDoubleClick 双击了图例区
     * @param legend
     * @param item
     */
    void legendDoubleClick(QCPLegend* legend, QCPAbstractLegendItem* item);

    /**
     * @brief selectionChanged 改变了选择区域
     */
    void selectionChanged();

    /**
     * @brief mousePress 按下了鼠标
     */
    void mousePress();

    /**
     * @brief mouseWheel 滚动了鼠标滚轮
     */
    void mouseWheel();

    /**
     * @brief contextMenuRequest 右键菜单
     * @param pos
     */
    void contextMenuRequest(QPoint pos);

    /**
     * @brief removeSelectedGraph 移除选中的图层
     */
    void removeSelectedGraph();

    /**
     * @brief moveLegend 移动图列
     */
    void moveLegend();

    /**
     * @brief editSelectedGraph 编辑选中的图层
     */
    void editSelectedGraph();

    /**
     * @brief output2Img 输出到图片
     */
    void output2Img();

    /**
     * @brief graphClicked 点击了图层
     * @param plottable
     * @param dataIndex
     */
    void graphClicked(QCPAbstractPlottable* plottable, int dataIndex);

    /**
     * @brief selectionSlot
     */
    void selectionSlot(const QCPDataSelection & s);

signals:
    void playIntervalChanged(int interval);

protected:
    virtual void btn_moveCanvas_clicked(bool isChecked) override;

    virtual void btn_property_clicked() override;

    virtual void btn_fullView_clicked() override;

    virtual void btn_ratioView_clicked() override;

    virtual void btn_print_clicked() override;

    virtual void btn_choose_clicked() override;

    virtual void otherAction(QMenu* menu);


public:
    QVector<double> selected_X_Series;
    QVector<double> selected_Y_Series;
    double selected_Y_min=0.0;
    double selected_Y_max=0.0;
    double selected_Y_avg=0.0;
};

#endif // CCPlotInterication_H
