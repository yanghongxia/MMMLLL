#include "client.h"
#include "ui_client.h"
#include <QDataStream>
#include <QByteArray>
#include <QDataStream>
#include <QTcpServer>
#include <QTest>

MyThread::MyThread(){}
MyThread::~MyThread(){}


void read(void){

}

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);

     socket1 =new QTcpSocket(this);
     socket2 =new QTcpSocket(this);
     socket3 =new QTcpSocket(this);
     socket4 =new QTcpSocket(this);
     socket5 =new QTcpSocket(this);
     socket6 =new QTcpSocket(this);
     socket7 =new QTcpSocket(this);
     socket8 =new QTcpSocket(this);
     socket9 =new QTcpSocket(this);
     socket10 =new QTcpSocket(this);
     socket11 =new QTcpSocket(this);
     socket12 =new QTcpSocket(this);
     socket13 =new QTcpSocket(this);
     socket14 =new QTcpSocket(this);
     socket15 =new QTcpSocket(this);
     socket16 =new QTcpSocket(this);
     socket17 =new QTcpSocket(this);
     socket18 =new QTcpSocket(this);
     deviceledstatus=NULL;
     deviceledstatus1=NULL;

}

Client::~Client()
{
    delete ui;


}

bool Client:: PLCDiscovery(QStringList &DeviceMACAddrList)
{

      socket1->connectToHost("192.168.9.20",19999);
      if(socket1->waitForConnected())
      {
          QDataStream out(socket1);
          out<<"plcdiscovery";
          out<<"devicemacaddress";
          socket1->waitForBytesWritten();
      }
      connect(socket1,SIGNAL(readyRead()),this,SLOT(readyread1()));
       connect(socket1,SIGNAL(readyRead()),thread,SLOT(read()));
       return 1;
}

