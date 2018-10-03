// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/YaNotes/blob/master/LICENSE

#ifndef YNWIDGET_H
#define YNWIDGET_H

#include <QWidget>
class QVBoxLayout;
class QHBoxLayout;
class QLabel;
class QTextBrowser;
class QToolBar;
class QToolButton;
class QComboBox;
class QStatusBar;

class YNWidget : public QWidget
{
    Q_OBJECT
public:
    explicit YNWidget(QWidget *parent = nullptr);
    ~YNWidget();
signals:

public slots:

private:
    void            setVertUIProto();
    QVBoxLayout*    _ltVertical;
    QLabel*         _lbOne;
    QLabel*         _lbTwo;
    QTextBrowser*   _textBrowser;
    QToolBar*       _tbarTop;
    QToolButton*    _tbOne;
    QToolButton*    _tbTwo;
    QComboBox*      _cbOne;
    QStatusBar*     _sbOne;
};

#endif // YNWIDGET_H
