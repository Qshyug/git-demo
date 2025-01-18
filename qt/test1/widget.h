#ifndef WIDGET_H
#define WIDGET_H

#include "serialportmanager.h"   // 引入 SerialPortManager 类的头文件
extern "C"{
    #include "WD663X.h"
    #include "visatype.h"

}

#include <QPalette>

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>

#include <QSpinBox>
#include <QComboBox>
#include <QGroupBox>

#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <QDesktopServices>
#include <QUrl>
#include <QLabel>

#include <QRadioButton>
#include <QButtonGroup>
//窗口截屏头文件
#include <QScreen>
#include <QGuiApplication>
#include <QPixmap>
#include <QDir>
#include <QDateTime>
#include <QMessageBox>
//设置波特率
#include <QSplashScreen>
#include <QPixmap>
#include <QTimer>
#include <QApplication>
#include <QFile>
#include <QEventLoop>

#include <QListWidget>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


class Widget : public QWidget
{
        Q_OBJECT

    public:
        Widget(QWidget *parent = nullptr);
        ~Widget();

    private slots:
        void on_spinBox1_textChanged(const QString &arg1);//设置通道函数
        void on_comboBox_2_activated(const QString &arg1);//设置通信模式
        void on_comboBox_3_activated(const QString &arg1);//设置通道开关

        void on_comboBox_activated(const QString &arg1);//设置波特率
        void on_spinBox1_4_valueChanged(int arg1);//设置停止位
        void on_spinBox1_3_valueChanged(int arg1);//设置数据位
        void on_comboBox_4_activated(const QString &arg1);//设置校验位

        void on_pushButton_clicked();//退出程序按钮
        void on_pushButton_2_clicked();//公司介绍“关于”按钮
        void on_pushButton_3_clicked();//窗口截屏操作
        void on_pushButton_4_clicked();//清除窗口数据

        void on_comboBox_5_activated(const QString &arg1);//定时开关
        void on_spinBox1_5_textChanged(const QString &arg1);//定时设置的帧长度
//        void on_spinBox1_6_textChanged(const QString &arg1);//定时周期


        void on_spinBox1_6_valueChanged(int arg1);

        void on_auto_link_clicked();  //自动连接

        void on_man_link_clicked();  // 指定连接

private:
        Ui::Widget *ui;
        QSpinBox *spinBox1;
        QSpinBox *spinBox1_3;
        QSerialPort *serialPort;  // 设置串口对象指针

        void showSplashScreen(const QString &imagePath, int delayMs);  // 加载界面函数
        SerialPortManager *serialPortManager;  // 串口管理器对象

                    int autoConnect(int &cardnum);  // 模拟自动连接autoConnect函数

        uint32_t HW_VER, SF_VER;  // 存储硬件和软件版本号
//        PCI_SOURCE pPCI_SOURCE[10];  // 用于存储外部库函数返回的设备信息


};
#endif // WIDGET_H
