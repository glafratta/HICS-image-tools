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

Colour CameraInterface::whatColour(cv::Mat src){
    cv::Mat mat[3];
    cv::cvtColour(src, src, COLOR_BGR2HSV); //convert to HSV pixel format, range 0-180
    cv::split(src, mat);
    for (int r=0; r<mat.rows; r++){
        for (int c=0; c<mat.cols; c++){
            
        }
    }
}