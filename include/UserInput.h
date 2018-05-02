#ifndef USERINPUT
#define USERINPUT

#include <QtQuick>

class UserInput: public QQuickView
{
Q_OBJECT
public:
    UserInput(QString userName);
    ~UserInput();
    bool event(QEvent *e) Q_DECL_OVERRIDE;

public slots:
    void onEntrButtonClicked(QString msg);
    void onMessageRecieved(QString usrName, QString msg);

signals:
    void messageReady(QString user, QString msg);
    void userQuit(QString);

private:
    QString m_userName;
    QObject* m_view;

};

#endif
