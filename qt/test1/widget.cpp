#include "widget.h"
#include "ui_widget.h"
#include "serialportmanager.h"

//#include <QSplashScreen>
//#include <QPixmap>
//#include <QTimer>
//#include <QApplication>
//#include <QFile>
//#include <QEventLoop>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)  //初始化UI界面
    , serialPort(new QSerialPort(this))  // 初始化串口对象 serialPort
    , serialPortManager(new SerialPortManager(serialPort))  // 初始化 SerialPortManager
{
    ui->setupUi(this);
    ui->spinBox1->setPrefix("CH");//设置通道后缀
    ui->spinBox1_3->setSuffix("bit");//设置通道后缀

    showSplashScreen("C:/Users/Administrator/Desktop/qt/test1/59474a20ae0ba.png", 1500);  //加载界面

    serialPortManager = new SerialPortManager(serialPort, this);  // 初始化 SerialPortManager 对象，并将父窗口传递给它


//信号与槽连接
    connect(ui->comboBox, SIGNAL(activated(QString)), this, SLOT(on_comboBox_activated(QString)));     // 波特率设置
    connect(ui->spinBox1_3, SIGNAL(valueChanged(int)), this, SLOT(on_spinBox1_3_valueChanged(int)));   // 数据位设置
    connect(ui->spinBox1_4, SIGNAL(valueChanged(int)), this, SLOT(on_spinBox1_4_valueChanged(int)));     // 停止位设置
    connect(ui->comboBox_4, SIGNAL(activated(QString)), this, SLOT(on_comboBox_4_activated(QString)));      // 校验位设置
//    connect(ui->man_link, &QPushButton::clicked, this, &Widget::on_man_link_clicked);
}

Widget::~Widget()
{
    delete ui;
}
//加载页面显示
void Widget::showSplashScreen(const QString &imagePath, int delayMs)
{
    // 加载并显示启动画面
    QPixmap pixmap(imagePath);
    if (pixmap.isNull()) {
        qDebug() << "加载图片失败，路径：" << imagePath;
        return;
    }

    QSplashScreen splash(pixmap);
    splash.setWindowFlags(Qt::SplashScreen | Qt::FramelessWindowHint);
    splash.show();

    // 确保加载画面有时间显示
    QApplication::processEvents();  // 处理当前的事件，确保图片渲染

    // 使用 QEventLoop 确保延迟生效
    QEventLoop loop;
    QTimer::singleShot(delayMs, &loop, &QEventLoop::quit);  // 延迟指定毫秒后退出事件循环
    loop.exec();  // 执行事件循环，直到定时器触发

    // 延迟后关闭启动画面并显示主窗口
    splash.close();
    this->show();  // 显示主窗口
}
//退出程序按钮
void Widget::on_pushButton_clicked()
{
    this->close();
}
//公司介绍“关于”按钮
void Widget::on_pushButton_2_clicked()
{
    QDesktopServices::openUrl(QUrl("http://ys-amc.com/"));
}
//窗口截屏操作
void Widget::on_pushButton_3_clicked()
{
    QScreen *screen = QGuiApplication::primaryScreen();
        if (!screen) {
            QMessageBox::critical(this, "错误", "无法获取屏幕");
            return;
        }

        // 捕获当前窗口的内容
        QPixmap pixmap = screen->grabWindow(this->winId());

        // 创建保存路径
        QString savePath = "D:/SerialPort Result";
        QDir dir(savePath);
        if (!dir.exists()) {
            bool created = dir.mkpath(savePath);
            if (!created) {
                QMessageBox::critical(this, "错误", "无法创建保存路径");
                return;
            }
        }
        // 生成文件名
        QString fileName = QDateTime::currentDateTime().toString("yyyy-MM-dd_HH-mm-ss") + ".png";
        QString filePath = savePath + "/" + fileName;

        // 保存截图
        bool saved = pixmap.save(filePath);
        if (saved) {
            QMessageBox::information(this, "成功", "截图已保存到 " + filePath);
        } else {
            QMessageBox::critical(this, "错误", "无法保存截图");
        }
}
//设置通道函数
void Widget::on_spinBox1_textChanged(const QString &arg1)
{

}
//设置波特率
void Widget::on_comboBox_activated(const QString &arg1)
{
    serialPortManager->setBaudRate(arg1);  // 调用封装的波特率设置函数
}
//设置数据位
void Widget::on_spinBox1_3_valueChanged(int arg1)
{
   serialPortManager->setDataBits(arg1);  // 调用封装的数据位设置函数
}
//设置停止位
void Widget::on_spinBox1_4_valueChanged(int arg1)
{
    serialPortManager->setStopBits(arg1);  // 调用封装的数据位设置函数
}
//设置校验位
void Widget::on_comboBox_4_activated(const QString &arg1)
{
     serialPortManager-> setParity(arg1);  // 调用封装的校验位设置函数
}
//设置通信模式
void Widget::on_comboBox_2_activated(const QString &arg1)
{

}
//设置通道开关
void Widget::on_comboBox_3_activated(const QString &arg1)
{

}
//定时开关
void Widget::on_comboBox_5_activated(const QString &arg1)
{

}
//定时发送的帧长度
void Widget::on_spinBox1_5_textChanged(const QString &arg1)
{

}
//硬件定时发送周期
void Widget::on_spinBox1_6_valueChanged(int arg1)
{

}

