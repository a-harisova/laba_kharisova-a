#include "Pipe.h"
#include"Utils.h"

using namespace std;
int PIPE::MaxID = 0;

int PIPE::GetID() const
{
	return id;
}

void PIPE::SetID()
{
	id = ++MaxID;
}

std::ostream& operator << (std::ostream& out, const PIPE& pipe)
{
	out << " PIPE INFORMATION: " << endl
		<< "ID = " << pipe.id << endl
		<< "Name = " << pipe.name << endl
		<< "Length = " << pipe.length << endl
		<< "Diameter = " << pipe.diameter << endl;
	if (pipe.repair)
		out << "Repairs needed - yes" << endl;
	else out << "Repairs needed - no" << endl;
	return out;
}

std::istream& operator >> (std::istream& in, PIPE& pipe)
{
	pipe.SetID();
	cout << "Please enter the name of the pipe: ";
	cin.ignore(2000, '\n');
	getline(cin, pipe.name);
	cout << "How long is the pipe? Please enter a double value: ";
	pipe.length = Get_Correct_Number(0.0, 1000000.0);
	cout << "What is the diameter of the pipe? Please enter an integer value: ";
	pipe.diameter = Get_Correct_Number(0, 1000000);
	pipe.repair = false;
	return in;
}

std::ofstream& operator << (std::ofstream& out, const PIPE& pipe)
{
	out << pipe.GetID() << endl
		<< pipe.name << endl
		<< pipe.length << endl
		<< pipe.diameter << endl
		<< pipe.repair << endl;
	return out;
}

std::ifstream& operator >> (std::ifstream& in, PIPE& pipe)
{
	in >> pipe.id;
	in >> pipe.name;
	in >> pipe.length;
	in >> pipe.diameter;
	in >> pipe.repair;
	return in;
}

void PIPE::Edit_Pipe()
{
	repair = (!repair);
}


