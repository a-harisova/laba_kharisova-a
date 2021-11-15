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

	friend std::ostream& operator << (std::ostream& out, KS& ks);
	KS Input_KS();
	void Edit_KS(KS& ks);
};

