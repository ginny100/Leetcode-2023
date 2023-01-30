/**
 * @file Day29LFUCache.cpp
 * @author Ginny Dang
 * @brief 460. LFU Cache (https://leetcode.com/problems/lfu-cache/description/)
 * @version 0.1
 * @date 2023-01-29
 *
 * @copyright Copyright (c) 2023
 *
 */

class LFUCache
{
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache; // key : (freq : iterator pointing to a list of {key : value} pairs) in the other map
    unordered_map<int, list<pair<int, int>>> frequencies;                // freq : {{key1 : value1}, {key2 : value2}, {key3 : value3}, ...}
    int minFreq;                                                         // the minimum frequency at any given time
    int capacity;                                                        // the capacity given in the input

    void insert(int key, int val, int freq)
    {
        frequencies[freq].push_back({key, val});
        cache[key] = {freq, --frequencies[freq].end()}; // --frequencies[freq].end() refers to the very last element of the list frequencies[freq]
    }

public:
    LFUCache(int capacity) : minFreq(0),
                             capacity(capacity) {}

    int get(int key)
    {
        // Get the iterator pointing to an entry in cache
        const auto keyItInCache = cache.find(key);

        // If this key does not exist in the cache
        if (keyItInCache == cache.end())
            return -1;

        // If this key exists in the cache
        const pair<int, pair<int, list<pair<int, int>>::iterator>> keyEntryInCache = *keyItInCache;
        const int freq = keyEntryInCache.second.first;     // The frequency of this key
        const auto freqIt = keyEntryInCache.second.second; // The iterator associating with the frequency of this key
        const pair<int, int> kv = *freqIt;                 // The actual (key : value) pair associating with freq in the frequencies unordered map
        //// Update frequencies and the min frequency
        frequencies[freq].erase(freqIt); // Can be understood as removing the old frequency of this key
        if (frequencies[freq].empty() && minFreq == freq)
            minFreq++;
        //// Insert this key to the cache
        insert(key, kv.second, freq + 1);
        return kv.second;
    }

    void put(int key, int value)
    {
        if (capacity <= 0)
            return;

        // Get the iterator pointing to an entry in cache
        const auto keyItInCache = cache.find(key);

        // If this key is already in the cache
        if (keyItInCache != cache.end())
        {
            // Update the (new) value of this key
            keyItInCache->second.second->second = value; // keyItInCache->second is the frequency of this key
            // Update the new frequency of this key
            get(key);
            return;
        }
        // If this key is not in the cache
        //// If the capacity has been full
        if (cache.size() == capacity)
        {
            // Get the least frequently used key
            int leastFreqUsedKey = frequencies[minFreq].front().first;
            // Erase the least frequently used key
            cache.erase(leastFreqUsedKey);
            frequencies[minFreq].pop_front();
        }
        //// Update the cache with the new key
        minFreq = 1;
        insert(key, value, minFreq);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Time complexity: O(1)
// Space complexity: O(N)