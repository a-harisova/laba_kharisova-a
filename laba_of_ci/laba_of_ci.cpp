// laba_c++.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct PIPE
{
	int id;
	double length;
	double diameter;
	string repair;
};

struct KS
{
	int id;
	string name;
	int number_of_workshops;
	int number_of_working_workshops;
	double efficiency;
};

void Output(PIPE& pipe)
{
	cout << "ID = " << pipe.id;
	cout << "Length = " << pipe.length;
	cout << "Diameter = " << pipe.diameter;
	cout << "Indicator under repair = " << pipe.repair;
}

PIPE Input_Pipe()
{
	PIPE pipe;
	pipe.id = 0;
	cout << "How long is the pipe? Please enter a number without spaces: ";
	cin >> pipe.length;
	cout << "What is the diameter of the pipe? Please enter a number: ";
	cin >> pipe.diameter;
	pipe.repair = 'no';
	return pipe;
}

KS Input_KS()
{
	KS ks;
	ks.id = 0;
	cout << "Please enter the name of compressor station: ";
	cin >> ks.name;
	cout << "Please enter the number of workshops of the compressor station: ";
	cin >> ks.number_of_workshops;
	cout << "Please enter the number of workshops of the compressor station, that are currently operating: ";
	cin >> ks.number_of_working_workshops;
	ks.efficiency = 80;
	return ks;
}

int main()
{
	PIPE pipe = Input_Pipe();
	KS ks = Input_KS();
	Output(pipe);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
