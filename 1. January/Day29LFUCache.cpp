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
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;
    unordered_map<int, list<pair<int, int>>> frequencies;
    int minFreq;  // the minimum frequency at any given time
    int capacity; // the capacity given in the input

    void insert(int key, int val, int freq)
    {
        frequencies[freq].push_back({key, val});
        cache[key] = {freq, --frequencies[freq].end()};
    }

public:
    LFUCache(int capacity) : minFreq(0),
                             capacity(capacity) {}

    int get(int key)
    {
        const auto keyIt = cache.find(key);

        // If this key does not exist in the cache
        if (keyIt == cache.end())
            return -1;

        // If this key exists in the cache
        const int freq = keyIt->second.first;
        const auto freqIt = keyIt->second.second;
        const pair<int, int> kv = *freqIt;
        //// Update frequencies and the min frequency
        frequencies[freq].erase(freqIt);
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

        const auto keyIt = cache.find(key);

        // If this key is already in the cache
        if (keyIt != cache.end())
        {
            // Update the value and frequency of this key
            keyIt->second.second->second = value;
            get(key);
            return;
        }
        // If this key is not in the cache
        //// If the capacity has been full
        if (cache.size() == capacity)
        {
            // Erase the least frequently used key
            cache.erase(frequencies[minFreq].front().first);
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