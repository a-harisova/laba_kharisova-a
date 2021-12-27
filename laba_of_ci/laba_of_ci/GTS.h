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
	unordered_map <int, int> VertexIndices();
	unordered_map <int, int> VertexIndicesBack();
	vector <vector <double>> MatrixWeights();
	vector <vector <int>> MatrixThroughput();
	void TopologicalSort(const unordered_map<int, int>& IndexVertices);
	void MaxStream();
	void ShortestWay(const unordered_map<int, int>& VerticesIndexForOutput);

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
	bool IsKSConnected(int KSId);
};