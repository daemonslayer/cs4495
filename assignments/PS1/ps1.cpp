/**
 * Author: Kapil Gupta <kpgupta98@gmail.com>
 * Organization: XantheLabs
 * Created: December 2016
 */

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>

#include "canny_edge.h"
#include "find_circles.h"
#include "hough_circles_acc.h"
#include "hough_lines_acc.h"
#include "hough_lines_draw.h"
#include "hough_peaks.h"

using namespace std;
using namespace cv;


int main(int argc, char const *argv[]) {
  title("Problem Set 1");
  string win_name = "PS1";
  Mat img_a;
  Mat img_b;

/**
 * Find Image Edges
 */
  img_a = imread("../input/ps1-input0.png");
  namedWindow(win_name + "_a", CV_WINDOW_AUTOSIZE);
  imshow(win_name + "_a", img_a);

  Mat img_a_gray;
  cvtColor(img_a, img_a_gray, CV_BGR2GRAY );
  stat_comp("color to gray");
  Mat img_a_edges = Mat(img_a.size(), img_a.type(), CV_32SC1);
  canny_threshold(img_a_gray, img_a_edges);
  stat_comp("edge detection");

  imwrite("../output/ps1-1-a-1.png", img_a_edges);

/**
 * Find Lines with Hough Transform
 */
  int col_l = img_a_edges.cols;
  int row_l = img_a_edges.rows;
  int dia_l = sqrt(pow(col_l, 2) + pow(row_l, 2));

  std::vector<std::vector<int> > hough_acc(dia_l, std::vector<int>(180, 0));
  std::vector<double> rhos;
  std::vector<double> thetas;

  for (int i = -dia_l; i < dia_l; i++) {
    rhos.push_back(i);
  }
  for (int i = -90; i < 90; i++) {
    double buff = (i * M_PI / 180);
    thetas.push_back(buff);
  }

  int rho_resolution = 1;
  int theta_resolution = 1;

  if (hough_lines_acc(img_a_edges, hough_acc, thetas, rhos, rho_resolution, theta_resolution)) {
    stat_comp("hough lines");
  }

  waitKey(0);
  return 0;
}
