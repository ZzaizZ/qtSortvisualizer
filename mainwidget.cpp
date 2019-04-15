#include "mainwidget.h"
#include "ui_mainwidget.h"

#include <QPainter>
#include <QPaintEvent>


#include <algorithm>

#include "sorts.cpp"


MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    connect(ui->btn_shuffle, SIGNAL(clicked()), ui->wg_screen, SLOT(shuffle()));
    connect(ui->wg_screen, SIGNAL(sortIsDone(int)), this, SLOT(showSortTime(int)));
    ui->lbl_el_time->setText(QString::number(0));
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::showSortTime(int time_elapsed)
{
    ui->lbl_el_time->setText(QString::number(time_elapsed));
}

void MainWidget::on_btn_sort_clicked()
{
    emit startSort(ui->cbx_sorts->currentIndex()+1);
}
