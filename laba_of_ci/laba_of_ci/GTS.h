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

class GTS
{
	unordered_map  <int, PIPE> pipes = {};
	unordered_map  <int, KS> kss = {};
	map <int, int> SortNumberKS;
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
	void Filter_For_PIPE(unordered_map <int, PIPE>& pipes);
	void Filter_For_KS(unordered_map <int, KS>& kss);
};

template <typename type>
type& Select(unordered_map  <int, type>& smth)
{
	if (smth.size() == 0)
		cout << "Error! No data entered" << endl;
	else
	{
		cout << "Please enter index (1, " << smth.size() << "): ";
		unsigned int index = Get_Correct_Number(1u, smth.size());
		return smth[index];
	}
}

template <typename type>
void Delete(unordered_map  <int, type>& smth)
{
	if (smth.size())
	{
		cout << "Please, enter the index(1 - " << smth.size() << "): ";
		int index = Get_Correct_Number(1u, smth.size());
		smth.erase(index);
	}
	else
		cout << "Impossible to remove, since it hasn't yet been entered." << endl;
}

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
