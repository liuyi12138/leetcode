class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> myMap;
    vector<int> result;
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(!myMap.count(val)){
            myMap[val] = result.size();
            result.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!myMap.count(val))
            return false;
        int temp = result[result.size()-1];
        myMap[temp] = myMap[val];
        result[myMap[val]] = temp;
        result.pop_back();
        myMap.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int i = rand()%myMap.size();
        return result[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */