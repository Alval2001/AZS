#include <QApplication>
#include <QQmlApplicationEngine>
#include <QCryptographicHash>
#include "cryptocontroller.h"
#include <QObject>
#include <QQmlContext>
#include <Windows.h>
#include <QMessageBox>
#include <QProcess>
#include <atlstr.h>

typedef unsigned long long QWORD;



int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;                                               // создание объекта движка/интерпретатора QML

//    QByteArray data = "ff*rt8ferg__=-*&YT";
//    data = QCryptographicHash::hash(data, QCryptographicHash::Md5);
//    qDebug() << data;


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    cryptoController crp;
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("cryptoController", &crp);

    // БЛОК ЗАЩИТЫ ОТ ОТЛАДКИ МЕТОДОМ САМООТЛАДКИ
        QProcess *satelliteProcess = new QProcess();
        int pid = QApplication::applicationPid();
        qDebug() << "pid = " << pid;
        QStringList arguments = {QString::number(pid)};
        qDebug() << "arguments = " << arguments;
        satelliteProcess->start("DebugProtector.exe", arguments);
        bool ProtectorStarted = satelliteProcess->waitForStarted(1000);
        qDebug() << "ProtectorStarted = " << ProtectorStarted;
    //// БЛОК ПРОСТЕЙШЕГО ОБНАРУЖЕНИЯ ОТЛАДЧИКА
        ///
     //    bool debuggerFound = IsDebuggerPresent();
     //    if (debuggerFound) {
     //        qDebug() << "Debugger is found !!! Teminating the App !!!";
    //        std::cout << "Debugger is found !!! Teminating the App !!!" << std::endl;
    //        return -1;
    //    }

    //ЗАЩИТА ОТ ПАТЧИНГА
    //     чтобы определить начальный адрес, с которого приложение размещается в виртуальной памяти,
    //     вызывается WinAPI-функция GetModuleHandle
        QWORD moduleBase = (QWORD)GetModuleHandle(NULL);
        QWORD text_segment_start = moduleBase + 0x1000; // сегмент .text располагается с отступом 0x1000
        qDebug() << "text_segment_start = " << Qt::hex << text_segment_start;

    //    // Определить длину сегмента из заголовка
        PIMAGE_DOS_HEADER pIHD = reinterpret_cast<PIMAGE_DOS_HEADER>(moduleBase);
        PIMAGE_NT_HEADERS pINH = reinterpret_cast<PIMAGE_NT_HEADERS>(moduleBase + pIHD->e_lfanew);

        QWORD size_of_text = pINH->OptionalHeader.SizeOfCode;  // размер сегмента .text


        QByteArray text_segment_contents = QByteArray((char*)text_segment_start, size_of_text);// помещаем содержимое сегмента .text в массив char QByteArray
        QByteArray current_hash = QCryptographicHash::hash(text_segment_contents, QCryptographicHash::Sha256);//получаем хэш сегмента .text
        QByteArray current_hash_base64 = current_hash.toBase64();//переводим хэш в формат Base64, т.к. некоторые символы могут быть нечитыаемы в исходном хэше

        const QByteArray hash0_base64 = QByteArray("6jJZ9frELdX+ZtWrJaBZR+dhaXJGAw9/Btbi0Qo5T8c=");//задаем константу, в которой будет храниться эталонный хэш

        //для проверки выводим все данные в отладку
        qDebug() << "text_segment_start = " << Qt::hex << text_segment_start;
        qDebug() << "size_of_text = " << size_of_text;
        qDebug() << "text_segment_contents = " << Qt::hex << text_segment_contents.first(100);
        qDebug() << "current_hash_base64 = " << current_hash_base64;

        bool checkresult = (current_hash_base64==hash0_base64);//проверка эталлоного хэша с фактическим
        qDebug() << "checkresult = " << checkresult;//вывод результата проверки

        if (!checkresult){//если false, то вывод сообщения о модификации приложения
            int result = QMessageBox::critical(nullptr, "Внимание!", "Приложение модифицировано");
           return -1;
        }

        engine.load(url);

    return app.exec();
}
