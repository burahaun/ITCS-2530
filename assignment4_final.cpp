/*
                                                        								Progamming Assignment 4

Name: Burahaun Uddin
Date: 06/16/2022
Class: ITCS-2530

this program will calculate the number of vowels in a .txt file. it will return the total number of vowels also. it will also be run from the command line.

libraries and variables are declared before the main() function
        */

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstring>

const char asterisk = '*';
const char period = '.';
using namespace std;
const char a = 'a';
const char A = 'A';
const char E = 'E';
const char I = 'I';
const char O = 'O';
const char U = 'U';
const char e = 'e';
const char i = 'i';
const char o = 'o';
const char u = 'u';
int numOfA = 0, numOfE = 0, numOfI = 0, numOfO = 0, numOfU = 0, totalVowels = 0;

int main(int argc, char* argv[]) {
  // header of program
	string line;
	fstream myFile;
	myFile.open(argv[1]);
  cout << setw(50) << setfill(asterisk) << asterisk << endl;
  cout << setfill('*') << setw(11) << asterisk << "Welcome to my letter counter"
       << setfill('*') << setw(11) << asterisk << endl;
  cout << setw(50) << setfill(asterisk) << asterisk << endl;
  cout << endl;

  cout << "Analyzing file" << endl;
  
	if (myFile.is_open()) {
    char letter;
    while (myFile.get(letter)) {
      if (letter == a || letter == A) {
        numOfA = numOfA + 1;
      }
      if (letter == e || letter == E) {
        numOfE = numOfE + 1;
      }
      if (letter == i || letter == I) {
        numOfI = numOfI + 1;
      }
      if (letter == o || letter == O) {
        numOfO = numOfO + 1;
      }
      if (letter == u || letter == U) {
        numOfU = numOfU + 1;
      }
    }
  }

  totalVowels = numOfA + numOfE + numOfI + numOfO + numOfU;

  cout << left << setw(50) << setfill(period) << "The number of A's" << numOfA
       << endl;
  cout << left << setw(50) << setfill(period) << "The number of E's" << numOfE
       << endl;
  cout << left << setw(50) << setfill(period) << "The number of I's" << numOfI
       << endl;
  cout << left << setw(50) << setfill(period) << "The number of O's" << numOfO
       << endl;
  cout << left << setw(50) << setfill(period) << "The number of U's" << numOfU
       << endl;
  cout << left << setw(50) << setfill(period) << "The vowel count is" << totalVowels << endl;

  return 0;
}
