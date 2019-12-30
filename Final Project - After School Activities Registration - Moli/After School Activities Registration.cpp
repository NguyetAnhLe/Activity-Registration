// This is a After School Activities Registration program that will be filled by parents of the Children are attending Delta's School.
// After School Activities Registration - Final Project
// Programmer: Anh Le ( Moli )
// Last Modified: May 2, 2016

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Validation Function Prototypes.h"
#include "After School Activities Prototypes.h"

using namespace std;

void main() {
	const int
		REGISTER = 1,
		REPORT = 2,
		EXIT = 3,
		SYMBOL = 4, // diamond symbol
		SIZE = 100;
	string title[] = {
		"This is a After School Activities Registration program",
		"that need to be filled by parents of the children are attending Delta's School",
		"by Moli",
		""
	};
	string report[] = {
		"REPORT",
		"=================================",
		""
	};

	string parentFirstName, parentLastName, childFirstName, childLastName, classChoose, 
		line[SIZE], activity[SIZE], time[SIZE], note[SIZE], purpose[SIZE];
	ifstream inputFile;
	ofstream outputFile;
	int n, numberOfClass, classes, menuChoice, numberOfStudent;
	char choice, yesNo;
	double	individualFee, monthlyFee, numberOfChildren, money;

	cout.imbue(locale(""));
	cout << fixed << setprecision(2);

	system("color A0");
	system("title After School Activities Registration");

	cout << endl;
	printBanner(title);

	while (true) {
		cout << endl << endl;
		printMenu();
		cout << "\n\n Please enter your choice: ";
		menuChoice = getRangeNumber(1, 3);

		system("CLS");

		switch (menuChoice) {
		case EXIT:
			cout << "\n\n Thank you for using our program.\n Please hit Enter to terminate.\n";
			cin.get();
			exit(menuChoice);

			break;

		case REGISTER:
			system("color B0");

			// Read Custom Tuition Fee from file
			inputFile.open("InputSchoolFee.txt");
			inputFile.ignore(10000, '$');
			inputFile >> monthlyFee;
			inputFile.ignore(10000, '$');
			inputFile >> individualFee;
			inputFile.close();
			// End reading input file

			//Registration starts here
			outputFile.open("Report.txt", ios::app);

			//Read input file of activities
			inputFile.open("After School Activity Classes input.txt");
			numberOfClass = loadData(activity, time, note, purpose, inputFile);
			inputFile.close();
			// End reading input file

			printActivities(activity, numberOfClass);

			cout
				<< "\n\nIf you want to see more information about the classes, hit \"I\"."
				<< "\n\tIf you already decided, hit \"R\" for register. ";
			choice = getTwoLetterRange('I', 'R');

			if (choice == 'I' || choice == 'i') {
				system("CLS");
				printActivities(activity, numberOfClass);
				cout << "\n\nPlease enter your choice from 1 to " << numberOfClass - 1 << ": ";
				classes = getRangeNumber(1, numberOfClass - 1);
				printSchedule(activity, time, note, purpose, classes, SYMBOL);

				cout
					<< endl
					<< "Do you want to see the information of others class? (Y/N): ";
				yesNo = getTwoLetterRange('Y', 'N');

				while (yesNo == 'Y' || yesNo == 'y') {
					cout << "\nPlease enter your choice from 1 to " << numberOfClass - 1 << ": ";
					classes = getRangeNumber(1, numberOfClass - 1);

					printSchedule(activity, time, note, purpose, classes, SYMBOL);

					cout << "\nDo you want to see the information of others class? (Y/N): ";
					yesNo = getTwoLetterRange('Y', 'N');
				}
				system("CLS");
			}

			cout
				<< "\n Do you want to register for classes? "
				<< "\n  Please hit \"R\" to continue the registration or \"M\" to go back to the main menu";
			yesNo = getTwoLetterRange('R', 'M');

			if (yesNo == 'R' || yesNo == 'r') {
				system("CLS");

				cout << "\n\nWhat is your first name? ";
				parentFirstName = getName();
				cout << "What is your last name? ";
				parentLastName = getName();

				cout
					<< "\nHello Mr/Mrs. " << parentLastName << ", \n\tThank you for interest in After School Program of Delta's School."
					<< endl << endl << setw(80) << setfill((char)SYMBOL) << "";
				cout << setfill(' ');

				cout << "\nHow many children you want register for After School Activities? "
					<< "\n\t < Depend on how many chidren, there will be an exact number of registration form > ";
				numberOfChildren = getWholePositiveNumber();

				system("CLS");

				for (n = 1; n <= numberOfChildren; n++) {
					int individual = 0;
					double totalFee = 0;

					cout << "\n\t\t\t REGISTRATION #" << n;

					cout << "\n\nWhat is your child's first name? ";
					childFirstName = getName();
					cout << "What is your child's last name? ";
					childLastName = getName();

					printActivities(activity, numberOfClass);

					cout
						<< "\n\nWhich class you want to register for your kid?"
						<< "\n\tPlease enter a number from 1 to " << numberOfClass - 1 << ": ";
					classes = getRangeNumber(1, numberOfClass - 1);

					printClassChoose(activity, classes);

					cout << "\nPlease hit \"Y\" to comfirm or hit \"N\" to try again: ";
					yesNo = getTwoLetterRange('Y', 'N');

					while (yesNo == 'N' || yesNo == 'n') {
						printActivities(activity, numberOfClass);

						cout
							<< "\nPlease choose again. Which class you want to register for your kid?"
							<< "\n\tPlease enter a number from 1 to " << numberOfClass - 1 << ": ";
						classes = getRangeNumber(1, numberOfClass - 1);

						printClassChoose(activity, classes);

						cout << "\nPlease hit \"Y\" to comfirm or hit \"N\" to try again: ";
						yesNo = getTwoLetterRange('Y', 'N');
					}

					cout
						<< endl << setw(80) << setfill((char)SYMBOL) << ""
						<< endl << "\t\t" << childFirstName << " " << childLastName << " is registered in ";
					printClassReg(activity, classes);
					cout
						<< endl << endl
						<< setw(80) << setfill((char)SYMBOL) << "";
					cout << setfill(' ');

					cout << "\n\n Please hit Enter to continue";
					cin.get();
					system("CLS");

					cout << "\n\n The Monthly Fee will be: $" << monthlyFee << " per class.";

					// Ask for Extra Fee or not
					cout
						<< "\n\n Delta's School also offer individual intructor for each class"
						<< "\n\t with $" << individualFee << " per class.\n"
						<< "\n\n Do you prefer to have a personal intructor for your kid ? "
						<< "\n Please choose: (Y/N) ";

					yesNo = getTwoLetterRange('Y', 'N');
					if (yesNo == 'y' || yesNo == 'Y') {
						individual = 1;
					}
					totalFee = calTotalFee(monthlyFee, individualFee, individual);

					cout
						<< "\n\n\t****************************************"
						<< "\n\nYour total amount due will be: $" << totalFee << " a month. "
						<< "\n\tHit \"S\" to submit or \"C\" to cancel the registration. "
						<< "\n\n *** Please notice that if you hit cancel, \n\tyou will have to go all the process again. ";
					yesNo = getTwoLetterRange('C', 'S');

					if (yesNo == 'c' || yesNo == 'C') {
						system("CLS");
						break;
					}

					cout
						<< endl << setw(80) << setfill((char)SYMBOL) << ""
						<< "\n*** Congratulation!!! You have sucessfully register for ";
					printClassReg(activity, classes);
					cout
						<< " ***" << endl << endl
						<< setw(80) << setfill((char)SYMBOL) << "";
					cout << setfill(' ');

					//Write in output File
					classChoose = getClassName(activity, classes);

					outputFile
						<< "Parent: " << parentFirstName << " " << parentLastName << endl
						<< "Student Name: " << childFirstName << " " << childLastName << endl
						<< "Resgister in " << classChoose << " : "
						<< (individual == 1 ? " Individual Tutor. " : " Group Class. ") << endl
						<< "Total Amount: $" << totalFee << endl << endl
						<< "\t\t\t===================================*\n\n";

					cout << "\n\n Please hit Enter to continue";
					cin.get();
					system("CLS");

				}
			}
			outputFile.close();
			cout << setfill(' ');
			system("CLS");

			break;

			// Print all registration Report
		case REPORT:
			system("color F0");
			double totalAmountEarn = 0;

			//Open Report file
			inputFile.open("Report.txt");
			cout << endl << endl;
			printBanner(report);

			numberOfStudent = readReport(line, inputFile);

			cout << endl;
			printReport(line, numberOfStudent);
			cout << "***There" << (numberOfStudent - 2 == 1 ? " is " : " are ") << numberOfStudent - 2 << " student" << (numberOfStudent - 1 == 1 ? "" : "s") << " registered in the After School Program.";
			inputFile.close();
			// Done print out report

			//Read to calculate the sum amount
			inputFile.open("Report.txt");
			inputFile.ignore(1000, '$');
			while (inputFile >> money) {
				inputFile.ignore(1000, '$');
				totalAmountEarn += money;
			}
			inputFile.close();

			//Print out calculation report of the total amount of all payments
			cout
				<< "\n\nTotal Amount from " << numberOfStudent - 2 << " student" << (numberOfStudent - 2 == 1 ? "" : "s") << " is $" << totalAmountEarn << " dollars."
				<< "\n  Average fee for each student is $" << totalAmountEarn / (numberOfStudent - 2) << " dollars.";

			cout << "\n\n Please hit Enter to continue";
			cin.get();
			system("CLS");

			break;
		}
	}
}