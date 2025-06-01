class RandomizedSet {
public:

    vector<int> arr;
    unordered_map<int, int> mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        arr.push_back(val);

        mp[val] = arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;

        int index = mp[val];
        int lastElement = arr.back();
        arr[index] = lastElement;
        arr.pop_back();
        mp[lastElement] = index;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int index = rand()%arr.size();
        return arr[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */