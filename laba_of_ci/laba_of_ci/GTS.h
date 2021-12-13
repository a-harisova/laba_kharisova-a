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
	void Filter_For_PIPE();
	void Filter_For_KS();
	void DeletePipe();
	void DeleteKS();
};

template <typename type, typename type_param>
using Filter = bool(*)(const type& smth, type_param param);
template <typename type>
bool Check_By_Name(const type& smth, string param)
{
	return smth.name == param;
}
bool Check_By_Repair(const PIPE& smth, bool param)
{
	return smth.repair != param;
}
bool Check_By_Number_Of_Workshops(const KS& smth, double param)
{
	return (smth.GetNumbOfWorkWorkshops() / smth.GetNumbOfWorkshops()) * 100 == param;
}

template <typename type, typename type_param>
vector <int> Find_By_Filter(const unordered_map <int, type>& map, Filter <type, type_param> f, type_param param)
{
	vector <int> res;
	for (auto& smth : map)
	{
		if (f(smth.second, param))
			res.push_back(smth.first);
	}
	return res;
}

