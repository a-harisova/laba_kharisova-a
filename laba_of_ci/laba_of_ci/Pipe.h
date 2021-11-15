#pragma once
#include <string>
#include <iostream>

class PIPE
{
public:
	int id;
	std::string name;
	double length;
	int diameter;
	bool repair = false;

	friend std::ostream& operator << (std::ostream& out, const PIPE& pipe);
	friend std::istream& operator >> (std::istream& in, PIPE& pipe);
	static void Edit_Pipe(PIPE& pipe);
};

