// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/YaNotes/blob/master/LICENSE

#ifndef SHARE_H
#define SHARE_H
#include <QDebug>
#include <QDateTime>

// use more complete __PRETTY_FUNCTION__ for gcc/clang
// for MSVC prior 2015/R14(1900) use __FUNCTION__, for latest C++11's __func__

#ifdef _MSC_VER
#if (_MSC_VER >= 1900)
    #define YN_TIMESTAMP() \
            {qDebug() << QDateTime::currentMSecsSinceEpoch() << __func__;}
#else //_MSC_VER << 1900
    #define YN_TIMESTAMP() \
        {qDebug() << QDateTime::currentMSecsSinceEpoch() << __FUNCTION__;}
#endif //_MSC_VER << 1900
#else //_MSC_VER
    #define YN_TIMESTAMP() \
        { qDebug() << QDateTime::currentMSecsSinceEpoch() << __PRETTY_FUNCTION__; }
#endif //_MSC_VER

class YnPerf{


public:
    YnPerf();

    void start(){_timeStart = QDateTime::currentMSecsSinceEpoch();}
    void stop(){_timeStop = QDateTime::currentMSecsSinceEpoch();
                _timeDiff = _timeStop - _timeStart;
                qDebug() << "diff: " << _timeDiff << "msec" ;
               }
private:
    qint64      _timeStart;
    qint64      _timeStop;
    qint64      _timeDiff;
};

#endif // SHARE_H
