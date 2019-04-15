#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QTime>

#define NUMBERS_COUNT 39

class DrawWidget : public QWidget
{

    Q_OBJECT

public:
    DrawWidget(QWidget *parent = nullptr);
    ~DrawWidget() {}

protected:
    void paintEvent(QPaintEvent *e);
    QTimer tim;
    int ints[NUMBERS_COUNT];
    int32_t current_number;
    bool sorted;
    bool sort_in_process;
    int I, J;
    int current_mode;
    QTime time_elapsed;


    void drawAll();
    void drawBubbleSort();
    void drawInsertionSort();
protected slots:
    void init(int _mode);
public slots:
    void draw();
    void shuffle();

signals:
    void sortIsDone(int ms_time);

};

#endif // DRAWWIDGET_H
