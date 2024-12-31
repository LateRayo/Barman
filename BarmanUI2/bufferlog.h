#ifndef BUFFERLOG_H
#define BUFFERLOG_H

#include <QMainWindow>

class BufferLog
{
public:
    BufferLog();
    BufferLog(int _ID, QString _USER, QString _PASS); //carga
    BufferLog( const BufferLog &Usuario ); // copia

    int getID() const;
    void setID(int newID);
    QString getUSER() const;
    void setUSER(const QString &newUSER);
    QString getPASSWORD() const;
    void setPASSWORD(const QString &newPASSWORD);

private:
    int ID;
    QString USER;
    QString PASSWORD;
};



#endif // BUFFERLOG_H
