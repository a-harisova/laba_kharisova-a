#include "Pipe.h"
#include"Utils.h"

using namespace std;
int kol_pipe = 1;

std::ostream& operator << (std::ostream& out, const PIPE& pipe)
{
	out << pipe.id << " PIPE INFORMATION: " << endl
		<< "ID = " << pipe.id << endl
		<< "Name = " << pipe.name << endl
		<< "Length = " << pipe.length << endl
		<< "Diameter = " << pipe.diameter << endl;
	if (pipe.repair)
		out << "Repairs needed - yes" << endl;
	else out << "Repairs needed - no" << endl << endl;
	return out;
}

std::istream& operator >> (std::istream& in, PIPE& pipe)
{
	pipe.id = kol_pipe;
	kol_pipe++;
	cout << "Please enter the name of the pipe: ";
	cin.ignore(2000, '\n');
	in >> pipe.name;
	cout << "How long is the pipe? Please enter a double value: ";
	pipe.length = Get_Correct_Number(0.0, 1000000.0);
	cout << "What is the diameter of the pipe? Please enter an integer value: ";
	pipe.diameter = Get_Correct_Number(0, 1000000);
	pipe.repair = false;
	return in;
}

void PIPE::Edit_Pipe(PIPE& pipe)
{
	pipe.repair = (!pipe.repair);
}

