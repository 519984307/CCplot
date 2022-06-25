/********************************************************************************
** Form generated from reading UI file 'ccplotlayout.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPLOTLAYOUT_H
#define UI_CCPLOTLAYOUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CCPlotLayout
{
public:
    QGridLayout *gridLayout_3;
    QFrame *functionWidgetsGrroup;
    QGridLayout *gridLayout;
    QPushButton *btn_moveCanvas;
    QPushButton *btn_fullView;
    QPushButton *btn_ratioView;
    QPushButton *btn_print;
    QPushButton *btn_property;
    QFrame *playWidgetsGroup;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QPushButton *btn_pause;
    QPushButton *btn_play;
    QSlider *playSlider;
    QWidget *widget_canvas;

    void setupUi(QWidget *CCPlotLayout)
    {
        if (CCPlotLayout->objectName().isEmpty())
            CCPlotLayout->setObjectName(QString::fromUtf8("CCPlotLayout"));
        CCPlotLayout->resize(551, 467);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/spline-chart.png"), QSize(), QIcon::Normal, QIcon::Off);
        CCPlotLayout->setWindowIcon(icon);
        CCPlotLayout->setStyleSheet(QString::fromUtf8("#PlotLayout\n"
"{\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        gridLayout_3 = new QGridLayout(CCPlotLayout);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        functionWidgetsGrroup = new QFrame(CCPlotLayout);
        functionWidgetsGrroup->setObjectName(QString::fromUtf8("functionWidgetsGrroup"));
        functionWidgetsGrroup->setFrameShape(QFrame::StyledPanel);
        functionWidgetsGrroup->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(functionWidgetsGrroup);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(2);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn_moveCanvas = new QPushButton(functionWidgetsGrroup);
        btn_moveCanvas->setObjectName(QString::fromUtf8("btn_moveCanvas"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/move.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_moveCanvas->setIcon(icon1);
        btn_moveCanvas->setIconSize(QSize(20, 20));
        btn_moveCanvas->setCheckable(true);
        btn_moveCanvas->setChecked(false);

        gridLayout->addWidget(btn_moveCanvas, 0, 0, 1, 1);

        btn_fullView = new QPushButton(functionWidgetsGrroup);
        btn_fullView->setObjectName(QString::fromUtf8("btn_fullView"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/full-screen.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_fullView->setIcon(icon2);
        btn_fullView->setIconSize(QSize(20, 20));

        gridLayout->addWidget(btn_fullView, 0, 1, 1, 1);

        btn_ratioView = new QPushButton(functionWidgetsGrroup);
        btn_ratioView->setObjectName(QString::fromUtf8("btn_ratioView"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/golden-ratio.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_ratioView->setIcon(icon3);
        btn_ratioView->setIconSize(QSize(20, 20));

        gridLayout->addWidget(btn_ratioView, 0, 2, 1, 1);

        btn_print = new QPushButton(functionWidgetsGrroup);
        btn_print->setObjectName(QString::fromUtf8("btn_print"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_print->setIcon(icon4);
        btn_print->setIconSize(QSize(20, 20));

        gridLayout->addWidget(btn_print, 0, 3, 1, 1);

        btn_property = new QPushButton(functionWidgetsGrroup);
        btn_property->setObjectName(QString::fromUtf8("btn_property"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/control.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_property->setIcon(icon5);
        btn_property->setIconSize(QSize(20, 20));

        gridLayout->addWidget(btn_property, 0, 4, 1, 1);


        gridLayout_3->addWidget(functionWidgetsGrroup, 0, 0, 1, 1);

        playWidgetsGroup = new QFrame(CCPlotLayout);
        playWidgetsGroup->setObjectName(QString::fromUtf8("playWidgetsGroup"));
        playWidgetsGroup->setFrameShape(QFrame::StyledPanel);
        playWidgetsGroup->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(playWidgetsGroup);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(2);
        gridLayout_2->setVerticalSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(playWidgetsGroup);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 4, 1, 1);

        btn_pause = new QPushButton(playWidgetsGroup);
        btn_pause->setObjectName(QString::fromUtf8("btn_pause"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_pause->setIcon(icon6);
        btn_pause->setIconSize(QSize(20, 20));

        gridLayout_2->addWidget(btn_pause, 0, 1, 1, 1);

        btn_play = new QPushButton(playWidgetsGroup);
        btn_play->setObjectName(QString::fromUtf8("btn_play"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/play-button-arrowhead.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_play->setIcon(icon7);
        btn_play->setIconSize(QSize(20, 20));

        gridLayout_2->addWidget(btn_play, 0, 0, 1, 1);

        playSlider = new QSlider(playWidgetsGroup);
        playSlider->setObjectName(QString::fromUtf8("playSlider"));
        playSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(playSlider, 0, 3, 1, 1);


        gridLayout_3->addWidget(playWidgetsGroup, 0, 1, 1, 1);

        widget_canvas = new QWidget(CCPlotLayout);
        widget_canvas->setObjectName(QString::fromUtf8("widget_canvas"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_canvas->sizePolicy().hasHeightForWidth());
        widget_canvas->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(widget_canvas, 1, 0, 1, 3);


        retranslateUi(CCPlotLayout);

        QMetaObject::connectSlotsByName(CCPlotLayout);
    } // setupUi

    void retranslateUi(QWidget *CCPlotLayout)
    {
        CCPlotLayout->setWindowTitle(QCoreApplication::translate("CCPlotLayout", "CCPlot", nullptr));
#if QT_CONFIG(tooltip)
        btn_moveCanvas->setToolTip(QCoreApplication::translate("CCPlotLayout", "\347\247\273\345\212\250\347\224\273\345\270\203", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_moveCanvas->setText(QString());
#if QT_CONFIG(tooltip)
        btn_fullView->setToolTip(QCoreApplication::translate("CCPlotLayout", "\351\223\272\346\273\241\350\247\206\345\233\276", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_fullView->setText(QString());
#if QT_CONFIG(tooltip)
        btn_ratioView->setToolTip(QCoreApplication::translate("CCPlotLayout", "\347\255\211\346\257\224\350\247\206\345\233\276", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_ratioView->setText(QString());
#if QT_CONFIG(tooltip)
        btn_print->setToolTip(QCoreApplication::translate("CCPlotLayout", "\346\211\223\345\215\260\350\276\223\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_print->setText(QString());
#if QT_CONFIG(tooltip)
        btn_property->setToolTip(QCoreApplication::translate("CCPlotLayout", "\345\261\236\346\200\247\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_property->setText(QString());
        label->setText(QCoreApplication::translate("CCPlotLayout", "0", nullptr));
        btn_pause->setText(QString());
        btn_play->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CCPlotLayout: public Ui_CCPlotLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPLOTLAYOUT_H
