#include<QApplication>
#include "mwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MWindow window;
    window.showFullScreen();
    return app.exec();
}

