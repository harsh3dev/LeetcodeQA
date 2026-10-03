class MyHashMap {
    vector<list<pair<int, int>>> mp;
    int size = 10000;
public:
    MyHashMap() {
        mp.resize(size);
    }
    
    void put(int key, int value) {
        auto &list = mp[key % size];
        for(auto & val : list){
            if(val.first == key){
                val.second = value;
                return;
            }
        }

        list.emplace_back(key, value);
    }
    
    int get(int key) {
        const auto& list = mp[key%size];
        if(list.empty()){
            return -1;
        }
        for(const auto& val:list){
            if(val.first == key){
                return val.second;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        auto& list = mp[key%size];
        for (auto it = list.begin(); it != list.end(); ++it) {
            auto& val = *it;

            if (val.first == key) {
                list.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */