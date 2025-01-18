#include "widget.h"
#include "ui_widget.h"
#include <QWidget>
#include <QSerialPort>
#include "serialportmanager.h"


SerialPortManager::SerialPortManager(QSerialPort *port, QWidget *parent)
    : serialPort(port), parentWidget(parent)
{
}



//波特率设置封装函数
void SerialPortManager::setBaudRate(const QString &baudRate)
{
    int baudRateInt = 0;

    // 检查串口是否已初始化且已打开
    if (serialPort == nullptr || !serialPort->isOpen()) {
            QMessageBox::critical(parentWidget, "警告","串口未初始化或未打开");
            return;
        }

    // 根据选择的波特率字符串转换为整数
    QMap<QString, int> baudRateMap = {
        {"230400", 230400},{"460800", 460800},{"100000", 100000},{"200000", 200000},
        {"500000", 500000},{"921600", 921600},{"2.4M", 2400000},{"3.125M", 3125000},
        {"6.25M", 6250000},{"38400", 38400},{"57600", 57600}, {"115200", 115200}
    };

    // 检查波特率是否在映射表中
        if (baudRateMap.contains(baudRate)) {
            baudRateInt = baudRateMap[baudRate];
        } else {
            qWarning() << "未知的波特率：" << baudRate;
            QMessageBox::warning(parentWidget, "警告", "无效的波特率");
            return;
        }

    // 设置串口波特率
            serialPort->setBaudRate(baudRateInt);

    // 输出设置的波特率
            qDebug() << "Baud rate set to:" << baudRate;

}

//数据位设置封装函数
void SerialPortManager::setDataBits(int dataBits)
{
    if (serialPort == nullptr || !serialPort->isOpen()) {
            QMessageBox::critical(parentWidget, "Error", "Serial port is not initialized or not open!");
            return;
        }

    switch (dataBits) {
            case 5:
                serialPort->setDataBits(QSerialPort::Data5);
                break;
            case 6:
                serialPort->setDataBits(QSerialPort::Data6);
                break;
            case 7:
                serialPort->setDataBits(QSerialPort::Data7);
                break;
            case 8:
                serialPort->setDataBits(QSerialPort::Data8);
                break;
            default:
                QMessageBox::critical(parentWidget, "Error", "Unsupported data bits value!");
                return;
        }

        qDebug() << "Data bits set to:" << dataBits;
}

//停止位设置封装函数
void SerialPortManager::setStopBits(int stopBits)
{
        if (serialPort == nullptr || !serialPort->isOpen()) {
            QMessageBox::critical(parentWidget, "Error", "Serial port is not initialized or not open!");
            return;
        }

        switch (stopBits) {
            case 1:
                serialPort->setStopBits(QSerialPort::OneStop);
                break;
            case 2:
                serialPort->setStopBits(QSerialPort::TwoStop);
                break;
            default:
                QMessageBox::critical(parentWidget, "Error", "Unsupported stop bits value!");
                return;
        }
    qDebug() << "Stop bits set to:" << stopBits;
}

//校验位设置封装函数
void SerialPortManager::setParity(const QString &parity)
{
    // 检查串口是否已初始化和打开
    if (serialPort == nullptr || !serialPort->isOpen()) {
        QMessageBox::critical(parentWidget, "Error", "Serial port is not initialized or not open!");
        return;
    }

    // 根据用户选择设置校验位
    if (parity == "NONE") {
        serialPort->setParity(QSerialPort::NoParity);
    } else if (parity == "ODD") {
        serialPort->setParity(QSerialPort::OddParity);
    } else if (parity == "EVEN") {
        serialPort->setParity(QSerialPort::EvenParity);
    } else {
        QMessageBox::critical(parentWidget, "Error", "Unsupported parity value!");
    }
}

