QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bdd.cpp \
    fenetre_login.cpp \
    gestionnaire_password.cpp \
    main.cpp \
    master_password_creation.cpp \
    openwall_crypt/crypt_blowfish.c \
    openwall_crypt/crypt_gensalt.c \
    openwall_crypt/wrapper.c \
    qtbcrypt.cpp

HEADERS += \
    bdd.h \
    fenetre_login.h \
    gestionnaire_password.h \
    master_password_creation.h \
    openwall_crypt/crypt_blowfish.h \
    openwall_crypt/crypt_gensalt.h \
    openwall_crypt/ow-crypt.h \
    qtbcrypt.h

FORMS += \
    fenetre_login.ui \
    gestionnaire_password.ui \
    master_password_creation.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    fonts.qrc
