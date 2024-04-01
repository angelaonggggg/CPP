#ifndef SQUARE_H
#define SQUARE_H
#include "ShapeTwoD.h"

class Square: public ShapeTwoD
{
    private:
        // private variables
        int min_X;
        int min_Y;
        int max_X;
        int max_Y;
        int xDistance;
        int yDistance;
        // array to store 4 elements
        int x[4];
        int y[4];
        double area;
    public: 
        // public functions
        Square(string, bool);
        // override keyword is required to override a virtual function
		void setData(int *x, int *y) override;
		double computeArea() override;
		double getArea() override;
		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;
		string toString() override;
};
#endif