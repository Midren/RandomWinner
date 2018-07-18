#ifndef READING_WINNERS_CPP
#define READING_WINNERS_CPP

#include <QString>
#include <QUrl>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

#include <iostream>

std::vector<QUrl> read_winners_url() {
    QFile file(":/data/url.txt");
    std::vector<QUrl> ret;

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cout << "Houston we have troubles" << std::endl;
    }

    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine();
        ret.push_back(QUrl(line));
    }
    return ret;
}

std::vector<QString> read_winners_str() {
    QFile file(":/data/str.txt");
    std::vector<QString> ret;

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cout << "Houston we have troubles" << std::endl;
    }

    QTextStream in(&file);
    while(!in.atEnd()) {
//        std::cout << 3 << std::endl;
        QString line = in.readLine();
        ret.push_back(line);
    }
    return ret;
}

#endif
