#ifndef SHAPETWOD_H
#define SHAPETWOD_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class ShapeTwoD 
{
    protected: 
        // protected variables
        string name;
        bool containsWarpSpace;
        
    public: 
        // public functions
        ShapeTwoD(string, bool);
        string getName();
        bool getContainsWarpSpace();
        void setName(string);
        // virtual function is used so that is can be override
        virtual double computeArea()
        {
            return 1.0;
        };
        virtual double getArea()
        {
            return 1.0;
        };
        virtual void setData(int[], int[])
        {};
		virtual void setCircleData(int, int, int)
		{};
        virtual bool isPointInShape(int, int)
        {
            return false;
        };
        virtual bool isPointOnShape(int, int)
        {
            return false;
        };
		void setContainsWarpSpace(bool);
		virtual string toString();
};
#endif