#pragma once
#include "ArrayMap.h"
#include "HashMap.h"
#include <iostream>

template<typename ValueType>
void PrintMap(ArrayMap<std::pair<int,int>,ValueType>& map)
{
	for (auto c : map)
	{
		std::cout <<"(("<<c.key.first << ","<<c.key.second<<")," << c.value<<"),";
	}
}

template<typename ValueType>
void PrintMap(ArrayMap<int, ValueType>& map)
{
	for (auto c : map)
	{
		std::cout << "(" << c.key << "," << c.value << "),";
	}
}

template<typename ValueType>
void PrintMap(HashMap<std::pair<int,int>, ValueType>& map)
{
	for (auto c : map)
	{
		std::cout << "((" << c.key.first << "," << c.key.second << ")," << c.val << ")\n";
	}
}

template<typename ValueType>
void PrintMap(HashMap<int, ValueType>& map)
{
	for (auto c : map)
	{
		std::cout << "(" << c.key << "," << c.val << "),";
	}
}

int main()
{
	{
		HashMap<std::pair<int, int>, int> hmap(2);
		hmap.Put({ 20,30 }, 100);
		hmap.Put({ 10,0 }, 300);
		hmap.Put({ 0,0 }, 400);
		PrintMap(hmap);
		hmap.Put({ 20,30 }, 200);

		PrintMap(hmap);
		std::cout << "\nNumber of cells: " << hmap.Size()<<std::endl;
		std::cout << "entry for {20,30}:  " << hmap.Get({ 20,30 }) << std::endl;
		std::cout << "entry for {0,0}:  " << hmap.Get({ 0,0 }) << std::endl;

	}

	std::cin.get();
	return 0;
}