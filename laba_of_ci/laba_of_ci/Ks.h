#pragma once
#include <string>
#include <iostream>

class KS
{
	int id;
	int number_of_workshops;
	int number_of_working_workshops;
public:
	std::string name;
	double efficiency;

	int GetID() const;
	void SetID();
	void SetIDFromFile(int);
	int GetNumbOfWorkshops() const;
	void SetNumbOfWorkshops();
	void SetNumbOfWorkshopsInFile(int);
	int GetNumbOfWorkWorkshops() const;
	void SetNumbOfWorkWorkshops();
	void SetNumbOfWorkWorkshopsInFile(int);

	friend std::ostream& operator << (std::ostream& out, const KS& ks);
	friend std::istream& operator >> (std::istream& in, KS& ks);
	static void Edit_KS(KS& ks);
};

