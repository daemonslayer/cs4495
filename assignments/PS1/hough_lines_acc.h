/**
 * Author: Kapil Gupta <kpgupta98@gmail.com>
 * Organization: XantheLabs
 * Created: December 2016
 */

#pragma once


#ifndef HOUGH_LINES_ACC_H_
#define HOUGH_LINES_ACC_H_

#define THETA_GRANULARITY		(4*100)
#define RHO_GRANULARITY     1

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <vector>
#include <math.h>
#include "util.h"

/**
 * [hough_lines_acc ]
 * @param img_a_edges [image containing edge pixels]
 * @param hough_acc   [hough accumulator array]
 */
bool hough_lines_acc(cv::Mat img_a_edges, std::vector<std::vector<int> > &hough_acc) {
  int img_w = img_a_edges.cols;
  int img_h = img_a_edges.rows;

  int max_votes = 0;
  int min_votes = INT_MAX;

  for (size_t r = 0; r < img_h; r++) {
    for (size_t c = 0; c < img_w; c++) {
      if(true) {
        for (size_t angle = 0; angle < 180; angle++) {
          double theta = (angle * M_PI / 180);
          double rho = ( (c * cos(theta)) + (r * sin(theta)) );
          int buff = ++hough_acc[static_cast<int>(abs(rho))][static_cast<int>(theta)];

          if (buff > max_votes) {
            max_votes = buff;
          }
          if (buff < min_votes) {
            min_votes = buff;
          }
        }
      }
    }
  }

  double div = static_cast<double>(max_votes) / 255;
  int threshold = 10;
  int possible_edge = round(static_cast<double>(max_votes) / div) - threshold;

  cv::Mat img_mat = cv::Mat(hough_acc.size(), hough_acc[0].size(), CV_8UC1, cv::Scalar(0));

  for (size_t i = 0; i < hough_acc.size(); i++) {
    for (size_t j = 0; j < hough_acc[0].size(); j++) {
      img_mat.at<uint8_t> (i,j) = hough_acc[i][j];
    }
  }

  imwrite("../output/ps1-­2-­b-­1.png", img_mat);
  return true;
}



#endif  // HOUGH_LINES_ACC_H_
