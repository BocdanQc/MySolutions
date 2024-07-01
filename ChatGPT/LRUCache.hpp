#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity;
    std::list<std::pair<int, int>> cacheList; // key, value
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap; // key, iterator

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1; // Key not found
        } else {
            // Move the accessed key to the front of the cacheList
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return cacheMap[key]->second;
        }
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // Update the value and move the accessed key to the front of the cacheList
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key]->second = value;
        } else {
            // If the cache is at capacity, remove the least recently used item
            if (cacheList.size() == capacity) {
                int lruKey = cacheList.back().first;
                cacheList.pop_back();
                cacheMap.erase(lruKey);
            }
            // Insert the new key-value pair at the front of the cacheList
            cacheList.emplace_front(key, value);
            cacheMap[key] = cacheList.begin();
        }
    }
};
