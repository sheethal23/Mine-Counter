
#include<iostream>		//Pre defined header files
#include<iomanip>
#include<vector>
#include<cstdlib>

using std::cout;		//Appropriate using statements used in the program
using std::cin;			//
using std::setw;		//
using std::setfill;		//
using std::vector;
using std::endl;

#ifndef prog5_h		//Header guards
#define prog5_h		//
#endif

/************************************************************************************************************************************
Function buildMineField( vector< vector<bool> > &, double &): Determines if a location in vector of mines has a mine.
*************************************************************************************************************************************/

void buildMineField( vector< vector<bool> > &, double &);	//Function declaration which are used in the program

/************************************************************************************************************************************
Function fixcounts(vector< vector<bool> > &, vector< vector<unsigned int> > &):checks boolean value for each locations and sets value. 
*************************************************************************************************************************************/

void fixcounts(vector< vector<bool> > &, vector< vector<unsigned int> > &);

/*************************************************************************************************************************************
Function displayMineLocations(vector< vector<bool> > &): Displays the mine feild and display "X" in each mine location
**************************************************************************************************************************************/

void displayMineLocations(vector< vector<bool> > &);

/**************************************************************************************************************************************
Function displayMineCounts(vector< vector<unsigned int> > &): Displays the minecounts for each mine locations.
***************************************************************************************************************************************/

void displayMineCounts(vector< vector<unsigned int> > &);

