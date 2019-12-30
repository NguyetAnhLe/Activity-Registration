#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
 
// Pre-Conditions:	None
// Post-Conditions:	It will print the menu choice using the output stream object
void printMenu();

// Pre-Conditions:	activity, time, description, purpose are string array, and input file.
// Post-Conditions:	It will read specific line of string from input file
//					Will return a interger
int loadData( string activity[], string time[], string description[], string purpose[], ifstream &inStream);

// Pre-Conditions:	activity is string array, interger n
// Post-Conditions:	It will print out specific line of string activities from input file
void printActivities( string activity[],int n , ostream &os = cout);

//int getFileLine(ifstream &file);

// Pre-Conditions:	activity, time, description, purpose are string array, and interger n
// Post-Conditions:	It will print out specific line of string from input file
void printSchedule(string activity[], string time[], string description[], string purpose[], int n, int SYMBOL, ostream &os=cout);

// Pre-Conditions:	activity is string array, integer n
// Post-Conditions:	It will print out specific line of string activities from input file
void printClassChoose(string activity[], int n, ostream &os = cout);

// Pre-Conditions:	activity is string array, integer n
// Post-Conditions:	It will print out specific line of string activities from input file
void printClassReg(string activity[], int n, ostream &os = cout);

// Pre-Conditions:	activity is string array, integer n
// Post-Conditions:	It will get the specific line of string activities from input file
//					Will return a string
string getClassName(string activity[], int n);

// Pre-Conditions:	string array, double , integer inputfile
// Post-Conditions:	It will read and print out all line from report file
void printReport(string line[], int n, ostream &os = cout);

// Pre-Conditions:	double monthlyFee and extraFee, and a interger 
// Post-Conditions:	It will calculate the total amount
//					Will return a double
double calTotalFee(double monthlyFee, double extraFee, int condition);

// Pre-Conditions:	string array line, and input file.
// Post-Conditions:	It will read specific line of string from input file
//					Will return a interger
int readReport(string line[],ifstream &inputFile);

