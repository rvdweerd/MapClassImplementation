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

	
	HashMap<int, int> hmap(12);
	hmap.Put(1, 10, 0);
	//hmap.Put(2, 20, 0);
	//hmap.Put(3, 30, 0);
	//hmap.Put(4, 40, 1);
	hmap.Put(5, 50, 11);
	hmap.Put(6, 60, 11);

	//	for (int i = 1; i < 10; i++)
//	{
//		hmap.Put(i, i * 10);
//	}
	

	//for (auto v : hmap)
	auto iter = hmap.begin();
	for (; iter!=hmap.end();++iter)
	{
		std::cout << iter.Get()->key << "," << iter.Get()->val << std::endl;
	}
	std::cout << iter.Get()->key << "," << iter.Get()->val << std::endl;

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