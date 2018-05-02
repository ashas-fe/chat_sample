#include "chatCore.h"


void ChatCore::createNewUser()
{
    QString userName = "User#" + QString::number(m_usersCount++); //construct simple unique username
    UserInput* user = new UserInput(userName);
    user->setPosition(m_posX, m_posY);
    m_posX += 20;
    m_posY += 20; //update start position for next user's window
    user->show();
    connect(user, SIGNAL(messageReady(QString, QString)),
                     this, SLOT(onMessageRecieved(QString, QString)));
    connect(this, SIGNAL(messageForAll(QString, QString)),
                     user, SLOT(onMessageRecieved(QString, QString)));
    connect(user, SIGNAL(userQuit(QString)),
                     this, SLOT(OnUserQuit(QString)));
    m_users.insert(std::make_pair(userName, user));
}

void ChatCore::OnUserQuit(QString userName)
{
    disconnect(m_users[userName], SIGNAL(messageReady(QString, QString)),
               this, SLOT(onMessageRecieved(QString, QString)));
    disconnect(m_users[userName], SIGNAL(userQuit(QString)),
                     this, SLOT(OnUserQuit(QString)));
    disconnect(this, SIGNAL(messageForAll(QString, QString)),
                     m_users[userName], SLOT(onMessageRecieved(QString, QString)));
    delete m_users[userName];
    m_users.erase(userName);
}

void ChatCore::onMessageRecieved(QString userName, QString message)
{
    emit messageForAll(userName, message);
}

ChatCore::~ChatCore()
{
    for (auto user: m_users)
    {
        disconnect(user.second, SIGNAL(messageReady(QString, QString)),
                         this, SLOT(onMessageRecieved(QString, QString)));
        disconnect(this, SIGNAL(messageForAll(QString, QString)),
                         user.second, SLOT(onMessageRecieved(QString, QString)));
        disconnect(user.second, SIGNAL(userQuit(QString)),
                         this, SLOT(OnUserQuit(QString)));
        user.second->close();
        delete user.second;
    }
}
