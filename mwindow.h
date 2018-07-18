#ifndef MWINDOW_H
#define MWINDOW_H
#include"mainwindow.h"

#include <QMainWindow>

class MWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MWindow(QWidget *parent = nullptr);

signals:

public slots:
    void resizeEvent(QResizeEvent* event);
};

#endif // MWINDOW_H
