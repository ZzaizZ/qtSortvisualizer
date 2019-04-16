#include "mainwidget.h"
#include "sorts.cpp"
#include <QApplication>
#include <QtCore>
#include <QtGui>

int main(int argc, char **argv)
{
    int a[7] = {3, 4, 10, 2, 15, 13, 4};
    uint64_t len = sizeof(a)/sizeof (a[0]);

    int *sorted = new int[len];
    copy(sorted, a, len);
    printf("Source array:\n");
    for (uint64_t i = 0; i < len; i++)
        printf("%i ", sorted[i]);
    printf("\n");

    bubble_sort(sorted, len);
    printf("Bubble sort:\n");
    for (uint64_t i = 0; i < len; i++)
        printf("%i ", sorted[i]);
    printf("\n");

    copy(sorted, a, len);
    insertion_sort(sorted, len);
    printf("Insert sort:\n");
    for (uint64_t i = 0; i < len; i++)
        printf("%i ", sorted[i]);
    printf("\n");

    copy(sorted, a, len);
    selection_sort(sorted, len);
    printf("Select sort:\n");
    for (uint64_t i = 0; i < len; i++)
        printf("%i ", sorted[i]);
    printf("\n");

    delete[] sorted;

    QApplication app(argc, argv);
    MainWidget mw;
    mw.show();

    return app.exec();
}
