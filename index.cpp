/*

Progamming Assignment 6

Name: Burahaun Uddin
Date: 06/30/2022
Class: ITCS-2530

this program will read bowling scores from a .txt file. it will store the names of the bowlers in a 1d array, their scores in a 2d array, and their avergaes in a third 1d array. we will use loops to traverse through the file and array and make the calculations.

																													*/


#include<iostream>
#include<fstream>
#include<string>
#include <iomanip>

using namespace std;

//Were using const ints here because this txt file has 10 players each with 4 scores

const int numberOfPlayers = 10, playerScores = 4;


//this function will return a bool true or false. it takes a string array (which we store the player names in), a 2d int array, which stores the bowlers scores', and a string which is the name of the file which is passed through the function. it returns false if the file isnt opened properly

bool GetBowlingData(string playersNames[], int allScores[][playerScores], string nameOfFile) {


ifstream fin(nameOfFile);

//if file not opened, return false and end the program
		if (fin.is_open() == false) {
			return false;
		}


//the nested for loop allows us to iterate and build our 2d array, we have to iterate twice to get and store the scores
	for (int i = 0; i < numberOfPlayers; i = i + 1) {
		fin >> playersNames[i];
			for (int j = 0; j < playerScores; j = j + 1) {
				fin >> allScores[i][j];
		}
	}

	
//Once were done getting the names and scores we close the file and return true to stop the function
	
	fin.close();
	return true;
}



//Our GetAverageScores function is used for getting each players score average. we use pointers so we can access our score and player names arrays.



float* GetAverageScores(int allScores[][playerScores], string* playersNames) {

//Here we are using a dynamic sized array which is helpful for getting the right amount of memory needed

float* average = new float[numberOfPlayers];

//We use this nested for loop to calculate the average. we initialize the total to 0, and increment the total after every full iteration, then get our average by our score total/# of scores
	
		for (int i = 0; i < numberOfPlayers; i = i + 1) {
			float total = 0;
				for (int j = 0; j < playerScores; j = j + 1)
					total = total + allScores[i][j];
					average[i] = total / playerScores;
			}
//here we return the average pointer use
	return average;
}

//here we use a void function to just return the information in a nice format. it takes a pointer to our players array and the 2d array we used to store all the scores.

void PrettyPrintScores(string* playersNames, int allScores[][playerScores]) {

//we use this to get the average of the scores.
	
float* average = GetAverageScores(allScores, playersNames);

//We use i/o manipulators to format the out put cleanly. A the first for loop prints the names from the array with the player names, and the second for loop prints the scores and averages
for (int i = 0; i < numberOfPlayers; i = i + 1) {
	cout << setw(40) << left << "Name:" << playersNames[i] << endl;
	cout << setw(40) << left <<  "Scores:";
	for (int j = 0; j < playerScores; j = j + 1)
		cout << allScores[i][j] << " ";
		cout << endl;
		cout << setw(40) << "Average: " << average[i] << endl << endl;
	}
}

int main() {

//This is where you enter the name of whichever file you want to use
string nameOfFile = "BowlingScores.txt";

//the players array is a string array which contains the names of all players
	
string playersNames[numberOfPlayers];

//this is the 2d array where all the scores are stored

int allScores[numberOfPlayers][playerScores];
bool opened = false;


opened = GetBowlingData(playersNames, allScores, nameOfFile);
		if (opened == false) {
			cout << "File not opened." << endl;
		}	
		else {
			PrettyPrintScores(playersNames, allScores);
		}
	return 0;
}