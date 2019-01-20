#include "widget.h"
#include "ui_widget.h"
#include <QMediaPlayer>
#include <QSound>
#include<bits/stdc++.h>
#include <windows.h>
#include <QtWidgets>
#include <QtNetwork>
#include <mmsystem.h>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Internet Notifier");
    //this->setStyleSheet("color: #022052; background-color: #ccffff; selection-background-color: white;");



}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_startButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Internet UP : Continiously beeping sound\n\nInternet DOWN : No sound");
    msgBox.exec();

    ui->appStatus->setText("Status : Running");
    for(;;){
        if(flag == true){
            flag = false;
            ui->message->setText("Internet: Unknown");
            break;
        }
        QNetworkAccessManager nam;
        QNetworkRequest req(QUrl("http://www.google.com"));
        QNetworkReply *reply = nam.get(req);
        QEventLoop loop;


        connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();

        if(reply->bytesAvailable()){
                PlaySound(TEXT("beep.wav"), NULL, SND_SYNC);
                ui->message->setText("Internet : UP");

        }
        else{
            ui->message->setText("Internet : DOWN");
        }

    }




}

void Widget::on_closeButton_clicked()
{
    ui->appStatus->setText("Status : Stopped");
    flag = true;
}
