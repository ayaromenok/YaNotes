// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/YaNotes/blob/master/LICENSE

#include "ynwidget.h"
#include "../share/share.h"
#include "../share/mdobject.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextBrowser>
#include <QToolBar>
#include <QToolButton>
#include <QComboBox>
#include <QStatusBar>

#include <QScrollBar>
#include <QScrollArea>
#include <QAbstractScrollArea>
#include <QAbstractSlider>
#include <QList>

#include "../3rdparty/qmarkdowntextedit/qmarkdowntextedit.h"

YNWidget::YNWidget(QWidget *parent) : QWidget(parent)
{
    YN_TIMESTAMP();
    _md = new MDObject(this);
    _mdTextEdit = new QMarkdownTextEdit();
    //! \todo create geometry scale engine
    // _mdTextEdit->setFixedHeight(200); // - don't scale correctly on Android
    _textBrowser = new QTextBrowser();

    connect (_mdTextEdit, SIGNAL(textChanged()),
             this, SLOT(updateMD()));

    setTestMDText();
    setWindowTitle(tr("YaNotes"));
    setVertUIProto();
    setAndroidScrollBarDirtyFix();
}

YNWidget::~YNWidget()
{
    YN_TIMESTAMP();
    delete _md;
}

void
YNWidget::updateMD()
{
    YN_TIMESTAMP();
    QString md = _mdTextEdit->toPlainText();
    _textBrowser->setHtml(_md->toHtml(md));
}

void
YNWidget::setVertUIProto()
{
    YN_TIMESTAMP();
    setFixedSize(480,800);

    _lbOne = new QLabel("label #1");
    _lbTwo = new QLabel("label #2");

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
    _ltVertical->addWidget(_mdTextEdit);
    _ltVertical->addWidget(_sbOne);
    setLayout(_ltVertical);
}

void
YNWidget::setTestMDText()
{
    YN_TIMESTAMP();
    QString strTestToC("### Hello\n - from YaNotes\n - from Me\n\n");

    strTestToC.append("#### TOC\n\n");
    strTestToC.append(" 1. [Heading 1](#heading1)\n\n");
    strTestToC.append(" 2. [Heading 2](#heading2)\n\n");
    strTestToC.append(" 3. [Heading 3](#heading3)\n\n");
    strTestToC.append("### Heading 1<a name = \"heading1\"></a>\n ");
    strTestToC.append("\n\n1\n\n2\n\n3\n\n4\n\n5\n\n");
    strTestToC.append("### Heading 2<a name = \"heading2\"></a>\n ");
    strTestToC.append("\n\n1\n\n2\n\n3\n\n4\n\n5\n\n");
    strTestToC.append("### Heading 3<a name = \"heading3\"></a>\n ");
    _mdTextEdit->appendPlainText(strTestToC);
}

void
YNWidget::setAndroidScrollBarDirtyFix()
{
    YN_TIMESTAMP();
    QScrollBar* _sbOne;
    QScrollBar* _sbTwo;
    _sbOne = _textBrowser->verticalScrollBar();
    _sbOne->setMaximumWidth(30);
    _sbTwo = _mdTextEdit->verticalScrollBar();
    _sbTwo->setMaximumWidth(30);
    _textBrowser->setLayoutDirection(Qt::RightToLeft);
    _mdTextEdit->setLayoutDirection(Qt::RightToLeft);
}
