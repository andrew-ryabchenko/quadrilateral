#pragma once
#include "floatingPointComparison.h"

#ifndef lineType_H
#define lineType_H

//This class defines the instance of the line. Given the quotients of the
//equation of the line in standard form (ax + by = c) it analyzes the given line 
//and determines its slope and intercept. It also defines functionality such as 
//to determine if two lines are perpendicular or parallel. 

class lineType: public floatCompare {
	bool vertical, horizontal;
	double a, b, c, slope, intercept;
	void setSlope();
	void setIntercept();

public:
	lineType() {};
	lineType(double, double, double);
	double getSlope();
	double getIntercept();
	double geta();
	double getb();
	double getc();
	bool isVertical();
	bool isHorizontal();
	bool areParallel(lineType);
	bool arePerpendicular(lineType);
	bool areEqual(lineType);
	double interceptX(lineType);
	double interceptY(double);
};

#endif