//清除窗口数据
void Widget::on_pushButton_4_clicked()
{

}
//板卡的自动连接
                // 模拟自动连接的操作，通常在这里调用串口相关的函数进行连接
                int Widget::autoConnect(int &cardnum)
                {
                    cardnum = 123;  // 模拟的卡号
                    HW_VER = 0x1234; // 模拟的硬件版本
                    SF_VER = 0x5678; // 模拟的软件版本
                    return 0;  // 返回 0 表示成功
                }

void Widget::on_auto_link_clicked()
{
    int cardnum = 0;
    int result = autoConnect(cardnum);  // 调用autoConnect 函数

    if (result == 0) {  // 连接成功
        // 连接成功后的操作
        // 例如，更新UI显示连接状态和版本号
        QMessageBox::information(this, "连接成功", "已成功连接到设备！");

        // 更新版本号（可以通过信号槽或直接在这里更新）
        QString devVersion = QString("硬件版本号：%1-V%2.%3").arg((HW_VER >> 12) & 0xF)
                                                                .arg((HW_VER >> 8) & 0xF)
                                                                .arg(HW_VER & 0xFF, 2, 16, QChar('0'));
        QString softVersion = QString("软件版本号：%1-V%2.%3").arg((SF_VER >> 12) & 0xF)
                                                                 .arg((SF_VER >> 8) & 0xF)
                                                                 .arg(SF_VER & 0xFF, 2, 16, QChar('0'));
        // 显示版本信息
        QMessageBox::information(this, "硬件版本号", devVersion);
        QMessageBox::information(this, "软件版本号", softVersion);

        // 更新 UI：连接状态指示灯为成功
        QPalette palette = ui->light->palette();
        palette.setColor(QPalette::Base, QColor("#aaff7f"));  // 设置粉色表示成功
        ui->light->setPalette(palette);

        // 禁用自动连接按钮和总线按钮
        ui->auto_link->setEnabled(false);
//        ui->bus_button->setEnabled(false);
    }
    else {  // 连接失败
        // 显示连接失败的消息框
        QMessageBox::critical(this, "连接失败", "无法连接到设备，请检查连接并重试。");

        // 启用按钮和控件
        ui->auto_link->setEnabled(true);
//        ui->bus_button->setEnabled(true);

        // 更新light控件的背景颜色为失败状态
        QPalette palette = ui->light->palette();
        palette.setColor(QPalette::Window, QColor("#ffffff"));  // 设置为白色表示失败
        ui->light->setPalette(palette);
    }
}


////板卡的指定连接
//void Widget::on_man_link_clicked()
//{
//    int findNum = 0;  // 查找到的设备数量

//        // 调用外部库函数来查找设备
//        ViStatus hr = WDSerial_DeviceFind_PCI(10, pPCI_SOURCE, (ViUInt16*)&findNum);

