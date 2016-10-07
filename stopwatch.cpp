#include "stopwatch.h"
#include "ui_stopwatch.h"
#include<QTimer>
#include<QObject>


StopWatch::StopWatch(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StopWatch)
{
    ui->setupUi(this);


    connect(&myQTimer, SIGNAL(timeout()),this, SLOT(start_button_click1st()));

    //make connections

}

StopWatch::~StopWatch()
{
    delete ui;
}

void StopWatch::start_button_click1st()
{
    millisecond++;

    if (millisecond==100)
    {
        second++;
        millisecond = 0;
    }
    if (second == 60)
    {
        minute++;
        second = 0;
    }

    if(millisecond<10){
        ui->millisecondLabel->setText("0"+QString::number(millisecond));
    }else {
        ui->millisecondLabel->setText(QString::number(millisecond));
    }

    if(second<10){
        ui->secondLabel->setText("0"+QString::number(second));
    }else {
        ui->secondLabel->setText(QString::number(second));
    }

    if(minute<10){
        ui->minuteLabel->setText("0"+QString::number(minute));
    }else {
        ui->minuteLabel->setText(QString::number(minute));
    }
}

void StopWatch::on_startButton_clicked()
{

    startClick++;

    if (startClick==1)
    {

        myQTimer.start(10);

        if (myQTimer.isActive()) {
            myQTimer.setSingleShot(FALSE);
            myQTimer.start(10);
        }

        ui->startButton->setText("PAUSE");
    }
    else if (startClick==2)
    {
        myQTimer.stop();
        startClick = 0;
        ui->startButton->setText("START");
    }
}

void StopWatch::on_resetButton_clicked()
{
    ui->millisecondLabel->setText("00");
    ui->minuteLabel->setText("00");
    ui->secondLabel->setText("00");
    millisecond = 0;
    second = 0;
    minute = 0;
    startClick = 0;
}
