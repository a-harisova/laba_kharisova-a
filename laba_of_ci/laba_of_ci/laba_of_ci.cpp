// laba_c++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <fstream>
#include <tuple>
#include <unordered_map>
#include <vector>
#include "Pipe.h"
#include "Ks.h"
#include "Utils.h"

using namespace std;

void PrintMenu()
{
	cout << "1. Input pipe" << endl
		 << "2. Input KS" << endl
		 << "3. Print all objects" << endl
		 << "4. Edit pipe" << endl
		 << "5. Edit KS" << endl
		 << "6. Save" << endl
		 << "7. Dowload" << endl
		 << "8. Delete pipe" << endl
		 << "9. Delete KS" << endl
		 << "10. Search" << endl
		 << "0. Exit" << endl
		 << "Choose action, please: ";
}

void Input_From_File(ifstream& fin, unordered_map <int, PIPE>& pipes, unordered_map <int, KS>& kss)
{
	PIPE pipe;
	KS ks;
	int pipes_size, kss_size;
	fin >> pipes_size >> kss_size;
	for (int i = 1; i <= pipes_size; i++)
	{
		fin >> pipe;
		pipes.emplace(pipes.size() + 1, pipe);
	}
	for (int i = 1; i <= kss_size; i++)
	{
		fin >> ks;
		kss.emplace(kss.size() + 1, ks);
	}
}

template <typename type>
type& Select(unordered_map  <int, type>& smth)
{
	if (smth.size() == 0)
		cout << "Error! No data entered" << endl;
	else
	{
		cout << "Please enter index (1, " << smth.size() << "): ";
		unsigned int index = Get_Correct_Number(1u, smth.size());
		return smth[index];
	}
}

template <typename type>
void Delete(unordered_map  <int, type>& smth)
{
	if (smth.size())
	{
		cout << "Please, enter the index(1 - " << smth.size() << "): ";
		int index = Get_Correct_Number(1u, smth.size());
		smth.erase(index);
	}
	else
		cout << "Impossible to remove, since it hasn't yet been entered." << endl;
}

template <typename type, typename type_param>
using Filter = bool(*)(const type& smth, type_param param);
template <typename type>
bool Check_By_Name(const type& smth, string param)
{
	return smth.name == param;
}
bool Check_By_Repair(const PIPE& smth, bool param)
{
	return smth.repair != param;
}
bool Check_By_Number_Of_Workshops(const KS& smth, double param)
{
	return (smth.GetNumbOfWorkWorkshops() / smth.GetNumbOfWorkshops()) * 100 == param;
}

template <typename type, typename type_param>
vector <int> Find_By_Filter(const unordered_map <int, type>& map, Filter <type, type_param> f, type_param param)
{
	vector <int> res;
	for (auto& smth : map)
	{
		if (f(smth.second, param))
			res.push_back(smth.first);
	}
	return res;
}

void Filter_For_PIPE(unordered_map <int, PIPE>& pipes)
{
	if (pipes.size() == 0)
		return;
	cout << "What do you want to do?" << endl
		<< "Enter 1 if you want to filter by name." << endl
		<< "Enter 2 if you want to filter by repair." << endl;
	switch (Get_Correct_Number(1, 2))
	{
		case 1:
		{
			string name;
			cin >> ws;
			cin.ignore(2000, '\n');
			cout << "Please, enter pipe name: ";
			getline(cin, name);
			vector <int> IDs = Find_By_Filter(pipes, Check_By_Name, name);
			for (auto& id : IDs)
				cout << id << pipes[id];
			break;
		}
		case 2:
		{
			cout << "Please, enter 0 if pipes don't work and 1 if pipes work: ";
			bool repair = Get_Correct_Number(0, 1);
			vector <int> IDs = Find_By_Filter(pipes, Check_By_Repair, repair);
			for (auto& id : IDs)
				cout << id << pipes[id];
			break;
		}
		default:
		{
			cout << "Error! Please try again!" << endl;
		}
	}
}

void Filter_For_KS(unordered_map <int, KS>& kss)
{
	if (kss.size() == 0)
		return;
	cout << "What do you want to do?" << endl
		<< "Enter 1 if you want to filter by name." << endl
		<< "Enter 2 if you want to filter by number of workshops." << endl;
	switch (Get_Correct_Number(1, 2))
		{
		case 1:
		{
			string name;
			cin >> ws;
			cout << "Please, enter ks name: ";
			cin.ignore(2000, '\n');
			getline(cin, name);
			vector <int> IDs = Find_By_Filter(kss, Check_By_Name, name);
			for (auto& id : IDs)
				cout << id << kss[id];
			break;
		}
		case 2:
		{
			cout << "Please, enter the percentage of unused workshops: ";
			double percent = Get_Correct_Number(0.0, 100.0);
			vector <int> IDs = Find_By_Filter(kss, Check_By_Number_Of_Workshops, percent);
			for (auto& id : IDs)
				cout << id << kss[id];
			break;
		}
		default:
		{
			cout << "Error! Please try again!" << endl;
		}
	}
}

