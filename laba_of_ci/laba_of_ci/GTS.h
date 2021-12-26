#pragma once
#include <unordered_map>
#include <set>
#include <tuple>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_set>
#include <queue>
#include "Pipe.h"
#include "Ks.h"
#include "Utils.h"
#include "Filter.h"

using namespace std;

class GTS
{
	unordered_map  <int, PIPE> pipes = {};
	unordered_map  <int, KS> kss = {};
	vector <vector <int>> ribs;
	vector <vector <double>> weight;
	vector <vector <int>> throughput;

	vector <vector <int>> AddGraph();
	unordered_map <int, int> GetIndexVertices();
	unordered_map <int, int> GetIndexVerticesBack();
	
public :
	void InputPipe();
	void InputKS();
	void PrintAllPipes();
	void PrintAllKSs();
	void EditPipes();
	void EditKSs();
	void Save(const string &filename);
	void Dowload(string filename);
	void Filter_For_PIPE();
	void Filter_For_KS();
	void DeletePipe();
	void DeleteKS();
	void ConnectPipeAndKSs();
	void DisconnectPipeAndKSs();
	void ShowConnection();
	void Sort();
};