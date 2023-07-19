#include <array>
#include <vector>
#include "opencv2/imgproc.hpp"
#include "camera.h"
typedef std::array<int,3> Pixel; //OpenCV BGR pixel2
typedef std::pair<int,int> HueRange;
enum Colour {RED, YELLOW, GREEN, CYAN, BLUE, MAGENTA, UNDEFINED};
const HueRange RED_HUE_RANGE(330/2, 30/2);
const HueRange YELLOW_HUE_RANGE(30/2,90/2); //degrees on a scale 0-180
const HueRange GREEN_HUE_RANGE(90/2,150/2); //degrees on a scale 0-180
const HueRange CYAN_HUE_RANGE(150/2,210/2); //degrees on a scale 0-180
const HueRange BLUE_HUE_RANGE(210/2,270/2); //degrees on a scale 0-180
const HueRange MAGENTA_HUE_RANGE(270/2,330/2); //degrees on a scale 0-180
const std::vector <std::pair<Colour, HueRange>> HUES= {{RED,RED_HUE_RANGE}, 
                                                    {YELLOW, YELLOW_HUE_RANGE},
                                                    {GREEN, GREEN_HUE_RANGE},
                                                    {CYAN, CYAN_HUE_RANGE}, 
                                                    {BLUE, BLUE_HUE_RANGE}, 
                                                    {MAGENTA,MAGENTA_HUE_RANGE}};


class CameraInterface{
public:
// pixel RedThreshold = {75, 75, 195};
// pixel BlueThreshold ={170, 210, 70};

CameraInterface()= default;

Colour whatColour(Pixel);

Colour whatColour(cv::Mat);

Colour getHue(int); //"dumb" range-based binning of hue values

std::pair<bool, int> findFirst(std::vector <std::pair<Colour, int>>, Colour); //returns a) if value t is in vector v and b) its index

//std::pair<bool, int> findSecond(std::vector <std::pair <T, I>, I);
void printColour(Colour);
};
