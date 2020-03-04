
/*
CIS 22B
Lab 3: Make A Rectangle Class and overload the +, -,<<, and >> operators
Author: Christian Rojas
Date:03/03/2020
Professor Goel

Program Description: Creates two rectangles and add and subtract them. Then return and print out their four points,area, and perimeter.

Pseudocode main.cpp:

Open output file to output program console outputs as well as any User Interactivity
Set a cond for the User Loop
Create two Rectangle Objects
Let User Input Their Attributes
Print them out on console as well as output file
Create third Rectangle Object that is initalize to first and second Rectangles added together
Print Out Added Rectangle - outputfile as well
Create Fourth Rectangle that is initalize to first and second Rectangles subtracted together
Print out Fourth Rectangle - outputfile as vwell
Ask User if They wish to Keep running program
If user inputs y then deletes Rectangles and start again
else program exits with proper message

*/

#include <iostream>
#include <fstream>
#include "rectangle.h"

int main() {


	//To Display UserInteraction and Program Outputs
	std::ofstream outputFile;
	outputFile.open("output.txt");

	if (outputFile.fail()) {
		std::cerr << "File cannot be open! " << std::endl;
		exit(1);
	}

	char cond = 'y';

	//Let the User Decide when to End Program
	while (cond == 'y' || cond == 'Y')
	{

		//UserInputs Rectangles and set their attributes
		Rectangle a, b;
		std::cin >> a;
		std::cin >> b;
		
		//Print out to console and to "output.txt"
		std::cout << a;
		outputFile << a;
		std::cout << b;
		outputFile << b;

		//Use overloaded + operator to add two Rectangles together and return Rectangle that contains both,
		std::cout << "Adding your two rectangles together........." << std::endl;
		outputFile << "Adding your two rectangles together........." << std::endl;
		Rectangle addedRect = a + b;
		std::cout << addedRect << std::endl;
		outputFile << addedRect << std::endl;

		//Use overloaded - operator to subtract two Rectangles together and return Rectangle that is left from their overlap
		std::cout << "Subtracting your rectangles together........." << std::endl;
		outputFile << "Subtracting your rectangles together........." << std::endl;
		Rectangle subRect = a - b;
		std::cout << subRect << std::endl;
		outputFile << subRect << std::endl;

		//Ask user if they wish to keep running the program
		std::cout << "Do you want to try another two rectangles input 'y' for yes or 'n' for no" << std::endl;
		outputFile << "Do you want to try another two rectangles input 'y' for yes or 'n' for no" << std::endl;

		std::cin >> cond;
		std::cin.ignore();
		outputFile << "UserInput: " << cond << std::endl;
	
	}

	std::cout << "Okay have a good day" << std::endl;
	outputFile << "Okay have a good day " << cond << std::endl;

	outputFile.close();
	system("pause");



	return 0;
}