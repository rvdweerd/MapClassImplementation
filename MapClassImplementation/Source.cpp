#pragma once
#include "ArrayMap.h"
//#include <string>
#include <iostream>


int main()
{
	ArrayMap<int,int> map;
	map.Put(1, 100);
	map.Put(2, 200);

	std::cout << "Value for key 2 = " << map.Get(2) << std::endl;
	std::cout << "Size of map = " << map.Size() << std::endl;
	std::cout << "Map contains key 1 = " << map.ContainsKey(1) << std::endl;

	map.Put(2, 300);
	std::cout << "Put another value for key 2\n";
	std::cout << "Value for key 2 = " << map.Get(2) << std::endl;
	std::cout << "Size of map = " << map.Size() << std::endl;
	std::cout << "Map contains key 1 = " << map.ContainsKey(1) << std::endl;

	map.Clear();
	std::cout << "Map cleared\n";
	std::cout << "Value for key 2 = " << map.Get(2) << std::endl;
	std::cout << "Size of map = " << map.Size() << std::endl;
	std::cout << "Map contains key 1 = " << map.ContainsKey(1) << std::endl;

	std::cin.get();
	return 0;
}