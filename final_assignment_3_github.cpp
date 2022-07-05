/* 
									Progamming Assignment 3
											
Name: Burahaun Uddin
Date: 06/07/2022
Class: ITCS-2530

this program will ask calculate the shipping cost based on various factors, like total cost of order, destination being shipped etc. I'll be using if and else statements to make sure valid inputs are being passed through to my program

libraries and variables are declared before the main() function
	*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>>

using namespace std;
//variables that could change
double shipCost;
double totalCost;
const char period = '.';
string itemName;
char userResponse;
double orderTotal;
string destination;
const char dash = '-';

//shipping variables
const double hugeOrder = 0.00;
const double smallOrderUSA = 6.00;
const double smallOrderCAN = 8.00;
const double smallOrderAUS = 10.00;
const double mediumOrderUSA = 9.00;
const double mediumOrderCAN = 12.00;
const double mediumOrderAUS = 14.00;
const double largeOrderUSA = 12.00;
const double largeOrderCAN = 15.00;
const double largeOrderAUS = 17.00;
const double fragileItem = 2.00;
const double marsOrder = 100.00;

//price variables
const double mediumOrderMIN = 50.01;
const double mediumOrderMAX = 100.01;
const double largeOrderMAX = 150.00;




int main() {
	//Header Section of Progam to mock example
  cout << setw(50) << setfill(period) << period << endl;
  cout << "ITCS-2530 - Programming Assignment for week #3" << endl;
  cout << setw(50) << setfill(period) << period << endl;
	cout << endl;
	cout << endl;

// Line 1 of progam	
	cout << left <<setw(49) << setfill(period) << "Please enter the item name (no spaces)" << ":";
	cin >> itemName;
// takes user input for item name

	
//Line 2
cout << left <<setw(49) << setfill(period) << "Is the item fragile? (y=yes/n=no)" << ":";
	cin >> userResponse;
			switch (userResponse)
				{
					case 'y':
					shipCost = shipCost + fragileItem;
					break;
					case 'Y':
					shipCost = shipCost + fragileItem;
					break;
					case 'n':
					break;
					case 'N':
					break;
					default:
						cout << endl;
						cout << "Invalid entry, exiting";
						return 0;
//asks user if item is fragile, if y or Y, adds two to shipping and if n or N, continues without doing anything, and if neither, prints error and ends program
				}
				

// Line 3
	cout << left <<setw(49) << setfill(period) << "Please enter your order total" << ":";
	cin >> orderTotal;
//takes order total
	
//Line 4
		cout << left <<setw(49) << setfill(period) << "Please enter destination. (usa/can/aus/mars)" << ":";
	cin >> destination;
		if (destination == "aus" || destination == "can" || destination == "usa" || destination == "mars") {
			cout << endl;
			}
		else {
			cout << endl;
			cout << "Invalid entry, exiting";
			return 0;
			}
//takes user input for destination, and prints error message if not one of our choices
//Line 5
//uppercases the name of our item
		transform(itemName.begin(), itemName.end(), itemName.begin(), ::toupper);
	cout << left <<setw(40) << setfill(period) << "Your item is" << itemName << endl;
//formatting^

	//Line 6
//below are a bunch of if statements that help us decide which category shipping falls into. we decide shipping from incrementing shipCost by order size + location
	if (orderTotal < mediumOrderMIN && destination == "usa") {
		shipCost = shipCost + smallOrderUSA;
		}
	else if (orderTotal < mediumOrderMIN && destination == "can") {
		shipCost = shipCost + smallOrderCAN;
	}
	else if (orderTotal < mediumOrderMIN && destination == "aus") {
		shipCost = shipCost + smallOrderAUS;
	}
	else if (orderTotal > mediumOrderMIN && orderTotal <= mediumOrderMAX && destination == "usa") {
		shipCost = shipCost + mediumOrderUSA;
	}
	else if (orderTotal > mediumOrderMIN && orderTotal <= mediumOrderMAX && destination == "can") {
		shipCost = shipCost + mediumOrderCAN;
	}
	else if (orderTotal > mediumOrderMIN && orderTotal <= mediumOrderMAX && destination == "aus") {
		shipCost = shipCost + mediumOrderAUS;
	}
	else if (orderTotal > mediumOrderMAX && orderTotal <= largeOrderMAX && destination == "usa") {
		shipCost = shipCost + largeOrderUSA;
	}
	else if (orderTotal > mediumOrderMAX && orderTotal <= largeOrderMAX && destination == "can") {
		shipCost = shipCost + largeOrderCAN;
	}
	else if (orderTotal > mediumOrderMAX && orderTotal <= largeOrderMAX && destination == "aus") {
		shipCost = shipCost + largeOrderAUS;
		}
	else if (destination == "mars") {
		shipCost = marsOrder;
	}
	else { //this takes any large amount and uses 0 for shipping
		shipCost = hugeOrder;
	}

	cout << left <<setw(40) << setfill(period) << "Your shipping cost is" << "$";
	cout << fixed << setprecision(2) << shipCost << endl;

//Line 7
//uppercases destination 
		transform(destination.begin(), destination.end(), destination.begin(), ::toupper);
	
		cout << left <<setw(40) << setfill(period) << "Your are shipping to" << destination << endl;

//Line 8
	totalCost = shipCost + orderTotal;
	
		cout << left <<setw(40) << setfill(period) << "Your total shipping costs are" << "$" << totalCost << endl;
	cout << endl;
//outputs total cost of order

	
//Footer
	cout << setfill(dash) << setw(40) << dash;
  cout << "Thank You!" << endl;

	}