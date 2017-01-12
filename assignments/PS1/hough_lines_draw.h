/**
 * Author: Kapil Gupta <kpgupta98@gmail.com>
 * Organization: XantheLabs
 * Created: December 2016
 */

#pragma once


#ifndef HOUGH_LINES_DRAW_H_
#define HOUGH_LINES_DRAW_H_


#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <vector>
#include <string>


/**
 * [hough_lines_draw description]
 * @param img_a      [description]
 * @param output_img [description]
 * @param peaks      [description]
 * @param rho        [description]
 * @param theta      [description]
 */
void hough_lines_draw(cv::Mat *img_a, std::string output_img, int peaks, int rho, int theta) {

}



#endif  // HOUGH_LINES_DRAW_H_
