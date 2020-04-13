//Hashmap
class RandomizedSet {
public:
    unordered_map<int,int> map;
    vector<int> res;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.find(val) != map.end())        
            return false;
        map[val] =res.size();
        res.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (map.find(val) == map.end())
            return false;
        int size = res.size();
        res[map[val]] = res[size - 1];
        map[res[size - 1]] = map[val];
        res.pop_back();
        map.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int size = res.size();
        int index = rand() % size;
        return res[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */