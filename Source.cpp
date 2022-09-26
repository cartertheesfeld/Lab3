/*
Carter Theesfeld
C++ Fall 2022
Due September 26, 2022
Lab 3: User and File I/O
Program that teaches how to get user input from a file and from the computer 
*/
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


//gets input from files
string inputFileName = "inMeanStats.dat";
string outFileName = "outMeanStats.dat";

//saves the values from the file
int a;
int b;
int c;
int d;
float mean;
float pop;

//creates the files
ifstream infile;
ofstream outfile;

//declares the void calculations
void calculations();
void fileCalculations();
void userInput();
void fileInput();

int main()
{
	userInput();
	calculations();
	fileInput();
	fileCalculations();

	outfile.close();
	infile.close();
	return 0;
}

//user input from keyboard
void userInput()
{
	
	cout << "Please type in a integer: ";
	cin >> a;
	cout << "Please type in a integer: ";
	cin >> b;
	cout << "Please type in a integer: ";
	cin >> c;
	cout << "Please type in a integer: ";
	cin >> d;

	cout << "The numbers you chose were: " << a << " " << b << " " << c << " " << d << endl;
}
void meanCalc()
{
	mean = float(a + b + c + d) / 4.0;
}

void popSDCalc()
{
	pop = sqrt((pow((a - mean), 2) + pow((b - mean), 2) + pow((c - mean), 2) + pow((d - mean), 2)) / 4);
}

// a function for mean and population standard deviation and print it to the screen
void calculations()
{
	meanCalc();
	cout << "The mean is: " << mean;
	popSDCalc();
	cout << endl << "The Population standard deviation is: " << pop;
}

void fileInput()
{
	//first takes file input output
	infile.open(inputFileName);

	if (!infile)
		cout << "Can't find file!\n";

	infile >> a >> b >> c >> d;
	//cout << a << b << c << d;
	outfile.open(outFileName);

}

//make a function for mean and population standard deviation that prints to a file
void fileCalculations()
{
	meanCalc();
	outfile << "The mean is: " << mean << endl;


	popSDCalc();
	outfile << "The Population standard deviation is: " << pop;
}
