#include "floatingPointComparison.h"
#include <float.h>
#include <math.h>

bool floatCompare::areEqualValues(double a, double b) {
	//If both absolute values of 'a' and 'b' are less then FLT_EPSILON 
	//they considered to be equal in context of the this class
	if ((fabs(a) <= FLT_EPSILON) && (fabs(b) <= FLT_EPSILON)) {
		return true;
	} 

	double adiff = fabs(a - b);

	if (adiff <= FLT_EPSILON) {
		return true;
	}
	else {
		return false;
	}
}