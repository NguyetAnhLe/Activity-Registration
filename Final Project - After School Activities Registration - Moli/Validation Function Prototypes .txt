
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;
// Pre-Conditions:	Tiltle must be a string array
// Post-Conditions:	It will print the title using the output stream object
void printBanner(string title[]);

// Pre-Conditions:	None
// Post-Condition:	Will return a string
//					Will not take any initial white space at the beginning
string getName();

// Pre-Conditions:	None
// Post-Condition:	Will return a double number
//					Will not crash if there is any non - numberic input
double getDouble();

// Pre-Conditions:	None
// Post-Condition:	Will return a number
//					Will not crash if there is any non - numberic input
//					Will take only number that more than zero
double getPositiveNumber();

// Pre-Conditions:	None
// Post-Condition:	Will return a number
//					Will not crash if there is any non - numberic input
//					Will take only WHOLE number that more than zero
double getWholePositiveNumber();

// Pre-Conditions: None
// Post-Condition:	Will return a character
//					Will take only a first input character
char getChar();

// Pre-Conditions:	None
// Post-Condition:	Will return a number
//					Will not crash if there is any non - numberic input 
double getRangeNumber(int min, int max);

// Pre-Conditions: None
// Post-Condition:	Will return a character
//					Will take only letter from a to z or A to Z
char getLetter();

// Pre-Conditions: two letters a and b
// Post-Condition:	Will return a letter
//					Will take only letter from range a to b or A to B
char getTwoLetterRange(char a, char b);

// Pre-Conditions:	None
// Post-Condition:	Will return a double number
//					Will not crash if there is any non - numberic input
double getNumber();