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
int low_threshold = 100;
int const max_low_threshold = 100;
int ratio = 2;
int kernel_size = 5;
std::string window_name = "edge map";


/**
 * [canny_threshold description]
 * @param img_a_gray  [description]
 * @param img_a_edges [description]
 */
void canny_threshold(cv::Mat &img_a_gray, cv::Mat &img_a_edges) {
  cv::Mat mask;
  img_a_edges = cv::Scalar::all(0);

  blur(img_a_gray, mask, cv::Size(3, 3));
  Canny(img_a_gray, img_a_edges, low_threshold, low_threshold*ratio, kernel_size);

  cv::namedWindow(window_name);
  cv::imshow(window_name, img_a_edges);
}



#endif  // CANNY_EDGE_H_
