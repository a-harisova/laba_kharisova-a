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
#include "GTS.h"

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
		 << "11. Connection KSs with pipe" << endl
		 << "12. Print all connections" << endl
		 << "0. Exit" << endl
		 << "Choose action, please: ";
}

//template <typename type>
//type& Select(unordered_map  <int, type>& smth)
//{
//	if (smth.size() == 0)
//		cout << "Error! No data entered" << endl;
//	else
//	{
//		cout << "Please enter index (1, " << smth.size() << "): ";
//		unsigned int index = Get_Correct_Number(1u, smth.size());
//		return smth[index];
//	}
//}
//
//template <typename type>
//void Delete(unordered_map  <int, type>& smth)
//{
//	if (smth.size())
//	{
//		cout << "Please, enter the index(1 - " << smth.size() << "): ";
//		int index = Get_Correct_Number(1u, smth.size());
//		smth.erase(index);
//	}
//	else
//		cout << "Impossible to remove, since it hasn't yet been entered." << endl;
//}


//void Filter_For_PIPE(unordered_map <int, PIPE>& pipes)
//{
//	if (pipes.size() == 0)
//		return;
//	cout << "What do you want to do?" << endl
//		<< "Enter 1 if you want to filter by name." << endl
//		<< "Enter 2 if you want to filter by repair." << endl;
//	switch (Get_Correct_Number(1, 2))
//	{
//		case 1:
//		{
//			string name;
//			cin >> ws;
//			cin.ignore(2000, '\n');
//			cout << "Please, enter pipe name: ";
//			getline(cin, name);
//			vector <int> IDs = Find_By_Filter(pipes, Check_By_Name, name);
//			for (auto& id : IDs)
//				cout << id << pipes[id] << endl;
//			cout << "Do you want delete pipes? Please, enter 1 if yes and 0 if no: ";
//			bool number = Get_Correct_Number(0, 1);
//			if (number)
//				for (auto& id : IDs)
//					pipes.erase(id);
//			break;
//		}
//		case 2:
//		{
//			cout << "Please, enter 0 if pipes don't work and 1 if pipes work: ";
//			bool repair = Get_Correct_Number(0, 1);
//			vector <int> IDs = Find_By_Filter(pipes, Check_By_Repair, repair);
//			for (auto& id : IDs)
//				cout << id << pipes[id] << endl;
//			cout << "Do you want delete pipes? Please, enter 1 if yes and 0 if no: ";
//			bool number = Get_Correct_Number(0, 1);
//			if (number)
//				for (auto& id : IDs)
//					pipes.erase(id);
//			break;
//		}
//		default:
//		{
//			cout << "Error! Please try again!" << endl;
//		}
//	}
//}

//void Filter_For_KS(unordered_map <int, KS>& kss)
//{
//	if (kss.size() == 0)
//		return;
//	cout << "What do you want to do?" << endl
//		<< "Enter 1 if you want to filter by name." << endl
//		<< "Enter 2 if you want to filter by number of workshops." << endl;
//	switch (Get_Correct_Number(1, 2))
//		{
//		case 1:
//		{
//			string name;
//			cin >> ws;
//			cout << "Please, enter ks name: ";
//			cin.ignore(2000, '\n');
//			getline(cin, name);
//			vector <int> IDs = Find_By_Filter(kss, Check_By_Name, name);
//			for (auto& id : IDs)
//				cout << id << kss[id] << endl;
//			cout << "Do you want delete kss? Please, enter 1 if yes and 0 if no: ";
//			bool number = Get_Correct_Number(0, 1);
//			if (number)
//				for (auto& id : IDs)
//					kss.erase(id);
//			break;
//		}
//		case 2:
//		{
//			cout << "Please, enter the percentage of unused workshops: ";
//			double percent = Get_Correct_Number(0.0, 100.0);
//			vector <int> IDs = Find_By_Filter(kss, Check_By_Number_Of_Workshops, percent);
//			for (auto& id : IDs)
//				cout << id << kss[id] << endl;
//			cout << "Do you want delete kss? Please, enter 1 if yes and 0 if no: ";
//			bool number = Get_Correct_Number(0, 1);
//			if (number)
//				for (auto& id : IDs)
//					kss.erase(id);
//			break;
//		}
//		default:
//		{
//			cout << "Error! Please try again!" << endl;
//		}
//	}
//}

int main()
{
	GTS gts;
	while (1)
	{
		system("cls");
		PrintMenu();
		switch (Get_Correct_Number(0, 12))
		{
			case 1:
			{
				gts.InputPipe();
				break;
			}
			case 2:
			{
				gts.InputKS();
				break;
			}
			case 3: 
			{
				gts.PrintAllPipes();
				gts.PrintAllKSs();
				break;
			}
			case 4:
			{
				gts.EditPipes();
				break;
			}
			case 5:
			{
				gts.EditKSs();
				break;
			}
			case 6:
			{
				cout << "Please, enter the file name: ";
				string filename;
				cin >> ws;
				getline(cin, filename);
				gts.Save(filename);
				break;
			}
			case 7:
			{	
				cout << "Please, enter the file name: ";
				string filename;
				cin >> ws;
				getline(cin, filename);
				gts.Dowlonad(filename);
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
 