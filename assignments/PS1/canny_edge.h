/**
 * Author: Kapil Gupta <kpgupta98@gmail.com>
 * Organization: XantheLabs
 * Created: January 2017
 */

#ifndef CANNY_EDGE_H_
#define CANNY_EDGE_H_


#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <vector>
#include <string>


/**
 * Parameters for canny edge detector
 */

int edge_thresh = 1;
int low_threshold;
int const max_low_threshold = 100;
int ratio = 3;
int kernel_size = 3;
std::string window_name = "edge map";

void canny_threshold(cv::Mat &img_a_gray, cv::Mat &img_a_edges) {
  cv::namedWindow(window_name);
  
  blur(img_a_gray, img_a_edges, cv::Size(3, 3));
  Canny(img_a_edges, img_a_edges, low_threshold, low_threshold*ratio, kernel_size);

  cv::Mat mask;
  mask = cv::Scalar::all(0);

  img_a_gray.copyTo(mask, img_a_edges);
  cv::imshow(window_name, mask);
}
























#endif  // CANNY_EDGE_H_
