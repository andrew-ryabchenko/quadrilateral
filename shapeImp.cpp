#include "shape.h"
#include "floatingPointComparison.h"
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

shape::shape(line coordinates[]) {
	lineType a_a(coordinates[0].a, coordinates[0].b, coordinates[0].c);
	a = a_a;
	lineType b_b(coordinates[1].a, coordinates[1].b, coordinates[1].c);
	b = b_b;
	lineType c_c(coordinates[2].a, coordinates[2].b, coordinates[2].c);
	c = c_c;
	lineType d_d(coordinates[3].a, coordinates[3].b, coordinates[3].c);
	d = d_d;
	setSideLenghts();
	determineShapeType();
}

void shape::printName() {
	cout << shapeType << endl;
}
void shape::determineShapeType() {
	if (a.areParallel(b) && c.areParallel(d)) {
		//One of rectangle, square, rhombus or paralellogram
		double angle1 = angle(a, c);
		double angle2 = angle(b, d);
		if (floatCompare::areEqualValues(angle1, 90.0) && floatCompare::areEqualValues(angle2, 90.0)) {
			//Square or rectangle
			if (floatCompare::areEqualValues(side_a, side_b) && floatCompare::areEqualValues(side_a, side_c) && floatCompare::areEqualValues(side_a, side_d) && floatCompare::areEqualValues(side_b, side_c) && floatCompare::areEqualValues(side_b, side_d) && floatCompare::areEqualValues(side_c, side_d)) {
				//All sides are equal
				shapeType = "square";
			}
			else {
				shapeType = "rectangle";
			}
		}
		//Not a square or rectangle
		else if (floatCompare::areEqualValues(side_a, side_b) && floatCompare::areEqualValues(side_a, side_c) && floatCompare::areEqualValues(side_a, side_d) && floatCompare::areEqualValues(side_b, side_c) && floatCompare::areEqualValues(side_b, side_d) && floatCompare::areEqualValues(side_c, side_d)) {
			//All sides are equal
			//Rhombus
			shapeType = "rhombus";
		}
		else {
			//Paralellogram
			shapeType = "paralellogram";
		}
	}
	//Only a two sides are parallel
	else if (a.areParallel(b) ^ c.areParallel(d)) {
		//Trapezoid
		shapeType = "trapezoid";
	}
	//Any other case of quadrilateral
	else {
		//Undefined quadrilateral
		shapeType = "undefined";
	}
}

void shape::setSideLenghts() {
	//Variable names of format 'abc', where a = line1, b = line2, c = x or y coordinate.

	double acx = a.interceptX(c);
	double acy = a.interceptY(acx);
	double adx = a.interceptX(d);
	double ady = a.interceptY(adx);
	side_a = distance(acx, adx, acy, ady);

	double bcx = b.interceptX(c);
	double bcy = b.interceptY(acx);
	double bdx = b.interceptX(d);
	double bdy = b.interceptY(adx);
	side_b = distance(bcx, bdx, bcy, bdy);

	double cax = c.interceptX(a);
	double cay = c.interceptY(cax);
	double cbx = c.interceptX(b);
	double cby = c.interceptY(cbx);
	side_c = distance(cax, cbx, cay, cby);

	double dax = d.interceptX(a);
	double day = d.interceptY(dax);
	double dbx = d.interceptX(b);
	double dby = d.interceptY(dbx);
	side_d = distance(cax, cbx, cay, cby);
}

double shape::distance(double x1, double x2, double y1, double y2) {
	//d = sqrt[(x2 – x1)^2 + (y2 – y1)^2]
	double expr = pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0);
	double distance = sqrt(expr);
	return distance;

}

double shape::angle(lineType a, lineType b) {
	//Angle between two lines is defined as arctan[(slope2 - slope1)/(1+slope2*slope1)]
	//Special cases are when one line is vertical and other is not horizontal
	if ((a.isVertical() && b.isHorizontal()) || (b.isVertical() && a.isHorizontal())) {
		return 90.0;
	}
	else if (a.isVertical() || b.isVertical()) {
		//Special case
	}
	else {
		//Standard case
		double slope1 = a.getSlope();
		double slope2 = b.getSlope();
		return atan((slope2 - slope1) / (1.0 + slope2 * slope1));
	}
}