#include "Ks.h"
#include "Utils.h"

using namespace std;
int KS::MaxID = 0;

std::ostream& operator << (std::ostream& out, const KS& ks)
{
	out << " KS INFORMATION: " << endl
		<< "ID = " << ks.id << endl
		<< "Name = " << ks.name << endl
		<< "The number of workshops of the compressor station = " << ks.number_of_workshops << endl
		<< "The number of workshops of the compressor station, that are currently operating = " << ks.number_of_working_workshops << endl
		<< "Efficiency, % = " << ks.efficiency << endl;
	return out;
}

std::istream& operator >> (std::istream& in, KS& ks)
{
	ks.SetID();
	cout << "Please enter the name of compressor station: ";
	cin.ignore(2000, '\n');
	getline(cin, ks.name);
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

std::ofstream& operator << (std::ofstream& out, const KS& ks)
{
	out << ks.id << endl
		<< ks.name << endl
		<< ks.number_of_workshops << endl
		<< ks.number_of_working_workshops << endl
		<< ks.efficiency << endl
		<< ks.link;
	return out;
}

std::ifstream& operator >> (std::ifstream& in, KS& ks)
{
	in >> ks.id;
	in >> ks.name;
	in >> ks.number_of_workshops;
	in >> ks.number_of_working_workshops;
	in >> ks.efficiency;
	in >> ks.link;
	return in;
}

int KS::GetID() const
{
	return id;
}

void KS::SetID()
{
	id = ++MaxID;
}

int KS::GetNumbOfWorkshops() const
{
	return number_of_workshops;
}

void KS::SetNumbOfWorkshops()
{
	number_of_workshops = Get_Correct_Number(0, 1000000);
}

int KS::GetNumbOfWorkWorkshops() const
{
	return number_of_working_workshops;
}

void KS::SetNumbOfWorkWorkshops()
{
	number_of_working_workshops = Get_Correct_Number(0, 1000000);
}

void KS::Edit_KS()
{
	cout << "What do you want to do?" << endl
		<< "Enter 1 if you want to create a new workshop." << endl
		<< "Enter 2 if you want to start an existing workshop." << endl
		<< "Enter 3 if you want to stop an existing workshop." << endl;
	switch (Get_Correct_Number(1, 3))
	{
	case 1:
	{
		number_of_workshops++;
		break;
	}
	case 2:
	{
		if (number_of_workshops == number_of_working_workshops)
			cout << "\nIt is impossible to start the existing workshop, since all the workshops are working." << endl << endl;
		else
			number_of_working_workshops++;
		break;
	}
	case 3:
	{
		if (number_of_working_workshops == 0)
			cout << "\nIt is impossible to stop the existing workshop, since all the workshops aren't working." << endl << endl;
		else
			number_of_working_workshops--;
		break;
	}
	default:
	{
		system("cls");
		cout << "Error!" << endl;
		Edit_KS();
	}
	}
}

void KS::Connect()
{
	if (!link) link = true;
}

void KS::BreakTheConnection()
{
	link = false;
}

bool KS::Connection()
{
	return link;
}

