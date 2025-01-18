/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_rec;
    QRadioButton *radioButton_rec_hex;
    QRadioButton *radioButton_rec_txt;
    QCheckBox *checkBox_data_save;
    QCheckBox *checkBox_dpy_time;
    QCheckBox *checkBox_3;
    QLabel *label;
    QSpinBox *spinBox_send_time_2;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_rec_length;
    QLineEdit *lineEdit_2_send_length;
    QGroupBox *groupBox_CH;
    QSpinBox *spinBox1_3;
    QLineEdit *type_2;
    QComboBox *comboBox;
    QLineEdit *boundary;
    QLineEdit *type;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QLineEdit *data;
    QSpinBox *spinBox1;
    QSpinBox *spinBox1_4;
    QLineEdit *channel;
    QLineEdit *check;
    QComboBox *comboBox_2;
    QLineEdit *stop;
    QGroupBox *groupBox_3;
    QLineEdit *type_5;
    QComboBox *comboBox_5;
    QSpinBox *spinBox1_6;
    QLineEdit *type_4;
    QLineEdit *type_3;
    QSpinBox *spinBox1_5;
    QGroupBox *groupBox_rec_2;
    QSpinBox *spinBox_send_ch;
    QPushButton *pushButton_5;
    QCheckBox *checkBox_4;
    QRadioButton *radioButton_send_string;
    QSpinBox *spinBox_send_time;
    QRadioButton *radioButton_send_txt;
    QRadioButton *radioButton_send_hex;
    QLineEdit *channel_2;
    QPushButton *pushButton_6;
    QPushButton *auto_link;
    QPushButton *man_link;
    QLineEdit *light;
    QListWidget *deviceListWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1150, 850);
        QFont font;
        font.setPointSize(11);
        Widget->setFont(font);
        Widget->setAcceptDrops(false);
        Widget->setAutoFillBackground(true);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 810, 161, 31));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(255, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Active, QPalette::Link, brush);
        palette.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush3(QColor(51, 153, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush4(QColor(0, 0, 0, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        pushButton->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Kartika"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton->setFont(font1);
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setAcceptDrops(true);
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 770, 161, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush5(QColor(0, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette1.setBrush(QPalette::Active, QPalette::Link, brush);
        palette1.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        pushButton_2->setPalette(palette1);
        pushButton_2->setFont(font1);
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        pushButton_2->setAcceptDrops(true);
        groupBox_rec = new QGroupBox(Widget);
        groupBox_rec->setObjectName(QString::fromUtf8("groupBox_rec"));
        groupBox_rec->setGeometry(QRect(217, 700, 231, 141));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Lao UI"));
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        groupBox_rec->setFont(font2);
        groupBox_rec->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #cbcbcb;  /* \350\276\271\346\241\206\351\242\234\350\211\262\350\256\276\347\275\256\344\270\272 #cbcbcb */\n"
"    border-radius: 5px;          /* \345\234\206\350\247\222\346\225\210\346\236\234\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"    padding: 10px;               /* \345\206\205\350\276\271\350\267\235\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"}"));
        radioButton_rec_hex = new QRadioButton(groupBox_rec);
        radioButton_rec_hex->setObjectName(QString::fromUtf8("radioButton_rec_hex"));
        radioButton_rec_hex->setGeometry(QRect(14, 64, 61, 18));
        QPalette palette2;
        QBrush brush6(QColor(85, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        QBrush brush7(QColor(85, 170, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush7);
        QBrush brush8(QColor(170, 170, 255, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        QBrush brush9(QColor(85, 170, 255, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        QBrush brush10(QColor(120, 120, 120, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        radioButton_rec_hex->setPalette(palette2);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Lao UI"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        radioButton_rec_hex->setFont(font3);
        radioButton_rec_hex->setIconSize(QSize(50, 50));
        radioButton_rec_txt = new QRadioButton(groupBox_rec);
        radioButton_rec_txt->setObjectName(QString::fromUtf8("radioButton_rec_txt"));
        radioButton_rec_txt->setGeometry(QRect(14, 34, 61, 18));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        radioButton_rec_txt->setPalette(palette3);
        radioButton_rec_txt->setFont(font3);
        radioButton_rec_txt->setIconSize(QSize(50, 50));
        checkBox_data_save = new QCheckBox(groupBox_rec);
        checkBox_data_save->setObjectName(QString::fromUtf8("checkBox_data_save"));
        checkBox_data_save->setGeometry(QRect(90, 22, 113, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Lao UI"));
        font4.setPointSize(14);
        font4.setBold(false);
        font4.setWeight(50);
        checkBox_data_save->setFont(font4);
        checkBox_dpy_time = new QCheckBox(groupBox_rec);
        checkBox_dpy_time->setObjectName(QString::fromUtf8("checkBox_dpy_time"));
        checkBox_dpy_time->setGeometry(QRect(90, 48, 113, 20));
        checkBox_dpy_time->setFont(font4);
        checkBox_3 = new QCheckBox(groupBox_rec);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(90, 72, 141, 21));
        checkBox_3->setFont(font4);
        label = new QLabel(groupBox_rec);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 104, 141, 21));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush11(QColor(170, 255, 255, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        label->setPalette(palette4);
        QFont font5;
        font5.setPointSize(14);
        font5.setBold(false);
        font5.setWeight(50);
        label->setFont(font5);
        spinBox_send_time_2 = new QSpinBox(groupBox_rec);
        spinBox_send_time_2->setObjectName(QString::fromUtf8("spinBox_send_time_2"));
        spinBox_send_time_2->setGeometry(QRect(145, 100, 75, 31));
        spinBox_send_time_2->setLayoutDirection(Qt::RightToLeft);
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(220, 0, 931, 551));
        textEdit->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid green;\n"
"    border-radius: 10px;\n"
"    padding: 15px;\n"
"}"));
        textEdit_2 = new QTextEdit(Widget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(690, 590, 455, 251));
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 730, 161, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette5.setBrush(QPalette::Active, QPalette::Link, brush);
        palette5.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        pushButton_3->setPalette(palette5);
        pushButton_3->setFont(font1);
        pushButton_3->setFocusPolicy(Qt::NoFocus);
        pushButton_3->setAcceptDrops(true);
        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 690, 161, 31));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette6.setBrush(QPalette::Active, QPalette::Link, brush);
        palette6.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        pushButton_4->setPalette(palette6);
        pushButton_4->setFont(font1);
        pushButton_4->setFocusPolicy(Qt::NoFocus);
        pushButton_4->setAcceptDrops(true);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(699, 561, 111, 21));
        QFont font6;
        font6.setPointSize(14);
        font6.setBold(true);
        font6.setWeight(75);
        label_2->setFont(font6);
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(930, 560, 111, 21));
        label_3->setFont(font6);
        lineEdit_rec_length = new QLineEdit(Widget);
        lineEdit_rec_length->setObjectName(QString::fromUtf8("lineEdit_rec_length"));
        lineEdit_rec_length->setEnabled(false);
        lineEdit_rec_length->setGeometry(QRect(805, 555, 111, 31));
        QFont font7;
        font7.setPointSize(8);
        lineEdit_rec_length->setFont(font7);
        lineEdit_2_send_length = new QLineEdit(Widget);
        lineEdit_2_send_length->setObjectName(QString::fromUtf8("lineEdit_2_send_length"));
        lineEdit_2_send_length->setEnabled(false);
        lineEdit_2_send_length->setGeometry(QRect(1034, 555, 111, 31));
        lineEdit_2_send_length->setFont(font7);
        groupBox_CH = new QGroupBox(Widget);
        groupBox_CH->setObjectName(QString::fromUtf8("groupBox_CH"));
        groupBox_CH->setGeometry(QRect(10, 10, 201, 361));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        groupBox_CH->setPalette(palette7);
        groupBox_CH->setFont(font2);
        groupBox_CH->setLayoutDirection(Qt::LeftToRight);
        groupBox_CH->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #cbcbcb;  /* \350\276\271\346\241\206\351\242\234\350\211\262\350\256\276\347\275\256\344\270\272 #cbcbcb */\n"
"    border-radius: 5px;          /* \345\234\206\350\247\222\346\225\210\346\236\234\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"    padding: 10px;               /* \345\206\205\350\276\271\350\267\235\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"}"));
        spinBox1_3 = new QSpinBox(groupBox_CH);
        spinBox1_3->setObjectName(QString::fromUtf8("spinBox1_3"));
        spinBox1_3->setEnabled(true);
        spinBox1_3->setGeometry(QRect(90, 118, 91, 31));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Lao UI"));
        font8.setPointSize(13);
        font8.setBold(true);
        font8.setWeight(75);
        font8.setKerning(true);
        spinBox1_3->setFont(font8);
        spinBox1_3->setContextMenuPolicy(Qt::NoContextMenu);
        spinBox1_3->setAutoFillBackground(false);
        spinBox1_3->setStyleSheet(QString::fromUtf8("mm"));
        spinBox1_3->setWrapping(true);
        spinBox1_3->setAlignment(Qt::AlignCenter);
        spinBox1_3->setReadOnly(false);
        spinBox1_3->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox1_3->setAccelerated(false);
        spinBox1_3->setProperty("showGroupSeparator", QVariant(false));
        spinBox1_3->setSuffix(QString::fromUtf8(""));
        spinBox1_3->setPrefix(QString::fromUtf8(""));
        spinBox1_3->setMinimum(5);
        spinBox1_3->setMaximum(8);
        type_2 = new QLineEdit(groupBox_CH);
        type_2->setObjectName(QString::fromUtf8("type_2"));
        type_2->setEnabled(false);
        type_2->setGeometry(QRect(20, 310, 71, 31));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush5);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        QBrush brush12(QColor(85, 85, 127, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette8.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette8.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette8.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Active, QPalette::HighlightedText, brush5);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette8.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette8.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        type_2->setPalette(palette8);
        QFont font9;
        font9.setFamily(QString::fromUtf8("Angsana New"));
        font9.setPointSize(20);
        font9.setBold(false);
        font9.setUnderline(false);
        font9.setWeight(50);
        font9.setStrikeOut(false);
        type_2->setFont(font9);
        type_2->setCursorPosition(6);
        type_2->setAlignment(Qt::AlignCenter);
        type_2->setReadOnly(true);
        type_2->setCursorMoveStyle(Qt::VisualMoveStyle);
        comboBox = new QComboBox(groupBox_CH);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(true);
        comboBox->setGeometry(QRect(90, 74, 91, 31));
        comboBox->setFont(font2);
        comboBox->setEditable(false);
        boundary = new QLineEdit(groupBox_CH);
        boundary->setObjectName(QString::fromUtf8("boundary"));
        boundary->setEnabled(false);
        boundary->setGeometry(QRect(20, 74, 71, 31));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush);
        palette9.setBrush(QPalette::Active, QPalette::Light, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette9.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette9.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette9.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Active, QPalette::HighlightedText, brush5);
        palette9.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette9.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette9.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette9.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette9.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette9.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette9.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        boundary->setPalette(palette9);
        QFont font10;
        font10.setFamily(QString::fromUtf8("Angsana New"));
        font10.setPointSize(14);
        font10.setBold(true);
        font10.setUnderline(false);
        font10.setWeight(75);
        font10.setStrikeOut(false);
        boundary->setFont(font10);
        boundary->setCursorPosition(0);
        boundary->setAlignment(Qt::AlignCenter);
        boundary->setReadOnly(true);
        boundary->setCursorMoveStyle(Qt::VisualMoveStyle);
        type = new QLineEdit(groupBox_CH);
        type->setObjectName(QString::fromUtf8("type"));
        type->setEnabled(false);
        type->setGeometry(QRect(20, 260, 71, 31));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush);
        palette10.setBrush(QPalette::Active, QPalette::Light, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette10.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette10.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette10.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Active, QPalette::HighlightedText, brush5);
        palette10.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette10.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette10.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette10.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette10.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette10.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette10.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        type->setPalette(palette10);
        type->setFont(font10);
        type->setCursorPosition(2);
        type->setAlignment(Qt::AlignCenter);
        type->setReadOnly(true);
        type->setCursorMoveStyle(Qt::VisualMoveStyle);
        comboBox_3 = new QComboBox(groupBox_CH);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setEnabled(true);
        comboBox_3->setGeometry(QRect(90, 310, 91, 31));
        comboBox_3->setBaseSize(QSize(2, 0));
        comboBox_3->setFont(font8);
        comboBox_3->setLayoutDirection(Qt::LeftToRight);
        comboBox_3->setEditable(false);
        comboBox_3->setFrame(true);
        comboBox_4 = new QComboBox(groupBox_CH);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setEnabled(true);
        comboBox_4->setGeometry(QRect(90, 211, 89, 29));
        comboBox_4->setFont(font2);
        comboBox_4->setEditable(false);
        comboBox_4->setInsertPolicy(QComboBox::InsertAtCurrent);
        comboBox_4->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        data = new QLineEdit(groupBox_CH);
        data->setObjectName(QString::fromUtf8("data"));
        data->setEnabled(false);
        data->setGeometry(QRect(20, 118, 71, 31));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush);
        palette11.setBrush(QPalette::Active, QPalette::Light, brush5);
        palette11.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        palette11.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette11.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette11.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette11.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette11.setBrush(QPalette::Active, QPalette::HighlightedText, brush5);
        palette11.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette11.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette11.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette11.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette11.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette11.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette11.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette11.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        data->setPalette(palette11);
        data->setFont(font10);
        data->setCursorPosition(3);
        data->setAlignment(Qt::AlignCenter);
        data->setReadOnly(true);
        data->setCursorMoveStyle(Qt::VisualMoveStyle);
        spinBox1 = new QSpinBox(groupBox_CH);
        spinBox1->setObjectName(QString::fromUtf8("spinBox1"));
        spinBox1->setEnabled(true);
        spinBox1->setGeometry(QRect(90, 30, 91, 31));
        spinBox1->setFont(font3);
        spinBox1->setContextMenuPolicy(Qt::NoContextMenu);
        spinBox1->setStyleSheet(QString::fromUtf8(""));
        spinBox1->setWrapping(true);
        spinBox1->setAlignment(Qt::AlignCenter);
        spinBox1->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox1->setAccelerated(false);
        spinBox1->setProperty("showGroupSeparator", QVariant(false));
        spinBox1->setSuffix(QString::fromUtf8(""));
        spinBox1->setPrefix(QString::fromUtf8(""));
        spinBox1->setMaximum(23);
        spinBox1_4 = new QSpinBox(groupBox_CH);
        spinBox1_4->setObjectName(QString::fromUtf8("spinBox1_4"));
        spinBox1_4->setEnabled(true);
        spinBox1_4->setGeometry(QRect(90, 164, 91, 31));
        spinBox1_4->setFont(font3);
        spinBox1_4->setContextMenuPolicy(Qt::NoContextMenu);
        spinBox1_4->setLayoutDirection(Qt::LeftToRight);
        spinBox1_4->setStyleSheet(QString::fromUtf8("mm"));
        spinBox1_4->setWrapping(true);
        spinBox1_4->setAlignment(Qt::AlignCenter);
        spinBox1_4->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox1_4->setAccelerated(false);
        spinBox1_4->setProperty("showGroupSeparator", QVariant(false));
        spinBox1_4->setSuffix(QString::fromUtf8(""));
        spinBox1_4->setPrefix(QString::fromUtf8(""));
        spinBox1_4->setMinimum(1);
        spinBox1_4->setMaximum(2);
        channel = new QLineEdit(groupBox_CH);
        channel->setObjectName(QString::fromUtf8("channel"));
        channel->setEnabled(false);
        channel->setGeometry(QRect(20, 30, 71, 31));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush);
        palette12.setBrush(QPalette::Active, QPalette::Light, brush5);
        palette12.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        palette12.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette12.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette12.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette12.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette12.setBrush(QPalette::Active, QPalette::HighlightedText, brush5);
        palette12.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette12.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette12.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette12.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette12.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette12.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette12.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        channel->setPalette(palette12);
        QFont font11;
        font11.setFamily(QString::fromUtf8("Aharoni"));
        font11.setPointSize(14);
        font11.setBold(true);
        font11.setUnderline(false);
        font11.setWeight(75);
        font11.setStrikeOut(false);
        channel->setFont(font11);
        channel->setCursorPosition(3);
        channel->setAlignment(Qt::AlignCenter);
        channel->setReadOnly(true);
        channel->setCursorMoveStyle(Qt::VisualMoveStyle);
        check = new QLineEdit(groupBox_CH);
        check->setObjectName(QString::fromUtf8("check"));
        check->setEnabled(false);
        check->setGeometry(QRect(20, 210, 71, 31));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush);
        palette13.setBrush(QPalette::Active, QPalette::Light, brush5);
        palette13.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        palette13.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette13.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette13.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette13.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Active, QPalette::HighlightedText, brush5);
        palette13.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette13.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette13.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette13.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette13.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette13.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette13.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette13.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette13.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette13.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette13.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette13.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush5);
        palette13.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        check->setPalette(palette13);
        check->setFont(font10);
        check->setCursorPosition(3);
        check->setAlignment(Qt::AlignCenter);
        check->setReadOnly(true);
        check->setCursorMoveStyle(Qt::VisualMoveStyle);
        comboBox_2 = new QComboBox(groupBox_CH);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setEnabled(true);
        comboBox_2->setGeometry(QRect(90, 260, 91, 31));
        comboBox_2->setFont(font2);
        comboBox_2->setEditable(false);
        comboBox_2->setFrame(true);
        stop = new QLineEdit(groupBox_CH);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setEnabled(false);
        stop->setGeometry(QRect(20, 164, 71, 31));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush);
        palette14.setBrush(QPalette::Active, QPalette::Light, brush5);
        palette14.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        palette14.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette14.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette14.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette14.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette14.setBrush(QPalette::Active, QPalette::HighlightedText, brush5);
        palette14.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette14.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette14.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette14.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette14.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette14.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette14.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette14.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette14.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette14.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette14.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette14.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette14.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette14.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette14.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush5);
        palette14.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette14.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        stop->setPalette(palette14);
        stop->setFont(font10);
        stop->setCursorPosition(3);
        stop->setAlignment(Qt::AlignCenter);
        stop->setReadOnly(true);
        stop->setCursorMoveStyle(Qt::VisualMoveStyle);
        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 380, 201, 171));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette15.setBrush(QPalette::Active, QPalette::Shadow, brush5);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette15.setBrush(QPalette::Inactive, QPalette::Shadow, brush5);
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette15.setBrush(QPalette::Disabled, QPalette::Shadow, brush5);
        groupBox_3->setPalette(palette15);
        groupBox_3->setFont(font2);
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #cbcbcb;  /* \350\276\271\346\241\206\351\242\234\350\211\262\350\256\276\347\275\256\344\270\272 #cbcbcb */\n"
"    border-radius: 5px;          /* \345\234\206\350\247\222\346\225\210\346\236\234\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"    padding: 10px;               /* \345\206\205\350\276\271\350\267\235\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"}"));
        type_5 = new QLineEdit(groupBox_3);
        type_5->setObjectName(QString::fromUtf8("type_5"));
        type_5->setEnabled(false);
        type_5->setGeometry(QRect(20, 120, 71, 31));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush);
        palette16.setBrush(QPalette::Active, QPalette::Light, brush5);
        palette16.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        palette16.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette16.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette16.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette16.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush13(QColor(255, 255, 127, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette16.setBrush(QPalette::Active, QPalette::Highlight, brush13);
        palette16.setBrush(QPalette::Active, QPalette::HighlightedText, brush5);
        palette16.setBrush(QPalette::Active, QPalette::Link, brush);
        QBrush brush14(QColor(255, 255, 0, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette16.setBrush(QPalette::Active, QPalette::LinkVisited, brush14);
        palette16.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette16.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette16.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette16.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette16.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette16.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Highlight, brush13);
        palette16.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette16.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush14);
        palette16.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette16.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette16.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette16.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette16.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette16.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        palette16.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush5);
        palette16.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush14);
        palette16.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        type_5->setPalette(palette16);
        type_5->setFont(font10);
        type_5->setCursorPosition(2);
        type_5->setAlignment(Qt::AlignCenter);
        type_5->setReadOnly(true);
        type_5->setCursorMoveStyle(Qt::VisualMoveStyle);
        comboBox_5 = new QComboBox(groupBox_3);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setEnabled(true);
        comboBox_5->setGeometry(QRect(90, 30, 91, 31));
        comboBox_5->setBaseSize(QSize(2, 0));
        comboBox_5->setFont(font8);
        comboBox_5->setLayoutDirection(Qt::LeftToRight);
        comboBox_5->setEditable(false);
        comboBox_5->setFrame(true);
        spinBox1_6 = new QSpinBox(groupBox_3);
        spinBox1_6->setObjectName(QString::fromUtf8("spinBox1_6"));
        spinBox1_6->setEnabled(true);
        spinBox1_6->setGeometry(QRect(90, 120, 91, 31));
        spinBox1_6->setFont(font3);
        spinBox1_6->setContextMenuPolicy(Qt::NoContextMenu);
        spinBox1_6->setLayoutDirection(Qt::LeftToRight);
        spinBox1_6->setStyleSheet(QString::fromUtf8("mm"));
        spinBox1_6->setWrapping(true);
        spinBox1_6->setAlignment(Qt::AlignCenter);
        spinBox1_6->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox1_6->setAccelerated(false);
        spinBox1_6->setProperty("showGroupSeparator", QVariant(false));
        spinBox1_6->setSuffix(QString::fromUtf8(""));
        spinBox1_6->setPrefix(QString::fromUtf8(""));
        spinBox1_6->setMinimum(0);
        spinBox1_6->setMaximum(1000000000);
        type_4 = new QLineEdit(groupBox_3);
        type_4->setObjectName(QString::fromUtf8("type_4"));
        type_4->setEnabled(false);
        type_4->setGeometry(QRect(20, 74, 71, 31));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette17.setBrush(QPalette::Active, QPalette::Button, brush);
        palette17.setBrush(QPalette::Active, QPalette::Light, brush5);
        palette17.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        palette17.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette17.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette17.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette17.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette17.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette17.setBrush(QPalette::Active, QPalette::Highlight, brush13);
        palette17.setBrush(QPalette::Active, QPalette::HighlightedText, brush5);
        palette17.setBrush(QPalette::Active, QPalette::Link, brush);
        palette17.setBrush(QPalette::Active, QPalette::LinkVisited, brush14);
        palette17.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette17.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette17.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette17.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette17.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::Highlight, brush13);
        palette17.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush14);
        palette17.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette17.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette17.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette17.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette17.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette17.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette17.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        palette17.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush5);
        palette17.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush14);
        palette17.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette17.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        type_4->setPalette(palette17);
        type_4->setFont(font10);
        type_4->setCursorPosition(3);
        type_4->setAlignment(Qt::AlignCenter);
        type_4->setReadOnly(true);
        type_4->setCursorMoveStyle(Qt::VisualMoveStyle);
        type_3 = new QLineEdit(groupBox_3);
        type_3->setObjectName(QString::fromUtf8("type_3"));
        type_3->setEnabled(false);
        type_3->setGeometry(QRect(20, 30, 71, 31));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette18.setBrush(QPalette::Active, QPalette::Button, brush);
        palette18.setBrush(QPalette::Active, QPalette::Light, brush5);
        palette18.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        palette18.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette18.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette18.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette18.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette18.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette18.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette18.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette18.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette18.setBrush(QPalette::Active, QPalette::Highlight, brush13);
        palette18.setBrush(QPalette::Active, QPalette::HighlightedText, brush5);
        palette18.setBrush(QPalette::Active, QPalette::Link, brush);
        palette18.setBrush(QPalette::Active, QPalette::LinkVisited, brush14);
        palette18.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette18.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette18.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette18.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette18.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette18.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette18.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette18.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette18.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette18.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette18.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Highlight, brush13);
        palette18.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette18.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush14);
        palette18.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette18.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette18.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette18.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette18.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette18.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette18.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette18.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette18.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette18.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        palette18.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush5);
        palette18.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush14);
        palette18.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette18.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette18.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        type_3->setPalette(palette18);
        type_3->setFont(font9);
        type_3->setCursorPosition(6);
        type_3->setAlignment(Qt::AlignCenter);
        type_3->setReadOnly(true);
        type_3->setCursorMoveStyle(Qt::VisualMoveStyle);
        spinBox1_5 = new QSpinBox(groupBox_3);
        spinBox1_5->setObjectName(QString::fromUtf8("spinBox1_5"));
        spinBox1_5->setEnabled(true);
        spinBox1_5->setGeometry(QRect(90, 74, 91, 31));
        spinBox1_5->setFont(font3);
        spinBox1_5->setContextMenuPolicy(Qt::NoContextMenu);
        spinBox1_5->setLayoutDirection(Qt::LeftToRight);
        spinBox1_5->setStyleSheet(QString::fromUtf8("mm"));
        spinBox1_5->setWrapping(true);
        spinBox1_5->setAlignment(Qt::AlignCenter);
        spinBox1_5->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox1_5->setAccelerated(false);
        spinBox1_5->setProperty("showGroupSeparator", QVariant(false));
        spinBox1_5->setSuffix(QString::fromUtf8(""));
        spinBox1_5->setPrefix(QString::fromUtf8(""));
        spinBox1_5->setMinimum(0);
        spinBox1_5->setMaximum(1000000000);
        groupBox_rec_2 = new QGroupBox(Widget);
        groupBox_rec_2->setObjectName(QString::fromUtf8("groupBox_rec_2"));
        groupBox_rec_2->setGeometry(QRect(460, 590, 221, 251));
        QPalette palette19;
        palette19.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette19.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette19.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        groupBox_rec_2->setPalette(palette19);
        groupBox_rec_2->setFont(font2);
        groupBox_rec_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid #cbcbcb;  /* \350\276\271\346\241\206\351\242\234\350\211\262\350\256\276\347\275\256\344\270\272 #cbcbcb */\n"
"    border-radius: 5px;          /* \345\234\206\350\247\222\346\225\210\346\236\234\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"    padding: 10px;               /* \345\206\205\350\276\271\350\267\235\357\274\210\345\217\257\351\200\211\357\274\211 */\n"
"}"));
        spinBox_send_ch = new QSpinBox(groupBox_rec_2);
        spinBox_send_ch->setObjectName(QString::fromUtf8("spinBox_send_ch"));
        spinBox_send_ch->setEnabled(true);
        spinBox_send_ch->setGeometry(QRect(100, 30, 101, 31));
        spinBox_send_ch->setFont(font3);
        spinBox_send_ch->setContextMenuPolicy(Qt::NoContextMenu);
        spinBox_send_ch->setStyleSheet(QString::fromUtf8(""));
        spinBox_send_ch->setWrapping(true);
        spinBox_send_ch->setAlignment(Qt::AlignCenter);
        spinBox_send_ch->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBox_send_ch->setAccelerated(false);
        spinBox_send_ch->setProperty("showGroupSeparator", QVariant(false));
        spinBox_send_ch->setSuffix(QString::fromUtf8(""));
        spinBox_send_ch->setPrefix(QString::fromUtf8(""));
        spinBox_send_ch->setMaximum(23);
        pushButton_5 = new QPushButton(groupBox_rec_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(16, 189, 191, 41));
        QPalette palette20;
        palette20.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette20.setBrush(QPalette::Active, QPalette::Button, brush);
        palette20.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette20.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette20.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette20.setBrush(QPalette::Active, QPalette::Text, brush);
        palette20.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette20.setBrush(QPalette::Active, QPalette::Base, brush);
        palette20.setBrush(QPalette::Active, QPalette::Window, brush);
        palette20.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette20.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette20.setBrush(QPalette::Active, QPalette::Link, brush);
        palette20.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        palette20.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette20.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette20.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette20.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette20.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette20.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette20.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        palette20.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette20.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette20.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        pushButton_5->setPalette(palette20);
        pushButton_5->setFont(font3);
        pushButton_5->setFocusPolicy(Qt::NoFocus);
        pushButton_5->setAcceptDrops(true);
        checkBox_4 = new QCheckBox(groupBox_rec_2);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(20, 149, 101, 31));
        checkBox_4->setFont(font4);
        checkBox_4->setLayoutDirection(Qt::LeftToRight);
        radioButton_send_string = new QRadioButton(groupBox_rec_2);
        radioButton_send_string->setObjectName(QString::fromUtf8("radioButton_send_string"));
        radioButton_send_string->setGeometry(QRect(20, 70, 61, 18));
        QPalette palette21;
        palette21.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette21.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette21.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette21.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette21.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette21.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette21.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette21.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette21.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette21.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        radioButton_send_string->setPalette(palette21);
        radioButton_send_string->setFont(font3);
        radioButton_send_string->setIconSize(QSize(50, 50));
        spinBox_send_time = new QSpinBox(groupBox_rec_2);
        spinBox_send_time->setObjectName(QString::fromUtf8("spinBox_send_time"));
        spinBox_send_time->setGeometry(QRect(115, 149, 91, 31));
        QFont font12;
        font12.setPointSize(15);
        spinBox_send_time->setFont(font12);
        spinBox_send_time->setLayoutDirection(Qt::RightToLeft);
        radioButton_send_txt = new QRadioButton(groupBox_rec_2);
        radioButton_send_txt->setObjectName(QString::fromUtf8("radioButton_send_txt"));
        radioButton_send_txt->setGeometry(QRect(80, 70, 61, 18));
        QPalette palette22;
        palette22.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette22.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette22.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette22.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette22.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette22.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette22.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette22.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette22.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette22.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette22.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette22.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        radioButton_send_txt->setPalette(palette22);
        radioButton_send_txt->setFont(font3);
        radioButton_send_txt->setIconSize(QSize(50, 50));
        radioButton_send_hex = new QRadioButton(groupBox_rec_2);
        radioButton_send_hex->setObjectName(QString::fromUtf8("radioButton_send_hex"));
        radioButton_send_hex->setGeometry(QRect(140, 70, 61, 18));
        QPalette palette23;
        palette23.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette23.setBrush(QPalette::Active, QPalette::Text, brush7);
        palette23.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette23.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette23.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette23.setBrush(QPalette::Inactive, QPalette::Text, brush7);
        palette23.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette23.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette23.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette23.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette23.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette23.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        radioButton_send_hex->setPalette(palette23);
        radioButton_send_hex->setFont(font3);
        radioButton_send_hex->setIconSize(QSize(50, 50));
        channel_2 = new QLineEdit(groupBox_rec_2);
        channel_2->setObjectName(QString::fromUtf8("channel_2"));
        channel_2->setEnabled(false);
        channel_2->setGeometry(QRect(20, 30, 81, 31));
        QPalette palette24;
        palette24.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette24.setBrush(QPalette::Active, QPalette::Button, brush);
        palette24.setBrush(QPalette::Active, QPalette::Light, brush5);
        palette24.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        palette24.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette24.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette24.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette24.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette24.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette24.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette24.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette24.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette24.setBrush(QPalette::Active, QPalette::HighlightedText, brush5);
        palette24.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette24.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette24.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette24.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette24.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette24.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette24.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette24.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette24.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette24.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette24.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette24.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette24.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette24.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette24.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette24.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette24.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette24.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette24.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette24.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette24.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette24.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette24.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette24.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette24.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette24.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette24.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette24.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette24.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        palette24.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette24.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush5);
        palette24.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette24.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette24.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette24.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        channel_2->setPalette(palette24);
        QFont font13;
        font13.setFamily(QString::fromUtf8("Aharoni"));
        font13.setPointSize(15);
        font13.setBold(true);
        font13.setUnderline(false);
        font13.setWeight(75);
        font13.setStrikeOut(false);
        channel_2->setFont(font13);
        channel_2->setCursorPosition(3);
        channel_2->setAlignment(Qt::AlignCenter);
        channel_2->setReadOnly(true);
        channel_2->setCursorMoveStyle(Qt::VisualMoveStyle);
        pushButton_6 = new QPushButton(groupBox_rec_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(14, 97, 191, 41));
        QPalette palette25;
        palette25.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette25.setBrush(QPalette::Active, QPalette::Button, brush);
        palette25.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette25.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette25.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette25.setBrush(QPalette::Active, QPalette::Text, brush);
        palette25.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette25.setBrush(QPalette::Active, QPalette::Base, brush);
        palette25.setBrush(QPalette::Active, QPalette::Window, brush);
        palette25.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette25.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette25.setBrush(QPalette::Active, QPalette::Link, brush);
        palette25.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        palette25.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette25.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette25.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette25.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette25.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette25.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette25.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette25.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette25.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        palette25.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette25.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette25.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        pushButton_6->setPalette(palette25);
        pushButton_6->setFont(font3);
        pushButton_6->setFocusPolicy(Qt::NoFocus);
        pushButton_6->setAcceptDrops(true);
        auto_link = new QPushButton(Widget);
        auto_link->setObjectName(QString::fromUtf8("auto_link"));
        auto_link->setGeometry(QRect(30, 570, 161, 41));
        QPalette palette26;
        palette26.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette26.setBrush(QPalette::Active, QPalette::Button, brush);
        palette26.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette26.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette26.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette26.setBrush(QPalette::Active, QPalette::Text, brush);
        palette26.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette26.setBrush(QPalette::Active, QPalette::Base, brush);
        palette26.setBrush(QPalette::Active, QPalette::Window, brush);
        palette26.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette26.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette26.setBrush(QPalette::Active, QPalette::Link, brush);
        palette26.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        palette26.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette26.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette26.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette26.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette26.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette26.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette26.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette26.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette26.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        palette26.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette26.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette26.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        auto_link->setPalette(palette26);
        QFont font14;
        font14.setFamily(QString::fromUtf8("Kartika"));
        font14.setPointSize(14);
        font14.setBold(true);
        font14.setWeight(75);
        auto_link->setFont(font14);
        auto_link->setFocusPolicy(Qt::NoFocus);
        auto_link->setAcceptDrops(true);
        man_link = new QPushButton(Widget);
        man_link->setObjectName(QString::fromUtf8("man_link"));
        man_link->setGeometry(QRect(30, 620, 161, 41));
        QPalette palette27;
        palette27.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette27.setBrush(QPalette::Active, QPalette::Button, brush);
        palette27.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette27.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette27.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette27.setBrush(QPalette::Active, QPalette::Text, brush);
        palette27.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette27.setBrush(QPalette::Active, QPalette::Base, brush);
        palette27.setBrush(QPalette::Active, QPalette::Window, brush);
        palette27.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette27.setBrush(QPalette::Active, QPalette::Highlight, brush);
        palette27.setBrush(QPalette::Active, QPalette::Link, brush);
        palette27.setBrush(QPalette::Active, QPalette::LinkVisited, brush);
        palette27.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette27.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette27.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette27.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette27.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette27.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::Highlight, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette27.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette27.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette27.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        palette27.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette27.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette27.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        man_link->setPalette(palette27);
        QFont font15;
        font15.setFamily(QString::fromUtf8("Arial"));
        font15.setPointSize(14);
        font15.setBold(true);
        font15.setItalic(false);
        font15.setUnderline(false);
        font15.setWeight(75);
        font15.setStrikeOut(false);
        man_link->setFont(font15);
        man_link->setFocusPolicy(Qt::NoFocus);
        man_link->setAcceptDrops(true);
        light = new QLineEdit(Widget);
        light->setObjectName(QString::fromUtf8("light"));
        light->setEnabled(false);
        light->setGeometry(QRect(220, 560, 461, 25));
        QPalette palette28;
        palette28.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette28.setBrush(QPalette::Active, QPalette::Button, brush);
        palette28.setBrush(QPalette::Active, QPalette::Light, brush5);
        palette28.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        palette28.setBrush(QPalette::Active, QPalette::Dark, brush6);
        palette28.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette28.setBrush(QPalette::Active, QPalette::Text, brush5);
        palette28.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette28.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette28.setBrush(QPalette::Active, QPalette::Base, brush14);
        palette28.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush15(QColor(255, 85, 127, 255));
        brush15.setStyle(Qt::SolidPattern);
        palette28.setBrush(QPalette::Active, QPalette::Shadow, brush15);
        palette28.setBrush(QPalette::Active, QPalette::Highlight, brush13);
        palette28.setBrush(QPalette::Active, QPalette::HighlightedText, brush5);
        palette28.setBrush(QPalette::Active, QPalette::Link, brush);
        palette28.setBrush(QPalette::Active, QPalette::LinkVisited, brush14);
        palette28.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        palette28.setBrush(QPalette::Active, QPalette::ToolTipBase, brush);
        palette28.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette28.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette28.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette28.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette28.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette28.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette28.setBrush(QPalette::Inactive, QPalette::Dark, brush6);
        palette28.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette28.setBrush(QPalette::Inactive, QPalette::Text, brush5);
        palette28.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette28.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette28.setBrush(QPalette::Inactive, QPalette::Base, brush14);
        palette28.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette28.setBrush(QPalette::Inactive, QPalette::Shadow, brush15);
        palette28.setBrush(QPalette::Inactive, QPalette::Highlight, brush13);
        palette28.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush5);
        palette28.setBrush(QPalette::Inactive, QPalette::Link, brush);
        palette28.setBrush(QPalette::Inactive, QPalette::LinkVisited, brush14);
        palette28.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette28.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush);
        palette28.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette28.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette28.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette28.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette28.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette28.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette28.setBrush(QPalette::Disabled, QPalette::Dark, brush6);
        palette28.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette28.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette28.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette28.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette28.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette28.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette28.setBrush(QPalette::Disabled, QPalette::Shadow, brush15);
        palette28.setBrush(QPalette::Disabled, QPalette::Highlight, brush3);
        palette28.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush5);
        palette28.setBrush(QPalette::Disabled, QPalette::Link, brush);
        palette28.setBrush(QPalette::Disabled, QPalette::LinkVisited, brush14);
        palette28.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette28.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush);
        palette28.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette28.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        light->setPalette(palette28);
        light->setFont(font10);
        light->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\n"