/*
bool Client::PLCGetLocalDevice(QString &DeviceMACAddress)
{
    socket2->connectToHost("192.168.9.83",66666);
    if(socket2->waitForConnected())
    {
        QDataStream out(socket2);
        out<<"PLCGetLocalDevice";
        out<<"DeviceMACAddress";
        socket2->waitForBytesWritten();
    }
    if(connect(socket2,SIGNAL(readyread()),this,SLOT(readyread2())))
    {
         //
         DeviceMACAddress=devicemacaddress2;
         return true;
    }
    else
    {
        return false;
    }
}

bool Client::PLCGetDeviceModelName( QString &DeviceMACAddress, QString &DeviceModelName)
{
    socket3->connectToHost("192.168.9.83",66666);
    if(socket3->waitForConnected())
    {
        QDataStream out(socket3);
        out<<"PLCGetDeviceModelName";
        out<<"DeviceMACAddress";
        socket3->waitForBytesWritten();
    }
    if(connect(socket3,SIGNAL(readyread()),this,SLOT(readyread3())))
    {
         //
         DeviceMACAddress=devicemacaddress3;
         DeviceModelName=devicemodelname;
         return true;
    }
    else
    {
        return false;
    }


}

bool Client::PLCGetDeviceFWVersion( QString &DeviceMACAddress, QString &DeviceFWVersion)
{
    socket4->connectToHost("192.168.9.83",66666);
    if(socket4->waitForConnected())
    {
        QDataStream out(socket4);
        out<<"PLCGetDeviceFWVersion";
        out<<"DeviceMACAddress";
        socket4->waitForBytesWritten();
    }
    if(connect(socket4,SIGNAL(readyread()),this,SLOT(readyread4())))
    {
         //
         DeviceMACAddress=devicemacaddress4;
         DeviceFWVersion=devicefwversion;
         return true;
    }
    else
    {
        return false;
    }
}

bool Client::PLCGetDeviceName( QString &DeviceMACAddress, QString &DeviceName)
{
    socket5->connectToHost("192.168.9.83",66666);
    if(socket5->waitForConnected())
    {
        QDataStream out(socket5);
        out<<"PLCGetDeviceName";
        out<<"DeviceMACAddress";
        socket5->waitForBytesWritten();
    }
    if(connect(socket5,SIGNAL(readyread()),this,SLOT(readyread5())))
    {

         DeviceMACAddress=devicemacaddress5;
         DeviceName=devicename;
         return true;
    }
    else
    {
        return false;
    }



}

bool Client::PLCGetNetworkType( QString &DeviceMACAddress, QString &DeviceNetworkType)
{
    socket6->connectToHost("192.168.9.83",66666);
    if(socket6->waitForConnected())
    {
        QDataStream out(socket6);
        out<<"PLCGetNetworkType";
        out<<"DeviceMACAddress";
        socket6->waitForBytesWritten();
    }
    if(connect(socket6,SIGNAL(readyread()),this,SLOT(readyread6())))
    {
         //
         DeviceMACAddress=devicemacaddress6;
         DeviceNetworkType=devicenetworktype;
         return true;
    }
    else
    {
        return false;
    }
}

bool Client::PLCGetDeviceLedStatus( QString &DeviceMACAddress, int *DeviceLedStatus)
{
    socket7->connectToHost("192.168.9.249",66666);
    if(socket7->waitForConnected())
    {
        QDataStream out(socket7);
        out<<"PLCGetDeviceLedStatus";
        out<<"DeviceMACAddress";
        socket7->waitForBytesWritten();
    }
    if(connect(socket7,SIGNAL(readyread()),this,SLOT(readyread7())))
    {
         //
         DeviceMACAddress=devicemacaddress7;
         DeviceLedStatus = deviceledstatus;

         return true;
    }
    else
    {
        return false;
    }

}

bool Client::PLCGetDeviceLinkRate(  QString &DeviceMACAddress, QMap<QString,QPair<qint16,qint16> > &DeviceLinkRateTable)
{
    socket8->connectToHost("192.168.9.83",66666);
    if(socket8->waitForConnected())
    {
        QDataStream out(socket8);
        out<<"PLCGetDeviceLinkRate";
        out<<"DeviceMACAddress";
        socket8->waitForBytesWritten();
    }
    if(connect(socket8,SIGNAL(readyread()),this,SLOT(readyread8())))
    {
         //
          DeviceMACAddress=devicemacaddress8;
          DeviceLinkRateTable= devicelinkratetable;
         return true;
    }
    else
    {
        return false;
    }


}

bool Client::PLCGetDeviceQoSStatus( QString &DeviceMACAddress
                           , QVector<QPair<QString, int> > &qosMacs
                           , QVector<QPair<quint16, int> > &qosPorts
                             , bool &checkVLAN
                             , bool &checkTOS )
{
    socket9->connectToHost("192.168.9.83",66666);
    if(socket9->waitForConnected())
    {
        QDataStream out(socket9);
        out<<"PLCGetDeviceQoSStatus";
        out<<"DeviceMACAddress";
        socket9->waitForBytesWritten();
    }
    if(connect(socket9,SIGNAL(readyread()),this,SLOT(readyread9())))
    {
         //
         DeviceMACAddress=devicemacaddress9;
          qosMacs=qosmacs;
          qosPorts=qosports;
          checkVLAN=checkvlan;
          checkTOS=checktos;
         return true;
    }
    else
    {
        return false;
    }


}


bool Client::PLCGetDeviceForwardtable( QString &DeviceMACAddress, QStringList &ForwardTable)
{
    socket10->connectToHost("192.168.9.83",66666);
    if(socket10->waitForConnected())
    {
        QDataStream out(socket10);
        out<<"PLCGetDeviceForwardtable";
        out<<"DeviceMACAddress";
        socket10->waitForBytesWritten();
    }
    if(connect(socket10,SIGNAL(readyread()),this,SLOT(readyread10())))
    {
         //
         DeviceMACAddress=devicemacaddress10;
         ForwardTable=forwardtable;
         return true;
    }
    else
    {
        return false;
    }


}

bool Client::PLCGetDeviceFWUpgradeVersion (QString &DeviceMACAddress, QString &DeviceFWUpgradeVersion)
{

    socket11->connectToHost("192.168.9.83",66666);
    if(socket11->waitForConnected())
    {
        QDataStream out(socket11);
        out<<"PLCGetDeviceFWUpgradeVersion";
        out<<"DeviceMACAddress";
        socket11->waitForBytesWritten();
    }
    if(connect(socket11,SIGNAL(readyread()),this,SLOT(readyread11())))
    {
         //

         DeviceMACAddress=devicemacaddress11;
         DeviceFWUpgradeVersion=devicepgradeversion;
         return true;
    }
    else
    {
        return false;
    }


}

bool Client::PLCGetDeviceFWUpgradeRegion ( QString &DeviceMACAddress, QString &DeviceFWUpgradeResion)
{
    socket12->connectToHost("192.168.9.83",66666);
    if(socket12->waitForConnected())
    {
        QDataStream out(socket12);
        out<<"PLCGetDeviceFWUpgradeRegion";
        out<<"DeviceMACAddress";
        socket12->waitForBytesWritten();
    }
    if(connect(socket12,SIGNAL(readyread()),this,SLOT(readyread12())))
    {
         //
         DeviceMACAddress=devicemacaddress12;
         DeviceFWUpgradeResion=devicefwupgraderesion;
         return true;
    }
    else
    {
        return false;
    }
}



bool Client::PLCSetDeviceName(QString &DeviceMACAddress,  QString &DeviceName)
{
    socket13->connectToHost("192.168.9.83",66666);
    if(socket13->waitForConnected())
    {
        QDataStream out(socket13);
        out<<"PLCSetDeviceName";
        out<<"DeviceMACAddress";
        socket13->waitForBytesWritten();
    }
    if(connect(socket13,SIGNAL(readyread()),this,SLOT(readyread13())))
    {
         //
         DeviceMACAddress=devicemacaddress13;
         DeviceName=devicename1;
         return true;
    }
    else
    {
        return false;
    }

}

bool Client::PLCSetDeviceLedStatus( QString &DeviceMACAddress, int DeviceLedStatus)
{
    socket14->connectToHost("192.168.9.83",66666);
    if(socket14->waitForConnected())
    {
        QDataStream out(socket14);
        out<<"PLCSetDeviceLedStatus";
        out<<"DeviceMACAddress";
        socket14->waitForBytesWritten();
    }
    if(connect(socket14,SIGNAL(readyread()),this,SLOT(readyread14())))
    {
         //
         DeviceMACAddress=devicemacaddress14;
         DeviceLedStatus=*deviceledstatus1;
         return true;
    }
    else
    {
        return false;
    }

}

bool Client::PLCSetDeviceSecurityKey( QString &DeviceMACAddress,  QString &SecurityKey, QString &DevicePassword)
{
    socket15->connectToHost("192.168.9.83",66666);
    if(socket15->waitForConnected())
    {
        QDataStream out(socket15);
        out<<"PLCSetDeviceSecurityKey";
        out<<"DeviceMACAddress";
        socket15->waitForBytesWritten();
    }
    if(connect(socket15,SIGNAL(readyread()),this,SLOT(readyread15())))
    {
         //
        DeviceMACAddress=devicemacaddress15;
         SecurityKey=securitykey;
         DevicePassword=devicepassword;
         return true;
    }
    else
    {
        return false;
    }
}

bool Client::PLCSetDeviceQoS( QString &DeviceMACAddress
                                    ,  QVector<QPair<QString, int> > &qosMacs
                                    ,  QVector<QPair<quint16, int> > &qosPorts
                                    , bool checkVLAN
                                    , bool checkTOS )
    {
    socket16->connectToHost("192.168.9.83",66666);
    if(socket16->waitForConnected())
    {
        QDataStream out(socket16);
        out<<"PLCSetDeviceQoS";
        out<<"DeviceMACAddress";
        socket16->waitForBytesWritten();
    }
    if(connect(socket16,SIGNAL(readyread()),this,SLOT(readyread16())))
    {
         //
        DeviceMACAddress=devicemacaddress16;

         qosMacs=qosmacs1;
         qosPorts=qosports1;
         checkVLAN=checkvlan1;
         checkTOS=checktos1;
         return true;
    }
    else
    {
        return false;
    }


    }

bool Client::PLCSetDeviceResetDefault( QString &DeviceMACAddress)
{
    socket17->connectToHost("192.168.9.83",66666);
    if(socket17->waitForConnected())
    {
        QDataStream out(socket17);
        out<<"PLCSetDeviceResetDefault";
        out<<"DeviceMACAddress";
        socket17->waitForBytesWritten();
    }
    if(connect(socket17,SIGNAL(readyread()),this,SLOT(readyread17())))
    {
         //
        DeviceMACAddress=devicemacaddress17;

         return true;
    }
    else
    {
        return false;
    }

}


bool Client::PLCCheckDevicePassword(QString &DeviceMACAddress,  QString &Dakcode)
{
    socket18->connectToHost("192.168.9.83",66666);
    if(socket18->waitForConnected())
    {
        QDataStream out(socket18);
        out<<"PLCCheckDevicePassword";
        out<<"DeviceMACAddress";
        socket18->waitForBytesWritten();
    }
    if(connect(socket18,SIGNAL(readyread()),this,SLOT(readyread18())))
    {
         //
        DeviceMACAddress=devicemacaddress18;
        Dakcode=dakcode;

         return true;
    }
    else
    {
        return false;
    }
}


*/


