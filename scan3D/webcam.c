#include "webcam.h"

#define RED 2
#define GREEN 1
#define BLUE 0


int pointNonDetecter = 0;

Position findGreenDot(CvCapture *camera){
	IplImage *image;
	image = cvQueryFrame(camera);
	Position point;

	CvPoint detected = searchFirstGreen(image);

	point.x = detected.x;
	point.y = detected.y;
	drawRectangle(image, point.x, point.y);
//	cvShowImage("ANAGRAMME",image);
 return point;
}

int drawRectangle(IplImage *image_, int x, int y){
	if(0 > x || x > HAUTEUR || 0 > y || y > LARGEUR){
		return 1;
	}

	CvArr *image = image_;
	CvPoint left_corner = cvPoint(x-5,y-5);
	CvPoint right_corner = cvPoint(x+5,y+5);

	cvRectangle(image, left_corner, right_corner, CV_RGB(10,255,10), 1, 8/*4*/, 0);

  return 0;
}

CvPoint searchFirstGreen(IplImage *image){
	CvScalar s;
	Max redDot;
	redDot.redIntensity = LUMINOSITE;
	redDot.coordinate = cvPoint(-1,-1);
	int ecartRed;
	for(int x = 0; x < image->width; x++){
		for(int y = 0; y < image->height; y++){
			s = cvGet2D(image,y,x);
			ecartRed = s.val[GREEN]/3 + s.val[RED]/3 + s.val[BLUE]/3;
/*			ecartRed = s.val[0];*/
			if(ecartRed > redDot.redIntensity){
				redDot.redIntensity = ecartRed;
				redDot.coordinate = cvPoint(x,y);
			}
		}
	}
	if(redDot.coordinate.x + redDot.coordinate.y < 0){
		pointNonDetecter++;
	}
  return redDot.coordinate;
}


