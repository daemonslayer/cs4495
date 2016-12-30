% Author: Kapil Gupta <kpgupta98@gmail.com>
% Organization: XantheLabs
% Created: December 2016


% Input images
img_a = imread('./input/lena.tiff');
img_b = imread('./input/leaves.png');

% imshow(img_a);
% imshow(img_b);

imwrite(img_a, './output/ps0-1-a-1.png');
imwrite(img_b, './output/ps0-1-a-2.png');



% Color Planes
img_a_red = img_a(:, :, 1);
img_a_green = img_a(:, :, 2);
img_a_blue = img_a(:, :, 3);

img_a(:, :, 1) = img_a_blue;
img_a(:, :, 3) = img_a_red;

% a. Swap the red and blue pixels of image 1
imwrite(img_a, './output/ps0-2-a-1.png');
% b. Create a monochrome image (img1_green) by selecting the green channel of image 1
imwrite(img_a_green, './output/ps0-2-b-1.png');
% c. Create a monochrome image (img1_red) by selecting the red channel of image 1
imwrite(img_a_red, './output/ps0-2-c-1.png');



% Replacement of pixels




% Arithmetic and Geometric operations




% Noise
