#include "Square.h"

Square::Square(string name, bool containsWarpSpace):ShapeTwoD(name, containsWarpSpace){}

void Square::setData(int *x, int *y) 
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
            this->min_X = x[i];
            this->max_X = x[0];
            check = true;
        }
        else if (x[i] > x[0])
        {
            this->min_X = x[0];
            this->max_X = x[i];
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
            this->min_Y = y[i];
            this->max_Y = y[0];
            check = true;
        }
        else if (y[i] > y[0])
        {
            this->min_Y = y[0];
            this->max_Y = y[i];
            check = true;
        }
    }
    // set distance from left to right
    this->xDistance = max_X - min_X; 
    // set distance from top to bottom
    this->yDistance = max_Y - min_Y; 
    for (int i = 0; i < 4; i++)
    {
    	this->x[i] = x[i];
    }
    for (int i = 0; i < 4; i++)
    {
    	this->y[i] = y[i];
    }
}

// calculate the area
double Square::computeArea()
{
    area = xDistance * yDistance;
	return area;
}

// get area of the square
double Square::getArea()
{
	return area;
}

// check if point is in the shape
bool Square::isPointInShape(int x, int y)
{
    if (min_X < x && x < max_X) 
    {
		if (min_Y < y && y < max_Y)
			return true;
	}
	return false;
}

// check if point is on the perimeter
bool Square::isPointOnShape(int x, int y)
{
	if (x == min_X || x == max_X) 
    {
        if (min_Y < y && y < max_Y)
            return true;
    }
    else if (y == min_Y || y == max_Y)
    {
        if (min_X < x && x < max_X)
            return true;
    }
    return false;
}

// output the area, vertices, points, points on perimeter and within shapes
string Square::toString()
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
	for (int i = min_X; i <= max_X;i++)
    {
		for (int j = min_Y; j <= max_Y; j++)
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
	
	// output the points that are within the shape
	output += "\n\nPoints within shape: ";
    if(area == 1)
    {
		output += "none!";
    }
    else
    {
        for (int i = min_X; i <= max_X;i++)
        {
            for (int j = min_Y; j <= max_Y; j++)
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