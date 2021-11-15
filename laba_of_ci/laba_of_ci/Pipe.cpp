#include "Pipe.h"
#include"Utils.h"

using namespace std;
int kol_pipe = 1;

ostream& operator << (ostream& out, PIPE& pipe)
{
	out << pipe.id << " PIPE INFORMATION: " << endl
		<< "ID = " << pipe.id << endl
		<< "Length = " << pipe.length << endl
		<< "Diameter = " << pipe.diameter << endl;
	if (pipe.repair)
		out << "Repairs needed - yes" << endl;
	else out << "Repairs needed - no" << endl << endl;
	return out;
}

PIPE PIPE::Input_Pipe()
{
	PIPE pipe;
	pipe.id = kol_pipe;
	kol_pipe++;
	cout << "How long is the pipe? Please enter a double value: ";
	pipe.length = Get_Correct_Number(0.0, 1000000.0);
	cout << "What is the diameter of the pipe? Please enter an integer value: ";
	pipe.diameter = Get_Correct_Number(0, 1000000);
	pipe.repair = false;
	return PIPE();
}

void PIPE::Edit_Pipe(PIPE& pipe)
{
	pipe.repair = (!pipe.repair);
}

