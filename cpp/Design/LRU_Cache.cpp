#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) { }

    int get(int key) {
        auto it = cache.find(key);   // constant time because of hashmap
        if (it == cache.end())
            return -1;
        touch(it);   // update the LRU list and LRU iterator
        return it->second.first;
    }

    void set(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end())
            touch(it);   // update the LRU list and LRU iterator
        else {
            if (cache.size() == _capacity) {
                cache.erase(used.back());  // erase the end of LRU information
                used.pop_back();   // erase the end LRU list node
            }
            used.push_front(key);
        }
        cache[key] = {value, used.begin()};
    }

private:
    typedef list<int> LI;                    // {key}
    typedef pair<int, LI::iterator> PII;     // {value, iterator}
    typedef unordered_map<int, PII> HIPII;   // {key, {value, iterator}}

    HIPII cache;   // a hash map
    LI used;       // a list, the head of list is the LRU node
    int _capacity;

    // implement in the hash map, it takes constant time
    void touch(HIPII::iterator it) {
        int key = it->first;
        used.erase(it->second.second);  // erase by iterator, so that the cost time will be constant
        used.push_front(key);  // update the LRU list
        it->second.second = used.begin();  // update the iterator based on the theory of LRU
    }
};

int main() {
    LRUCache tmp(10);
    return 0;
}
