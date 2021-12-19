#include "GTS.h"

using namespace std;

void GTS::InputPipe()
{
	PIPE pipe;
	cin >> pipe;
	pipes.emplace(pipe.MaxID, pipe);
}

void GTS::InputKS()
{
	KS ks;
	cin >> ks;
	kss.emplace(ks.MaxID, ks);
}

void GTS::PrintAllPipes()
{
	if (pipes.size() != 0)
	{
		for (const auto& [id, p] : pipes)
		{
			cout << id;
			cout << p << endl;
		}
	}
	else
		cout << "No pipe data, please enter it and try again." << endl;
}

void GTS::PrintAllKSs()
{
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
}

void GTS::EditPipes()
{
	if (pipes.size() != 0)
	{
		cout << "Do you want to edit all pipes or multiple? Please, enter 1 if all pipes or 2 if multiple pipe: ";
		switch (Get_Correct_Number(1, 2))
		{
		case 1:
		{
			for (auto& [id, p] : pipes)
				p.Edit_Pipe();
			break;
		}
		case 2:
		{
			cout << "How many pipes do you want to edit? Please, enter integer value of pipes (1, " << pipes.size() << "):";
			int n = Get_Correct_Number(1u, pipes.size());
			for (int i = 0; i < n; i++)
			{
				cout << "Please enter index (1, " << pipes.size() << "): ";
				unsigned int index = Get_Correct_Number(1u, pipes.size());
				pipes[index].Edit_Pipe();
			}
			break;
		}
		}
	}
	else
		cout << "No pipe data, please enter it and try again." << endl;
}

void GTS::EditKSs()
{
	if (kss.size() != 0)
	{
		cout << "Do you want to edit all kss or multiple? Please, enter 1 if all kss or 2 if multiple ks: ";
		switch (Get_Correct_Number(1, 2))
		{
		case 1:
		{
			for (auto& [id, k] : kss)
				k.Edit_KS();
			break;
		}
		case 2:
		{
			cout << "How many kss do you want to edit? Please, enter integer value of kss (1, " << kss.size() << "):";
			int n = Get_Correct_Number(1u, kss.size());
			for (int i = 0; i < n; i++)
			{
				cout << "Please enter index (1, " << kss.size() << "): ";
				unsigned int index = Get_Correct_Number(1u, kss.size());
				kss[index].Edit_KS();
			}
			break;
		}
		}
	}
	else
		cout << "No ks data, please enter it and try again." << endl;
}

void GTS::Save(const string& filename)
{
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
}

void GTS::Dowload(string filename)
{
	ifstream fin;
	fin.open(filename);
	if (fin.is_open())
	{
		PIPE pipe;
		KS ks;
		int kol = 0;
		int pipes_size, kss_size;
		fin >> pipes_size >> kss_size;
		for (int i = 1; i <= pipes_size; i++)
		{
			fin >> pipe;
			for (auto& [id, p] : pipes)
			{
				if (pipe.GetID() == id)
				{
					kol++;
				}
			}
			if (kol == 0)
			{
				pipe.MaxID++;
				pipes.emplace(pipe.MaxID, pipe);
			}
			else
			{
				kol = 0;
			}
		}
		for (int i = 1; i <= kss_size; i++)
		{
			fin >> ks;
			for (auto& [id, k] : kss)
			{
				if (ks.GetID() == id)
				{
					kol++;
				}
			}
			if (kol == 0)
			{
				ks.MaxID++;
				kss.emplace(ks.MaxID, ks);
			}
			else
			{
				kol = 0;
			}
		}
		fin.close();
	}
	else
		cout << "File didn't open! Please, try again.";
}



void GTS::DeletePipe()
{
	if (pipes.size())
	{
		cout << "Please, enter the index(1 - " << pipes.size() << "): ";
		int index = Get_Correct_Number(1u, pipes.size());
		pipes.erase(index);
	}
	else
		cout << "Impossible to remove, since it hasn't yet been entered." << endl;
}

void GTS::DeleteKS()
{
	if (kss.size())
	{
		cout << "Please, enter the index(1 - " << kss.size() << "): ";
		int index = Get_Correct_Number(1u, kss.size());
		kss.erase(index);
	}
	else
		cout << "Impossible to remove, since it hasn't yet been entered." << endl;
}
