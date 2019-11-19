#pragma once

static constexpr int HASH_SEED = 5381;
static constexpr int HASH_MULTIPLIER = 33;
static constexpr int HASH_MASH = unsigned(-1)>>1;

int HashCode(int a)
{
	unsigned hash = HASH_SEED + a * HASH_MULTIPLIER;
	return int(hash & HASH_MASH);
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
					//bucketIndex++;
					for (; (++bucketIndex < nBuckets); )//bucketIndex++)
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
		count(0),
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
					std::cout << "cell ("<<pTemp->key<<","<<pTemp->val<<") deleted";
					delete pTemp;
					pTemp = nullptr;
					
				} 
			std::cout << "\nbucket "<<i<<" deleted\n";
			}
		}
		delete buckets;
		buckets = nullptr;
		std::cout << "buckets array deleted, dtor completed\n";
	}
	void Put(KeyType key, ValueType val)
	{
		int bucketIndex = HashCode(key) % nBuckets;
		//int bucketIndex = index;
		if (buckets[bucketIndex] == nullptr)
		{
			buckets[bucketIndex] = new Cell(key, val, nullptr);
		}
		else
		{
			Cell* pRunner = buckets[bucketIndex];
			while (pRunner->link != nullptr)
			{
				pRunner = pRunner->link;
			}
			pRunner->link = new Cell(key, val, nullptr);
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
		//Cell* pLastCell = nullptr;
		//Iterator iter = begin();
		//for (; iter.Get() != nullptr; pLastCell = iter.Get(), ++iter);
		//return Iterator(pLastCell,buckets,nBuckets,nBuckets-1);
		return Iterator(nullptr , buckets, nBuckets, nBuckets - 1);
	}

private:
	Cell** buckets = nullptr;
	int nBuckets = 0;
	int count = 0;

};
