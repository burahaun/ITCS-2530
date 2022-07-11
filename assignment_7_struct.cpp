/*

Progamming Assignment 7

Name: Burahaun Uddin
Date: 07/06/2022
Class: ITCS-2530

this program will read bowling scores from a .txt file. it will store the names of the bowlers in a 1d array, their scores in a 2d array, and their avergaes in a third 1d array. we will use loops to traverse through the file and array and make the calculations.

																																																	*/


#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

const int numberOfPlayers = 10, playerScores = 5;

const char asterisk = '*';

//we use this struct to store each bowlers information. 
//three paramaters: bowlerName to store their names, an array of ints which store the players scores
//and and a double to display the average (assignment says to use int, but used double for accuracy)

struct bowler {
	string bowlerName;
	int scores[playerScores];
	double scoreAverage;
};

//the bool function GetBowlingData reads from the file and returns the bowlers names, the number of bowlers and their scores.

bool GetBowlingData(bowler *players, int* bowlingPlayers, int* scores, string nameOfFile) {
	//fstream library lets us open files 
	fstream myFile;
	string line;
	//initiailze score and # of bolwers to 0
	*scores = 0; 
	*bowlingPlayers = 0; 

	myFile.open(nameOfFile, ios::in); 
//ends the program if error in opening gile
	if (!myFile.good()) { 
		return false;
	}

	while (getline(myFile, line)) { 
		
		bool nameExists = true; 
		string info = ""; 
		//initialzied to 0
		*scores = 0; 
		
	//we use this for loop to iterate over each line of the text file	
		for (int i = 0; i < line.size(); i = i + 1) { 
			//we use this to check if there is a player name and the loop will see if theres a char before it
			if (line[i] == ' ') {
				if (nameExists) { 
					players[*bowlingPlayers].bowlerName = info; 
					info = ""; 
					nameExists = false; 
				}
			else if (i == (line.size()-1)) {
				if (nameExists) { 
					players[*bowlingPlayers].bowlerName = info; 
					info = "";
					nameExists = false;
				}
			}
			
				else {
					if (i == (line.size() - 1)) { 
						info = info + line[i]; 
					}
					players[*bowlingPlayers].scores[*scores] = stoi(info); 
					(*scores) = (*scores) + 1; 
					info = "";
				}
			} 
			else { 
				//
				info = info + line[i]; 
			}
		}
		(*bowlingPlayers) = (*bowlingPlayers) + 1;
	}

	return true; //true is returned which closes the function since its a bool retruning funct
}


// this function get average scores  takes an array of structs and retruns the average score
void GetAverageScore(bowler *players, int bowlingPlayers, int scores) {
	//we initialize each average to 0
	int average = 0;
	//than we use a nested for loop to get the players with the first loop and with the 
	for (int i = 0; i < bowlingPlayers; i = i + 1) { 
		average = 0; 
		//second loop we update the average of each individuals average in the players array in the str
			for (int j = 0; j < scores; j = j + 1) { 
				average = average + players[i].scores[j]; 
		}
		players[i].scoreAverage = average /(float) scores; 
	}
}



//we use the function PrettyPrintResults (which is a void function) that formats the output of the bowlers and their score averages. Also adds a header to the output
void PrettyPrintResults(bowler *players, int bowlingPlayers) {
  cout << setw(50) << setfill(asterisk) << asterisk << endl;
  cout << setfill('*') << setw(14) << asterisk << "Bowling Player Scores"
       << setfill('*') << setw(15) << asterisk << endl;
  cout << setw(50) << setfill(asterisk) << asterisk << endl;
  cout << endl;
//this loop prints the bolwers name and score on each iteration
	for (int i = 0; i < bowlingPlayers; i = i + 1) { 
		cout << "Bowler Name: " << players[i].bowlerName << endl;
		cout << "Score Average: " << players[i].scoreAverage << endl;
		cout << endl;
	}
}

int main() {
	//arrays to store the data and initailzie variables to 0
	bowler players[numberOfPlayers];
	int bowlingPlayers = 0;
	int scores = 0;
	string file = "BowlingScores.txt";

//Read data from file
	bool result = GetBowlingData(players, &bowlingPlayers, &scores, "BowlingScores.txt");
	GetAverageScore(players, bowlingPlayers, scores);
	PrettyPrintResults(players, bowlingPlayers);
	
	return 0;
}
