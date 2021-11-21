#pragma once
#include <string>
#include <iostream>

class PIPE
{
	int id;
	bool repair = false;
public:
	std::string name;
	double length;
	int diameter;

	int GetID() const;
	void SetID();
	void SetIDFromFile(int);
	bool GetRepair() const;
	void SetRepair();
	void SetRepairFromFile(bool);

	friend std::ostream& operator << (std::ostream& out, const PIPE& pipe);
	friend std::istream& operator >> (std::istream& in, PIPE& pipe);
	static void Edit_Pipe(PIPE& pipe);
};

