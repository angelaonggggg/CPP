#include "ShapeTwoD.h"
#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Cross.h"

#include <cctype>
#include <iostream>
#include <cstring>
using namespace std;

// vector to store shape and shape calculated
vector<ShapeTwoD *> shape;
vector<ShapeTwoD *> shapecalculated;

// print out the main menu
int displayMenu()
{
    int choice;
    cout << "--------------------------------------" << endl;
    cout << "Welcome to Shape Calculation Program!" << endl;
    cout << "--------------------------------------" << endl;
    cout << endl;
    cout << "1)\tInput sensor data" << endl;
    cout << "2)\tCompute area (for all records)" << endl;
    cout << "3)\tPrint shapes report" << endl;
    cout << "4)\tSort shape data" << endl;
    cout << "5)\tQuit" << endl;
    cout << endl;
    // Loop until a valid choice is entered
    while (true)
    {
        cout << "Please enter your choice: ";
        // Get user input
        cin >> choice;

        // Check if the input is a valid integer
        if (cin.fail())
        {
            cout << "Invalid input. Please enter a valid number." << endl;
            cout << endl;
            // Clear the input buffer to prevent an infinite loop
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (choice >= 1 && choice <= 5)
        {
            break; // Valid choice, exit the loop
        }
        else
        {
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            cout << endl;
        }
    }

    return choice;
}

// option 1 input data
void inputSensorData()
{
    cout << endl;
    string name;
    string type;

    cout << "[Input sensor data]" << endl;
    bool checkShape = false;
    bool checkType = false;

    // check if correct shape is keyed
    while (checkShape == false)
    {
        cout << "Please enter name of shape: ";
        cin >> name;

        // change a string to lowercase
        for (int i = 0; i < name.length(); i++)
        {
            name[i] = tolower(name[i]);
        }

        // check if the name of the shape is correct
        if (name == "cross" || name == "square" || name == "circle" || name == "rectangle")
        {
            checkShape = true;
        }
        else
        {
            cout << endl;
            cout << "Please enter a valid shape (Cross/ Square/ Circle/ Rectangle)" << endl;
            cout << endl;
        }
    }

    // check if the correct type is keyed
    while (checkType == false)
    {
        cout << "Please enter special type: ";
        cin >> type;

        // change a string to uppercase
        for (int i = 0; i < type.length(); i++)
        {
            type[i] = toupper(type[i]);
        }

        // key in WS or NS
        if (type == "WS" || type == "NS")
        {
            checkType = true;
        }
        // did not key in WS or NS, user required to type again
        else
        {
            cout << endl;
            cout << "Please enter a valid special type (WS/ NS)" << endl;
            cout << endl;
        }
    }

    // containsWarpSpace is a variable use to assign type as bool
    bool containsWarpSpace;
    if (type == "WS")
    {
        containsWarpSpace = true;
    }
    else
    {
        containsWarpSpace = false;
    }
    cout << endl;

    // Enter x/y-ordinate and store it
    if (name == "cross")
    {
        int x[12];
        int y[12];
        shape.push_back(new Cross(name, containsWarpSpace));
        for (int i = 0; i < 12; i++)
        {
            cout << "Please enter x-ordinate of pt." << i + 1 << ": ";
            cin >> x[i];
            cout << "Please enter y-ordinate of pt." << i + 1 << ": ";
            cin >> y[i];
        }
        shape[(shape.size() - 1)]->setData(x, y);
    }

    // Enter x/y-ordinate and store in square
    else if (name == "square")
    {
        int x[4];
        int y[4];
        shape.push_back(new Square(name, containsWarpSpace));
        for (int i = 0; i < 4; i++)
        {
            // int i = 1
            cout << "Please enter x-ordinate of pt." << i + 1 << ": ";
            cin >> x[i];
            cout << "Please enter y-ordinate of pt." << i + 1 << ": ";
            cin >> y[i];
        }
        shape[(shape.size() - 1)]->setData(x, y);
    }

    // Enter integers and store in circle
    else if (name == "circle")
    {
        int mid_X;
        int mid_Y;
        int radius;
        shape.push_back(new Circle(name, containsWarpSpace));
        cout << "Please enter x-ordinate of center: ";
        cin >> mid_X;
        cout << "Please enter y-ordinate of center: ";
        cin >> mid_Y;
        cout << "Please enter radius (units): ";
        cin >> radius;
        shape[(shape.size() - 1)]->setCircleData(mid_X, mid_Y, radius);
    }

    // Enter x/y ordinate and store in rectangle
    else if (name == "rectangle")
    {
        int x[4];
        int y[4];
        shape.push_back(new Rectangle(name, containsWarpSpace));
        for (int i = 0; i < 4; i++)
        {
            cout << "Please enter x-ordinate of pt:" << i + 1 << ": ";
            cin >> x[i];
            cout << "Please enter y-ordinate of pt:" << i + 1 << ": ";
            cin >> y[i];
        }
        shape[(shape.size() - 1)]->setData(x, y);
    }
    cout << endl;
    cout << "Record successfully stored. Going back to main menu ..." << endl;
    cout << endl;
}

// option 2 compute area of shape
void calculateArea()
{
    cout << endl;
    // if no shape in the data
    if (shape.size() == 0)
    {
        cout << "You have not entered a shape." << endl;
        cout << endl;
    }
    else
    {
        for (int i = 0; i < shape.size(); i++)
        {
            // add into computed shape vector
            shapecalculated.push_back(shape[i]);
            // computes the shape
            shapecalculated.back()->computeArea();
        }
        cout << "Computation completed! (" << shape.size() << " records were updated)" << endl;
        cout << endl;
        // clear vector
        shape.clear();
    }
}

// user selects option 3 print shape report
void printShapeReport()
{
    // if no computed shapes
    if (shapecalculated.size() == 0)
    {
        cout << "You have not entered a shape." << endl;
        cout << endl;
    }
    else
    {
        cout << "Total no. of records available = " << shapecalculated.size() << endl
             << endl;
        for (int i = 0; i < shapecalculated.size(); i++)
        {
            cout << "Shape [" << i << "]" << endl;
            // print report for each shape
            cout << shapecalculated[i]->toString() << endl;
        }
    }
}

// sort area in ascending order (option a)
bool areaAscending(ShapeTwoD *a, ShapeTwoD *b)
{
    return (a->getArea() < b->getArea());
}

// sort area in descending order (option b)
bool areaDescending(ShapeTwoD *a, ShapeTwoD *b)
{
    return (a->getArea() > b->getArea());
}

// sort by type then area in descending order (option c)
bool comparetype(ShapeTwoD *a, ShapeTwoD *b)
{
    if (a->getContainsWarpSpace() != b->getContainsWarpSpace())
        return a->getContainsWarpSpace() == true;
    else
        return a->getArea() > b->getArea();
}

// option 4 sort shapes choices
void sortShapeData()
{
    char sortChoice;
    bool check = false;
    static int i = 0;

    // if no computed shapes
    if (shapecalculated.size() == 0)
        cout << "You have not input data" << endl;
    while (sortChoice != 'q')
    {
        cout << "a)\tSort by area (ascending)" << endl;
        cout << "b)\tSort by area (descending)" << endl;
        cout << "c)\tSort by special type and area" << endl;
        cout << endl;
        cout << "Please select sort option ('q' to go main menu) : ";
        cin >> sortChoice;
        cout << endl;
        sortChoice = tolower(sortChoice);

        // return back to main menu
        if (sortChoice == 'q')
        {
        }

        // sort shapes by area in ascending order
        else if (sortChoice == 'a')
        {
            cout << "Sort by area (smallest to largest)" << endl
                 << endl;
            sort(shapecalculated.begin(), shapecalculated.end(), areaAscending);
            for (int i = 0; i < shapecalculated.size(); i++)
            {
                cout << "Shape [" << i << "]" << endl;
                // print shapes report
                cout << shapecalculated[i]->toString() << endl;
            }
            // go back to main menu
            sortChoice = 'q';
        }

        // sort shapes by area in descending order
        else if (sortChoice == 'b')
        {
            cout << "Sort by area (largest to smallest)" << endl
                 << endl;
            sort(shapecalculated.begin(), shapecalculated.end(), areaDescending);
            for (int i = 0; i < shapecalculated.size(); i++)
            {
                cout << "Shape [" << i << "]" << endl;
                // print shapes report
                cout << shapecalculated[i]->toString() << endl;
            }
            sortChoice = 'q';
        }

        // sort shapes by type then area in descending order
        else if (sortChoice == 'c')
        {
            cout << "Sort by special type (WS to NS) then area (largest to smallest)" << endl
                 << endl;
            sort(shapecalculated.begin(), shapecalculated.end(), comparetype);
            for (int i = 0; i < shapecalculated.size(); i++)
            {
                cout << "Shape [" << i << "]" << endl;
                // print shapes report
                cout << shapecalculated[i]->toString() << endl;
            }
            sortChoice = 'q';
        }
        else
        {
            cout << "Please select an option." << endl
                 << endl;
        }
    }
}

// clears the vectors when program exits
void safelydeallocatememory()
{
    shape.clear();
    shapecalculated.clear();
    cout << "Thank you for using Shape Calculation Program!" << endl;
}

int main()
{
    bool exit = false;
    while (exit == false)
    {
        int choice = displayMenu();
        switch (choice)
        {
        // call option 1 function
        case 1:
            inputSensorData();
            break;
        // call option 2 function
        case 2:
            calculateArea();
            break;
        // call option 3 function
        case 3:
            printShapeReport();
            break;
        // call option 4 function
        case 4:
            sortShapeData();
            break;
        // to exit from the system
        case 5:
            safelydeallocatememory();
            exit = true;
            break;
        default:
            cout << endl;
            cout << "Please enter a valid choice" << endl;
            cout << endl;
            break;
        }
    }
    return 0;
}
