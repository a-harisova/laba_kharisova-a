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

	int in = 0, out = 0;
	void Connect(int myin, int myout); 
	void BreakTheConnection(); 
	bool Connection() const; 
	bool CanBeUsed() const; 
	void ShowTheConnection(int id) const; 

	friend std::ostream& operator << (std::ostream& out, const PIPE& pipe);
	friend std::istream& operator >> (std::istream& in, PIPE& pipe);
	friend std::ofstream& operator << (std::ofstream& out, const PIPE& pipe);
	friend std::ifstream& operator >> (std::ifstream& in, PIPE& pipe);
};

