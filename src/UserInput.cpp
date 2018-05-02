#include "UserInput.h"

UserInput::UserInput(QString userName): m_userName(userName)
{
    setSource(QUrl(QStringLiteral("qrc:/UserInput.qml")));
    m_view = rootObject();
    setTitle(m_userName);
    connect(m_view, SIGNAL(sendMsgSignal(QString)),
            this, SLOT(onEntrButtonClicked(QString)));

    setResizeMode(SizeRootObjectToView);
}

void UserInput::onMessageRecieved(QString usrName, QString msg)
{
    if (usrName == m_userName)
        usrName = "Me"; //change sender name for our own messages

    QString internalMessage = usrName + ": " + msg; //construct output string
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_view, "addMessage",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, internalMessage));
}

UserInput::~UserInput()
{
    disconnect(m_view, SIGNAL(sendMsgSignal(QString)),
            this, SLOT(onEntrButtonClicked(QString)));
}

void UserInput::onEntrButtonClicked(QString msg)
{
    if (msg.isEmpty())
        return; //ignore empty messages
    emit messageReady(m_userName, msg);
}

bool UserInput::event(QEvent *e) //to handle closing event
{
    if (e->type() == QEvent::Close)
    {
        emit userQuit(m_userName);
        return true;
    }
    return QQuickView::event(e);
}
