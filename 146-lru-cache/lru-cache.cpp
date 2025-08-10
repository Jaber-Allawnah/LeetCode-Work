class LRUCache {
    int cap;
    list<pair<int,int>> dq;  
    unordered_map<int, list<pair<int,int>>::iterator> pos;

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end()) return -1;
        dq.splice(dq.begin(), dq, it->second);   
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = pos.find(key);
        if (it != pos.end()) {
            it->second->second = value;        
            dq.splice(dq.begin(), dq, it->second); 
            return;
        }
        if (cap == 0) return; 
        if ((int)dq.size() == cap) {
            int oldKey = dq.back().first;        
            pos.erase(oldKey);
            dq.pop_back();
        }
        dq.emplace_front(key, value);           
        pos[key] = dq.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */