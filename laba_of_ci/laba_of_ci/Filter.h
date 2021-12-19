#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Pipe.h"
#include "Ks.h"

using namespace std;

template<typename T>
bool Check_By_Name(const T& map, string param);

template<typename T, typename T_param>
using Filter = bool (*)(const T& map, T_param param);

void PipeFilter(unordered_map<int, PIPE>& pipes);

void KSFilter (unordered_map<int, KS>& kompres);

template <typename T, typename T_param>
vector <int> Find_By_Filter(const unordered_map <int, T>& map, Filter <T, T_param> f, T_param param)
{
    vector <int> res;
    for (auto& smth : map)
    {
        if (f(smth.second, param))
            res.push_back(smth.first);
    }
    return res;
}

template<typename T>
inline bool Check_By_Name(const T& smth, string param)
{
    return smth.name == param;;
}