//        // 如果查找设备失败
//        if (hr != 0) {
//            // 弹出错误提示框
//            QMessageBox::critical(this, "Error", "Failed to find PCI devices.");
//            return;
//        }

//        // 检查查找到的设备数量是否大于 10，避免数组越界
//        if (findNum > 10) {
//            findNum = 10;  // 将设备数量限制为 10
//        }







////    ViUInt16 FindNum=0;
////    ViUInt32 cardnum;
////    ViStatus hr ;

////    hr= WDSerial_DeviceFind_PCI(10, pPCI_SOURCE, &FindNum);  // 查找 PCI 设备

////    if (hr != 0) {
////        // 查找设备失败，弹出错误提示
////        QMessageBox::critical(this, "Error", "Failed to find PCI devices.");
////        return;
////    }

////         // 检查 findNum 的值是否大于 10，避免数组越界
////           if (FindNum > 10) {
////               FindNum = 10;   // 将设备数量限制为 10
////           }

////        // 清空设备列表
////        ui->deviceListWidget->clear();

////        // 遍历并显示找到的设备
////        for (int i = 0; i < FindNum; ++i) {

////            // 打印每个设备的详细信息
////                    qDebug() << "pPCI_SOURCE[" << i << "] = BusNumber: "
////                             << pPCI_SOURCE[i].BusNumber
////                             << ", SlotNumber: " << pPCI_SOURCE[i].SlotNumber
////                             << ", VendorId: " << pPCI_SOURCE[i].VendorId
////                             << ", DeviceId: " << pPCI_SOURCE[i].DeviceId;


////            QString msg = QString("PCI板卡-Bus Number: %1, Slot Number: %2, VendorId: %3, DeviceId: %4")
////                              .arg(pPCI_SOURCE[i].BusNumber)
////                              .arg(pPCI_SOURCE[i].SlotNumber)
////                              .arg(pPCI_SOURCE[i].VendorId, 0, 16)  // 十六进制显示 VendorId
////                              .arg(pPCI_SOURCE[i].DeviceId, 0, 16);  // 十六进制显示 DeviceId

////            // 将设备信息添加到 QListWidget 控件
////            ui->deviceListWidget->addItem(msg);
////        }

////        // 连接设备，假设连接第一个设备

////        hr = WDSerial_Init(pPCI_SOURCE[0].BusNumber, pPCI_SOURCE[0].SlotNumber, &cardnum);

////        if (hr == 0) {
////            // 连接成功
////            QMessageBox::information(this, "Success", "Device connected successfully.");
////        } else {
////            // 连接失败
////            QMessageBox::critical(this, "Error", "Failed to connect to the device.");
////        }
//}
//void Widget::updateDeviceList(int findNum)
//{
//    // 清空设备列表
//    ui->deviceListWidget->clear();

//    // 遍历并显示每个找到的设备
//    for (int i = 0; i < findNum; ++i) {
//        // 打印每个设备的详细信息
//        qDebug() << "pPCI_SOURCE[" << i << "] = BusNumber: "
//                 << pPCI_SOURCE[i].BusNumber
//                 << ", SlotNumber: " << pPCI_SOURCE[i].SlotNumber
//                 << ", VendorId: " << pPCI_SOURCE[i].VendorId
//                 << ", DeviceId: " << pPCI_SOURCE[i].DeviceId;

//        // 构建字符串消息显示设备信息
//        QString msg = QString("PCI板卡-Bus Number: %1, Slot Number: %2, VendorId: %3, DeviceId: %4")
//                          .arg(pPCI_SOURCE[i].BusNumber)
//                          .arg(pPCI_SOURCE[i].SlotNumber)
//                          .arg(pPCI_SOURCE[i].VendorId, 0, 16)  // 十六进制显示 VendorId
//                          .arg(pPCI_SOURCE[i].DeviceId, 0, 16);  // 十六进制显示 DeviceId

//        // 将设备信息添加到 QListWidget 控件
//        ui->deviceListWidget->addItem(msg);
//    }
//}
