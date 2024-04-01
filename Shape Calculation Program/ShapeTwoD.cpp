#include "ShapeTwoD.h"

ShapeTwoD::ShapeTwoD(string name, bool containsWarpSpace)
{
    this->name = name;
    this->containsWarpSpace = containsWarpSpace;
}

// get Method to get name 
string ShapeTwoD::getName()
{
    return name;
}

bool ShapeTwoD::getContainsWarpSpace()
{
    return containsWarpSpace;
}

// mutator method to set name
void ShapeTwoD::setName(string name)
{
    this->name = name;
}

void ShapeTwoD::setContainsWarpSpace(bool containsWarpSpace)
{
    this->containsWarpSpace = containsWarpSpace;
}

// output the name and the special type
string ShapeTwoD::toString()
{
    if (containsWarpSpace == true)
    {
        return ("Name : " + name + "\nSpecial Type : WS\n");
    }
    else 
    {
        return ("Name : " + name + "\nSpecial Type : NS\n");
    }
}