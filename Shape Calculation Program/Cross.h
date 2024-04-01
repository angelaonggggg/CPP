#ifndef CROSS_H
#define CROSS_H
#include "ShapeTwoD.h"

using namespace std;

class Cross : public ShapeTwoD
{
	private:
	    // private variables
		int x[12];
		int y[12];
		int minX;
		int maxX;
		int minY;
		int maxY;
		int bottomLeftX;
		int bottomRightX;
		int bottomLeftY;
		int bottomTopY;
		int lefttopy;
		int topleftx; 
		int toprightx;
		int righttopy;
		int rightboty;
		int topboty;
		int leftrightx;
		int rightleftx;
		int toparea;
		int leftarea;
		int rightarea;
		int bottomArea;
		int midarea;
		int area;
	public:
	    // public functions
		Cross(string, bool);
		void setData(int *x, int *y) override;
		double computeArea() override;
		double getArea() override;
		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;
		string toString() override;
};

#endif