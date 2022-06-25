/********************************************************************************
** Form generated from reading UI file 'setplot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPLOT_H
#define UI_SETPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_setPlot
{
public:
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_xaxisName;
    QLabel *label_2;
    QSpinBox *spinBox_xaxisMin;
    QLabel *label_3;
    QSpinBox *spinBox_xaxisMax;
    QLabel *label_4;
    QLineEdit *lineEdit_yaxisName;
    QLabel *label_5;
    QSpinBox *spinBox_yaxisMin;
    QLabel *label_6;
    QSpinBox *spinBox_yaxisMax;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_showMainAxis;
    QCheckBox *checkBox_showSubAxis;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QLineEdit *le_titleLabel;
    QLabel *label_8;
    QFontComboBox *fontComboBox_titleFont;
    QLabel *label_9;
    QSpinBox *spinBox_titleFontSize;
    QCheckBox *checkBox_showTitle;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_4;
    QLabel *label_22;
    QComboBox *comboBox;
    QComboBox *cbx_linestyle;
    QLabel *label_21;
    QLabel *label_19;
    QSpinBox *spinBox_width;
    QLabel *label_17;
    QLabel *label_16;
    QComboBox *cbx_scatter;
    QLineEdit *le_curveName;
    QLabel *label_18;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lb_color;
    QToolButton *pb_setColor;
    QSpinBox *spinBox_scatterSize;
    QCheckBox *checkBox_showLegend;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QLabel *label_23;
    QSpinBox *spinBox_playInterval;

    void setupUi(QDialog *setPlot)
    {
        if (setPlot->objectName().isEmpty())
            setPlot->setObjectName(QString::fromUtf8("setPlot"));
        setPlot->resize(293, 621);
        gridLayout_5 = new QGridLayout(setPlot);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox = new QGroupBox(setPlot);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_xaxisName = new QLineEdit(groupBox);
        lineEdit_xaxisName->setObjectName(QString::fromUtf8("lineEdit_xaxisName"));

        gridLayout->addWidget(lineEdit_xaxisName, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBox_xaxisMin = new QSpinBox(groupBox);
        spinBox_xaxisMin->setObjectName(QString::fromUtf8("spinBox_xaxisMin"));
        spinBox_xaxisMin->setMinimum(-100000000);
        spinBox_xaxisMin->setMaximum(100000000);

        gridLayout->addWidget(spinBox_xaxisMin, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        spinBox_xaxisMax = new QSpinBox(groupBox);
        spinBox_xaxisMax->setObjectName(QString::fromUtf8("spinBox_xaxisMax"));
        spinBox_xaxisMax->setMinimum(-100000000);
        spinBox_xaxisMax->setMaximum(100000000);

        gridLayout->addWidget(spinBox_xaxisMax, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_yaxisName = new QLineEdit(groupBox);
        lineEdit_yaxisName->setObjectName(QString::fromUtf8("lineEdit_yaxisName"));

        gridLayout->addWidget(lineEdit_yaxisName, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        spinBox_yaxisMin = new QSpinBox(groupBox);
        spinBox_yaxisMin->setObjectName(QString::fromUtf8("spinBox_yaxisMin"));
        spinBox_yaxisMin->setMinimum(-100000000);
        spinBox_yaxisMin->setMaximum(100000000);

        gridLayout->addWidget(spinBox_yaxisMin, 4, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        spinBox_yaxisMax = new QSpinBox(groupBox);
        spinBox_yaxisMax->setObjectName(QString::fromUtf8("spinBox_yaxisMax"));
        spinBox_yaxisMax->setMinimum(-100000000);
        spinBox_yaxisMax->setMaximum(100000000);

        gridLayout->addWidget(spinBox_yaxisMax, 5, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBox_showMainAxis = new QCheckBox(groupBox);
        checkBox_showMainAxis->setObjectName(QString::fromUtf8("checkBox_showMainAxis"));

        horizontalLayout->addWidget(checkBox_showMainAxis);

        checkBox_showSubAxis = new QCheckBox(groupBox);
        checkBox_showSubAxis->setObjectName(QString::fromUtf8("checkBox_showSubAxis"));

        horizontalLayout->addWidget(checkBox_showSubAxis);


        gridLayout->addLayout(horizontalLayout, 6, 0, 1, 2);


        gridLayout_5->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(setPlot);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        le_titleLabel = new QLineEdit(groupBox_2);
        le_titleLabel->setObjectName(QString::fromUtf8("le_titleLabel"));

        gridLayout_2->addWidget(le_titleLabel, 0, 1, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 1, 0, 1, 1);

        fontComboBox_titleFont = new QFontComboBox(groupBox_2);
        fontComboBox_titleFont->setObjectName(QString::fromUtf8("fontComboBox_titleFont"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fontComboBox_titleFont->sizePolicy().hasHeightForWidth());
        fontComboBox_titleFont->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(fontComboBox_titleFont, 1, 1, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 2, 0, 1, 1);

        spinBox_titleFontSize = new QSpinBox(groupBox_2);
        spinBox_titleFontSize->setObjectName(QString::fromUtf8("spinBox_titleFontSize"));
        sizePolicy.setHeightForWidth(spinBox_titleFontSize->sizePolicy().hasHeightForWidth());
        spinBox_titleFontSize->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(spinBox_titleFontSize, 2, 1, 1, 1);

        checkBox_showTitle = new QCheckBox(groupBox_2);
        checkBox_showTitle->setObjectName(QString::fromUtf8("checkBox_showTitle"));

        gridLayout_2->addWidget(checkBox_showTitle, 3, 0, 1, 2);


        gridLayout_5->addWidget(groupBox_2, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(setPlot);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_5->addWidget(buttonBox, 4, 0, 1, 1);

        groupBox_3 = new QGroupBox(setPlot);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_22, 7, 0, 1, 1);

        comboBox = new QComboBox(groupBox_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(comboBox, 1, 2, 1, 1);

        cbx_linestyle = new QComboBox(groupBox_3);
        cbx_linestyle->addItem(QString());
        cbx_linestyle->addItem(QString());
        cbx_linestyle->addItem(QString());
        cbx_linestyle->addItem(QString());
        cbx_linestyle->addItem(QString());
        cbx_linestyle->addItem(QString());
        cbx_linestyle->setObjectName(QString::fromUtf8("cbx_linestyle"));
        sizePolicy.setHeightForWidth(cbx_linestyle->sizePolicy().hasHeightForWidth());
        cbx_linestyle->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(cbx_linestyle, 5, 1, 1, 2);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        sizePolicy1.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_21, 6, 0, 1, 1);

        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy1.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_19, 4, 0, 1, 1);

        spinBox_width = new QSpinBox(groupBox_3);
        spinBox_width->setObjectName(QString::fromUtf8("spinBox_width"));
        sizePolicy.setHeightForWidth(spinBox_width->sizePolicy().hasHeightForWidth());
        spinBox_width->setSizePolicy(sizePolicy);
        spinBox_width->setValue(1);

        gridLayout_4->addWidget(spinBox_width, 4, 1, 1, 2);

        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        sizePolicy1.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_17, 2, 0, 1, 1);

        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy1.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_16, 1, 0, 1, 2);

        cbx_scatter = new QComboBox(groupBox_3);
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->setObjectName(QString::fromUtf8("cbx_scatter"));
        sizePolicy.setHeightForWidth(cbx_scatter->sizePolicy().hasHeightForWidth());
        cbx_scatter->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(cbx_scatter, 6, 1, 1, 2);

        le_curveName = new QLineEdit(groupBox_3);
        le_curveName->setObjectName(QString::fromUtf8("le_curveName"));
        sizePolicy.setHeightForWidth(le_curveName->sizePolicy().hasHeightForWidth());
        le_curveName->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(le_curveName, 2, 1, 1, 2);

        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        sizePolicy1.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_18, 3, 0, 1, 1);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        sizePolicy1.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(label_20, 5, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lb_color = new QLabel(groupBox_3);
        lb_color->setObjectName(QString::fromUtf8("lb_color"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lb_color->sizePolicy().hasHeightForWidth());
        lb_color->setSizePolicy(sizePolicy2);
        lb_color->setAutoFillBackground(true);

        horizontalLayout_4->addWidget(lb_color);

        pb_setColor = new QToolButton(groupBox_3);
        pb_setColor->setObjectName(QString::fromUtf8("pb_setColor"));

        horizontalLayout_4->addWidget(pb_setColor);


        gridLayout_4->addLayout(horizontalLayout_4, 3, 1, 1, 2);

        spinBox_scatterSize = new QSpinBox(groupBox_3);
        spinBox_scatterSize->setObjectName(QString::fromUtf8("spinBox_scatterSize"));
        sizePolicy.setHeightForWidth(spinBox_scatterSize->sizePolicy().hasHeightForWidth());
        spinBox_scatterSize->setSizePolicy(sizePolicy);
        spinBox_scatterSize->setValue(1);

        gridLayout_4->addWidget(spinBox_scatterSize, 7, 1, 1, 2);

        checkBox_showLegend = new QCheckBox(groupBox_3);
        checkBox_showLegend->setObjectName(QString::fromUtf8("checkBox_showLegend"));

        gridLayout_4->addWidget(checkBox_showLegend, 0, 0, 1, 3);


        gridLayout_5->addWidget(groupBox_3, 2, 0, 1, 1);

        groupBox_4 = new QGroupBox(setPlot);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        sizePolicy1.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label_23, 0, 0, 1, 1);

        spinBox_playInterval = new QSpinBox(groupBox_4);
        spinBox_playInterval->setObjectName(QString::fromUtf8("spinBox_playInterval"));
        sizePolicy.setHeightForWidth(spinBox_playInterval->sizePolicy().hasHeightForWidth());
        spinBox_playInterval->setSizePolicy(sizePolicy);
        spinBox_playInterval->setMinimum(1);
        spinBox_playInterval->setMaximum(1000);
        spinBox_playInterval->setValue(1);

        gridLayout_3->addWidget(spinBox_playInterval, 0, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_4, 3, 0, 1, 1);


        retranslateUi(setPlot);
        QObject::connect(buttonBox, SIGNAL(accepted()), setPlot, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), setPlot, SLOT(reject()));

        QMetaObject::connectSlotsByName(setPlot);
    } // setupUi

    void retranslateUi(QDialog *setPlot)
    {
        setPlot->setWindowTitle(QCoreApplication::translate("setPlot", "\347\273\230\345\233\276\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("setPlot", "\345\235\220\346\240\207\350\275\264", nullptr));
        label->setText(QCoreApplication::translate("setPlot", "X\350\275\264\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("setPlot", "X\350\275\264\346\234\200\345\260\217\345\200\274", nullptr));
        label_3->setText(QCoreApplication::translate("setPlot", "X\350\275\264\346\234\200\345\244\247\345\200\274", nullptr));
        label_4->setText(QCoreApplication::translate("setPlot", "Y\350\275\264\345\220\215\347\247\260", nullptr));
        label_5->setText(QCoreApplication::translate("setPlot", "Y\350\275\264\346\234\200\345\260\217\345\200\274", nullptr));
        label_6->setText(QCoreApplication::translate("setPlot", "Y\350\275\264\346\234\200\345\244\247\345\200\274", nullptr));
        checkBox_showMainAxis->setText(QCoreApplication::translate("setPlot", "\346\230\276\347\244\272\344\270\273\345\235\220\346\240\207\350\275\264", nullptr));
        checkBox_showSubAxis->setText(QCoreApplication::translate("setPlot", "\346\230\276\347\244\272\345\211\257\345\235\220\346\240\207\350\275\264", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("setPlot", "\346\240\207\351\242\230", nullptr));
        label_7->setText(QCoreApplication::translate("setPlot", "\346\240\207\351\242\230\345\220\215", nullptr));
        label_8->setText(QCoreApplication::translate("setPlot", "\345\255\227\344\275\223", nullptr));
        label_9->setText(QCoreApplication::translate("setPlot", "\345\244\247\345\260\217", nullptr));
        checkBox_showTitle->setText(QCoreApplication::translate("setPlot", "\346\230\276\347\244\272\346\240\207\351\242\230", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("setPlot", "\346\233\262\347\272\277", nullptr));
        label_22->setText(QCoreApplication::translate("setPlot", "\345\244\247\345\260\217", nullptr));
        cbx_linestyle->setItemText(0, QCoreApplication::translate("setPlot", "None", nullptr));
        cbx_linestyle->setItemText(1, QCoreApplication::translate("setPlot", "Line", nullptr));
        cbx_linestyle->setItemText(2, QCoreApplication::translate("setPlot", "StepLeft", nullptr));
        cbx_linestyle->setItemText(3, QCoreApplication::translate("setPlot", "StepRight", nullptr));
        cbx_linestyle->setItemText(4, QCoreApplication::translate("setPlot", "StepCenter", nullptr));
        cbx_linestyle->setItemText(5, QCoreApplication::translate("setPlot", "Impulse", nullptr));

        label_21->setText(QCoreApplication::translate("setPlot", "\347\202\271\345\236\213", nullptr));
        label_19->setText(QCoreApplication::translate("setPlot", "\347\272\277\345\256\275", nullptr));
        label_17->setText(QCoreApplication::translate("setPlot", "\345\220\215\347\247\260", nullptr));
        label_16->setText(QCoreApplication::translate("setPlot", "\351\200\211\346\213\251\346\233\262\347\272\277", nullptr));
        cbx_scatter->setItemText(0, QCoreApplication::translate("setPlot", "None", nullptr));
        cbx_scatter->setItemText(1, QCoreApplication::translate("setPlot", "Dot", nullptr));
        cbx_scatter->setItemText(2, QCoreApplication::translate("setPlot", "Cross", nullptr));
        cbx_scatter->setItemText(3, QCoreApplication::translate("setPlot", "Plus", nullptr));
        cbx_scatter->setItemText(4, QCoreApplication::translate("setPlot", "Circle", nullptr));
        cbx_scatter->setItemText(5, QCoreApplication::translate("setPlot", "Disc", nullptr));
        cbx_scatter->setItemText(6, QCoreApplication::translate("setPlot", "Square", nullptr));
        cbx_scatter->setItemText(7, QCoreApplication::translate("setPlot", "Diamond", nullptr));
        cbx_scatter->setItemText(8, QCoreApplication::translate("setPlot", "Star", nullptr));
        cbx_scatter->setItemText(9, QCoreApplication::translate("setPlot", "Triangle", nullptr));
        cbx_scatter->setItemText(10, QCoreApplication::translate("setPlot", "TriangleInverted", nullptr));
        cbx_scatter->setItemText(11, QCoreApplication::translate("setPlot", "CrossSquare", nullptr));
        cbx_scatter->setItemText(12, QCoreApplication::translate("setPlot", "PlusSquare", nullptr));
        cbx_scatter->setItemText(13, QCoreApplication::translate("setPlot", "CrossCircle", nullptr));
        cbx_scatter->setItemText(14, QCoreApplication::translate("setPlot", "PlusCircle", nullptr));
        cbx_scatter->setItemText(15, QCoreApplication::translate("setPlot", "Peace", nullptr));

        label_18->setText(QCoreApplication::translate("setPlot", "\351\242\234\350\211\262", nullptr));
        label_20->setText(QCoreApplication::translate("setPlot", "\347\272\277\345\236\213", nullptr));
        lb_color->setText(QString());
        pb_setColor->setText(QCoreApplication::translate("setPlot", "...", nullptr));
        checkBox_showLegend->setText(QCoreApplication::translate("setPlot", "\346\230\276\347\244\272\345\233\276\344\276\213", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("setPlot", "\345\212\250\347\224\273", nullptr));
        label_23->setText(QCoreApplication::translate("setPlot", "\351\200\237\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setPlot: public Ui_setPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPLOT_H
