#include "bufferlog.h"

BufferLog::BufferLog()
{
    ID = 0;
    USER = "";
    PASSWORD = "";
}

// carga
BufferLog::BufferLog( int _ID, QString _USER, QString _PASS)
{
    ID = _ID;
    USER = _USER;
    PASSWORD = _PASS;
}

//copia
BufferLog::BufferLog( const BufferLog &Usuario )
{
    ID = Usuario.getID();
    USER = Usuario.getUSER();
    PASSWORD = Usuario.getPASSWORD();
}


int BufferLog::getID() const
{
    return ID;
}

void BufferLog::setID(int newID)
{
    ID = newID;
}

QString BufferLog::getUSER() const
{
    return USER;
}

void BufferLog::setUSER(const QString &newUSER)
{
    USER = newUSER;
}

QString BufferLog::getPASSWORD() const
{
    return PASSWORD;
}

void BufferLog::setPASSWORD(const QString &newPASSWORD)
{
    PASSWORD = newPASSWORD;
}

