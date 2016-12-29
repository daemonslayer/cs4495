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
  //
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


  waitKey(0);
  return 0;
}
