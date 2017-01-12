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
 * @brief      { function_description }
 *
 * @param[in]  img_a       The image a
 * @param[in]  output_img  The output image
 * @param      indicies    The indicies
 *
 * @return     { description_of_the_return_value }
 */
bool hough_lines_draw(cv::Mat img_a, std::string output_img, std::vector<std::vector<int> > &indicies) {
	std::vector<int> x(3);
	std::vector<int> y(3);
	double rho;
	double theta;

	int thickness = 2;
	int linetype = cv::LINE_8;
	int shift = 0;
	for (int i = 0; i < indicies.size(); ++i) {
		rho = indicies[i][0];
		theta = indicies[i][1];
		double c_theta = cos(theta);
		double s_theta = sin(theta);
		x[0] = static_cast<int> (rho * c_theta);
		y[0] = static_cast<int> (rho * s_theta);
		x[1] = static_cast<int> (x[0] + (1000 * (-c_theta)));
		y[1] = static_cast<int> (y[0] + (1000 * s_theta));
		x[2] = static_cast<int> (x[0] - (1000 * (-c_theta)));
		y[2] = static_cast<int> (y[0] - (1000 * s_theta));
		cv::line(img_a, cv::Point(x[1], y[1]), cv::Point(x[2], y[2]), cv::Scalar(0, 255, 0), thickness, linetype, shift);
	}

  imwrite("../output/" + output_img, img_a);

	return true;
}



#endif  // HOUGH_LINES_DRAW_H_
