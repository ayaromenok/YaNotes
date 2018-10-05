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
class QMarkdownTextEdit;
class MDObject;

class YNWidget : public QWidget
{
    Q_OBJECT
public:
    explicit YNWidget(QWidget *parent = nullptr);
    ~YNWidget();
signals:

public slots:
private slots:
    void updateMD();

private:
    //MD
    MDObject*                   _md;
    //UI proto
    void                        setVertUIProto();
    void                        setTestMDText();
    void                        setAndroidScrollBarDirtyFix();
    QVBoxLayout*                _ltVertical;
    QLabel*                     _lbOne;
    QLabel*                     _lbTwo;
    QTextBrowser*               _textBrowser;
    QToolBar*                   _tbarTop;
    QToolButton*                _tbOne;
    QToolButton*                _tbTwo;
    QComboBox*                  _cbOne;
    QStatusBar*                 _sbOne;
    QMarkdownTextEdit*          _mdTextEdit;    
};

#endif // YNWIDGET_H
