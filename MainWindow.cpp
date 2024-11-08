#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
{
    this->mainWidget = new QWidget(this);
    this->setWindowTitle("串口工具");
    this->resize(900,600); 
    this->setCentralWidget(this->mainWidget);
    this->serialPort = new MySerialPort();

    //初始化控件
    this->initInterface();

    connect(this->detectionPort_Button,&QPushButton::clicked,[this](){
        this->serialPort->findSerialPort(this->port_ComboBox);
    });

    connect(this->clear_Receive,&QPushButton::clicked,[this](){
        this->show_Infoemation->clear();
    });

    connect(this->openPort_Button,&QPushButton::clicked,[this](){
                                                            this->serialPort->openSerialPort(this->port_ComboBox->currentText(),
                                                            this->serialPort->getBaudRate((this->baudRate_ComboBox->currentText()).toInt()),
                                                            this->serialPort->getDataBit((this->dataBit_ComboBox->currentText()).toInt()),
                                                            this->serialPort->getParity((this->checkBit_ComboBox->currentText()).toInt()),
                                                            this->serialPort->getStopBit((this->stopBit_ComboBox->currentText()).toInt()));
                                                        });

    connect((this->serialPort->getSerialPort()),&QSerialPort::readyRead,[this](){
                                                                            this->serialPort->serialPort_Receive(this->show_Infoemation,
                                                                                                            this->time_Receive->checkState(),
                                                                                                            this->hex_Receive->checkState(),
                                                                                                            this->lineFeed_Receive->checkState());
                                                                            });


    connect(this->send_Button,&QPushButton::clicked,[this](){
        this->serialPort->serialPort_Send(this->in_Infoemation->toPlainText(),
                                          this->hex_Send->checkState());
        this->show_Infoemation->insertPlainText("send<<- "+this->in_Infoemation->toPlainText());
    });

    connect(this->clear_Button,&QPushButton::clicked,[this](){
        this->in_Infoemation->clear();
    });
    
    this->setLayout(this->main_hLayout);
}

MainWindow::~MainWindow()
{
}

