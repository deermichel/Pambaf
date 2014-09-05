#include "PambafTool.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PambafTool w;
    w.show();

    return a.exec();
}
