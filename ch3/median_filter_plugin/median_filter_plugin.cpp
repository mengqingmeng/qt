#include "median_filter_plugin.h"

median_filter_plugin::median_filter_plugin()
{
}

QString median_filter_plugin::description(){
    return "this plugin applies median blur filters to any image.";
}

void median_filter_plugin::processImage(const cv::Mat &inputImage, cv::Mat &outputImage){
    cv::medianBlur(inputImage,outputImage,5);
}