void Client::readyread1()
{
    //qDebug()<<"hhhhhhhhhhhh";
    //接受服务器的数据
    QDataStream read(socket1);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;
    //QByteArray byte1;
    QString str = "k";
    //while(str!="")
    {   qDebug()<<"k";
        read>>byte;
        str = QString(byte);
        //qDebug()<<str;
        byte.clear();

       devicemacaddress1+=str;
    }



   //  QByteArray byte;
   // byte=QByteArray(str);
   // qDebug()<<QString::number(devicemacaddress1.count());
    //devicemacaddress1=str;
     // qDebug()<<devicemacaddress1;
    //st=QString(byte);
    //emit message();


}

/*
void Client::readyread2()
{
    //接受服务器的数据
    QDataStream read(socket2);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;

    QString str="hh";

    read>>byte;
   devicemacaddress2=QString(byte);

}

void Client::readyread3()
{
    //接受服务器的数据
    QDataStream read(socket3);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;
    QByteArray byte1;
    QString str="hh";

    read>>byte;
    devicemacaddress3=QString(byte);
    read>>byte1;
    devicemodelname=QString(byte1);
}

void Client::readyread4()
{
    //接受服务器的数据
    QDataStream read(socket4);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;
    QByteArray byte1;
    QString str="hh";

    read>>byte;
    devicemacaddress4=QString(byte);
    read>>byte1;
    devicefwversion=QString(byte1);

}

void Client::readyread5()
{
    //接受服务器的数据
    QDataStream read(socket5);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;
    QByteArray byte1;
    QString str="hh";

    read>>byte;
    devicemacaddress5=QString(byte);
    read>>byte1;
    devicename=QString(byte1);
}

void Client::readyread6()
{
    //接受服务器的数据
    QDataStream read(socket6);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;
    QByteArray byte1;
    QString str="hh";

    read>>byte;
    devicemacaddress6=QString(byte);
    read>>byte1;
    devicenetworktype=QString(byte1);
}
void Client::readyread7()
{
    QDataStream read(socket7);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;
    QByteArray byte1;
    QString str="hh";

    read>>byte;
    devicemacaddress4=QString(byte);
    read>>byte1;
    *deviceledstatus=(QString(byte1).toInt());
}

void Client::readyread8()
{
    QDataStream read(socket8);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;
    QByteArray byte1;
    QString str="hh";

    read>>byte;
    devicemacaddress8=QString(byte);
    read>>byte1;

 //devicelinkratetable =  (QMap<QString,QPair<qint16,qint16> >)QDataStream(byte1);

}

void Client::readyread9()
{

    QDataStream read(socket9);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;
    QByteArray byte1;
    QByteArray byte2;
    QByteArray byte3;
    QByteArray byte4;


    read>>byte;
    devicemacaddress9=QString(byte);
    read>>byte1;
    ///////////////////////
    //qosmacs=QString(byte1);
    ///////////////////////
    read>>byte2;
    ///////////////
    //qosports=QString(byte2);
    ///////////////
    read>>byte3;
    checkvlan=QString(byte3).toInt();
    read>>byte4;
    checktos=QString(byte4).toInt();
}

void Client::readyread10()
{
    QDataStream read(socket10);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;
    QByteArray byte1;
    read>>byte;
    devicemacaddress10=QString(byte);
    read>>byte1;
    /////////
    //forwardtable=QString(byte1);
    /////////
}

void Client::readyread11()
{
    QDataStream read(socket11);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;
    QByteArray byte1;


    read>>byte;
    devicemacaddress11=QString(byte);
    read>>byte1;
    devicepgradeversion=QString(byte1);



}

void Client::readyread12()
{
    QDataStream read(socket12);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;
    QByteArray byte1;


    read>>byte;
    devicemacaddress11=QString(byte);
    read>>byte1;
    devicefwupgraderesion=QString(byte1).toInt();

}

void Client::readyread13()
{
    QDataStream read(socket13);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;
    QByteArray byte1;

    read>>byte;
    devicemacaddress13=QString(byte);
    read>>byte1;
    devicename1=QString(byte1);

}
void Client::readyread14()
{
    QDataStream read(socket14);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;
    QByteArray byte1;
    QByteArray byte2;
    QByteArray byte3;
    QByteArray byte4;
    QString str="hh";

    read>>byte;
    devicemacaddress14=QString(byte);
    read>>byte1;
     *deviceledstatus1=QString(byte1).toInt();


}

void Client::readyread15()
{
    QDataStream read(socket14);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;
    QByteArray byte1;
    QByteArray byte2;

    read>>byte;
    devicemacaddress15=QString(byte);
    read>>byte1;
    securitykey=QString(byte1);
    read>>byte2;
    devicepassword=QString(byte2);




}

void Client::readyread16()
{
    QDataStream read(socket15);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;
    QByteArray byte1;
    QByteArray byte2;
    QByteArray byte3;
    QByteArray byte4;

    read>>byte;
    devicemacaddress16=QString(byte);
     read>>byte1;
     ////
    // qosMmacs1=QString(byte1);
     read>>byte2;
     /////
     //qosports1=QString(byte2);
     read>>byte3;
      checkvlan1=QString(byte3).toInt();
      read>>byte4;
      checktos1=QString(byte4).toInt();

}
void Client::readyread17()
{
    QDataStream read(socket17);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;

   read>>byte;
    devicemacaddress17=QString(byte);

}
void Client::readyread18()
{
    QDataStream read(socket17);
    read.setVersion(QDataStream::Qt_4_7);
    QByteArray byte;
    QByteArray byte1;

    read>>byte;
    devicemacaddress18=QString(byte);
    read>>byte1;
    dakcode=QString(byte1);


}
*/
