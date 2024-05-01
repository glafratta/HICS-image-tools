#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "cameraInterface.h"
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

struct CameraCallback:Camera::SceneCallback{
    CameraInterface cameraInterface;

    cv::Mat cropLeft(cv::Mat mat){
        return mat;
    }

    cv::Mat cropRight(cv::Mat mat){
        return mat;
    }

    void nextScene(const cv::Mat & mat){
        //featureparams (shi-tomasi corner detection) : these are fed to goodfeatures to track

        //lk params

        //crop frame x2: L/R

        //convert to grey
        cv::Mat mat_grey;
        cv::cvtColor(mat, mat_grey, cv::COLOR_BGR2GRAY);
        cv::imshow("grey", mat_grey);

        //goodfeatures to track

        //while(image is there)
            //crop and convert to grey
            //calcopticlalflowpyrLK
    }
};

int main(){
    int deviceID=0;
    int apiID=0;
    Camera camera;
    CameraCallback cameraCallback;
    camera.registerSceneCallback(&cameraCallback);
    camera.start(deviceID, apiID);
    do{
        
    }while(!getchar());
        camera.stop();
}