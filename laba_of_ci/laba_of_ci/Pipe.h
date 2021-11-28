#pragma once
#include <string>
#include <iostream>
#include <fstream>

class PIPE
{
	int id;
public:
	std::string name;
	double length;
	int diameter;
	bool repair;

	int GetID() const;
	void SetID();

	friend std::ostream& operator << (std::ostream& out, const PIPE& pipe);
	friend std::istream& operator >> (std::istream& in, PIPE& pipe);
	friend std::ofstream& operator << (std::ofstream& out, const PIPE& pipe);
	friend std::ifstream& operator >> (std::ifstream& in, PIPE& pipe);
	static void Edit_Pipe(PIPE& pipe);
};

