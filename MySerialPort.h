#ifndef MYSERIALPORT_H
#define MYSERIALPORT_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QComboBox>
#include <QPlainTextEdit>
#include <QDateTime>

class MySerialPort
{
public:
    MySerialPort(/* args */);
    ~MySerialPort();

private:
    QSerialPort *serialPort;
    QByteArray buf_Receivce = {""};
    QString str_Receivce = "";
    int num_Receivce = 0;

public:
    void findSerialPort(QComboBox* comboBox);
    QSerialPort* getSerialPort();
    QSerialPort::BaudRate getBaudRate(unsigned int baudRate);
    QSerialPort::DataBits getDataBit(unsigned int dataBit);
    QSerialPort::Parity getParity(unsigned int parity);
    QSerialPort::StopBits getStopBit(unsigned int stopBit);

    void openSerialPort(QString portName,QSerialPort::BaudRate bandRate,QSerialPort::DataBits dataBit,QSerialPort::Parity parity,QSerialPort::StopBits stopBit);
    void serialPort_Receive(QPlainTextEdit* plainTextEdit,bool isTime,bool isHex,bool isLineFeed);
    void serialPort_Send(QString str,bool isHex);
};


#endif //SERIALPORT_H
