#include "cameraInterface.h"

Colour CameraInterface::whatColour(pixel px){
    int maxPixelIndex=0;
    int index=0;
    for (int i:pxl){
        if(i>px[maxPixelIndex]){
            maxPixelIndex=index;
        }
    index++;
    }
    switch(maxPixelIndex){
        case 0: return BLUE; break;
        case 1: return GREEN; break;
        case 2: return RED; break;
    }
}

Colour CameraInterface::whatColour(cv::Mat mat){
    mat = cv::
}