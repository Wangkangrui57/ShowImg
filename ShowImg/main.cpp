#include "showimg.h"
#include "inputpath.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InPutPath w;
    w.show();

    return a.exec();
}
