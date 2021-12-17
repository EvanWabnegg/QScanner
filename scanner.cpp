#include "scanner.h"
#include <QTcpSocket>
#include <QAbstractSocket>

Scanner::Scanner(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void Scanner::on_scanButton_clicked()
{
    m_ports.clear();
    resultText->clear();
    QTcpSocket* socket = new QTcpSocket(this);

    m_hostnameString = hostName->text();
    m_portString = ports->text();
    m_splitPorts = m_portString.split(",");

    for(auto p : m_splitPorts)
    {
        m_ports.push_back(p.toInt());
    }

    for(auto p : m_ports)
    {
        socket->connectToHost(m_hostnameString,p);
        if(!socket->waitForConnected(1000))
        {
            resultText->append("port: " + QString::number(p) + " not connected");
        }
        else
        {
            resultText->append("port: " + QString::number(p) + " connected");
        }
        resultText->show();
    }


}
