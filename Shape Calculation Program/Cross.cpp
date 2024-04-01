#include "Cross.h"

Cross::Cross(string name, bool containsWarpSpace):ShapeTwoD(name, containsWarpSpace){}

void Cross::setData(int *x, int *y)
{
    // vector to store 
    vector<int> tempminX;
    vector<int> tempmaxX;
    vector<int> tempminY;
    vector<int> tempmaxY;
    for (int i = 0; i < 12; i++)
    {
    	this->x[i] = x[i];
    }
    for (int i = 0; i < 4; i++)
    {
    	this->y[i] = y[i];
    }

    minX = x[0];
    maxX = x[0];
    minY = y[0];
    maxY = y[0];
    
    // find min and max of x ordinate
    for(int i = 0; i < 12; i++)
    {
        if(x[i] < minX)
            minX = x[i];
        else if(x[i] > maxX)
            maxX = x[i];
    }
    
    // find min and max of y ordinate
    for(int i = 0; i < 12; i++)
    {
        if(y[i] < minY)
            minY = y[i];
        else if(y[i] > maxY)
            maxY = y[i];
    }
    
    // store it inside a vector
    for (int i = 0; i < 12; i++)
    {
        if (x[i] == minX)
            tempminX.push_back(y[i]);
        else if (x[i] == maxX)
            tempmaxX.push_back(y[i]);
        if (y[i] == minY)
            tempminY.push_back(x[i]);
        else if (y[i] == maxY)
            tempmaxY.push_back(x[i]);
    } 
    
    if (tempminX[0] < tempminX[1]) 
    {
        bottomLeftY = tempminX[0];
        lefttopy = tempminX[1];
    }
    else 
    {
        bottomLeftY = tempminX[1];
        lefttopy = tempminX[0];
    }
    if (tempmaxX[0] < tempmaxX[1])
    {
        rightboty = tempmaxX[0];
        righttopy = tempmaxX[1];
    }
    else 
    {
        rightboty = tempmaxX[1];
        righttopy = tempmaxX[0];
    }
    if (tempminY[0] < tempminY[1])
    {
        bottomLeftX = tempminY[0];
        bottomRightX = tempminY[1];
    }
    else 
    {
        bottomLeftX = tempminY[1];
        bottomRightX = tempminY[0];
    }
    if (tempmaxY[0] < tempmaxY[1])
    {
        topleftx = tempmaxY[0];
        toprightx = tempmaxY[1];
    }
    else 
    {
        topleftx = tempmaxY[1];
        toprightx = tempmaxY[0];
    }
    tempminX.clear();
    tempmaxX.clear();
    tempminY.clear();
    tempmaxY.clear();
    
    // sets the virtual lines that breaks the cross into 5 rectangles (closer to the corner)
    if (lefttopy > righttopy)
        topboty = lefttopy;
    else
        topboty = righttopy;
    if (bottomLeftY < rightboty)
        bottomTopY = bottomLeftY;
    else
        bottomTopY = rightboty;
    if (topleftx < bottomLeftX)
        leftrightx = topleftx;
    else
        leftrightx = bottomLeftX;
    if (toprightx > bottomRightX)
        rightleftx = toprightx;
    else
        rightleftx = bottomRightX;
}

//checks if parameters are within boundaries of the 5 rectangles, except the middle which is inclusive of boundaries
bool Cross::isPointInShape(int x, int y) 
{
    if (minX < x && x <= leftrightx)
    {
		if (bottomLeftY < y && y < lefttopy)
			return true;
	}
	else if (minY < y && y <= bottomTopY)
    {
		if (bottomLeftX < x && x < bottomRightX)
			return true;
	}
    else if (topboty <= y && y < maxY)
    {
		if (topleftx < x && x < toprightx)
			return true;
	}
    else if (rightleftx <= x && x < maxX)
    {
		if (rightboty < y && y < righttopy)
			return true;
	}
    else if (bottomTopY <= y && y <= topboty)
    {
		if (leftrightx <= x && x <= rightleftx)
			return true;
	}
	return false;
}

