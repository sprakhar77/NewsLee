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
        src/Backend/CustomBackend.cpp \
        src/Backend/SourcesBackend.cpp \
        src/Backend/TrendingBackend.cpp \
        src/Model/ArticleModel.cpp \
        src/Model/CheckableModel/CheckableItem.cpp \
        src/Model/CheckableModel/CheckableModel.cpp \
        src/Model/CheckableModel/CheckableModelFactory.cpp \
        src/Model/SourceModel.cpp \
        src/RestHandle/Request/CustomAPI.cpp \
        src/RestHandle/Response/Article.cpp \
        src/RestHandle/Response/Source.cpp \
        src/RestHandle/RestClient.cpp \
        src/Application.cpp \
        src/Dispatcher.cpp \
        src/RestHandle/Request/SourcesAPI.cpp \
        src/RestHandle/Request/TrendingAPI.cpp \
        src/Utils/Enums.cpp \
        src/main.cpp

RESOURCES += qml/qml.qrc \
    qml/images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/Backend/CustomBackend.h \
    src/Backend/SourcesBackend.h \
    src/Backend/TrendingBackend.h \
    src/Model/ArticleModel.h \
    src/Model/CheckableModel/CheckableItem.h \
    src/Model/CheckableModel/CheckableModel.h \
    src/Model/CheckableModel/CheckableModelFactory.h \
    src/Model/SourceModel.h \
    src/RestHandle/Request/CustomAPI.h \
    src/RestHandle/Response/Article.h \
    src/RestHandle/Response/Source.h \
    src/RestHandle/RestClient.h \
    src/Application.h \
    src/Dispatcher.h \
    src/RestHandle/Request/SourcesAPI.h \
    src/RestHandle/Request/TrendingAPI.h \
    src/Utils/Enums.h
