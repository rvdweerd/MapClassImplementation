# MapClassImplementation
Own implementation of map class (instructional material from Stanford's CS106B "Programming Abstractions", Roberts, Zelenski.

ArrayMap.h version:
Based on dynamic array which doubles capacity when needed.</br>

Features implemented:
* Basic set of public Map functions (Size(), IsEmpty(), Clear(), Put(), Get(), ContainsKey()
* Private Map functions (ExpandCapacity(), FindKey()
* Advanced Map functions (Iterator class, selection using brackets)

Features to be implemented:
* Copy / Move constructors (deep copying)
* Removing existing Map entries

Functionality to be checked:
* Behavior when calling map.at() vs. map[] (compare with std::map<>)

HashMap.h version:
Map class implementation using a hashmap, will ammortize to O(1) when load factor <1.
