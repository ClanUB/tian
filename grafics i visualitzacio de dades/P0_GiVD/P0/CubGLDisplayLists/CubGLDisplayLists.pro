#-------------------------------------------------
#
# Project created by QtCreator 2012-02-07T15:55:05
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = CubGLDisplayLists
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    cub.cpp \
    Common.cpp

HEADERS  += mainwindow.h \
    vec.h \
    mat.h \
    glwidget.h \
    cub.h \
    Common.h \
    CheckError.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    CubGLDisplayLists.pro.user



