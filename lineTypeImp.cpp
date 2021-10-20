#include "lineType.h"
#include "floatingPointComparison.h"

lineType::lineType(double a_value, double b_value, double c_value) {
	a = a_value;
	b = b_value;
	c = c_value;
	setSlope();
	setIntercept();
}

void lineType::setSlope() {
	if (b != 0) {
		slope = a / b;
		if (areEqualValues(slope, 0.0)) { 
			vertical = false;
			horizontal = true;
		}
		else {
			vertical = false;
			horizontal = false;
		}
	}
	else {
		vertical = true;
		horizontal = false;
	}
}

void lineType::setIntercept() {
	if (vertical) {
		intercept = c / a; //x-intercept
	}
	else {
		intercept = c / b; //y-intercept
	}
}

double lineType::geta() {
	return a;
}

double lineType::getb() {
	return b;
}

double lineType::getc() {
	return c;
}

bool lineType::isVertical() {
	return vertical;
}

bool lineType::isHorizontal() {
	return horizontal;
}

double lineType::getSlope() {
	return slope;
}

double lineType::getIntercept() {
	return intercept;
}

bool lineType::areParallel(lineType line) {
	if ((vertical && line.isVertical()) || (horizontal && line.isHorizontal())) {
		//Both lines are either vertical or horizontal
		return true;
	}
	else {
		if (!vertical && !line.isVertical()) {
			//Make sure that slopes are defined before comparison.
			//Compare slopes for equality.
			if (areEqualValues(slope, line.getSlope())) { 
				return true;
			}
			else {
				return false;
			}
		}
		else {
			//One of the lines is vertical and other is not
			return false;
		}
	}
}

bool lineType::arePerpendicular(lineType line) {
	if (vertical) {
		if (line.isHorizontal()) {
			return true;
		}
		else {
			return false;
		}
	}
	else if (line.isVertical()) {
		if (horizontal) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return (areEqualValues(slope, -line.getSlope()));
	}
}

bool lineType::areEqual(lineType line) {

	double k_a, k_b, k_c; //Solve for constant 'k'
	k_a = a / line.geta();
	k_b = b / line.getb();
	k_c = c / line.getc();

	if ((areEqualValues(k_a, k_b)) && (areEqualValues(k_a, k_c)) && (areEqualValues(k_c, k_b))) { 
		return true;
	}
	else {
		return false;
	}
}

double lineType::interceptX(lineType line)
{
	if (!vertical && !line.isVertical()) { //Standard case;
		double a_1 = line.geta(), b_1 = line.getb(), c_1 = line.getc();
		double x = (c / b - c_1 / b_1) / (a / b - a_1 / b_1);
		return x;
	}
	else if (vertical) {
		return intercept;
	}
	else {
		return line.getIntercept();
	}
}

double lineType::interceptY(double x)
{
	double y = (c - a * x) / b;
	return y;
}
