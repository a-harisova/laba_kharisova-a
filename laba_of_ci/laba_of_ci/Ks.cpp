#include "Ks.h"
#include "Utils.h"

using namespace std;
int kol_ks = 1;

std::ostream& operator << (std::ostream& out, const KS& ks)
{
	out << ks.id << " KS INFORMATION: " << endl
		<< "ID = " << ks.id << endl
		<< "Name = " << ks.name << endl
		<< "The number of workshops of the compressor station = " << ks.number_of_workshops << endl
		<< "The number of workshops of the compressor station, that are currently operating = " << ks.number_of_working_workshops << endl
		<< "Efficiency, % = " << ks.efficiency << endl << endl;
	return out;
}

std::istream& operator >> (std::istream& in, KS& ks)
{
	ks.id = kol_ks;
	kol_ks++;
	cout << "Please enter the name of compressor station: ";
	cin.ignore(2000, '\n');
	in >> ks.name;
	cout << "Please enter the integer value of workshops of the compressor station: ";
	ks.number_of_workshops = Get_Correct_Number(0, 1000000);
	do
	{
		cout << "Please enter the integer value of workshops of the compressor station, that are currently operating. " << endl
			<< "The number must be less than value of workshops of the compressor station!: ";
		ks.number_of_working_workshops = Get_Correct_Number(0, 1000000);
	} while (ks.number_of_workshops < ks.number_of_working_workshops);
	ks.efficiency = rand() % 100;
	return in;
}

void KS::Edit_KS(KS& ks)
{
	cout << "What do you want to do?" << endl << "Enter 1 if you want to create a new workshop." << endl
		<< "Enter 2 if you want to start an existing workshop." << endl
		<< "Enter 3 if you want to stop an existing workshop." << endl;
	switch (Get_Correct_Number(1, 3))
	{
		case 1:
		{
			ks.number_of_workshops++;
		}
		case 2:
		{
			if (ks.number_of_workshops == ks.number_of_working_workshops)
				cout << "\nIt is impossible to start the existing workshop, since all the workshops are working." << endl << endl;
			else
				ks.number_of_working_workshops++;
		}
		case 3:
		{
			if (ks.number_of_working_workshops == 0)
				cout << "\nIt is impossible to stop the existing workshop, since all the workshops aren't working." << endl << endl;
			else
				ks.number_of_working_workshops--;
		}
		default:
		{
			system("cls");
			cout << "Error!" << endl;
			KS::Edit_KS(ks);
		}
	}
}
