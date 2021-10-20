#pragma once
#ifndef floatingPointComparison_H
#define floatingPointComparison_H

//Compares two floating point values for equality by comparing them to the epsilon.

class floatCompare {
public:
	static bool areEqualValues(double, double);
};

#endif