QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Ruta de las cabeceras de MySQL Connector (ajústalo si es necesario)
INCLUDEPATH += /usr/include/mysql-cppconn

# Ruta de las bibliotecas y nombre de la biblioteca
LIBS += -L/usr/lib/x86_64-linux-gnu -lmysqlcppconn

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    login.cpp \
    selectrago.cpp

HEADERS += \
    login.h \
    selectrago.h

FORMS += \
    login.ui \
    selectrago.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Screenshot from 2024-10-24 14-58-41.png

RESOURCES += \
    loginpicc.qrc
