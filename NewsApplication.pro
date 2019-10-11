# allows to add DEPLOYMENTFOLDERS and links to the Felgo library and QtCreator auto-completion
CONFIG += felgo
CONFIG += felgo-live

# uncomment this line to add the Live Client Module and use live reloading with your custom C++ code
# for the remaining steps to build a custom Live Code Reload app see here: https://felgo.com/custom-code-reload-app/
# CONFIG += felgo-live

# Project identifier and version
# More information: https://felgo.com/doc/felgo-publishing/#project-configuration
PRODUCT_IDENTIFIER = com.yourcompany.wizardEVAP.NewsApplication
PRODUCT_VERSION_NAME = 1.0.0
PRODUCT_VERSION_CODE = 1

# Optionally set a license key that is used instead of the license key from
# main.qml file (App::licenseKey for your app or GameWindow::licenseKey for your game)
# Only used for local builds and Felgo Cloud Builds (https://felgo.com/cloud-builds)
# Not used if using Felgo Live
PRODUCT_LICENSE_KEY = ""

qmlFolder.source = src/qml
DEPLOYMENTFOLDERS += qmlFolder # comment for publishing

assetsFolder.source = resources/assets
DEPLOYMENTFOLDERS += assetsFolder

# Add more folders to ship with the application here

RESOURCES += #    resources/resources.qrc # uncomment for publishing

# NOTE: for PUBLISHING, perform the following steps:
# 1. comment the DEPLOYMENTFOLDERS += qmlFolder line above, to avoid shipping your qml files with the application (instead they get compiled to the app binary)
# 2. uncomment the resources.qrc file inclusion and add any qml subfolders to the .qrc file; this compiles your qml files and js files to the app binary and protects your source code
# 3. change the setMainQmlFile() call in main.cpp to the one starting with "qrc:/" - this loads the qml files from the resources
# for more details see the "Deployment Guides" in the Felgo Documentation

# during development, use the qmlFolder deployment because you then get shorter compilation times (the qml files do not need to be compiled to the binary but are just copied)
# also, for quickest deployment on Desktop disable the "Shadow Build" option in Projects/Builds - you can then select "Run Without Deployment" from the Build menu in Qt Creator if you only changed QML files; this speeds up application start, because your app is not copied & re-compiled but just re-interpreted


# The .cpp file which was generated for your project. Feel free to hack it.
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


android {
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
    OTHER_FILES += resources/android/AndroidManifest.xml       android/build.gradle
}

ios {
    QMAKE_INFO_PLIST = resources/ios/Project-Info.plist
    OTHER_FILES += $$QMAKE_INFO_PLIST
}

# set application icons for win and macx
win32 {
    RC_FILE += resources/win/app_icon.rc
}
macx {
    ICON = resources/macx/app_icon.icns
}

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

DISTFILES += \
    src/qml/Custom/Custom.qml \
    src/qml/Trending/Trending.qml \
    src/qml/Sources/Sources.qml \
    src/qml/Sources/Category.qml \
    src/qml/Sources/Language.qml \
    src/qml/Sources/Information.qml \
    src/qml/Trending/SelectionToolbar.qml \
    src/qml/Custom/SelectionToolbar.qml
