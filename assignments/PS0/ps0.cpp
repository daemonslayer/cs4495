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

using namespace std;
using namespace cv;


int main(int argc, char const *argv[]) {
  cout << "[!] Problem Set 0" << endl;
  string win_name = "PS0";
  Mat img_a;
  Mat img_b;


/**
 * Input Images
 */

  img_a = imread("../input/lena.tiff");
  img_b = imread("../input/leaves.png");

  if(!img_a.data || !img_b.data) {
    cout << "[-] Unable to open the images" << endl;
    return -1;
  }

  // namedWindow(win_name + "_a", CV_WINDOW_AUTOSIZE);
  // namedWindow(win_name + "_b", CV_WINDOW_AUTOSIZE);
  // imshow(win_name + "_a", img_a);
  // imshow(win_name + "_b", img_b);

  imwrite("../output/ps0-1-a-1.png", img_a);
  imwrite("../output/ps0-1-a-2.png", img_b);


/**
 * Color Planes
 */

  Mat img_a_color_planes[3];
  /**
   * blue: 0
   * green: 1
   * red: 2
   */
  split(img_a, img_a_color_planes);

  Mat img_a_swapped_planes[3];
  img_a_swapped_planes[0] = img_a_color_planes[2];
  img_a_swapped_planes[2] = img_a_color_planes[0];
  img_a_swapped_planes[1] = img_a_color_planes[1];

  merge(img_a_swapped_planes, 3, img_a);

  imwrite("../output/ps0-2-a-1.png", img_a);
  imwrite("../output/ps0-2-b-1.png", img_a_color_planes[1]);
  imwrite("../output/ps0-2-c-1.png", img_a_color_planes[2]);

/**
 * Replacement of pixels
 */

  // green is the better channel as red is too washed up (image_a has too much red content)
  // using green channel of image_a
  Mat img_b_color_planes[3];
  /**
   * blue: 0
   * green: 1
   * red: 2
   */
  split(img_b, img_b_color_planes);

  int img_a_centerx = img_a_color_planes[1].cols / 2;
  int img_a_centery = img_a_color_planes[1].rows / 2;
  int img_b_centery = img_b_color_planes[1].rows / 2;
  int img_b_centerx = img_b_color_planes[1].cols / 2;

  // In image_b, the red channel is the best
  // using red channel as the monochrome image_b
  Mat buff = img_b_color_planes[2].clone();
  img_a_color_planes[1](cv::Rect(img_a_centerx - 50, img_a_centery - 50, 100, 100)).copyTo(buff(cv::Rect(img_b_centerx - 50, img_b_centery - 50, 100, 100)));

  imwrite("../output/ps0-3-a-1.png", buff);

/**
 * Arithmetic and Geometric operations
 */

  double min;
  double max;
  Scalar mean;
  Scalar std_dev;

  minMaxLoc(img_a_color_planes[1], &min, &max);
  meanStdDev(img_a_color_planes[1], mean, std_dev);

  // cout << "[$] Minimum Pixel Value in green channel of img_a : " << min << endl;
  // cout << "[$] Maximum Pixel Value in green channel of img_a : " << max << endl;
  // cout << "[$] Mean Pixel Value in green channel of img_a : " << mean[0] << endl;
  // cout << "[$] Standard Deviation in Pixel Values in green channel of img_a : " << std_dev[0] << endl;

  Mat oper_b = img_a_color_planes[1].clone();

  absdiff(oper_b, mean[0], oper_b);
  divide(oper_b, std_dev[0], oper_b);
  multiply(oper_b, 10, oper_b);
  add(oper_b, mean, oper_b);

  imwrite("../output/ps0­-4­-b-­1.png", oper_b);

  // double transformation_mat[][3] = {
  //   { 1, 0, 2 },
  //   { 0, 1, 0 }
  // };
  // oper_c = warpAffine(&oper_c, &transformation_mat);

  Mat oper_c = Mat(img_a.size(), img_a_color_planes[1].type(), double(0));
  img_a_color_planes[1](cv::Rect(2, 0, oper_c.cols - 2, oper_c.rows)).copyTo(oper_c(cv::Rect(0, 0, oper_c.cols - 2, oper_c.rows)));
  imwrite("../output/ps0-4-c-1.png", oper_c);

  Mat oper_d = Mat(img_a.size(), img_a_color_planes[1].type(), double(0));
  subtract(img_a_color_planes[1], oper_c, oper_d);
  imwrite("../output/ps0-4-d-1.png", oper_d);
/**
 *  Noise
 */

  Mat img_a_noise_planes[3];
  img_a_noise_planes[0] = img_a_color_planes[0].clone();
  img_a_noise_planes[1] = img_a_color_planes[1].clone();
  img_a_noise_planes[2] = img_a_color_planes[2].clone();

  double Mean = 0.0;
  double StdDev = 10.0;
  Mat gauss_noise = Mat(img_a.size(), img_a_noise_planes[1].type());
  randn(gauss_noise, Scalar::all(Mean), Scalar::all(StdDev));

  addWeighted(gauss_noise, 1.0, img_a_noise_planes[1], 1.0, 1.0, img_a_noise_planes[1]);
  merge(img_a_noise_planes, 3, img_a);

  imwrite("../output/ps0-5-a-1.png", img_a);

  // img_a_noise_planes[0] = img_a_color_planes[0];
  // img_a_noise_planes[1] = img_a_color_planes[1];
  // img_a_noise_planes[2] = img_a_color_planes[2];

  addWeighted(gauss_noise, 1.0, img_a_noise_planes[0], 1.0, 1.0, img_a_noise_planes[0]);
  merge(img_a_noise_planes, 3, img_a);
  imwrite("../output/ps0-5-b-1.png", img_a);

  waitKey(0);
  return 0;
}
