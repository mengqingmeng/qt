QT -= gui

TEMPLATE = lib
CONFIG += plugin
DEFINES += MEDIAN_FILTER_PLUGIN_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    median_filter_plugin.cpp

HEADERS += \
    cvplugininterface.h \
    median_filter_plugin_global.h \
    median_filter_plugin.h

# Default rules for deployment.

!isEmpty(target.path): INSTALLS += target

unix: macx {
    INCLUDEPATH+="/usr/local/include/opencv4"
    INCLUDEPATH+="/usr/local/include/opencv4/opencv2"
    LIBS += -L/usr/local/lib -lopencv_imgproc -lopencv_core
}
