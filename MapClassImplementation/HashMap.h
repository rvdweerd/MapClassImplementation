#pragma once
#include <string>

static constexpr int HASH_SEED = 5381;
static constexpr int HASH_MULTIPLIER = 33;
static constexpr int HASH_MASH = unsigned(-1)>>1;

int HashCode(std::string str)
{
	unsigned hash = HASH_SEED;
	int n = str.length();
	for (int i = 0; i < n; i++)
	{
		hash = HASH_MULTIPLIER * hash + str[i];
	}
	return int(hash & HASH_MASH);
}

int HashCode(int a)
{
	return HashCode(std::to_string(a));
}

int HashCode(std::pair<int, int> a)
{
	return HashCode(a.first + a.second);
}

template <typename KeyType, typename ValueType>
class HashMap
{
public:
	struct Cell
	{
		Cell(KeyType key, ValueType val, Cell* link)
			:
			key(key),
			val(val),
			link(link)
		{}
		KeyType key = 0;
		ValueType val = 0;
		Cell* link = nullptr;
	};
	class Iterator
	{
	public:
		Iterator() = default;
		Iterator(Cell* pCell, Cell** buckets, int nBuckets, int bucketIndex)
			:
			pCell(pCell),
			buckets(buckets),
			nBuckets(nBuckets),
			bucketIndex(bucketIndex)
		{}
		Iterator& operator++()
		{
			if (pCell->link == nullptr)
			{
				if (bucketIndex == nBuckets - 1) //end of bucket array
				{
					pCell = nullptr;
				}
				else
				{
					pCell = nullptr;
					for (; (++bucketIndex < nBuckets); )
					{
						if (buckets[bucketIndex] != nullptr)
						{
							pCell = buckets[bucketIndex];
							break;
						}
					}
				}
			}
			else
			{
				pCell = pCell->link;
			}
			return *this;
		}
		Cell& operator*()
		{
			return *pCell;
		}
		bool operator!=(Iterator rhs) const
		{
			return pCell != rhs.pCell;
		}
		Cell* Get()
		{
			return pCell;
		}
	private:
		Cell* pCell = nullptr;
		Cell** buckets = nullptr;
		int nBuckets = 0;
		int bucketIndex = 0;
	};

public:
	HashMap() = default;
	HashMap(int nBuckets)
		:
		nBuckets(nBuckets),
		nCells(0),
		buckets(new Cell*[nBuckets])
	{
		for (int i = 0; i < nBuckets; i++)
		{
			buckets[i] = nullptr;
		}
	}
	~HashMap()
	{
		for (int i = 0; i < nBuckets; i++)
		{
			if (buckets[i] != nullptr)
			{
				Cell* pRunner = buckets[i];
				while (pRunner != nullptr)
				{
					Cell* pTemp = pRunner;
					pRunner = pRunner->link;
					//std::cout << "cell ("<<pTemp->key<<","<<pTemp->val<<") deleted";
					delete pTemp;
					pTemp = nullptr;
					
				} 
			//std::cout << "\nbucket "<<i<<" deleted\n";
			}
		}
		delete[] buckets;
		buckets = nullptr;
		std::cout << "buckets array deleted, dtor completed\n";
		nCells = 0;
	}
	int Size() const
	{
		return nCells;
	}
	bool IsEmpty() const
	{
		return nCells == 0;
	}
	void Clear()
	{
		for (int i = 0; i < nBuckets; i++)
		{
			if (buckets[i] != nullptr)
			{
				Cell* pRunner = buckets[i];
				buckets[i] = nullptr;
				while (pRunner != nullptr)
				{
					Cell* pTemp = pRunner;
					pRunner = pRunner->link;
					std::cout << "cell (" << pTemp->key << "," << pTemp->val << ") deleted";
					delete pTemp;
					pTemp = nullptr;

				}
				std::cout << "\nAll cells in bucket " << i << " deleted\n";
			}
		}
		std::cout << "buckets array cleared\n";
		nCells = 0;

	}
	void Put(KeyType key, ValueType val)
	{
		int bucketIndex = HashCode(key) % nBuckets;
		//int bucketIndex = index;
		if (buckets[bucketIndex] == nullptr)
		{
			buckets[bucketIndex] = new Cell(key, val, nullptr);
			nCells++;
		}
		else
		{
			if (FindKey(key) == nullptr) //findkey and check if already present.
			{
				Cell* pRunner = buckets[bucketIndex];
				while (pRunner->link != nullptr)
				{
					pRunner = pRunner->link;
				}
				pRunner->link = new Cell(key, val, nullptr);
				nCells++;
			}
		}
	}
	ValueType Get(const KeyType key)
	{
		Cell* pTarget = FindKey(key);
		if (pTarget == nullptr)
		{
			std::cout << "Error, no key present.\n";
			return ValueType(0);
		}
		else
		{
			return pTarget->val;
		}
	}
	Cell* FindKey(KeyType key)
	{
		int bucketIndex = HashCode(key) % nBuckets;
		if (buckets[bucketIndex] == nullptr)
		{
			return nullptr;
		}
		else
		{
			Cell* pRunner = buckets[bucketIndex];
			while (pRunner != nullptr)
			{
				if (pRunner->key == key)
				{
					return pRunner;
				}
				pRunner = pRunner->link;
			}
			return nullptr;
		}


	}
	Iterator begin()
	{
		int i = 0;
		for (; i < nBuckets && buckets[i] == nullptr; i++);
		return Iterator(buckets[i], buckets, nBuckets, i);
	}
	Iterator end()
	{
		return Iterator(nullptr , buckets, nBuckets, nBuckets - 1);
	}

private:
	Cell** buckets = nullptr;
	int nBuckets = 0;
	int nCells = 0;

};
