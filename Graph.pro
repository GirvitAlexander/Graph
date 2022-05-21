QT     += core gui
QT     += gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Use Precompiled headers (PCH)
PRECOMPILED_HEADER  = pch.h

SOURCES += \
    Actions/AddGraphs/addgraphdialog.cpp \
    Actions/AddGraphs/addgraphdialogerased.cpp \
    Actions/Axes/signaxesdialog.cpp \
    GraphsWidget/graphsplace.cpp \
    html.cpp \
    main.cpp \
    mainwindow/mainwindow.cpp

HEADERS += \
    Actions/AddGraphs/addgraphdialog.h \
    Actions/AddGraphs/addgraphdialogerased.h \
    Actions/Axes/signaxesdialog.h \
    GraphsWidget/graphsplace.h \
    html.h \
    mainwindow/mainwindow.h \
    pch.h

FORMS += \
    Actions/AddGraphs/addgraphdialog.ui \
    Actions/AddGraphs/addgraphdialogerased.ui \
    Actions/Axes/signaxesdialog.ui \
    GraphsWidget/graphsplace.ui \
    html.ui \
    mainwindow/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources/icons.qrc
