class LRUCache {
public:
    int cap;
    unordered_map<int, list<pair<int, int>>::iterator> iter;
    list<pair<int, int>> vals;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    void updateRecency(int key) {
        auto it = iter[key];
        auto pr = *it;
        
        vals.erase(it);
        vals.push_front(pr);
        
        iter[key] = vals.begin();
    }
    
    int get(int key) {
        // key not found
        if (!iter.count(key))
            return -1;
        // key found, now let's make it the most recent used key
        updateRecency(key);
        // after recency update, the key must be at the beginning of the list
        return vals.begin()->second;
    }
    
    void put(int key, int value) {
        
        // update the existing (key, value) pair and its recency
        if (iter.count(key)) {
            // update the value
            iter[key]->second = value;
            // now make it the most recent used key
            updateRecency(key);
            return;
        }
        
        // remove the least recent used key
        if (vals.size() == cap) {
            auto [k, v] = *prev(vals.end());
            iter.erase(k);
            vals.erase(prev(vals.end()));
        }
        
        // insert a new (key, value) pair
        vals.push_front({key, value});
        iter[key] = vals.begin();
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */