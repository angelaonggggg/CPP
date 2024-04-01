# Shape Calculation Program

The objective of this program is to provide a fundamental understanding of object-oriented programming concepts, including:

- Encapsulation
- Inheritance
- Polymorphism
- Function overloading

## Installation

To run the code locally:

1. Download the source code.
2. Open a terminal and navigate to the directory containing the script.
3. Ensure that the following files are in the same directory:
   - `ShapeCalculationProgram.cpp` (Main File)
   - `Circle.cpp`
   - `Circle.h`
   - `Cross.cpp`
   - `Cross.h`
   - `Rectangle.cpp`
   - `Rectangle.h`
   - `ShapeTwoD.cpp`
   - `ShapeTwoD.h`
   - `Square.cpp`
   - `Square.h`

## Usage

1. To execute the C++ code, open the terminal or command prompt and navigate to the directory containing the files.

2. On the terminal, compile the code by running the following command:
    ```
    g++ ShapeCalculationProgram.cpp Circle.cpp Cross.cpp Rectangle.cpp ShapeTwoD.cpp Square.cpp -o ShapeCalculationProgram
    ```
    
3. Execute the C++:
    ```
    ShapeCalculationProgram
    ```

3. The system will prompt the user to choose an an option to:
   - Read in sensor data on 2D shapes
   - Compute areas of these shapes
   - Print shapes report
   - Sort the shapes
   - Quit

    
## Features

1. **Read in sensor data on 2D shapes:**
    - Prompt the user to enter the name of the shape (e.g., Cross/ Square/ Circle/ Rectangle).
    - Prompt the user to enter the shape's type (NS/WS) which stands for non-warp or warp-space.
    - Prompt the user to input the x and y coordinates of the shape.

2. **Compute the area of these shapes:**
    - Calculate the area of the shapes.
    - Count the number of data that are updated.

3. **Print shapes report:**
    - Generate a report for each shape, including:
        - List of points
        - Name of shape
        - Special type
        - Area of shape
        - Whether the points are on the perimeter or within the shape.

4. **Sort shape data:**
    - Provide options to sort the shape data:
        - By area in ascending order
        - By area in descending order
        - By type and area in descending order.

5. **Quit:**
    - Allow users to exit the program.


