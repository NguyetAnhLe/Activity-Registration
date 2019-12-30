#include "Validation Function Prototypes.h"
#include "After School Activities Prototypes.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void printBanner(string title[]) {
	int n = 0, a,size = 0;

	while (title[size] != "")
		size++;

	for (n; n < size; n++) {
		a = (80 - title[n].size()) / 2;
		cout << setw(a) << "" << title[n] << endl;
	}
}
char getChar() {
	char ch;
	cin >> ch; cin.ignore(100, '\n');
	return ch;
}

char getLetter() {
	char letter;
	letter = getChar();
	while (letter < 'A' || letter > 'Z' && letter < 'a' || letter >'z') {
		cout << "\t" << letter << " is NOT a letter. Try again: ";
		letter = getChar();
		}
	return letter;
}

char getTwoLetterRange(char a, char b) {
	char letter;
	letter = getLetter();
	while (letter != a  && letter != tolower(a) && letter != b && letter != tolower(b)) {
		cout << "\tPlease choose between \""<<a<<"\" and \""<<b<<"\". Please try again: ";
		letter = getLetter();
	}
	return letter;
}

string getName() {
	char name[100];
	cin >> ws;
	cin.get(name, 100);
	return name;
}

double getDouble() {
	double number;
	number = getNumber();
	return number;
}

double getPositiveNumber() {
	double number;
	number = getDouble();
	while (number < 0) {
		cout << "\tPlease give a positive number: ";
		number = getDouble();
	}
	return number;
}

double getWholePositiveNumber() {
	double number;
	number = getPositiveNumber();
	while (number != (int)number) {
		cout << "\tPlease give a whole number: ";
		number = getPositiveNumber();
	}
	return number;
}

double getNumber(){
	double number;
while (!(cin >> number)) {
	cin.clear(); cin.ignore(10000, '\n');
	cout << "\tNo letter please. Try again: ";
}
cin.ignore(80, '\n');
return number;
}

double getRangeNumber(int min , int max) {
	double number;
	number = getWholePositiveNumber();
	while (number < min || number > max) {
		cout << "\tPlease enter choice from " << min << " to " << max << ". Try again: ";
		number = getWholePositiveNumber();
	}
	return number;

}

