#include "mainwindow.h"
#include <QPalette>


#include "reading_winners.cpp"
#include <iostream>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout;

    new QShortcut(Qt::CTRL + Qt::Key_D, this, SLOT(hoorayDen()));
    new QShortcut(Qt::Key_Space, this, SLOT(changeMan()));
    winner_image = new QLabel("winner image");
    possible_winners_str = read_winners_str();
    possible_winners_url = read_winners_url();

    mt = std::mt19937(rd());
    std::uniform_int_distribution<int> dist(0, possible_winners_str.size() - 1);
    int ind = dist(mt);

    winner_name = new QLabel("");
    QLabel *the_winner = new QLabel(tr("The Winner"));
    the_winner->setAlignment(Qt::AlignCenter);
    winner_name->setAlignment(Qt::AlignCenter);
    winner_name->setStyleSheet("QLabel {color: rgb(60, 22, 17);}");
    the_winner->setStyleSheet("QLabel {color: rgb(60, 22, 17);}");

//    QFont font = winner_name->font();
    std::cout << possible_winners_str[ind].toStdString() << std::endl;
    int id = QFontDatabase::addApplicationFont(":/fonts/gaby.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont font(family);
    font.setPointSize(48);
    font.setBold(true);
    font.setFamily(family);
    winner_name->setFont(font);
    font.setPointSize(64);
    the_winner->setFont(font);

    winner_image->setAlignment(Qt::AlignCenter);
    QPixmap is(QString(":/icons/is.png"));
    winner_image->setPixmap(is.scaled(288, 288));
    random_button = new QPushButton(tr("&Find winner!"));

    QVBoxLayout *cup_winner_layout = new QVBoxLayout;
    QPixmap cup = QPixmap();
    cup.load(":/icons/cup.png");
    cup_winner_layout->addWidget(the_winner);
    cup_winner_layout->addWidget(winner_image);

    cup_winner_layout->addWidget(winner_name);
//    cup_winner_layout->addWidget(random_button);

//    QUrl imageUrl(possible_winners_url[ind]);
//    m_pImgCtrl = new FileDownloader(imageUrl, this);
//    connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));
    connect(random_button, SIGNAL(clicked()), this, SLOT(changeMan()));
    layout->addItem(cup_winner_layout, 0, 0);
    setLayout(layout);
}

void MainWindow::loadImage()
{
 QPixmap buttonImage;
 buttonImage.loadFromData(m_pImgCtrl->downloadedData());
 winner_image->setPixmap(buttonImage.scaled(717, 734));
}

void MainWindow::changeMan() {
    std::uniform_int_distribution<int> dist(0, possible_winners_str.size() - 1);
    int ind = dist(mt);
    winner_name->setText(possible_winners_str[ind]);
    QUrl imageUrl(possible_winners_url[ind]);
    m_pImgCtrl = new FileDownloader(imageUrl, this);
    connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));
}

void MainWindow::hoorayDen() {
    winner_name->setText("Daniel Schauer");
    winner_image->setPixmap(QPixmap(":/icons/den.png"));
}
