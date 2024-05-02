#include "imgProc.h"
#include "window.h"


    // struct MyCallback : Libcam2OpenCV::Callback {
	// Window* window = nullptr;
	// virtual void hasFrame(const cv::Mat &frame, const libcamera::ControlList &) {
	//     if (nullptr != window) {
	// 	window->updateImage(frame);
	//     }
	// }
    // };


struct MyCallback : Libcam2OpenCV::Callback{
    Window* window = nullptr;

    cv::Mat cropLeft(cv::Mat mat){
        return mat;
    }

    cv::Mat cropRight(cv::Mat mat){
        return mat;
    }

    void hasFrame(const cv::Mat &frame, const libcamera::ControlList &){
        //featureparams (shi-tomasi corner detection) : these are fed to goodfeatures to track
        //lk params

        //crop frame x2: L/R

        //convert to grey
        cv::Mat frame_grey;
        cv::cvtColor(frame, frame_grey, cv::COLOR_BGR2GRAY);
       // cv::imshow("grey", mat_grey);

        //goodfeatures to track

        //while(image is there)
            //crop and convert to grey
            //calcopticlalflowpyrLK
        if (nullptr != window) {
		window->updateImage(frame);
	    }
    }
};

int main(){
    // int deviceID=0;
    // int apiID=0;
    // Camera camera;
    // CameraCallback cameraCallback;
    // camera.registerSceneCallback(&cameraCallback);
    // camera.start(deviceID, apiID);
    // do{
        
    // }while(!getchar());
    //     camera.stop();
    QApplication app(argc, argv);

        // create the window
    Window window;
    window.show();
}