// get method to get the area
double Cross::getArea()
{
	return area;
}

// function to find the cross area
double Cross::computeArea()
{
    toparea = (maxY - topboty) * (toprightx - topleftx);
    bottomArea = (bottomTopY - minY) * (bottomRightX - bottomLeftX);
    leftarea = (leftrightx - minX) * (lefttopy - bottomLeftY);
    rightarea = (maxX - rightleftx) * (righttopy - rightboty);
    midarea = (rightleftx - leftrightx) * (topboty - bottomTopY);
    area = toparea + leftarea + rightarea + bottomArea + midarea;
	return area;
}

//checks if the parameters are on the 12 lines of the cross's cornerss
bool Cross::isPointOnShape(int x, int y) 
{
	if (x == minX)
    {
        if (bottomLeftY < y && y < lefttopy)
            return true;
    }
    if (x == maxX)
    {
        if (rightboty < y && y < righttopy)
            return true;
    }
    if (x == topleftx)
    {
        if (lefttopy < y && y < maxY)
            return true;
    }
    if (x == toprightx)
    {
        if (righttopy < y && y < maxY)
            return true;
    }
    if (x == bottomLeftX)
    {
        if (minY < y && y < bottomLeftY)
            return true;
    }
    if (x == bottomRightX)
    {
        if (minY < y && y < rightboty)
            return true;
    }
    if (y == maxY)
    {
        if (topleftx < x && x < toprightx)
            return true;
    }
    if (y == minY)
    {
        if (bottomLeftX < x && x < bottomRightX)
            return true;
    }
    if (y == lefttopy)
    {
        if (minX < x && x < topleftx)
            return true;
    }
    if (y == bottomLeftY)
    {
        if (minX < x && x < bottomLeftX)
            return true;
    }
    if (y == righttopy)
    {
        if (toprightx < x && x < maxX)
            return true;
    }
    if (y == rightboty)
    {
        if (bottomRightX < x && x < maxX)
            return true;
    }
    return false;
}

// output the area, vertices, points, points on perimeter and within shapes
string Cross::toString()
{
	string output;
	output += ShapeTwoD::toString();
	output += "Area: " + to_string((int)area) + " units square\n";
    output += "Vertices:\n";
    output += "Point [0]: (" + to_string(bottomLeftX) + ", " + to_string(minY) + ")\n";
    output += "Point [1]: (" + to_string(bottomRightX) + ", " + to_string(minY) + ")\n";
    output += "Point [2]: (" + to_string(bottomRightX) + ", " + to_string(rightboty) + ")\n";
    output += "Point [3]: (" + to_string(maxX) + ", " + to_string(rightboty) + ")\n";
    output += "Point [4]: (" + to_string(maxX) + ", " + to_string(righttopy) + ")\n";
    output += "Point [5]: (" + to_string(toprightx) + ", " + to_string(righttopy) + ")\n";
    output += "Point [6]: (" + to_string(toprightx) + ", " + to_string(maxY) + ")\n";
    output += "Point [7]: (" + to_string(topleftx) + ", " + to_string(maxY) + ")\n";
    output += "Point [8]: (" + to_string(topleftx) + ", " + to_string(lefttopy) + ")\n";
    output += "Point [9]: (" + to_string(minX) + ", " + to_string(lefttopy) + ")\n";
    output += "Point [10]: (" + to_string(minX) + ", " + to_string(bottomLeftY) + ")\n";
    output += "Point [11]: (" + to_string(bottomLeftX) + ", " + to_string(bottomLeftY) + ")\n";
    // cout << endl;
	output += "Points on perimeter: ";
	for (int i = minX; i <= maxX; i++)
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
	output += "\n\nPoints within shape: ";
    if(area == 1)
    {
		output += "none";
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