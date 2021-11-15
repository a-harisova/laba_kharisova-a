#pragma once
#include <string>
#include <iostream>

class KS
{
public:
	int id;
	std::string name;
	int number_of_workshops;
	int number_of_working_workshops;
	double efficiency;

	friend std::ostream& operator << (std::ostream& out, const KS& ks);
	friend std::istream& operator >> (std::istream& in, KS& ks);
	static void Edit_KS(KS& ks);
};

