#ifndef CRYPTOCONTROLLER_H
#define CRYPTOCONTROLLER_H

#include <QObject>
#include <QString>

class cryptoController : public QObject
{
    Q_OBJECT
public:
    explicit cryptoController(QObject *parent = nullptr);
    ~cryptoController() {};

public slots:
    bool check_password(QString password);
    void text_to_clipboard(QString text, QString pin);
    void decrypt_db_file(QString password, int record_id=-1, int is_password=-1);
    void encrypt_db_file(QString password, int record_id=-1, int is_password=-1);
    QString decrypt_login_or_password(QString text, QString password);
    void encrypt_login_or_password(QString password);

private:
    unsigned char * iv = (unsigned char *)("77411230141456889873614547987324");

signals:
    void sendDbToQml(QString db_decrypted);
    void sendMessageToQml(QString message);

};

#endif // CRYPTOCONTROLLER_H
