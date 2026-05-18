class LRUCache {
public:
    int capacity;

    list<int> dll;

    map<int, pair<list<int>::iterator, int>> mp;

    // map<int,list<pair<int>::iterator,int>>mp;

    void recentlyMark(int key) {

        dll.erase(mp[key].first);

        dll.push_front(key);

        mp[key].first = dll.begin();
    }

    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            recentlyMark(key);
           return  mp[key].second;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {

            mp[key].second = value;

            recentlyMark(key);
        }

        else {

            dll.push_front(key);

            mp[key] = {dll.begin(), value};

            capacity--;
        }

        if (capacity < 0) {

            int key1 = dll.back();

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