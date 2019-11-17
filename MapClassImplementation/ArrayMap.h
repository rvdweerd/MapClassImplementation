#ifndef _map_h
#define _map_h

template <typename KeyType, typename ValueType>
class ArrayMap
{
public:
	struct ValuePair
	{
		ValuePair() = default;
		ValuePair(KeyType k,ValueType v)
			:
			key(k),
			value(v)
		{}
		KeyType key=0;
		ValueType value=0;
	};
public:
	class Iterator
	{
	public:
		Iterator() = default;
		Iterator(ValuePair* vp)
			:
			pValuePair(vp)
		{}
		Iterator& operator++()
		{
			pValuePair++;
			return *this;
		}
		ValuePair& operator*()
		{
			return *pValuePair;
		}
		bool operator!=(Iterator rhs) const
		{
			return pValuePair != rhs.pValuePair;
		}
	private:
		ValuePair* pValuePair = nullptr;
	};

public:
	ArrayMap();
	~ArrayMap();
	int Size() const;
	bool IsEmpty() const;
	void Clear();
	void Put(const KeyType key, const ValueType val);
	ValueType Get(const KeyType key) const;
	bool ContainsKey(const KeyType key) const;
	ValueType& operator[](const KeyType& key)
	{
		//ValueType val = entries[FindKey(key)].value;
		//Put(key, ValueType(0) );
		//return val;
		return entries[FindKey(key)].value;
	}
	Iterator begin()
	{
		return Iterator(entries);
	}
	Iterator end()
	{
		return Iterator(&entries[nEntries]);
	}
private:
	void ExpandCapacity();
	int FindKey(KeyType key) const;

	// To be added:
	// 1. Removing existing map entries
	// 2. Deep copying
	// 3. Selection using square brackets DONE
	// 4. Iterators DONE (basic; only begin() and end())

public:
	int nCapacity;
	int nEntries;
	ValuePair* entries;
};

#include "ArrayMap.cpp"

#endif