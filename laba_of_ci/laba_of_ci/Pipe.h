#pragma once
#include <string>
#include <iostream>

class PIPE
{
public:
	int id;
	double length;
	int diameter;
	bool repair = false;

	friend std::ostream& operator << (std::ostream& out, PIPE& pipe);
	PIPE Input_Pipe();
	void Edit_Pipe(PIPE& pipe);
};

