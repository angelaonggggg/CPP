#ifndef CIRCLE_H
#define CIRCLE_H
#include "ShapeTwoD.h"

using namespace std;

class Circle : public ShapeTwoD
{
	private:
	    // private variables
		int mid_X;
		int mid_Y;
		int radius;
		const double pie = 3.141592;
		double area;
	public:
	    // public functions
		Circle(string, bool);
		void setCircleData(int, int, int) override;
		double computeArea() override;
		double getArea() override;
		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;
		string toString() override;
};
#endif