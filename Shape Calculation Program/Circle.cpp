#include "Circle.h"

Circle::Circle(string name, bool containsWarpSpace):ShapeTwoD(name, containsWarpSpace){}

// set the circle center point and radius
void Circle::setCircleData(int x, int y, int radius)
{
    this->mid_X = x;
    this->mid_Y = y;
    this->radius = radius;
}

// calculate the circle area
double Circle::computeArea()
{
	area = pie * radius * radius;
	return area;
}

// get the area of circle
double Circle::getArea()
{
	return area;
}

// check if point is in the shape
bool Circle::isPointInShape(int x, int y)
{
    //
	int xDistance = mid_X-x; //distance of x from centre
    int yDistance = mid_Y-y; //distance of y from centre
    if (((xDistance * xDistance) + (yDistance * yDistance)) < (radius * radius)) 
    {
		if((x != mid_X) && (y != mid_Y))
			return true;
	}
	return false;
}

// check if point is on the perimeter
bool Circle::isPointOnShape(int x, int y)
{
	int xDistance = mid_X-x; //distance of x from centre
    int yDistance = mid_Y-y; //distance of y from centre
	if (((xDistance * xDistance) + (yDistance * yDistance)) == (radius * radius)) //a^2 + b^2 = c^2. if c^2 == r^2
    {
		return true;
	}
	return false;
}

// output the area, center, radius, points on perimeter and within shapes
string Circle::toString()
{
	string output;
	output += ShapeTwoD::toString();
	output += "Area: " + to_string(area) + " units square\n";
    output += "Centre Point: [" + to_string(mid_X) + ", " + to_string(mid_Y) + "]\n";
	output += "Radius: " + to_string(radius) + " units\n\n";
	cout << endl;
	// output the points that are on the shape perimeter
	output += "Points on perimeter:";
	for (int i = (mid_X - radius); i <= (mid_X + radius);i++)
    {
		for (int j = (mid_Y - radius); j <= (mid_Y + radius); j++)
        {
			if (isPointOnShape(i, j) == true)
            {
				output += " (" + to_string(i) + ", " + to_string(j) + "),";
            }
		}
	}
	if(radius == 1)
    {
		output += "none";
    }
    
    output.pop_back();
    cout << endl;
    // output the points that are within the shape
	output += "\n\nPoints within shape: ";
    if(radius == 1)
    {
		output += "none";
    }
    else
    {
        for (int i = (mid_X - radius); i <= (mid_X + radius);i++)
        {
            for (int j = (mid_Y - radius); j <= (mid_Y + radius); j++)
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