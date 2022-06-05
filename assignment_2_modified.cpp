/* 
									Progamming Assignment 2
											
Name: Burahaun Uddin
Date: 06/03/2022
Class: ITCS-2530

this program will ask calculate the total # of containers needed to hold cheese, the total cost to produce said # of containers of cheese, and the total profit

libraries and variables are declared before the main() function
	*/


#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//Variables
const double containerSpace = 2.76;
const double costToProduce = 4.12;
const double containerProfit = 1.45;
double totalCost;
int totalCheeseProduced;
double numberOfContainers;
double profitMade;
char asterisk = '*';
char empty = ' ';
string l2 =	"The number of containers to hold the cheese is: "; 


int main() {
	cout << setfill('*') << setw(67) << asterisk << endl;
	cout << setfill('*') << setw(18) << asterisk <<"The Cheese Calculator" << setfill('*') << setw(25) << asterisk << endl;
 cout << setfill('*') << setw(67) << asterisk << "\n" << endl;

	//Line 1: asking for user input
	cout << "Please enter the total number of kilograms of cheese produced: ";
	cin >> totalCheeseProduced; // <= store input in here
	
//Line 2
	numberOfContainers = round(totalCheeseProduced / containerSpace); 								
									//the number of containers has to be a whole
								 //number so the round method which we 												//imported with <cmath> allows us to round up 								//to the next close higher int 
	

	cout << l2;
	cout << setfill(empty) <<setw(26)<< numberOfContainers << endl;

	
//Line 3	
	string containers = "The cost of producing " + to_string(lround(numberOfContainers)) + " container(s) of cheese is: $"; //we initialize and are able to turn the 										//numberOfContainers into a string without hard
							//coding it into our program.
	totalCost = lround(numberOfContainers) * costToProduce;
	cout << containers << setfill(empty) << setw(20)<< totalCost <<endl;
							//we calculate total cost here with simple mult.
		
//Line 4	
	string profit = "The profit from producing " + to_string(lround(numberOfContainers)) + " container(s) of cheese is: $"; //Same as above
	profitMade = lround(numberOfContainers) * 1.45;
	cout << profit;
	cout << setw(16) << setfill(empty);
	cout << left <<setfill('0') << setw(5) << profitMade << endl; 
	
			//here I'm using format manipulators setfill and setw 				//to convert 191.4 => 191.40. setw allows us to put a 				//minimum number of characters to expect for a variable
			//and setfill lets us fill the with specific charatcers
			//if the specific amount isnt met

;	

	
	
}