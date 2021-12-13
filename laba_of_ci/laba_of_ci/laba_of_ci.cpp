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
				gts.Dowload(filename);
				break;
			}
			case 8:
			{
				gts.DeletePipe();
				break;
			}
			case 9:
			{
				gts.DeleteKS();
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
						gts.Filter_For_PIPE();
						break;
					}
					case 2:
					{
						gts.Filter_For_KS();
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
 