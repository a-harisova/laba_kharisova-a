#pragma once
#include <string>
#include <iostream>
#include <fstream>

class PIPE
{
	int id;
public:
	static int MaxID;
	std::string name;
	double length;
	int diameter;
	bool repair;

	int GetID() const;
	void SetID();
	void Edit_Pipe();

	friend std::ostream& operator << (std::ostream& out, const PIPE& pipe);
	friend std::istream& operator >> (std::istream& in, PIPE& pipe);
	friend std::ofstream& operator << (std::ofstream& out, const PIPE& pipe);
	friend std::ifstream& operator >> (std::ifstream& in, PIPE& pipe);
};

