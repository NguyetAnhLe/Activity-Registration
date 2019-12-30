#include "Validation Function Prototypes.h"
#include "After School Activities Prototypes.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void printMenu() {
	string menu[] = {
		"*******************************************************",
		"*             Welcome to Delta's School               *",
		"*                                                     *",
		"* Please enter your choice:                           *",
		"*       [1] Register for After School Activities      *",
		"*       [2] Print report                              *",
		"*       [3] Exit                                      *",
		"*                                                     *",
		"*******************************************************",
		"" };
	printBanner(menu);
}

int loadData(string activity[], string time[], string description[], string purpose[], ifstream &inStream) {
	int numOfReadData;

	for (numOfReadData = 0; !inStream.fail(); numOfReadData++) {
		inStream.ignore(80, '{');
		getline(inStream, activity[numOfReadData], '}');
		inStream.ignore(80, '[');
		getline(inStream, time[numOfReadData], ']'); 
		inStream.ignore(80, '(');
		getline(inStream, description[numOfReadData], ')'); 
		inStream.ignore(80, '<');
		getline(inStream, purpose[numOfReadData], '>'); 

	}
	return numOfReadData;
}

void printActivities(string activity[], int n, ostream &os){
	os << "\n\n\tHere are options of the activities: ";
	
	for (int h = 0; h <= n-2; h++) {
	os  << endl << "\t\t" << "["<< h+1<< "] " << activity[h];
	
	}
}

void printSchedule(string activity[], string time[], string description[], string purpose[], int n,int SYMBOL, ostream &os) {
	os
		<< endl << endl
		<< setw(80) << setfill((char)SYMBOL) << ""
		<< "\n\t\t\t" << activity[n - 1] << endl << endl
		<< "\t" << time[n - 1] << endl
		<< "\t" << description[n - 1] << endl
		<< "\t" << purpose[n - 1] << endl<<endl
		<< setw(80) << setfill((char)SYMBOL) << "" <<endl;
}

void printClassChoose(string activity[], int n, ostream &os) {
	os
		<< "\n\n\t\t   ******************************"
		<< "\n\n\t Your child will be registered for "
		<< activity[n - 1]
		<< " class."
		<< "\n\n\t\t   *******************************\n";
}
void printClassReg(string activity[], int n, ostream &os) {
	os << activity[n - 1] << " class.";
}

string getClassName(string activity[], int n) {
	string name;
	name = activity[n - 1];
	return name;
}

double calTotalFee(double monthlyFee, double extraFee, int condition) {
	double totalFee = 0;
	double noExtraFee = 0;
	totalFee = monthlyFee + (condition != 1 ? noExtraFee : extraFee);
	return totalFee;

}

int readReport(string line[],ifstream &inputFile) {
	int num;
	for (num = 0; !inputFile.fail(); num++) {
		getline(inputFile, line[num],'*');
	
	}
	return num;
}

void printReport(string line[], int n, ostream &os) {

	for (int h = 0; h <= n - 2; h++) {
		os << endl << line[h];
	}

}
