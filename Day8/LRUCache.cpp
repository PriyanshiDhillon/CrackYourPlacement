class LRUCache {
public:
    unordered_map<int,int>lrumap;
    LRUCache(int capacity) {
        int maxsize = capacity;
    }
    
    int get(int key) {
        auto it = lrumap.find(key);
        if (it != lrumap.end()){
            lrumap[key]++;
            return key;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(lrumap.size()== 2){
            int leastFreq= 2,leastFreqElement=-1;
            for (const auto& pair : lrumap) {
                if (pair.second < leastFreq) {
                    leastFreq = pair.second;
                    leastFreqElement = pair.first;
                }
            }
            lrumap.erase(leastFreqElement);
            lrumap.insert({key, 1});
            lrumap[1]--;
        }
        else{
            lrumap.insert({key, 1});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */