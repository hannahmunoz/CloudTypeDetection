#include <opencv2/opencv.hpp>
#include <opencv/highgui.h>

void WindowMaker(std::vector <std::string> name) {
	//create window
	cvNamedWindow("Cloud Type Detector", CV_WINDOW_NORMAL);
	cvResizeWindow("Cloud Type Detector", 500, 500);

	// set index and inital character to 0
	int index = 0;
	char c = 0;
	// create empty image
	IplImage* img;

	//cycle until exit has been hit
	while (c != 32 ) {
		// load the image and display in window
		img = cvLoadImage(name[index].c_str());
		cvShowImage("Cloud Type Detector", img);

		//wait on input key
		c = cvWaitKey(0);

		// cycle left (a) or right (b)
		// file names wont be in the same order as they are in windows explorer
		switch (c) {
			case 97:
				if (index > 1) {
					index--;
				}
				else {
					index = name.size()-1;
				}
			break;
			case 100:
				if (index < name.size()-1) {
					index++;
				}
				else {
					index = 0;
				}
			break;
		}
	}

	// release the image memory
	cvReleaseImage(&img);
	// destory the window
	cvDestroyAllWindows();
}
