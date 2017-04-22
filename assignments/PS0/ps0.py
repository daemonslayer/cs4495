#!/usr/bin/env python
##
# Author: Kapil Gupta <kpgupta98@gmail.com>
# Organization: XantheLabs
# Created: April 2017
##

from __future__ import print_function
import cv2

print("[!] Problem Set 0")

win_name = "PS0"

##
## Input Images
##

img_a = cv2.imread("input/lena.tiff")
img_b = cv2.imread("input/leaves.png")

# cv2.imshow(win_name + " : A", img_a)
# cv2.imshow(win_name + " : B", img_b)

cv2.imwrite("output/ps0-1-a-1.png", img_a);
cv2.imwrite("output/ps0-1-a-2.png", img_b);



##
## Color Planes
##

blue, green, red = cv2.split(img_a)
img_a_swapped_planes = cv2.merge((red, blue, green))

cv2.imshow(win_name + " : C", img_a_swapped_planes)



##
## Replacement of Pixels
##



##
## Arithmetic & Geometric Operations
##



##
## Noise
##




k = cv2.waitKey(0)
if k == 27:         # wait for ESC key to exit
    cv2.destroyAllWindows()

elif k == ord('s'): # wait for 's' key to save and exit
    cv2.imwrite('messigray.png',img)
    cv2.destroyAllWindows()
