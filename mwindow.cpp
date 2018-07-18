#include "mwindow.h"

#include <QPalette>
#include <QPixmap>
MWindow::MWindow(QWidget *parent) : QMainWindow(parent)
{
    MainWindow *window = new MainWindow();
    setCentralWidget(window);
}

void MWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    QPixmap bkgnd(":icons/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}