void MainWindow::initInterface(){
    //创建布局
    this->main_hLayout = new QHBoxLayout(this->mainWidget);
    this->left_vLayout = new QVBoxLayout;
    this->right_vLayout = new QVBoxLayout;
    this->left_Layout0 = new QGridLayout;
    this->left_Layout1 = new QGridLayout;
    this->left_Layout2 = new QGridLayout;
    this->right_Layout0 = new QGridLayout;

    //串口设置初始化
    this->port_Label = new QLabel("端口：",this);
    this->baudRate_Label = new QLabel("波特率：",this);
    this->dataBit_Label = new QLabel("数据位：",this);
    this->stopBit_Label = new QLabel("停止位：",this);
    this->checkBit_Label = new QLabel("校验位：",this);

    this->port_ComboBox = new QComboBox(this);
    this->baudRate_ComboBox = new QComboBox(this);
    this->dataBit_ComboBox = new QComboBox(this);
    this->stopBit_ComboBox = new QComboBox(this);
    this->checkBit_ComboBox = new QComboBox(this);

    //波特率
    this->baudRate_ComboBox->addItem("115200","115200");
    this->baudRate_ComboBox->addItem("57600","57600");
    this->baudRate_ComboBox->addItem("38400","38400");
    this->baudRate_ComboBox->addItem("19200","19200");
    this->baudRate_ComboBox->addItem("9600","9600");
    this->baudRate_ComboBox->addItem("4800","4800");
    this->baudRate_ComboBox->addItem("2400","2400");
    this->baudRate_ComboBox->addItem("1200","1200");
    this->baudRate_ComboBox->setCurrentIndex(4);

    //数据位
    this->dataBit_ComboBox->addItem("5","5");
    this->dataBit_ComboBox->addItem("6","6");
    this->dataBit_ComboBox->addItem("7","7");
    this->dataBit_ComboBox->addItem("8","8");
    this->dataBit_ComboBox->setCurrentIndex(3);

    //停止位
    this->stopBit_ComboBox->addItem("1","1");
    this->stopBit_ComboBox->addItem("1.5","1.5");
    this->stopBit_ComboBox->addItem("2","2");
    this->stopBit_ComboBox->setCurrentIndex(0);

    //校验位
    this->checkBit_ComboBox->addItem("无","无");
    this->checkBit_ComboBox->addItem("奇校验","奇校验");
    this->checkBit_ComboBox->addItem("偶校验","偶校验");
    this->checkBit_ComboBox->setCurrentIndex(0);

    this->detectionPort_Button = new QPushButton("检测端口",this);
    this->openPort_Button = new QPushButton("打开端口",this);

    // 将控件添加到网格布局
    this->left_Layout0->setSpacing(2);//设置间距
    this->left_Layout0->addWidget(port_Label,0,0);
    this->left_Layout0->addWidget(baudRate_Label,1,0);
    this->left_Layout0->addWidget(dataBit_Label,2,0);
    this->left_Layout0->addWidget(stopBit_Label,3,0);
    this->left_Layout0->addWidget(checkBit_Label,4,0);
    this->left_Layout0->addWidget(port_ComboBox,0,1);
    this->left_Layout0->addWidget(baudRate_ComboBox,1,1);
    this->left_Layout0->addWidget(dataBit_ComboBox,2,1);
    this->left_Layout0->addWidget(stopBit_ComboBox,3,1);
    this->left_Layout0->addWidget(checkBit_ComboBox,4,1);
    this->left_Layout0->addWidget(detectionPort_Button,5,0,1,2);
    this->left_Layout0->addWidget(openPort_Button,6,0,1,2);

    //接收设置界面初始化
    this->clear_Receive = new QPushButton("清空接收",this);
    this->hex_Receive = new QCheckBox("Hex接收",this);
    this->time_Receive = new QCheckBox("时间戳",this);
    this->lineFeed_Receive = new QCheckBox("自动换行",this);

    // 将控件添加到网格布局
    this->left_Layout1->setSpacing(2);//设置间距
    this->left_Layout1->addWidget(clear_Receive,0,0);
    this->left_Layout1->addWidget(hex_Receive,0,1);
    this->left_Layout1->addWidget(time_Receive,1,0);
    this->left_Layout1->addWidget(lineFeed_Receive,1,1);

    //发送设置控件初始化
    this->hex_Send = new QCheckBox("Hex发送",this);

    this->left_Layout2->addWidget(hex_Send,0,0);

    this->left_vLayout->addLayout(left_Layout0);
    //增加弹簧
    this->left_vLayout->addStretch(1);
    this->left_vLayout->addLayout(left_Layout1);
    //增加弹簧
    this->left_vLayout->addStretch(1);
    this->left_vLayout->addLayout(left_Layout2);
    //增加弹簧
    this->left_vLayout->addStretch(1);

    //信息显示窗口
    this->show_Infoemation = new QPlainTextEdit(this);
    this->show_Infoemation->setReadOnly(true);
    this->show_Infoemation->setEnabled(false);
    this->show_Infoemation->resize(650,450);
    this->right_vLayout->addWidget(show_Infoemation);
    //输入
    this->in_Infoemation = new QPlainTextEdit(this);
    this->in_Infoemation->resize(550,100);
    this->send_Button = new QPushButton("发送",this);
    this->clear_Button = new QPushButton("清除发送",this);
    this->right_Layout0->addWidget(in_Infoemation,0,0,2,1);
    this->right_Layout0->addWidget(send_Button,0,1,1,1);
    this->right_Layout0->addWidget(clear_Button,1,1,1,1);
    this->right_vLayout->addLayout(right_Layout0);

    this->main_hLayout->addLayout(left_vLayout);
    this->main_hLayout->addLayout(right_vLayout);
}