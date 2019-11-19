#pragma once
#include "ArrayMap.h"
#include "HashMap.h"
#include <iostream>


int main()
{
	ArrayMap<int, int> map;
	map.Put(1, 100);
	map.Put(2, 200);

	for (auto v : map)
	{
		std::cout << v.key << "," << v.value<<std::endl;
	}

	{
		HashMap<int, int> hmap(12);
		for (int i = 1; i < 10; i++)
		{
			hmap.Put(i, i * 10);
		}
	}
	//std::cout << "Value for key 2 = " << map.Get(2) << std::endl;
	//std::cout << "Size of map = " << map.Size() << std::endl;
	//std::cout << "Map contains key 1 = " << map.ContainsKey(1) << std::endl;

	//map.Put(2, 300);
	//std::cout << "Put another value for key 2\n";
	//std::cout << "Value for key 2 = " << map.Get(2) << std::endl;
	//std::cout << "Size of map = " << map.Size() << std::endl;
	//std::cout << "Map contains key 1 = " << map.ContainsKey(1) << std::endl;

	//map.Clear();
	//std::cout << "Map cleared\n";
	//std::cout << "Value for key 2 = " << map.Get(2) << std::endl;
	//std::cout << "Size of map = " << map.Size() << std::endl;
	//std::cout << "Map contains key 1 = " << map.ContainsKey(1) << std::endl;

	std::cin.get();
	return 0;
}