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
		std::cout << "((" << c.key.first << "," << c.key.second << ")," << c.val << "),";
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
		//ArrayMap<std::pair<int,int>, int> map;
		ArrayMap<int, int> map;
		//for (int i = 1; i < 1000000; i++)
		//map.Put({ 2,3 },  10);
		map.Put( 2, 10);
		PrintMap(map);
		std::cout << "\nNumber of cells: " << map.Size() << std::endl;
	}
	std::cin.get();
	{
		HashMap<std::pair<int, int>, int> hmap(2);
		//HashMap<int, int> hmap(120);
		//for (int i = 1; i < 100; i++)
		//{
		//	hmap.Put(i, i * 10);
		//}
		hmap.Put({ 20,30 }, 100);
		hmap.Put({ 20,30 }, 200);
		hmap.Put({ 10,0 }, 300);
		hmap.Put({ 0,0 }, 400);

		PrintMap(hmap);
		std::cout << "\nNumber of cells: " << hmap.Size()<<std::endl;
		std::cin.get();
		
		std::cout << "entry for {20,30}:  " << hmap.Get({ 20,30 }) << std::endl;
		std::cout << "entry for {0,0}:  " << hmap.Get({ 0,0 }) << std::endl;

	}

	std::cin.get();
	return 0;
}