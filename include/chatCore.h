#ifndef CHATCORE
#define CHATCORE

#include <QObject>
#include "UserInput.h"

class ChatCore : public QObject
{
    Q_OBJECT

public:
    explicit ChatCore (QObject* parent = 0) : QObject(parent), m_usersCount(0), m_posX(200), m_posY(200) {}
    ~ChatCore();

Q_INVOKABLE void createNewUser(); //creat and show new user's window

public slots:
    void onMessageRecieved(QString userName, QString message);
    void OnUserQuit(QString);

signals:
    void messageForAll(QString usrName, QString msg);

private:
    std::map<QString, UserInput*> m_users;
    int m_usersCount;
    int m_posX;
    int m_posY;
};

#endif
