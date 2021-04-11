#ifndef MEDIAN_FILTER_PLUGIN_H
#define MEDIAN_FILTER_PLUGIN_H

#include "median_filter_plugin_global.h"
#include "cvplugininterface.h"

class MEDIAN_FILTER_PLUGIN_EXPORT median_filter_plugin:public QObject,public CVPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.mqm") // 添加插件的元数据
    Q_INTERFACES(CVPluginInterface) // 声明接口
public:
    median_filter_plugin();
    ~median_filter_plugin();
    QString description();
    void processImage(const cv::Mat &inputImage,cv::Mat &outputImage);
};

#endif // MEDIAN_FILTER_PLUGIN_H
