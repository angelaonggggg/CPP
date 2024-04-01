#include "Rectangle.h"

Rectangle::Rectangle(string name, bool containsWarpSpace):ShapeTwoD(name, containsWarpSpace){}

void Rectangle::setData(int *x, int *y)
{
    bool check = false;
    int i = 1;
    // set X min and X max
    while (check == false) 
    {
        if (x[0] == x[i])
            i++;
        else if (x[0] > x[i])
        {
            this->minX = x[i];
            this->maxX = x[0];
            check = true;
        }
        else if (x[i] > x[0])
        {
            this->minX = x[0];
            this->maxX = x[i];
            check = true;
        }
    }
    
    i = 1;
    check = false;
    // set Y min and Y max
    while (check == false)
    {
        if (y[0] == y[i])
            i++;
        else if (y[0] > y[i])
        {
            this->minY = y[i];
            this->maxY = y[0];
            check = true;
        }
        else if (y[i] > y[0])
        {
            this->minY = y[0];
            this->maxY = y[i];
            check = true;
        }
    }
    // set distance from left to right
    this->xdist = maxX - minX; 
    // set distance from top to bottom
    this->ydist = maxY - minY; 
    for (int i = 0; i < 4; i++)
    {
    	this->x[i] = x[i];
    }
    for (int i = 0; i < 4; i++)
    {
    	this->y[i] = y[i];
    }
}

// calculate the area of Rectangle
double Rectangle::computeArea()
{
    area = xdist * ydist;
	return area;
}

// get area of rectangle
double Rectangle::getArea()
{
	return area;
}

// check if points are in the shape
bool Rectangle::isPointInShape(int x, int y)
{
    // if points are in shape
    if (minX < x && x < maxX)
    {
		if (minY < y && y < maxY)
			return true;
	}
	return false;
}

// check if point is on the perimeter
bool Rectangle::isPointOnShape(int x, int y)
{
    // if points form the parameter of the shape
	if (x == minX || x == maxX) 
    {
        if (minY < y && y < maxY)
            return true;
    }
    else if (y == minY || y == maxY)
    {
        if (minX < x && x < maxX)
            return true;
    }
    return false;
}

// output the area, vertices, points, points on perimeter and within shapes
string Rectangle::toString()
{
	string output;
	output += ShapeTwoD::toString();
	output += "Area: " + to_string((int)area) + " units square\n";
    output += "Vertices:\n";
    for (int i = 0; i < 4; i++)
    {
        output += "Point [" + to_string(i) + "]: (" + to_string(x[i]) + ", " + to_string(y[i]) + ")\n";
    }
    // output the points that are on the shape perimeter
	output += "Points on perimeter: ";
	for (int i = minX; i <= maxX;i++)
    {
		for (int j = minY; j <= maxY; j++)
        {
			if (isPointOnShape(i, j) == true)
            {
				output += " (" + to_string(i) + ", " + to_string(j) + "),";
            }
		}
	}
	if(area == 1)
    {
		output += "none!";
    }
    output.pop_back();
    cout << endl;
    
    // output the points that are within the shape perimeter
	output += "\n\nPoints within shape: ";
    if(area == 1)
    {
		output += "none!";
    }
    else
    {
        for (int i = minX; i <= maxX;i++)
        {
            for (int j = minY; j <= maxY; j++)
            {
                if(isPointInShape(i, j) == true)
                {
                    output += " (" + to_string(i) + ", " + to_string(j) + "),";
                }
            }
        }
    }
    output.pop_back();
	output += "\n";
	
	return output;
}