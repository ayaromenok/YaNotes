#ifndef MDOBJECT_H
#define MDOBJECT_H

#include <QObject>

class MDObject : public QObject
{
    Q_OBJECT
public:
    explicit MDObject(QObject *parent = nullptr);
    ~MDObject();
signals:

public slots:
    QString toHtml(QString &strMD);
};

#endif // MDOBJECT_H
