#pragma once
#include <unordered_map>
#include <set>
#include <tuple>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include "Pipe.h"
#include "Ks.h"
#include "Utils.h"

using namespace std;

class GTS
{
	unordered_map  <int, PIPE> pipes = {};
	unordered_map  <int, KS> kss = {};
public :
	struct Connect
	{
		int pipeID, fromID, toID;
	};
	vector <Connect> Connection;
	void InputPipe();
	void InputKS();
	void PrintAllPipes();
	void PrintAllKSs();
	void EditPipes();
	void EditKSs();
	void Save(const string &filename);
	void Dowload(string filename);
	void DeletePipe();
	void DeleteKS();
};



