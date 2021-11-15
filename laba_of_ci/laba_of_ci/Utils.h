#pragma once
#include <iostream>
#include <unordered_map>

template <typename type>
type Get_Correct_Number(type min, type max)
{
	type value;
	while ((std::cin >> value).fail() || value < min || value > max || std::cin.peek() != '\n')
	{
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Please enter correct data (" << min << "-" << max << ") : ";
	}
	return value;
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
};

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
};