class LRUCache {
public:
    int cap , sz ;
    map<int,int> mp;
    list<int> l;
    map<int,list<int>::iterator> add;
    LRUCache(int capacity) {
        cap = capacity;
        sz = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        list<int> :: iterator it = add[key];
        l.erase(it);
        add.erase(key);
        l.push_front(key);
        add[key] = l.begin();
        return mp[key];
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            l.erase(add[key]);
            add.erase(key);
            mp.erase(key);
            sz--;
        }
        if(sz == cap)
        {
            int k = l.back();
            l.pop_back();
            add.erase(k);
            mp.erase(k);
            sz--;
        }
        l.push_front(key);
        add[key] = l.begin();
        mp[key] = value;
        sz++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */