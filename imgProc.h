#include "libcam2opencv.h"
#include <libcamera/libcamera.h>
#include <unistd.h>
class ImgProc{
    public:
    ImgProc(){}

    void opticFlow(const cv::Mat&);

    private:
    cv::Mat prev_grey;
};