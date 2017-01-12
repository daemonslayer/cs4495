/**
 * Author: Kapil Gupta <kpgupta98@gmail.com>
 * Organization: XantheLabs
 * Created: December 2016
 */

#pragma once


#ifndef HOUGH_PEAKS_H_
#define HOUGH_PEAKS_H_


#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cstdint>
#include <algorithm>
#include <limits>
#include <vector>
#include "util.h"

typedef struct{
  int value;
  int row;
  int col;
} Pix;


/**
 * @brief      { function_description }
 *
 * @param      hough_acc         The hough acc
 * @param      indicies          The indicies
 * @param[in]  n_lines_detected  The n lines detected
 *
 * @return     { description_of_the_return_value }
 */
bool hough_peaks(std::vector<std::vector<int> > &hough_acc, std::vector<std::vector<int> > &indicies, int n_lines_detected) {
  std::vector<std::vector<int> > peaks(hough_acc.size(), std::vector<int> (hough_acc[0].size(), 0));
  peaks = hough_acc;
  std::vector<Pix> peak_val(n_lines_detected, {0, 0, 0});
  Pix max_buf = {0, 0, 0};
  for (size_t n = 0; n < n_lines_detected; n++) {
    for (size_t r = 0; r < peaks.size(); r++) {
      for (size_t c = 0; c < peaks[0].size(); c++) {
        if(peaks[r][c] > 0) {
          if(max_buf.value < peaks[r][c]) {
            max_buf.value = peaks[r][c];
            max_buf.row = r;
            max_buf.col = c;
          }
        }
      }
    }
    peak_val[n] = max_buf;
    peaks[max_buf.row][max_buf.col] = std::numeric_limits<int>::min();
    max_buf = {0, 0, 0};
  }

  peaks = hough_acc;
  cv::Mat img_mat = cv::Mat(peaks.size(), peaks[0].size(), CV_8UC1, cv::Scalar(0));

  for (size_t i = 0; i < peaks.size(); i++) {
    for (size_t j = 0; j < peaks[0].size(); j++) {
      img_mat.at<uint8_t> (i,j) = static_cast<uint8_t>(peaks[i][j]);
    }
  }

  // scale the intensity values to get better observations
  // equalizeHist(img_mat, img_mat);

  for (int i = 0; i < n_lines_detected; ++i) {
    indicies[i][0] = peak_val[i].row;
    indicies[i][1] = peak_val[i].col;
  }

  int radius = 18;
  int thickness = 1;
  int linetype = cv::LINE_8;
  int shift = 0;
  for (size_t i = 0; i < n_lines_detected; i++) {
    cv::circle(img_mat, cv::Point(peak_val[i].col, peak_val[i].row), radius, cv::Scalar(255, 255, 255), thickness, linetype, shift);
  }

  imwrite("../output/ps1-­2-b-­1.png", img_mat);

  return true;
}


#endif  // HOUGH_PEAKS_H_
