#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>//垂直布局
#include <QHBoxLayout>//水平布局
#include <QGridLayout>//栅栏布局
#include <QSpacerItem>
#include <QSizePolicy>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QCheckBox>

#include "MySerialPort.h"

class MainWindow : public QMainWindow
{
 Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget* mainWidget;

    QHBoxLayout* main_hLayout;
    QVBoxLayout* left_vLayout;
    QVBoxLayout* right_vLayout;
    QGridLayout* left_Layout0;
    QGridLayout* left_Layout1;
    QGridLayout* left_Layout2;
    QGridLayout* right_Layout0;

    //串口设置
    QLabel* port_Label;
    QLabel* baudRate_Label;
    QLabel* dataBit_Label;
    QLabel* stopBit_Label;
    QLabel* checkBit_Label;

    QComboBox* port_ComboBox;
    QComboBox* baudRate_ComboBox;
    QComboBox* dataBit_ComboBox;
    QComboBox* stopBit_ComboBox;
    QComboBox* checkBit_ComboBox;

    QPushButton* detectionPort_Button;
    QPushButton* openPort_Button;

    //接收设置
    QPushButton* clear_Receive;
    QCheckBox* hex_Receive;
    QCheckBox* time_Receive;
    QCheckBox* lineFeed_Receive;

    //发送设置
    QCheckBox* hex_Send;

    //信息显示窗口
    QPlainTextEdit* show_Infoemation;

    //输入
    QPlainTextEdit* in_Infoemation;
    QPushButton* send_Button;
    QPushButton* clear_Button;

    //串口
    MySerialPort* serialPort;

private:
    void initInterface();
};
#endif // MAINWINDOW_H
