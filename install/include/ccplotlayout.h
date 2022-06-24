#ifndef CCPlotLayout_H
#define CCPlotLayout_H

#include "ccplotbase.h"

namespace Ui {
class CCPlotLayout;
}

/**
 * @brief The CCPlotLayout class
 * pilot.phil
 * 2022-5-24
 * 632913013@qq.com
 * 绘图布局类
 * 元素布局即其槽函数
 * 包括画布等各种功能性按钮
 */
class CCPlotLayout : public CCPlotBase {
  Q_OBJECT

 public:
  explicit CCPlotLayout(QWidget* parent = nullptr);
  virtual ~CCPlotLayout();

  /**
   * @brief showFunctionWidgets 是否显示功能区控件组
   * @param flag
   */
  void showFunctionWidgets(bool flag = true);

  /**
   * @brief showPlayWidgets 是否隐藏播放控件组
   * @param flag
   */
  void showPlayWidgets(bool flag = true);

  /**
   * @brief setPlayWidgetsLabel 设置播放组件中文字显示
   * @param txt
   */
  void setPlayWidgetsLabel(const QString& txt);

  /**
   * @brief setPlayWidgetsSliderRanger 设置播放组件中滑动条范围
   * @param start
   * @param end
   */
  void setPlayWidgetsSliderRanger(int start, int end);

  /**
   * @brief getPlayWidgetsSliderRanger 获取播放组件中滑动条范围
   * @param start
   * @param end
   */
  void getPlayWidgetsSliderRanger(int& start, int& end);

  /**
   * @brief setPlayWidgetsSliderValue 设置播放组件中滑动条数值
   * @param val
   */
  void setPlayWidgetsSliderValue(int val);

  /**
   * @brief getPlayWidgetsSliderValue 获取播放组件中滑动条数值
   * @param val
   */
  int getPlayWidgetsSliderValue();

 protected:
  /*------功能区按键槽函数:纯虚函数，在intercation类中实现--------*/
  /**
   * @brief btn_moveCanvas_clicked 是否移动画布
   * @param isChecked
   */
  virtual void btn_moveCanvas_clicked(bool isChecked) = 0;

  /**
   * @brief btn_property_clicked 打开属性设置
   */
  virtual void btn_property_clicked() = 0;

  /**
   * @brief btn_fullView_clicked 画布全视图显示
   */
  virtual void btn_fullView_clicked() = 0;

  /**
   * @brief btn_ratioView_clicked 画布保持比例显示
   */
  virtual void btn_ratioView_clicked() = 0;

  /**
   * @brief btn_print_clicked 显示打印设置窗口
   */
  virtual void btn_print_clicked() = 0;

  /*------播放区按键槽函数:虚函数，仅在子类有动图播放需求类中实现--------*/
  /**
   * @brief sliderToggled
   * @param value
   */
  virtual void slider_playWidgets_valueChanged(int value);

  /**
   * @brief btn_play_clicked 播放按钮按下
   */
  virtual void btn_play_clicked();

  /**
   * @brief btn_pause_clicked 暂停按钮按下
   */
  virtual void btn_pause_clicked();


 private slots:
  void on_btn_moveCanvas_clicked();

  void on_btn_property_clicked();

  void on_btn_fullView_clicked();

  void on_btn_ratioView_clicked();

  void on_btn_print_clicked();

  void on_playSlider_valueChanged(int value);

  void on_btn_play_clicked();

  void on_btn_pause_clicked();

 private:
  Ui::CCPlotLayout* ui;

 protected:
  QCustomPlot* canvas;
};

#endif // CCPlotLayout_H
