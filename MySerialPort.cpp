#include "MySerialPort.h"

#include <QDebug>
#include <QMessageBox>

MySerialPort::MySerialPort(/* args */)
{
    this->serialPort = new QSerialPort;
}

MySerialPort::~MySerialPort()
{
    free(serialPort);
}

void MySerialPort::findSerialPort(QComboBox* comboBox){
    comboBox->clear();
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        comboBox->addItem(info.portName());
        qDebug("端口号：%s",info.portName());
    }
}

void MySerialPort::openSerialPort(QString portName,QSerialPort::BaudRate bandRate,QSerialPort::DataBits dataBit,QSerialPort::Parity parity,QSerialPort::StopBits stopBit){
    if (this->serialPort->isOpen())
    {
        this->serialPort->clear();
        this->serialPort->close();
        return;
    }

    this->serialPort->setPortName(portName);

    //用ReadWrite 的模式尝试打开串口
    if (!this->serialPort->open(QIODevice::ReadWrite))
    {
        qDebug()<<portName<<"打开失败!";
	    return;
    }
    else
    {
        this->serialPort->setBaudRate(bandRate,QSerialPort::AllDirections);//设置波特率和读写方向
        this->serialPort->setDataBits(dataBit);		//数据位为8位
        this->serialPort->setFlowControl(QSerialPort::NoFlowControl);//无流控制
        this->serialPort->setParity(parity);	//无校验位
        this->serialPort->setStopBits(stopBit); //一位停止位
    }
}

void MySerialPort::serialPort_Receive(QPlainTextEdit* plainTextEdit,bool isTime,bool isHex,bool isLineFeed){    
    this->buf_Receivce = this->serialPort->readAll();
    
    this->num_Receivce += this->buf_Receivce.size();

    //更具要求处理收到的数据
    if (!isHex){
        if (isTime){
            QDateTime nowtime = QDateTime::currentDateTime();
            this->str_Receivce = "receive>[" + nowtime.toString("yyyy-MM-dd hh:mm:ss") + "] —>";
            this->str_Receivce += QString(this->buf_Receivce).append("\r\n");
        }
        else{
            if (isLineFeed)
            {
                this->str_Receivce = "receive> ";
                this->str_Receivce += QString(this->buf_Receivce).append("\r\n");
            }
            else
            {
                this->str_Receivce = "receive> ";
                this->str_Receivce += QString(this->buf_Receivce);
            }
        }
    }
    else
    {
        // 16进制显示，并转换为大写
        QString str1 = this->buf_Receivce.toHex().toUpper();//.data();
        // 添加空格
        QString str2;
        for(int i = 0; i<str1.length (); i+=2)
        {
            str2 += str1.mid (i,2);
            str2 += " ";
        }
        if (isTime)
        {
            QDateTime nowtime = QDateTime::currentDateTime();
            this->str_Receivce = "receive>[" + nowtime.toString("yyyy-MM-dd hh:mm:ss") + "] <>";
            this->str_Receivce += str2;
            this->str_Receivce.append("\r\n");
        }
        else
        {
            if (isLineFeed)
            {
                this->str_Receivce = "receive> ";
                this->str_Receivce += str2;
                this->str_Receivce.append("\r\n");
            }
            else
            {
                this->str_Receivce = "receive> ";
                this->str_Receivce += str2;
            }
        }
        
    }

    plainTextEdit->moveCursor(QTextCursor::End);
    plainTextEdit->insertPlainText(str_Receivce);
    
}

void MySerialPort::serialPort_Send(QString str,bool isHex)
{
    QByteArray temp = str.toUtf8();
    if (isHex)
    {
        this->serialPort->write(temp.toHex());
    }
    else
    {
        this->serialPort->write(temp);
    }
}

QSerialPort* MySerialPort::getSerialPort(){
    return this->serialPort;
}

QSerialPort::BaudRate MySerialPort::getBaudRate(unsigned int baudRate){
    switch (baudRate)
    {
    case 4800:
        return QSerialPort::Baud4800;
        break;
    case 9600:
        return QSerialPort::Baud9600;
        break;
    case 19200:
        return QSerialPort::Baud19200;
        break;
    case 38400:
        return QSerialPort::Baud38400;
        break;
    case 57600:
        return QSerialPort::Baud57600;
        break;
    case 115200:
        return QSerialPort::Baud115200;
        break;
    case 1200:
        return QSerialPort::Baud1200;
        break;
    case 2400:
        return QSerialPort::Baud2400;
        break;
    
    default:
        return QSerialPort::UnknownBaud;
        break;
    }
}

QSerialPort::DataBits MySerialPort::getDataBit(unsigned int dataBit){
    switch (dataBit)
    {
    case 5:
        return QSerialPort::Data5;
        break;
    case 6:
        return QSerialPort::Data6;
        break;
    case 7:
        return QSerialPort::Data7;
        break;
    case 8:
        return QSerialPort::Data8;
        break;
    
    default:
        return QSerialPort::UnknownDataBits;
        break;
    }
}

QSerialPort::Parity MySerialPort::getParity(unsigned int parity){
    switch (parity)
    {
    case 0:
        return QSerialPort::NoParity;
        break;
    case 2:
        return QSerialPort::EvenParity;
        break;
    case 3:
        return QSerialPort::OddParity;
        break;
    case 4:
        return QSerialPort::SpaceParity;
        break;
    case 5:
        return QSerialPort::MarkParity;
        break;

    default:
        return QSerialPort::UnknownParity;
        break;
    }
}

QSerialPort::StopBits MySerialPort::getStopBit(unsigned int stopBit){
    switch (stopBit)
    {
    case 1:
        return QSerialPort::OneStop;
        break;
    case 2:
        return QSerialPort::TwoStop;
        break;
    case 3:
        return QSerialPort::OneAndHalfStop;
        break;
    
    default:
        return QSerialPort::UnknownStopBits;
        break;
    }
}

