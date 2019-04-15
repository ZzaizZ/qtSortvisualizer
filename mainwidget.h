#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "drawwidget.h"

#include <QTimer>

#define NUMBERS_COUNT 39

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
private slots:
    void on_btn_sort_clicked();
    void showSortTime(int elapsed_time);

private:
    Ui::MainWidget *ui;

signals:
    void startSort(int _mode);
};

#endif // MAINWIDGET_H
