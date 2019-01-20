#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startButton_clicked();


    void on_closeButton_clicked();

private:
    Ui::Widget *ui;
    bool flag = false;

};

#endif // WIDGET_H
