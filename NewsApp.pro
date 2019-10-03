QT += quick
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/RequestBackend.cpp \
        src/RestHandle/CustomAPI.cpp \
        src/RestHandle/Response/Article.cpp \
        src/RestHandle/Response/Source.cpp \
        src/RestHandle/RestClient/RestClient.cpp \
        src/Application.cpp \
        src/Dispatcher.cpp \
        src/RestHandle/SourcesAPI.cpp \
        src/RestHandle/TrendingAPI.cpp \
        src/main.cpp

RESOURCES += qml.qrc \
    images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/RequestBackend.h \
    src/RestHandle/CustomAPI.h \
    src/RestHandle/Response/Article.h \
    src/RestHandle/Response/Source.h \
    src/RestHandle/RestClient/RestClient.h \
    src/Application.h \
    src/Dispatcher.h \
    src/RestHandle/SourcesAPI.h \
    src/RestHandle/TrendingAPI.h
