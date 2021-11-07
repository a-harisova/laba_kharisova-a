// laba_c++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <fstream>
#include <tuple>
#include <map>

using namespace std;
int kol_pipe = 1;
int kol_ks = 1;

struct PIPE
{
	int id;
	double length;
	double diameter;
	bool repair = false;
};

struct KS
{
	int id;
	string name;
	int number_of_workshops;
	int number_of_working_workshops;
	double efficiency;
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
		 << "Choose action, please: ";
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

template <typename type>
type Get_Correct_Number(type min, type max)
{
	type value;
	while ((cin >> value).fail() || value < min || value > max)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Please enter correct data (" << min << "-" << max << ") : ";
	}
	return value;
}

PIPE Input_Pipe()
{
	PIPE pipe;
	pipe.id = kol_pipe;
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
	ks.id = kol_ks;
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

void Output_In_File(ofstream& fout, const map <int, PIPE&> pipes, const map <int, KS&> kss)
{
	for (int i = 0; i < kol_pipe - 1; i++)
	{
		fout << pipes[i].id << endl;
		fout << pipes[i].length << endl;
		fout << pipes[i].diameter << endl;
		fout << pipes[i].repair << endl;
	}
	for (int i = 0; i < kol_pipe - 1; i++)
	{
		fout << kss[i].id << endl;
		fout << kss[i].name << endl;
		fout << kss[i].number_of_workshops << endl;
		fout << kss[i].number_of_working_workshops << endl;
		fout << kss[i].efficiency << endl;
	}
}

tuple<PIPE, KS> Input_From_File(ifstream& fin)
{
	PIPE pipe;
	KS ks;
	fin >> pipe.id;
	fin >> pipe.length;
	fin >> pipe.diameter;
	fin >> pipe.repair;
	fin >> ks.id;
	fin >> ks.name;
	fin >> ks.number_of_workshops;
	fin >> ks.number_of_working_workshops;
	fin >> ks.efficiency;
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
	int choice = Get_Correct_Number(1, 3);
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

PIPE& Select_Pipe(map <int, PIPE>& pipes)
{
	if (pipes.size() == 0)
	{
		cout << "Error!Pipes don't enter" << endl;
	}
	else 
	{
		cout << "Please enter pipe index (1, " << kol_pipe << "): ";
		unsigned int index = Get_Correct_Number(1u, pipes.size());
		return pipes[index - 1];
	}
}

KS& Select_KS(map <int, KS>& kss)
{
	if (kss.size() == 0)
	{
		cout << "Error! KS don't enter" << endl;
	}
	else 
	{
		cout << "Please enter ks index(1, " << kol_ks << "): ";
		unsigned int index = Get_Correct_Number(1u, kss.size());
		return kss[index - 1];
	}
}

void operator << (ostream& out, PIPE& pipe)
{
	out << "PIPE INFORMATION: " << endl;
	out << "ID = " << pipe.id << endl;
	out << "Length = " << pipe.length << endl;
	out << "Diameter = " << pipe.diameter << endl;
	if (pipe.repair)
		out << "Repairs needed - yes" << endl;
	else out << "Repairs needed - no" << endl;
}

void operator << (ostream& out, KS& ks)
{
	out << "KS INFORMATION: " << endl;
	out << "ID = " << ks.id << endl;
	out << "Name = " << ks.name << endl;
	out << "The number of workshops of the compressor station = " << ks.number_of_workshops << endl;
	out << "The number of workshops of the compressor station, that are currently operating = " << ks.number_of_working_workshops << endl;
	out << "Efficiency, % = " << ks.efficiency << endl << endl;
}

int main()
{
	map <int, PIPE> pipes = {};
	map <int, KS> kss = {};
	PIPE pipe;
	KS ks;
	while (1)
	{
		system("cls");
		PrintMenu();
		switch (Get_Correct_Number(0, 7))
		{
			case 1:
			{
				pipe = Input_Pipe();
				pipes[kol_pipe] = { pipe };
				kol_pipe++;
				break;
			}
			case 2:
			{
				ks = Input_KS();
				kss[kol_ks] = { ks };
				kol_ks++;
				break;
			}
			case 3: 
			{
				if (pipe.id != 0)
				{
					cout << pipe;
				}
				else {
					cout << "Please enter information" << endl;
				}
				if (ks.id != 0)
				{
					cout << ks;
				}
				else {
					cout << "Please enter information" << endl;
				}
				break;
			}
			case 4:
			{
				cout << "Do you want to edit all pipes or one? Please, enter 1 if all pipes or 2 if one pipe: ";
				switch (Get_Correct_Number(1, 2))
				{
					case 1:
					{
						if (pipe.id != 0)
						{
							Edit_Pipe(pipe);
						}
					}
					case 2:
					{
						Edit_Pipe(Select_Pipe(pipes));
					}
				}
				break;
			}
			case 5:
			{
				cout << "Do you want to edit all kompression stations or one? Please, enter 1 if all kss or 2 if one ks: ";
				switch (Get_Correct_Number(1, 2))
				{
					case 1:
					{
						if (ks.id != 0)
						{
							Edit_KS(ks);
						}
					}
					case 2:
					{
						Edit_KS(Select_KS(kss));
					}
				}
				break;
			}
			case 6:
			{
				ofstream fout;
				fout.open("PIPE_and_KS.txt");
				if (fout.is_open())
				{
					fout << kol_pipe << endl;
					fout << kol_ks << endl;
					Output_In_File(fout, pipes, kss);
					fout.close();
				}
				else
				{
					cout << "Error! Text file didn't open! Try again." << endl;
				}
				break;
			}
			case 7:
			{
				ifstream fin;
				fin.open("PIPE_and_KS.txt");
				if (fin.is_open())
				{
					int pipes_size, kss_size;
					fin >> pipes_size;
					fin >> kss_size;
					int size = max(pipes_size, kss_size);
					while (size--)
					{
						tie(pipe, ks) = Input_From_File(fin);
						pipes[kol_pipe] = { pipe };
						kss[kol_ks] = { ks };
						kol_pipe++;
						kol_ks++;
					}	
					fin.close();
				}
				else
				{
					cout << "File didn't open! Please, try again.";
				}
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
 