// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/YaNotes/blob/master/LICENSE


#include <QApplication>
#include "ynwidget.h"
#include "../share/share.h"

int main(int argc, char *argv[])
{
    YN_TIMESTAMP();

    QApplication a(argc, argv);
    YNWidget yn;
    yn.show();

    return a.exec();
}
