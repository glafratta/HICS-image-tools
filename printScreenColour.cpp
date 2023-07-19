#include "cameraInterface.h"
#include <stdlib.h>
struct CameraCallback:Camera::SceneCallback{
    CameraInterface cameraInterface;
    void nextScene(const cv::Mat&mat){
        Colour colour =cameraInterface.whatColour(mat);
        cameraInterface.printColour(colour);
    }
};

int main(int argc, char** argv){
    int deviceID=0;
    int apiID=0;
    if (argc>1){
        deviceID = atoi(argv[1]);
    }
    if (argc>2){
        apiID = atoi(argv[2]);
    }
    printf("deviceID =%i API = %i\n", deviceID, apiID);
    Camera camera;
    CameraCallback cameraCallback;
    camera.registerSceneCallback(&cameraCallback);
    camera.start(deviceID, apiID);
    do {
    }while(getchar());
    camera.stop();
}