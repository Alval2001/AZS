//#include "backend.h"
//#include <QCryptographicHash>
//#include <QDebug>

//typedef void (Backend::*ftype1)(void);
//typedef void (Backend::*ftype2)(void);

//Backend::Backend(QObject *parent)
//    : QObject{parent}
//{
//    printf("constructor");
//}

//void Backend::function1(void)
//{
//    printf("string1");
//    return;
//}

//void Backend::function2(void)
//{
//    printf("string2");
//    return;
//}


//bool Backend::selfcheck()
//{
//    ftype1 fun_pointer1 = &Backend::function1;
//    ftype2 fun_pointer2 = &Backend::selfcheck;

//    char * ptr1 = reinterpret_cast<char*>(&fun_pointer1);
//    char * ptr2 = reinterpret_cast<char*>(&fun_pointer2);
//    unsigned long long data_length = ptr1 - ptr2;

//    qDebug() << "fun_pointer1 = " << &fun_pointer1;
//    qDebug() << "fun_pointer2 = " << &fun_pointer2;

//    qDebug() << "ptr1 = " << (unsigned long long)ptr1;
//    qDebug() << "ptr2 = " << (unsigned long long)ptr2;

//    QByteArray data = QByteArray(ptr1, 100);
//    QByteArray hash = QCryptographicHash::hash(data, QCryptographicHash::Sha256);
//    QByteArray hash_base64 = hash.toBase64();
//    QByteArray hash0_base64 = QByteArray::fromBase64("");

//    return (hash == hash0_base64);
//    return true;
//}

//void Backend::send_to_qml(bool checked_pin)
//{

//}

//void Backend::check_pin_code(QString & pin_code)
//{
//    QByteArray code = QByteArray("b01672c37b296eaf3f1854d10e9c2b8a6c96f77c739f9982d03e59f3e9696521");
//    qDebug() << "code = " << &code;
//    QByteArray hash64 = code.toBase64();
//    qDebug() << "hash64 = " << &hash64;
//    QByteArray byte_pin_code = pin_code.toUtf8();
//    qDebug() << "byte_pin_code = " << &byte_pin_code;
//    QByteArray hash_pin_code = QCryptographicHash::hash(byte_pin_code, QCryptographicHash::Sha256);
//    qDebug() << "hash_pin_code = " << &hash_pin_code;

//    emit send_to_qml(byte_pin_code == code);
//    return;
//}
