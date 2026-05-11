class LRUCache {
public:
    list<int> dll;

    map<int, pair<list<int>::iterator, int>> mp; // key->(list_node, value)

    int capacity;

    LRUCache(int capacity) { this->capacity = capacity; }

    void mostRecentlyUsed(int key) {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }

    int get(int key) {

        if (mp.find(key) == mp.end()) {
            return -1;
        }

        mostRecentlyUsed(key);

        return mp[key].second;
    }

    void put(int key, int value) {

        if (mp.count(key)) {
            mp[key].second = value;
            mostRecentlyUsed(key);
        } else {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            capacity--;
        }

        if (capacity < 0) {
            mp.erase(dll.back());
            dll.pop_back();
            capacity++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */