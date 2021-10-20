#pragma once
#include "lineType.h"
#include <string>
using namespace std;

#ifndef shape_H
#define shape_H

//This class defines an instance of the shape and outputs the type of that shape.
//Internally it uses lineType class to determine the type of quarilateral by following 
//the definitions below.

//A rhombus is a quadrilateral 
//whose four sides all have the same length.Another name is 
//equilateral quadrilateral, since equilateral means that all 
//of its sides are equal in length.

//A trapezium is a quadliteral with at lease one pair
//of parallel sides.

//A parallelogram is a simple quadrilateral with two pairs 
//of parallel sides.The opposite or facing sides of a parallelogram 
//are of equal length and the opposite angles of a parallelogram are 
//of equal measure.

//d = sqrt[(x2 – x1)^2 + (y2 – y1)^2]

struct line {
	double a, b, c;
};

class shape {
	double side_a, side_b, side_c, side_d; //Side lenghts
	lineType a, b, c, d; //lineType objects bounding the shape
	string shapeType;
	void setSideLenghts();
	void determineShapeType();
	double angle(lineType, lineType); //Determines angle between two lines
	double distance(double, double, double, double); //Euclidian distance between two points
public:
	shape(line coordinates[]);
	void printName();
};

#endif
