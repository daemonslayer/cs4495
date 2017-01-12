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
 * @brief      { function_description }
 *
 * @param[in]  img_a_edges       The image a edges
 * @param      hough_acc         The hough acc
 * @param      thetas            The thetas
 * @param      rhos              The rhos
 * @param[in]  rho_resolution    The rho resolution
 * @param[in]  theta_resolution  The theta resolution
 *
 * @return     { description_of_the_return_value }
 */
bool hough_lines_acc(cv::Mat img_a_edges, std::vector<std::vector<int> > &hough_acc, \
   std::vector<double> &thetas, std::vector<double> &rhos, int rho_resolution, int theta_resolution) {
  int img_w = img_a_edges.cols;
  int img_h = img_a_edges.rows;
  int img_dia = static_cast<int>(ceil(sqrt(pow(img_w, 2) + pow(img_h, 2))));

  int max_votes = 0;
  int min_votes = INT_MAX;

  for (size_t r = 0; r < img_h; r++) {
    for (size_t c = 0; c < img_w; c++) {
      if(img_a_edges.at<int>(r, c) > 0) {
        for (size_t i = 0; i < thetas.size(); i++) {
          double rho = ( (c * cos(thetas[i])) + (r * sin(thetas[i])) + img_dia);
          int buff = ++hough_acc[static_cast<int>(rho)][static_cast<int>(i)];

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

  props({
    {"max votes", max_votes},
    {"min votes", min_votes},
    {"scale", div}
  });

  cv::Mat img_mat = cv::Mat(hough_acc.size(), hough_acc[0].size(), CV_8UC1, cv::Scalar(0));

  for (size_t i = 0; i < hough_acc.size(); i++) {
    for (size_t j = 0; j < hough_acc[0].size(); j++) {
      img_mat.at<uint8_t> (i,j) = static_cast<uint8_t>(hough_acc[i][j]);
    }
  }
  // scale the intensity values to get better observations
  // equalizeHist(img_mat, img_mat);

  imwrite("../output/ps1-­2-­a-­1.png", img_mat);
  return true;
}



#endif  // HOUGH_LINES_ACC_H_
