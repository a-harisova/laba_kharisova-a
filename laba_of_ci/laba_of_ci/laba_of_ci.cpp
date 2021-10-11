// laba_c++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <fstream>
#include <tuple>

using namespace std;

struct PIPE
{
	int id = 0;
	double length = 0;
	double diameter = 0;
	bool repair = false;
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
		 << "7. Dowload" << endl
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
		if (pipe.repair)
			cout << "Repairs needed - yes" << endl;
		else cout << "Repairs needed - no" << endl;
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
		if (cin.fail() || value < 0 || cin.peek() != '\n' || value >= 1000000)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Please, enter correct data: " << endl;
		}
		else return value;
	}
}

PIPE Input_Pipe()
{
	PIPE pipe;
	cout << "Please, enter the pipe ID: ";
	pipe.id = Check_Number();
	cout << "How long is the pipe? Please enter a double value: ";
	pipe.length = Check_Number();
	cout << "What is the diameter of the pipe? Please enter an integer value: ";
	pipe.diameter = Check_Number();
	pipe.repair = false;
	return pipe;
}

KS Input_KS()
{
	KS ks;
	cout << "Please, enter the ks ID: ";
	ks.id = Check_Number();
	cout << "Please enter the name of compressor station: ";
	cin.ignore(2000, '\n');
	getline(cin, ks.name);
	cout << "Please enter the integer value of workshops of the compressor station: ";
	ks.number_of_workshops = Check_Number();
	do
	{
		cout << "Please enter the integer value of workshops of the compressor station, that are currently operating. ";
		cout << "The number must be less than value of workshops of the compressor station!: ";
		ks.number_of_working_workshops = Check_Number();
	} while (ks.number_of_workshops < ks.number_of_working_workshops);
	ks.efficiency = 80;
	return ks;
}

void Output_In_File(const PIPE& pipe, const KS& ks)
{

	if (pipe.length == 0)
	{
		cout << "No pipe information, fill in the data an try again." << endl;
	}
	if (ks.number_of_workshops == 0)
	{
		cout << "No KS information, fill in the data an try again." << endl;
	}
	ofstream fout;
	fout.open("PIPE_and_KS.txt");
	if (fout.is_open())
	{
		fout << pipe.id << endl;
		fout << pipe.length << endl;
		fout << pipe.diameter << endl;
		fout << pipe.repair << endl;
		fout << ks.id << endl;
		fout << ks.name << endl;
		fout << ks.number_of_workshops << endl;
		fout << ks.number_of_working_workshops << endl;
		fout << ks.efficiency << endl;
		fout.close();
	}
	else
	{
		cout << "Error! Text file didn't open! Try again." << endl;	
	}
}

tuple<PIPE, KS> Input_From_File()
{
	PIPE pipe;
	KS ks;
	ifstream fin;
	fin.open("PIPE_and_KS.txt");
	if (fin.is_open())
	{
		fin >> pipe.id;
		fin >> pipe.length;
		fin >> pipe.diameter;
		fin >> pipe.repair;
		fin >> ks.id;
		fin >> ks.name;
		fin >> ks.number_of_workshops;
		fin >> ks.number_of_working_workshops;
		fin >> ks.efficiency;
		fin.close();
	}
	else
	{
		cout << "File didn't open! Please, try again.";
	}
	return { pipe, ks };
}

void Edit_Pipe(PIPE& pipe)
{
	pipe.repair = (!pipe.repair);
}
void Edit_KS(KS& ks)
{
	if (ks.number_of_workshops == 0)
	{
		cout << "No KS information, fill in the data an try again." << endl << endl;
		return;
	}
	cout << "What do you want to do?" << endl;
	cout << "Enter 1 if you want to create a new workshop." << endl;
	cout << "Enter 2 if you want to start an existing workshop." << endl;
	cout << "Enter 3 if you want to stop an existing workshop." << endl;
	cout << "Enter 1 or 2 or 3: ";
	int choice = Check_Number();
	switch(choice)
	{
		case 1:
		{
			ks.number_of_workshops++;
		}
		case 2:
		{
			if (ks.number_of_workshops == ks.number_of_working_workshops)
			{
				cout << "\nIt is impossible to start the existing workshop, since all the workshops are working." << endl << endl;
			}
			else
			{
				ks.number_of_working_workshops++;
			}
		}
		case 3:
		{
			if (ks.number_of_working_workshops == 0)
			{
				cout << "\nIt is impossible to stop the existing workshop, since all the workshops aren't working." << endl << endl;
			}
			else
			{
				ks.number_of_working_workshops--;
			}
		}
		default:
		{
			system("cls");
			cout << "Error!" << endl;
			Edit_KS(ks);
		}
	}
}

int main()
{
	PIPE pipe;
	KS ks;
	while (1)
	{
		PrintMenu();
		int i;
		i = Check_Number();
		system("cls");
		switch (i)
		{
			case 1:
			{
				pipe = Input_Pipe();
				break;
			}
			case 2:
			{
				ks = Input_KS();
				break;
			}
			case 3: 
			{
				Output_Pipe(pipe);
				Output_KS(ks);
				break;
			}
			case 4:
			{
				Edit_Pipe(pipe);
				break;
			}
			case 5:
			{
				Edit_KS(ks);
				break;
			}
			case 6:
			{
				Output_In_File(pipe, ks);
				break;
			}
			case 7:
			{
				tie(pipe, ks) = Input_From_File();
				break;
			}
			case 0:
			{
				return 0;
			}
			default:
			{
				system("pause");
				cout << "Error! Please try again!" << endl;
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
