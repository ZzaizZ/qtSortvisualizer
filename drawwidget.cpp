#include "drawwidget.h"
#include "sorts.cpp"
#include "mainwidget.h"

#define UPDATE_INTERVAL_MS 5

DrawWidget::DrawWidget(QWidget *parent) :
    QWidget(parent)
{
    for (int i = 0; i < NUMBERS_COUNT; i++)
        ints[i] = 10+i*5;
    current_number = 0;
    shuffle();
    sorted = false;
    sort_in_process = false;
    I = 0; J = 0;
    current_mode = 0;
    connect(&tim, SIGNAL(timeout()), this, SLOT(draw()));
    connect(parent, SIGNAL(startSort(int)), this, SLOT(init(int)));
    tim.start(UPDATE_INTERVAL_MS);

}

void DrawWidget::init(int _mode)
{
    current_mode = _mode;
    tim.start(UPDATE_INTERVAL_MS);
}

void DrawWidget::shuffle()
{
    shuffle_array(ints, NUMBERS_COUNT);
    sorted = false;
    current_number = 0;
    current_mode = 0;
    tim.start(UPDATE_INTERVAL_MS);
}

void DrawWidget::draw()
{
    switch (current_mode)
    {
    case 1:
    {
        current_number = NUMBERS_COUNT;
        if (!sorted && !sort_in_process)
        {
            sort_in_process = true;
            I = 0; J = 0;
            time_elapsed.restart();
        }
    drawBubbleSort();
    break;
    }
    case 2:
    {
        current_number = NUMBERS_COUNT;
        if (!sorted && !sort_in_process)
        {
            sort_in_process = true;
            I = 0; J = I;
            time_elapsed.restart();
        }
        drawBubbleSort();
        break;
    }
    default:
    {
        drawAll();
        break;
    }
    }
}

void DrawWidget::drawAll()
{
    update();
    current_number++;
    if (current_number >= NUMBERS_COUNT)
        tim.stop();
}

void DrawWidget::drawBubbleSort()
{
    if (ints[J] > ints[J+1])
    {
        swaP(ints[J], ints[J+1]);
        update();
    }
    J++;
    if (J >= NUMBERS_COUNT -1 - I)
    {
        I++;
        J = 0;
    }
    if (I >= NUMBERS_COUNT)
    {
        tim.stop();
        emit sortIsDone(time_elapsed.elapsed());
        sorted = true;
        sort_in_process = false;
    }
}

void DrawWidget::drawInsertionSort()
{
    swaP(ints[J-1], ints[J]);
    current_number = NUMBERS_COUNT;
    update();
    if (J > 0 && ints[J-1] > ints[J])
    {
        I++;
        J = I;
    }

    J--;
    if (I >= NUMBERS_COUNT)
    {
        tim.stop();
        emit sortIsDone(time_elapsed.elapsed());
        sorted = true;
        sort_in_process = false;
    }
}

void DrawWidget::paintEvent(QPaintEvent *e)
{
    QWidget::paintEvent(e);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::black);
    painter.setBrush(QColor::fromRgb(200, 200, 200));
    QRect bg(0, 0, width(), height());
    painter.fillRect(bg, painter.brush());
    painter.drawRect(bg);
    painter.setBrush(Qt::white);
    for (int i = 0; i < current_number; i++)
    {
        QRect rect(10*i, height(), 8, -ints[i]);
        painter.fillRect(rect, painter.brush());
        painter.drawRect(rect);
    }
}
