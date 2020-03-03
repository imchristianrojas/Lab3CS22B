# Lab3CS22B
Rectangle Class - Overloading Functions, Basic OOP Principles

Program: Write a program that will manipulate Rectangle objects for which you will create a Rectangle class.

Declare a Rectangle class in a ".h" file with attributes and methods in the following points. Attributes should be private, methods should be generally public.
Define the Rectangle class in a ".cpp" file. Do not define anything inline in the ".h" file.
Do not use 'namespace std' in either the .h or .cpp file of the class.
A Rectangle is made up of two points (x.y) such that the first point (x1,y1) is the bottom left hand corner and second point (x2,y2) is the upper right hand corner. This will allow the Rectangle to be parallel to both axes.
Add a name attribute to the Rectangle which can be printed out from the program.
Write appropriate Constructors, Destructor, Accessors and Mutators as needed. For Constructors, use Constructor Initialization List in at least one constructor.
Write two methods that return the area and perimeter of the rectangle respectively.
Overload the input operator (>>) in the class to accept input for your class as needed. Do not use the cin operator in your class.
Overload the output operator (<<) in the class such that it prints the following for a Rectangle object with name Rect1 (without the bullet points):
*Rect1's four corners are at (5,3), (5,10), (8,10), (8,3).
*Rect1's area is 21 and perimeter is 20.
Overload the addition operator (+) as a class member such that it returns a rectangle that will contain the two rectangles being added.
Overload the subtraction operator (-) as a friend function such that it returns a rectangle that is formed by the overlap of the two rectangles. If there is no overlap between the two rectangles, it should return a rectangle where all four corners are at (0,0).
To use this class, write your main in a third file (.cpp) such that it will ask the user to input the two points and name for two rectangles.
Perform input validation to ensure that a valid rectangle can be formed.
It will then calculate the result of the addition and subtraction operations.
Then it will output the details of all 4 rectangles - to both screen and an output file.
Allow the user to keep running the program in a loop, if desired.
 
