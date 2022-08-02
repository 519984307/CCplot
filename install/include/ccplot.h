#ifndef CCPLOT_H
#define CCPLOT_H

#include "ccplotinterication.h"

#include <QMap>
#include <QTimer>

class CCPlot : public CCPlotInterication
{
public:
    CCPlot(QWidget* parent = nullptr);

    virtual ~CCPlot();

    /**
     * @brief setTiming 设置定时器
     * @param interval 间隔
     */
    void setTiming(int interval = 100) {if (interval > 0) {timer->setInterval(interval);}}

protected:
    /**
     * @brief btn_play_clicked 播放按钮按下
     */
    virtual void btn_play_clicked() {timer->start();};

    /**
     * @brief btn_pause_clicked 暂停按钮按下
     */
    virtual void btn_pause_clicked() {timer->stop();};

    /**
     * @brief makeGraph 图层设定
     */
    virtual void makeGraph();

    /**
     * @brief update 曲线更新
     */
    virtual void update();

    /**
     * @brief update 按照字典中是否更新进行更新曲线
     * @param updateFlags
     */
    virtual void update(const QMap<QString, bool>& updateFlags);

    /**
     * @brief timingUpdate 定时更新
     */
    virtual void timingUpdate();


    /**
     * @brief timer 定时更新定时器
     */
    QTimer* timer;
};

#endif // CCPLOT_H
