// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/YaNotes/blob/master/LICENSE

#include "ynwidget.h"
#include "../share/share.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextBrowser>
#include <QToolBar>
#include <QToolButton>
#include <QComboBox>
#include <QStatusBar>

YNWidget::YNWidget(QWidget *parent) : QWidget(parent)
{
    YN_TIMESTAMP();
    setWindowTitle(tr("YaNotes"));
    setVertUIProto();
}

YNWidget::~YNWidget()
{
    YN_TIMESTAMP();
}

void
YNWidget::setVertUIProto()
{
    setFixedSize(480,800);

    _lbOne = new QLabel("label #1");
    _lbTwo = new QLabel("label #2");
    _textBrowser = new QTextBrowser();

    _tbOne = new QToolButton();
    _tbTwo = new QToolButton();
    _tbTwo->setCheckable(true);
    _cbOne = new QComboBox();
    _cbOne->addItem("cb #1");
    _cbOne->addItem("cb #2");
    _cbOne->addItem("cb #3");

    _tbarTop = new QToolBar;
    _tbarTop->addAction("A1");
    _tbarTop->addAction("A2");
    _tbarTop->addSeparator();
    _tbarTop->addWidget(_tbOne);
    _tbarTop->addWidget(_tbTwo);
    _tbarTop->addSeparator();
    _tbarTop->addWidget(_cbOne);
    _tbarTop->addSeparator();
    _tbarTop->addWidget(_lbOne);

    _sbOne = new QStatusBar();
    _sbOne->addPermanentWidget(_lbTwo);
    _ltVertical = new QVBoxLayout;

    _ltVertical->addWidget(_tbarTop);
    _ltVertical->addWidget(_textBrowser);
    _ltVertical->addWidget(_sbOne);
    setLayout(_ltVertical);
}
