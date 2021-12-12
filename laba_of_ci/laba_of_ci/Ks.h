#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <set>

class KS
{
	int id;
	int number_of_workshops;
	int number_of_working_workshops;
public:
	static int MaxID;
	std::string name;
	double efficiency;

	set <int> ConnectedPIPE;

	int GetID() const;
	void SetID();
	int GetNumbOfWorkshops() const;
	void SetNumbOfWorkshops();
	int GetNumbOfWorkWorkshops() const;
	void SetNumbOfWorkWorkshops();
	void Edit_KS();

	friend std::ostream& operator << (std::ostream& out, const KS& ks);
	friend std::istream& operator >> (std::istream& in, KS& ks);
	friend std::ofstream& operator << (std::ofstream& out, const KS& ks);
	friend std::ifstream& operator >> (std::ifstream& in, KS& ks);
};

