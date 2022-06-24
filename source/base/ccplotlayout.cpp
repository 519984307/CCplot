#include "ccplotlayout.h"
#include "ui_ccplotlayout.h"

#include <QGridLayout>

CCPlotLayout::CCPlotLayout(QWidget* parent)
  : CCPlotBase(parent)
  , ui(new Ui::CCPlotLayout) {
  ui->setupUi(this);

  //为绘图区域canvas设置布局
  canvas = new QCustomPlot(this);
  QGridLayout* gl1 = new QGridLayout(this);
  gl1->setMargin(0);
  gl1->addWidget(canvas);
  ui->widget_canvas->setLayout(gl1);

  //默认显示功能区
  showFunctionWidgets(true);

  //默认不显示播放区
  showPlayWidgets(false);
}

CCPlotLayout::~CCPlotLayout() {
  delete ui;
}

void
CCPlotLayout::showFunctionWidgets(bool flag) {
  if (flag)
    ui->functionWidgetsGrroup->show();
  else
    ui->functionWidgetsGrroup->hide();
}

void
CCPlotLayout::showPlayWidgets(bool flag) {
  if (flag)
    ui->playWidgetsGroup->show();
  else
    ui->playWidgetsGroup->hide();
}

void
CCPlotLayout::setPlayWidgetsLabel(const QString& txt) {
  ui->label->setText(txt);
}

void
CCPlotLayout::setPlayWidgetsSliderRanger(int start, int end) {
  if (start < end)
    ui->playSlider->setRange(start, end);
}

void CCPlotLayout::getPlayWidgetsSliderRanger(int& start, int& end) {
  start = ui->playSlider->minimum();
  end = ui->playSlider->maximum();
}

void
CCPlotLayout::setPlayWidgetsSliderValue(int val) {
  ui->playSlider->setValue(val);
}

int CCPlotLayout::getPlayWidgetsSliderValue() {
  return ui->playSlider->value();
}

void
CCPlotLayout::slider_playWidgets_valueChanged(int value)
{}

void
CCPlotLayout::btn_play_clicked() {
}

void
CCPlotLayout::btn_pause_clicked() {
}

void
CCPlotLayout::on_btn_moveCanvas_clicked() {
  btn_moveCanvas_clicked(ui->btn_moveCanvas->isChecked());
}

void
CCPlotLayout::on_btn_property_clicked() {
  btn_property_clicked();
}

void
CCPlotLayout::on_btn_fullView_clicked() {
  btn_fullView_clicked();
}

void
CCPlotLayout::on_btn_ratioView_clicked() {
  btn_ratioView_clicked();
}

void
CCPlotLayout::on_btn_print_clicked() {
  btn_print_clicked();
}

void
CCPlotLayout::on_playSlider_valueChanged(int value) {
  slider_playWidgets_valueChanged(value);
}

void
CCPlotLayout::on_btn_play_clicked() {
  btn_play_clicked();
}

void
CCPlotLayout::on_btn_pause_clicked() {
  btn_pause_clicked();
}
