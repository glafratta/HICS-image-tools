#include <stdlib.h>
#include <array>
#include <opencv2/opencv.hpp>

//#include "camera.h"

typedef std::array<int,3> Pixel; //OpenCV BGR pixel
enum Colour {RED, GREEN, BLUE};

 class CameraInterface{
// pixel RedThreshold = {75, 75, 195};
// pixel BlueThreshold ={170, 210, 70};

CameraInterface()= default;

Colour whatColour(Pixel);

Colour whatColour(cv::Mat);


};
