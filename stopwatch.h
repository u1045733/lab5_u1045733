#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QMainWindow>
#include<QTimer>
#include<QObject>


namespace Ui {
class StopWatch;
}

class StopWatch : public QMainWindow
{
    Q_OBJECT

public:
    explicit StopWatch(QWidget *parent = 0);
    int QHundred = 0;
    int millisecond = 0;
    int second = 0;
    int minute = 0;
    int startClick = 0;

    QTimer myQTimer;


    ~StopWatch();

private slots:
    void start_button_click1st();

    void on_startButton_clicked();

    void on_resetButton_clicked();

private:
    Ui::StopWatch *ui;
};

#endif // STOPWATCH_H
