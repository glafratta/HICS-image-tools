#include "libcam2opencv.h"

class ImgProc{
    public:
    ImgProc(){}

    void opticFlow(const cv::Mat&);

    private:
    cv::Mat prev_grey;
};