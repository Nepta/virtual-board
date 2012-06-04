#ifndef __webcam_H__
#define __webcam_H__


#include <cv.h>
#include <highgui.h>
#include "sync.h"

int drawRectangle(IplImage *image_, int x, int y);
CvPoint searchFirstGreen(IplImage *image);
Position findGreenDot(CvCapture *camera);

typedef struct{
	long redIntensity;
	CvPoint coordinate;
} Max;

#endif /* __webcam_H__ */

