#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ShapeTwoD.h"

using namespace std;

class Rectangle : public ShapeTwoD
{
	private:
	    // private variables
		int minX;
		int maxX;
		int minY;
		int maxY;
		int xdist;
		int ydist;
		int x[4];
		int y[4];
		double area;
	public:
	    // public functions
		Rectangle(string, bool);
		void setData(int *x, int *y) override;
		double computeArea() override;
		double getArea() override;
		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;
		string toString() override;
};
#endif