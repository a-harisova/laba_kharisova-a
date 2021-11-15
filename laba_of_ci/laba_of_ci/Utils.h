#pragma once
#include <iostream>
#include <tuple>
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