int main()
{
	unordered_map  <int, PIPE> pipes = {};
	unordered_map  <int, KS> kss = {};
	PIPE pipe;
	KS ks;
	while (1)
	{
		system("cls");
		PrintMenu();
		switch (Get_Correct_Number(0, 10))
		{
			case 1:
			{
				cin >> pipe;
				pipes.emplace (pipes.size() + 1, pipe);
				break;
			}
			case 2:
			{
				cin >> ks;
				kss.emplace (kss.size() + 1, ks);
				break;
			}
			case 3: 
			{
				if (pipes.size() != 0)
				{
					for (const auto& [id, p]: pipes)
					{
						cout << id;
						cout << p << endl;
					}
				}
				else
					cout << "No pipe data, please enter it and try again." << endl;
				if (kss.size() != 0)
				{
					for (const auto& [id, k] : kss)
					{
						cout << id;
						cout << k << endl;
					}
				}
				else
					cout << "No ks data, please enter it and try again." << endl;
				break;
			}
			case 4:
			{
				if (pipes.size() != 0)
				{
					cout << "Do you want to edit all pipes or one? Please, enter 1 if all pipes or 2 if multiple pipe: ";
					switch (Get_Correct_Number(1, 2))
					{
						case 1:
						{
							for (auto& [id, p] : pipes)
								PIPE::Edit_Pipe(p);
							break;
						}
						case 2:
						{
							cout << "How many pipes do you want to edit? Please, enter integer value of pipes (1, " << pipes.size() << "):";
							int n = Get_Correct_Number(1u, pipes.size());
							for (int i = 0; i < n; i++)
								PIPE::Edit_Pipe(Select(pipes));
							break;
						}
					}
				}
				else
					cout << "No pipe data, please enter it and try again." << endl;
				break;
			}
			case 5:
			{
				if (kss.size() != 0 != 0)
				{
					cout << "Do you want to edit all kss or one? Please, enter 1 if all kss or 2 if multiple ks: ";
					switch (Get_Correct_Number(1, 2))
					{
						case 1:
						{
							for (auto& [id, k] : kss)
								KS::Edit_KS(k);
							break;
						}
						case 2:
						{
							cout << "How many kss do you want to edit? Please, enter integer value of kss (1, " << kss.size() << "):";
							int n = Get_Correct_Number(1u, kss.size());
							for (int i = 0; i < n; i++)
								KS::Edit_KS(Select(kss));
							break;
						}
					}
				}
				else
					cout << "No ks data, please enter it and try again." << endl;
				break;
			}
			case 6:
			{
				cout << "Please, enter the file name: ";
				string filename;
				cin >> ws;
				getline(cin, filename);
				ofstream fout;
				fout.open(filename);
				if (fout.is_open())
				{
					fout << pipes.size() << endl;
					fout << kss.size() << endl;
					for (const auto& [id, p] : pipes)
						fout << p;
					for (const auto& [id, k] : kss)
						fout << k;
					fout.close();
				}
				else
					cout << "Error! Text file didn't open! Try again." << endl;
				break;
			}
			case 7:
			{	
				cout << "Please, enter the file name: ";
				string filename;
				cin >> filename;
				ifstream fin;
				fin.open(filename);
				if (fin.is_open())
				{
					Input_From_File(fin, pipes, kss);
					fin.close();
				}
				else
					cout << "File didn't open! Please, try again.";
				break;
			}
			case 8:
			{
				Delete(pipes);
				break;
			}
			case 9:
			{
				Delete(kss);
				break;
			}
			case 10:
			{
				cout << "What do you want to do?" << endl
					<< "Enter 1 if you want to filter pipes." << endl
					<< "Enter 2 if you want to filter KS." << endl;
				switch (Get_Correct_Number(1,2))
				{
					case 1:
					{
						Filter_For_PIPE(pipes);
						break;
					}
					case 2:
					{
						Filter_For_KS(kss);
						break;
					}
					default:
					{
						cout << "Error! Please try again!" << endl;
					}
				}
				break;
			}
			case 0:
			{
				return 0;
			}
			default:
			{
				cout << "Error! Please try again!" << endl;
			}
		}
		system("pause");
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
 