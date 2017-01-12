/**
 * Author: Kapil Gupta <kpgupta98@gmail.com>
 * Organization: XantheLabs
 * Created: January 2017
 */

#pragma once


#ifndef HOUGH_LINES_ACC_CU_
#define HOUGH_LINES_ACC_CU_

#define THETA_GRANULARITY		(4*100)
#define RHO_GRANULARITY     1

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <vector>
#include <math.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>

#include "../util.h"
#include "cuda_util.h"



bool hough_lines_acc(cv::Mat img_a_edges, std::vector<std::vector<int> > &hough_acc,\
   std::vector<double> &thetas, std::vector<double> &rhos, int rho_resolution, int theta_resolution) {





}






#endif  // HOUGH_LINES_ACC_CU_
