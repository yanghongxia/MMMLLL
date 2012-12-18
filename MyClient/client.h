#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QStringList>
class MyThread:public QThread
{
  Q_OBJECT
public:
    MyThread();
    ~MyThread();
public slots:
   void read(void);
};
namespace Ui {
    class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = 0);
    ~Client();
public:
    bool PLCDiscovery(QStringList &DeviceMACAddrList) ;

    bool PLCGetLocalDevice(QString &DeviceMACAddress) ;

    bool PLCGetDeviceModelName( QString &DeviceMACAddress, QString &DeviceModelName);

    bool PLCGetDeviceFWVersion( QString &DeviceMACAddress, QString &DeviceFWVersion) ;

    bool PLCGetDeviceName( QString &DeviceMACAddress, QString &DeviceName) ;

    bool PLCGetNetworkType( QString &DeviceMACAddress, QString &DeviceNetworkType) ;

    bool PLCGetDeviceLedStatus( QString &DeviceMACAddress, int *DeviceLedStatus) ;

    bool PLCGetDeviceLinkRate(  QString &DeviceMACAddress, QMap<QString,QPair<qint16,qint16> > &DeviceLinkRateTable);
    bool PLCGetDeviceQoSStatus( QString &DeviceMACAddress
                               , QVector<QPair<QString, int> > &qosMacs
                               , QVector<QPair<quint16, int> > &qosPorts
                                 , bool &checkVLAN
                                 , bool &checkTOS );


    bool PLCGetDeviceForwardtable(  QString &DeviceMACAddress, QStringList &ForwardTable) ;

    bool PLCGetDeviceFWUpgradeVersion (QString &DeviceMACAddress, QString &DeviceFWUpgradeVersion) ;

    bool PLCGetDeviceFWUpgradeRegion ( QString &DeviceMACAddress, QString &DeviceFWUpgradeResion) ;



    bool PLCSetDeviceName( QString &DeviceMACAddress,  QString &DeviceName);

    bool PLCSetDeviceLedStatus( QString &DeviceMACAddress, int DeviceLedStatus) ;

    bool PLCSetDeviceSecurityKey(  QString &DeviceMACAddress,  QString &SecurityKey, QString &DevicePassword);

        bool PLCSetDeviceQoS( QString &DeviceMACAddress
                                        ,  QVector<QPair<QString, int> > &qosMacs
                                        ,  QVector<QPair<quint16, int> > &qosPorts
                                        , bool checkVLAN
                                        , bool checkTOS );

    bool PLCSetDeviceResetDefault( QString &DeviceMACAddress) ;

    bool PLCCheckDevicePassword( QString &DeviceMACAddress,  QString &dakcode);

public slots:

void readyread1();

/*
void readyread2();

void readyread3();
void readyread4();
void readyread5();
void readyread6();
void readyread7();
void readyread8();
void readyread9();
void readyread10();
void readyread11();
void readyread12();
void readyread13();
void readyread14();
void readyread15();
void readyread16();
void readyread17();
void readyread18();
*/


private:
    Ui::Client *ui;
    //还没有在构造函数中对其进行
    QTcpSocket *socket1;
    QTcpSocket *socket2;

    QTcpSocket *socket3;
    QTcpSocket *socket4;
    QTcpSocket *socket5;
    QTcpSocket *socket6;
    QTcpSocket *socket7;
    QTcpSocket *socket8;
    QTcpSocket *socket9;
    QTcpSocket *socket10;
    QTcpSocket *socket11;
    QTcpSocket *socket12;
    QTcpSocket *socket13;
    QTcpSocket *socket14;
    QTcpSocket *socket15;
    QTcpSocket *socket16;
    QTcpSocket *socket17;
    QTcpSocket *socket18;


    QStringList devicemacaddress1;
    QStringList qstringlist;
    QString devicemacaddress2;
    QString devicemacaddress3;
    QString devicemodelname;
    QString devicemacaddress4;
    QString devicefwversion;
    QString devicename;
    QString devicemacaddress5;
    QString devicenetworktype;
    QString devicemacaddress6;
    QString devicemacaddress7;
    int *deviceledstatus;
    QString devicemacaddress8;
    QMap<QString,QPair<qint16,qint16> >  devicelinkratetable;
    QString devicemacaddress9;
    QVector<QPair<QString, int> > qosmacs;
    QVector<QPair<quint16, int> > qosports;
    bool checkvlan;
    bool checktos;
    QString devicemacaddress10;
    QStringList forwardtable;
    QString devicemacaddress11;
    QString devicepgradeversion;
    QString devicemacaddress12;
    QString devicefwupgraderesion;
    QString devicemacaddress13;
    QString devicename1;
    QString devicemacaddress14;
    int *deviceledstatus1;
    QString devicemacaddress15;
    QString securitykey;
    QString devicepassword;
    QString devicemacaddress16;
    QVector<QPair<QString, int> > qosmacs1;
    QVector<QPair<quint16, int> > qosports1;
    bool checkvlan1;
    bool checktos1 ;
    QString devicemacaddress17;
    QString devicemacaddress18;
    QString dakcode;
    MyThread thread;

};

#endif // CLIENT_H
