#ifndef CVPLUGININTERFACE_H
#define CVPLUGININTERFACE_H

#include <QString>
#include <QObject>
#include "opencv2/opencv.hpp"

class CVPluginInterface{
public:
    virtual ~CVPluginInterface(){}
    virtual QString description() =0;
    virtual void processImage(const cv::Mat &inputImage,cv::Mat &outputImage) = 0;
};

#define CVPLUGININTERFACE_IID "com.mqm"

// 将类定义为接口
Q_DECLARE_INTERFACE(CVPluginInterface,CVPLUGININTERFACE_IID)

#endif // CVPLUGININTERFACE_H
