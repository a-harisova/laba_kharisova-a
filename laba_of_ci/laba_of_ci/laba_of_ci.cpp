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

void Output_In_File_Pipe(ofstream& fout, const PIPE pipe)
{
	fout << pipe.id << endl
		<< pipe.length << endl
		<< pipe.diameter << endl
		<< pipe.repair << endl;
}

void Output_In_File_KS(ofstream& fout, const KS ks)
{
	fout << ks.id << endl
		 << ks.name << endl
		 << ks.number_of_workshops << endl
		 << ks.number_of_working_workshops << endl
		 << ks.efficiency << endl;
}

void Input_From_File(ifstream& fin, unordered_map <int, PIPE>& pipes, unordered_map <int, KS>& kss)
{
	PIPE pipe;
	KS ks;
	int pipes_size, kss_size;
	fin >> pipes_size >> kss_size;
	for (int i = 1; i <= pipes_size; i++)
	{
		fin >> pipe.id;
		fin >> pipe.length;
		fin >> pipe.diameter;
		fin >> pipe.repair;
		pipes[kol_pipe] = { pipe };
		kol_pipe++;
	}
	for (int i = 1; i <= kss_size; i++)
	{
		fin >> ks.id;
		fin >> ks.name;
		fin >> ks.number_of_workshops;
		fin >> ks.number_of_working_workshops;
		fin >> ks.efficiency;
		kss[kol_ks] = { ks };
		kol_ks++;
	}
}

//vector<int> Find_By_Name_KS(const vector<Student>& group, string name = "Unknown")
//{
//	vector <int> res;
//	int i = 0;
//	for (auto& s : group)
//	{
//		if (s.name == name)
//			res.push_back(i);
//		i++;
//	}
//
//	return res;
//}
//
//template<typename T>
//using Filter = bool(*)(const T& smth, T param);
//
//bool Check_By_Name(const KS& smth, string param)
//{
//	return smth.name == param;
//}
//bool Check_By_Repair(const PIPE& smth, bool param)
//{
//	return smth.repair == param;
//}
//
//vector <int> Find_By_Filter_PIPE(const map <int, PIPE>& pipes, filter <T> f, bool repair)
//{
//	vector <int> res;
//	int i = 0;
//	for (int i = 1; i < pipes.size(); i++)
//	{
//		if (f(smth, param))
//			res[i]);
//		i++;
//	}
//
//	return res;
//}

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
		switch (Get_Correct_Number(0, 9))
		{
			case 1:
			{
				pipe = PIPE::Input_Pipe();
				pipes.emplace (pipe.id, pipe);
				break;
			}
			case 2:
			{
				ks = KS::Input_KS();
				kss.emplace (ks.id, ks);
				break;
			}
			case 3: 
			{
				if (pipes.size() != 0)
				{
					for (const auto& p : pipes)
						cout << p.second << endl;
				}
				else
					cout << "No pipe data, please enter it and try again." << endl;
				if (kss.size() != 0)
				{
					for (const auto& k : kss)
						cout << k.second << endl;
				}
				else
					cout << "No ks data, please enter it and try again." << endl;
				break;
			}
			case 4:
			{
				cout << "Do you want to edit all pipes or one? Please, enter 1 if all pipes or 2 if one pipe: ";
				switch (Get_Correct_Number(1, 2))
				{
					case 1:
					{
						if (pipes.size() != 0)
						{
							for (const auto& p : pipes)
								Edit_Pipe(p.second);
						}
						else
							cout << "No pipe data, please enter it and try again." << endl;
						break;
					}
					case 2:
					{
						if (pipes.size() != 0)
							Edit_Pipe(Select(pipes));
						else
							cout << "No pipe data, please enter it and try again." << endl;
						break;
					}
				}
				break;
			}
			case 5:
			{
				Edit_KS(Select(kss));
				break;
			}
			case 6:
			{
				cout << "Please, enter the file name: ";
				string filename;
				cin >> filename;
				ofstream fout;
				fout.open(filename);
				if (fout.is_open())
				{
					fout << pipes.size() << endl;
					fout << kss.size() << endl;
					for (const auto& p : pipes)
						Output_In_File_Pipe(fout, p.second);
					for (const auto& k : kss)
						Output_In_File_KS(fout, k.second);
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
				/*string name = "Unknown";
				for (int i : Find_By_Filter(pipes, Check_By_Repair, name))
					cout << pipes[i];

				for (int i : Find_By_Filter(kss, Check_By_Name, name))
					cout << kss[i];*/

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
 