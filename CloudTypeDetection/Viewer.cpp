#include <opencv2/opencv.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\/highgui\highgui.hpp>

int menuoptions(char c, int index, std::vector <std::string> name, cv::Mat img, std::vector <cv::Mat> channels);

void WindowMaker(std::vector <std::string> name) {
	//create window
	cvNamedWindow("Cloud Type Detector", CV_WINDOW_AUTOSIZE);

	// set index and inital character to 0
	int index = 0;
	char c = 0;
	// create empty image
	cv::Mat img;
	std::vector <cv::Mat> channels(3);

	//cycle until exit has been hit
	while (c != 32) {
		// load the image and display in window
		img = cv::imread(name[index].c_str(), CV_LOAD_IMAGE_COLOR);
		cv::split(img, channels);
		cv::putText(img, name[index].c_str(), cvPoint(0, 20), CV_FONT_HERSHEY_COMPLEX, 0.5, cvScalarAll(255), 1, 8, false);
		cv::imshow("Cloud Type Detector", img);

		//wait on input key
		c = cvWaitKey(0);
		index = menuoptions(c, index, name, img, channels);
	}

	// destory the window
	cvDestroyAllWindows();
}

int menuoptions(char c, int index, std::vector <std::string> name, cv::Mat img, std::vector <cv::Mat> channels) {
		// file names wont be in the same order as they are in windows explorer
		switch (c) {
			// cycle left (a)
		case 97:
			if (index > 1) {
				index--;
			}
			else {
				index = name.size() - 1;
			}
			break;
			//or right (b)
		case 100:
			if (index < name.size() - 1) {
				index++;
			}
			else {
				index = 0;
			}
			break;
			//w for smoothing
		case 119:
			cv::Mat imgout;
			//cv::bilateralFilter(img, imgout, 20, 20, 20, 4);
			//cv::GaussianBlur(img, imgout, cv::Size(23, 23), 0, 0, 4);
			//kernel.adjustROI(1, 1, 1, 1);
			//cv::dilate(img, imgout, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size (10,10), cv::Point(-1, -1)));
			//cv::Mat test;
			//cv::erode(img, test, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(10, 10), cv::Point(-1, -1)));
			//img = imgout - test;
			//cv::pyrUp(img, imgout, cv::Size (img.cols*2,img.rows*2));
			//cv::Laplacian (img, imgout, img.depth(), 1,1.0,0.0, 4);
			//cv::Sobel(img, imgout, img.depth(), 0, 2, 3, 1.0, 0.0, 4);
			//cv::Canny(img, imgout, 255/3, 255, 3, false);
			//std::vector<std::vector<cv::Point> > contours;
			//cv::findContours(imgout,  contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
			//cv::drawContours(imgout, contours, -1, 0, 1, 8);
			cv::imshow("Cloud Type Detector", channels [0]);
			c = cvWaitKey(0);
			index = menuoptions(c, index, name, img, channels);
			break;
		}

		return index;
	}

