/**
 * Author: Kapil Gupta <kpgupta98@gmail.com>
 * Organization: XantheLabs
 * Created: December 2016
 */

#pragma once


#ifndef HOUGH_PEAKS_H_
#define HOUGH_PEAKS_H_


#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <vector>
#include "util.h"


bool hough_peaks(std::vector<std::vector<int> > &hough_acc, std::vector<std::vector<int> > &peaks, int lines_detected) {
  for (size_t i = 0; i < lines_detected; i++) {
    
  }
  return true;
}


#endif  // HOUGH_PEAKS_H_
