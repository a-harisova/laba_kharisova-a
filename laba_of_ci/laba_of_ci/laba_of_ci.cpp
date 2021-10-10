// laba_c++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct PIPE
{
	int id = 0;
	double length = 0;
	double diameter = 0;
	string repair;
};

struct KS
{
	int id = 0;
	string name;
	int number_of_workshops = 0;
	int number_of_working_workshops = 0;
	double efficiency = 0;
};

void PrintMenu()
{
	cout << "1. Input pipe" << endl
		 << "2. Input KS" << endl
		 << "3. Print all objects" << endl
		 << "4. Edit pipe" << endl
		 << "5. Edit KS" << endl
		 << "6. Save" << endl
		 << "7. Dowlonad" << endl
		 << "0. Exit" << endl
		 << "Choose an action? please: ";
}

void Output_Pipe(const PIPE& pipe)
{
	cout << "PIPE INFORMATION: " << endl;
	if (pipe.length == 0)
	{
		cout << "No data, please enter information" << endl << endl;
	}
	else 
	{
		cout << "ID = " << pipe.id << endl;
		cout << "Length = " << pipe.length << endl;
		cout << "Diameter = " << pipe.diameter << endl;
		cout << "Indicator under repair = " << pipe.repair << endl;
	}
}

void Output_KS(const KS& ks)
{
	cout << "\nKS INFORMATION: " << endl;
	if (ks.number_of_workshops == 0)
	{
		cout << "No data, please enter information" << endl << endl;
	}
	else
	{
		cout << "ID = " << ks.id << endl;
		cout << "Name = " << ks.name << endl;
		cout << "The number of workshops of the compressor station = " << ks.number_of_workshops << endl;
		cout << "The number of workshops of the compressor station, that are currently operating = " << ks.number_of_working_workshops << endl;
		cout << "Efficiency, % = " << ks.efficiency << endl << endl;
	}
	
}

double Check_Number()
{
	double value;
	while (true)
	{
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Please, enter correct data: ";
		}
		else return value;
	}
}

PIPE Input_Pipe()
{
	PIPE pipe;
	pipe.id = 0;
	cout << "How long is the pipe? Please enter a double value: ";
	pipe.length = Check_Number();
	cout << "What is the diameter of the pipe? Please enter an integer value: ";
	pipe.diameter = Check_Number();
	pipe.repair = "no";
	return pipe;
}

KS Input_KS()
{
	KS ks;
	ks.id = 0;
	cout << "Please enter the name of compressor station: ";
	cin >> ks.name;
	cout << "Please enter the integer value of workshops of the compressor station: ";
	ks.number_of_workshops = Check_Number();
	cout << "Please enter the number of workshops of the compressor station, that are currently operating: ";
	ks.number_of_working_workshops = Check_Number();
	ks.efficiency = 80;
	return ks;
}

void Output_In_File_Pipe(const PIPE& pipe)
{
	ofstream fout;
	fout.open("PIPE.txt");
	if (pipe.length == 0)
	{
		if (!fout.is_open())
		{
			cout << "Error, text file didn't open." << endl;
		}
		else 
		{
			fout << "No pipe information, fill in the data an try again." << endl;
		}
	}
	else
	{
		fout << "PIPE INFORMATION:" << endl;
		fout << "ID = " << pipe.id << endl;
		fout << "Length = " << pipe.length << endl;
		fout << "Diameter = " << pipe.diameter << endl;
		fout << "Indicator under repair = " << pipe.repair << endl;
	}
	fout.close();
}

void Output_In_File_KS(const KS& ks)
{
	ofstream fout;
	fout.open("KS.txt");
	if (ks.number_of_workshops <= 0)
	{
		if (!fout.is_open())
		{
			cout << "Error, text file didn't open." << endl;
		}
		else
		{
			fout << "No KS information, fill in the data an try again." << endl;
		}
	}
	else
	{
		fout << "KS INFORMATION:" << endl;
		fout << "ID = " << ks.id << endl;
		fout << "Nime = " << ks.name << endl;
		fout << "Number of workshops = " << ks.number_of_workshops << endl;
		fout << "Number of working workshops = " << ks.number_of_working_workshops << endl;
		fout << "Efficiency, % = " << ks.efficiency << endl;
	}
	fout.close();
}

void Input_In_File_Pipe(PIPE& pipe)
{
	ofstream fout;
	fout.open("Pipe.txt");

}

int main()
{
	PIPE pipe;
	KS ks;
	while (1)
	{
		PrintMenu();
		int i;
		cin >> i;
		switch (i)
		{
			case 1:
			{
				system("cls");
				pipe = Input_Pipe();
				break;
			}
			case 2:
			{
				system("cls");
				ks = Input_KS();
				break;
			}
			case 3: 
			{
				system("cls");
				Output_Pipe(pipe);
				Output_KS(ks);
				break;
			}
			case 4:
			{
				system("cls");
					
				break;
			}
			case 5:
			{
				system("cls");

				break;
			}
			case 6:
			{
				system("cls");
				Output_In_File_Pipe(pipe);
				Output_In_File_KS(ks);
				break;
			}
			case 7:
			{
				system("cls");

				break;
			}
			case 0:
			{
				return 0;
			}
		}
	}
	return 0;
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
