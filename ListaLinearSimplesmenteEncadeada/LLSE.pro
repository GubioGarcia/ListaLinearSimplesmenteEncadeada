QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    llse.cpp \
    main.cpp \
    mainwindow.cpp \
    no.cpp

HEADERS += \
    llse.h \
    mainwindow.h \
    no.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ArquivosDeRecursos.qrc \
    teste.qrc

DISTFILES += \
    Arquivos/Imagem do WhatsApp de 2023-03-29 à(s) 09.35.58.jpg