#include "include/tvremote.h"
#include "src/ui_tvremote.h"

tvRemote::tvRemote(QWidget *parent) : QMainWindow(parent), ui(new Ui::tvRemote){

    ui->setupUi(this);

    connect(ui->Btn_0,SIGNAL(clicked()),this,SLOT(onDigitBtnClicked()));
    connect(ui->Btn_1,SIGNAL(clicked()),this,SLOT(onDigitBtnClicked()));
    connect(ui->Btn_2,SIGNAL(clicked()),this,SLOT(onDigitBtnClicked()));
    connect(ui->Btn_3,SIGNAL(clicked()),this,SLOT(onDigitBtnClicked()));
    connect(ui->Btn_4,SIGNAL(clicked()),this,SLOT(onDigitBtnClicked()));
    connect(ui->Btn_5,SIGNAL(clicked()),this,SLOT(onDigitBtnClicked()));
    connect(ui->Btn_6,SIGNAL(clicked()),this,SLOT(onDigitBtnClicked()));
    connect(ui->Btn_7,SIGNAL(clicked()),this,SLOT(onDigitBtnClicked()));
    connect(ui->Btn_8,SIGNAL(clicked()),this,SLOT(onDigitBtnClicked()));
    connect(ui->Btn_9,SIGNAL(clicked()),this,SLOT(onDigitBtnClicked()));

    connect(ui->Btn_ch_Up,SIGNAL(clicked()),this,SLOT(onChannelUpBtnClicked()));
    connect(ui->Btn_ch_Down,SIGNAL(clicked()),this,SLOT(onChannelDownBtnClicked()));
    connect(ui->Btn_vol_Up,SIGNAL(clicked()),this,SLOT(onVolumeUpBtnClicked()));
    connect(ui->Btn_vol_Down,SIGNAL(clicked()),this,SLOT(onVolumeDownBtnClicked()));

}

tvRemote::~tvRemote(){

    delete ui;
}

void tvRemote::onDigitBtnClicked(){
    QString str = ((QPushButton*)sender())->text();

    if (str.contains(QRegExp("[0-9]"))) {
        buffer_str = str;

        if(buffer_str.length() > 3 ){
            buffer_str.clear();
        }
    }
    qDebug() << buffer_str.toInt();
    channel = buffer_str.toInt();
    ui->Channel_display->setText(buffer_str);
}


void tvRemote::onVolumeUpBtnClicked(){
    if(volume < 10){
        volume++;

    }else{
        volume = 10;
    }

    qDebug()<< "Volume = " << volume;
    volume_str = QString::number(volume);
    ui->Volume_display->setText(volume_str);
}


void tvRemote::onVolumeDownBtnClicked(){
    if(volume > 0){
        volume--;

    }else{
        volume = 0;
    }

    qDebug()<< "Volume = " << volume;
    volume_str = QString::number(volume);
    ui->Volume_display->setText(volume_str);
}


void tvRemote::onChannelUpBtnClicked()
{
    if(channel < 9){
        channel++;

    }else{
        channel = 0;
    }

    qDebug() << "Channel = " << channel;
    channel_str = QString::number(channel);
    ui->Channel_display->setText(channel_str);
}


void tvRemote::onChannelDownBtnClicked()
{
    if(channel > 0){
        channel--;

    }else{
        channel = 9;
    }

    qDebug() << "Channel = " << channel;
    channel_str = QString::number(channel);
    ui->Channel_display->setText(channel_str);
}
