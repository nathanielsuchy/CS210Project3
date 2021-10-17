#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include "CS210Project3.h"

using namespace std;

/*
	Python helper functions moved to CS210Project3.h to declutter the main program file!
*/

int main()
{
	// Primary event-loop
	// 
	// SNHU Required Attribution: This event loop was adapted from my work in Project 2
	while (1) {
		std::string tmp; // Input buffer
		char* endPtr; // Pointer storage for string to double, int, long, etc functions
		int commandChoice = 0;

		std::cout << "";

		std::cout << "Enter a choice: ";
		getline(std::cin, tmp);
		commandChoice = std::strtod(tmp.c_str(), &endPtr);

		switch (commandChoice) {
			case 1: // Produce a list of all items purchased in a given day 
					// along with the number of times each item was purchased.
				CallProcedure("list_items_and_times_purchased");
				break;
			case 2: // Produce a number representing how many times a specific 
					// item was purchased in a given day.
				break;
			case 3: // Produce a text-based histogram listing all items purchased in a given day, 
					// along with a representation of the number of times each item was purchased.
				CallProcedure("histogram");
				break;
			case 4:
				std::cout << "All done. Exiting the program!" << std::endl;
				exit(0);
			default:
				// Visual Studio includes the headers for Windows Applications so you can use Windows.h
				// to make pretty popup boxes for error handling.
				// Any other OS will just get standard text output.
				#ifdef _WIN32
							MessageBox(nullptr, TEXT("You entered an invalid command!"), TEXT("Error"), MB_OK);
				#elif
							std::cout << "Invalid command choice!" << std::endl;
							sleep(5); // Pauses the program for 5 seconds so the user has time to see the error message
				#endif
		}
	}
	return 0;
}