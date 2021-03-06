#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {

	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("C:/Users/HS/Desktop/1.jpg", 1);
	if (srcMat.empty()) return -1;

	cv::Point2f pts1[] = {
		cv::Point2f(150, 150),
		cv::Point2f(150, 300),
		cv::Point2f(350, 300),
		cv::Point2f(350, 150) };

	cv::Point2f pts2[] = {
		cv::Point2f(200, 150),
		cv::Point2f(200, 300),
		cv::Point2f(340, 270),
		cv::Point2f(340, 180) };

	cv::Mat perspective_matrix = cv::getPerspectiveTransform(pts1, pts2);

	cv::warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());

	cv::imshow("1", srcMat);
	cv::imshow("2", dstMat);
	cv::waitKey(0);
}