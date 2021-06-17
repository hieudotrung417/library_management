QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    book.cpp \
    bookio.cpp \
    dialogaddbook.cpp \
    dialogadduser.cpp \
    dialogcreateadminaccount.cpp \
    dialoglogin.cpp \
    librarian.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindowclient.cpp \
    transaction.cpp \
    transactionio.cpp \
    user.cpp \
    userio.cpp

HEADERS += \
    book.h \
    bookio.h \
    common.h \
    dialogaddbook.h \
    dialogadduser.h \
    dialogcreateadminaccount.h \
    dialoglogin.h \
    librarian.h \
    mainwindow.h \
    mainwindowclient.h \
    transaction.h \
    transactionio.h \
    user.h \
    userio.h

FORMS += \
    dialogaddbook.ui \
    dialogadduser.ui \
    dialogcreateadminaccount.ui \
    dialoglogin.ui \
    mainwindow.ui \
    mainwindowclient.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
