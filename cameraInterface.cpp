#include "cameraInterface.h"

Colour CameraInterface::whatColour(Pixel px){
    int maxPixelIndex=0;
    int index=0;
    Colour result = UNDEFINED;
    for (int i:px){
        if(i>px[maxPixelIndex]){
            maxPixelIndex=index;
        }
    index++;
    }
    switch(maxPixelIndex){
        case 0: result= BLUE; break;
        case 1: result= GREEN; break;
        case 2: result= RED; break;
        default:break;
    }
    return result;
}

Colour CameraInterface::whatColour(cv::Mat src){
    cv::Mat mat, matSplit[3];
    cv::cvtColor(src, mat, cv::COLOR_BGR2HSV); //convert to HSV pixel format, range 0-180
//    cv::split(mat, matSplit);
    std::vector <std::pair<Colour, int>> coloursPoints;
    Colour colour;
    for (auto p: HUES){ //make vector;
        coloursPoints.push_back(std::pair<Colour, int>(p.first, 0));
    }
    for (int r=0; r<mat.rows; r++){
        for (int c=0; c<mat.cols; c++){
            cv::Vec3f pixel =mat.at<cv::Vec3f>(r, c);
            int hue = pixel[0];
            Colour hueName = getHue(hue);
            std::pair <bool, int> huePair= findFirst(coloursPoints, hueName); //find index of that colour in the vector
            if (huePair.first){
                coloursPoints[huePair.second].second++; //assign a point to that colour in the vector
            }
        }
    }
    int bestScore = coloursPoints[0].second;
    for (auto p:coloursPoints){ //find colour with the highest score
        if (p.second>bestScore){
            bestScore=p.second;
            colour= p.first;
        }
    }
    return colour;
}

Colour CameraInterface::getHue (int hue){
    Colour result = UNDEFINED;
    if (hue<0){
        hue+=180;
    }
    for (std::pair<Colour, HueRange> p: HUES){
        if (hue>p.second.first & hue<=p.second.second){
            result = p.first;
        }
    }
    return result;
}

std::pair<bool, int> CameraInterface::findFirst(std::vector <std::pair<Colour, int>>v, Colour t){
    std::pair <bool, int>result(false, 0);
    for (result.second=0;result.second<v.size();result.second++){
        if (v[result.second].first ==t){
            result.first=true;
            break;
        }
    }
    return result;
}

void CameraInterface::printColour(Colour c){
    switch (c){
        case RED: printf("RED\n"); break;
        case YELLOW: printf("YELLOW\n"); break;
        case GREEN: printf("GREEN\n"); break;
        case CYAN: printf("CYAN\n"); break;
        case BLUE: printf("BLUE\n"); break;
        case MAGENTA: printf("MAGENTA\n"); break;
        default: printf("NO COLOUR DETECTED\n"); break;
    }
}