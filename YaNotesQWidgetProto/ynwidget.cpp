// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/YaNotes/blob/master/LICENSE

#include "ynwidget.h"
#include "../share/share.h"
YNWidget::YNWidget(QWidget *parent) : QWidget(parent)
{
    YN_TIMESTAMP();
    setWindowTitle(tr("YaNotes"));
}

YNWidget::~YNWidget()
{
    YN_TIMESTAMP();
}
