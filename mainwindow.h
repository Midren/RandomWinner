#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <random>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QUrl>
#include <QFont>

#include "filedownloader.h"

#include <QFontDatabase>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

public slots:
    void loadImage();
    void changeMan();
    void hoorayDen();

private:
    std::random_device rd;
    std::mt19937 mt;
    std::vector<QUrl> possible_winners_url;
    std::vector<QString> possible_winners_str;
    QLabel *winner_image;
    QLabel *cup_image;
    QLabel *winner_name;
    QPushButton *random_button;

    FileDownloader *m_pImgCtrl;
};

#endif // MAINWINDOW_H
