#include "imgProc.h"
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

void ImgProc::opticFlow(cv::Mat& curr){
    cv::Mat curr_grey;
    cv::cvtColor(curr, curr_grey, cv::COLOR_BGR2GRAY);
    prev_grey=curr_grey;
}
