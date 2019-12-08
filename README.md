# MapClassImplementation
Own implementation of map class (instructional material from Stanford's CS106B "Programming Abstractions", Roberts, Zelenski.

<ins>ArrayMap.h version:</ins>
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

<ins>HashMap.h version:</ins>
Map class implementation using a hashmap, will ammortize to O(1) when load factor <1.</br>

Interface same as above (work-in-progress)