"	\"border-radius: 1px;\"\n"
")"));
        light->setCursorPosition(0);
        light->setAlignment(Qt::AlignCenter);
        light->setReadOnly(true);
        light->setCursorMoveStyle(Qt::VisualMoveStyle);
        deviceListWidget = new QListWidget(Widget);
        deviceListWidget->setObjectName(QString::fromUtf8("deviceListWidget"));
        deviceListWidget->setGeometry(QRect(217, 591, 231, 101));
        groupBox_CH->raise();
        groupBox_3->raise();
        groupBox_rec->raise();
        pushButton->raise();
        pushButton_2->raise();
        textEdit->raise();
        textEdit_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        label_2->raise();
        label_3->raise();
        lineEdit_rec_length->raise();
        lineEdit_2_send_length->raise();
        groupBox_rec_2->raise();
        auto_link->raise();
        man_link->raise();
        light->raise();
        deviceListWidget->raise();

        retranslateUi(Widget);

        comboBox->setCurrentIndex(0);
        comboBox_3->setCurrentIndex(0);
        comboBox_4->setCurrentIndex(0);
        comboBox_2->setCurrentIndex(0);
        comboBox_5->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Qshyug\344\270\262\345\217\243\345\212\251\346\211\213", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\345\205\263\344\272\216", nullptr));
        groupBox_rec->setTitle(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\350\256\276\347\275\256", nullptr));
        radioButton_rec_hex->setText(QCoreApplication::translate("Widget", "HEX", nullptr));
        radioButton_rec_txt->setText(QCoreApplication::translate("Widget", "TXT", nullptr));
        checkBox_data_save->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\345\255\230\345\202\250", nullptr));
        checkBox_dpy_time->setText(QCoreApplication::translate("Widget", "\346\230\276\347\244\272\346\227\266\351\227\264", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Widget", "\346\230\276\347\244\272\346\211\200\346\234\211\351\200\232\351\201\223", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\344\270\200\350\241\214\346\230\276\347\244\272\345\255\227\350\212\202\346\225\260", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\347\252\227\345\217\243\346\210\252\345\261\217", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "\346\270\205\351\231\244\347\252\227\345\217\243", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\345\255\227\350\212\202\346\225\260", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\345\255\227\350\212\202\346\225\260", nullptr));
        groupBox_CH->setTitle(QCoreApplication::translate("Widget", "\351\200\232\351\201\223\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(accessibility)
        spinBox1_3->setAccessibleName(QCoreApplication::translate("Widget", "mmm", "mm"));
#endif // QT_CONFIG(accessibility)
        spinBox1_3->setSpecialValueText(QString());
        type_2->setText(QCoreApplication::translate("Widget", "ON/OFF", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Widget", "  6.25M", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Widget", "3.125M", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Widget", "  2.4M", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Widget", "921600", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("Widget", "500000", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("Widget", "200000", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("Widget", "100000", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("Widget", "460800", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("Widget", "230400", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("Widget", "115200", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("Widget", " 57600", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("Widget", " 38400", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("Widget", "  6.25M", nullptr));
        boundary->setText(QCoreApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", nullptr));
        type->setText(QCoreApplication::translate("Widget", "\346\250\241\345\274\217", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("Widget", "    ON", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("Widget", "    OFF", nullptr));

        comboBox_3->setCurrentText(QCoreApplication::translate("Widget", "    ON", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("Widget", "   NONE", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("Widget", "    ODD", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("Widget", "   EVEN", nullptr));

        comboBox_4->setCurrentText(QCoreApplication::translate("Widget", "   NONE", nullptr));
        data->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", nullptr));
#if QT_CONFIG(accessibility)
        spinBox1->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        spinBox1->setSpecialValueText(QString());
#if QT_CONFIG(accessibility)
        spinBox1_4->setAccessibleName(QCoreApplication::translate("Widget", "mmm", "mm"));
#endif // QT_CONFIG(accessibility)
        spinBox1_4->setSpecialValueText(QString());
        channel->setText(QCoreApplication::translate("Widget", "\351\200\232\351\201\223\345\217\267", nullptr));
        check->setText(QCoreApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Widget", "  RS422", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Widget", "  RS232", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("Widget", "  RS485", nullptr));

        comboBox_2->setCurrentText(QCoreApplication::translate("Widget", "  RS422", nullptr));
        stop->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Widget", "\347\241\254\344\273\266\345\256\232\346\227\266\345\217\221\351\200\201\350\256\276\347\275\256", nullptr));
        type_5->setText(QCoreApplication::translate("Widget", "\345\221\250\346\234\237", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("Widget", "    ON", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("Widget", "    OFF", nullptr));

        comboBox_5->setCurrentText(QCoreApplication::translate("Widget", "    ON", nullptr));
#if QT_CONFIG(accessibility)
        spinBox1_6->setAccessibleName(QCoreApplication::translate("Widget", "mmm", "mm"));
#endif // QT_CONFIG(accessibility)
        spinBox1_6->setSpecialValueText(QString());
        type_4->setText(QCoreApplication::translate("Widget", "\345\270\247\351\225\277\345\272\246", nullptr));
        type_3->setText(QCoreApplication::translate("Widget", "ON/OFF", nullptr));
#if QT_CONFIG(accessibility)
        spinBox1_5->setAccessibleName(QCoreApplication::translate("Widget", "mmm", "mm"));
#endif // QT_CONFIG(accessibility)
        spinBox1_5->setSpecialValueText(QString());
        groupBox_rec_2->setTitle(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(accessibility)
        spinBox_send_ch->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        spinBox_send_ch->setSpecialValueText(QString());
        pushButton_5->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        checkBox_4->setText(QCoreApplication::translate("Widget", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        radioButton_send_string->setText(QCoreApplication::translate("Widget", "STR", nullptr));
        radioButton_send_txt->setText(QCoreApplication::translate("Widget", "TXT", nullptr));
        radioButton_send_hex->setText(QCoreApplication::translate("Widget", "HEX", nullptr));
        channel_2->setText(QCoreApplication::translate("Widget", "\351\200\232\351\201\223\345\217\267", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "\344\270\212\344\274\240\346\226\207\344\273\266", nullptr));
        auto_link->setText(QCoreApplication::translate("Widget", "\350\207\252\345\212\250\350\277\236\346\216\245", nullptr));
        man_link->setText(QCoreApplication::translate("Widget", "\346\214\207\345\256\232\350\277\236\346\216\245", nullptr));
        light->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
