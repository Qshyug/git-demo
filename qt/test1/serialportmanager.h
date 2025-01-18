#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H

#include <QSerialPort>
#include <QMessageBox>
#include <QDebug>

class SerialPortManager
{
public:
    SerialPortManager(QSerialPort *port, QWidget *parent = nullptr);

    // 设置串口参数的函数接口
    void setBaudRate(const QString &baudRate);  // 波特率函数接口
    void setDataBits(int dataBits);  //数据位函数接口
    void setStopBits(int stopBits);  //停止位函数接口
    void setParity(const QString &parity);  //校验位函数接口


private:
    QSerialPort *serialPort;  // 设置串口对象指针
    QWidget *parentWidget;    // 保存父窗口指针

};

#endif // SERIALPORTMANAGER_H
