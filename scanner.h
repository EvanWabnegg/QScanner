#ifndef SCANNER_H
#define SCANNER_H

#include "ui_scanner.h"

class Scanner : public QWidget, private Ui::Scanner
{
    Q_OBJECT

public:
    explicit Scanner(QWidget *parent = nullptr);

private slots:
    void on_scanButton_clicked();

private:
    QString m_portString;
    QString m_hostnameString;
    std::vector<int> m_ports;
    QStringList m_splitPorts;
};

#endif // SCANNER_H
