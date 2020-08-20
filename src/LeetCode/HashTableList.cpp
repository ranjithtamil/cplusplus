
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */
class Bucket {
    public:
    list<int> container;
    Bucket() {
       
    }
    void insert(int key) {
        container.push_back(key);
    }
    void remove(int key) {
        container.remove(key);
        
    }
    bool exists(int key) {
        if(find(container.begin(),container.end(),key)!=container.end()) {
            return true;
        }
        return false;
    }
};
class MyHashSet {
public:
    vector<Bucket> bucketArray;
    int keyRange;
    /** Initialize your data structure here. */
    MyHashSet() {
        keyRange=769;
        bucketArray=vector<Bucket>(keyRange);
    }
    
    int calcHash(int key) {
        int ret = key%keyRange;
        return ret;
    }
    
    void add(int key) {
        int hash_val = calcHash(key);
        bucketArray[hash_val].insert(key);
    }
    
    void remove(int key) {
        int hash_val = calcHash(key);
        bucketArray[hash_val].remove(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hash_val = calcHash(key);
        return bucketArray[hash_val].exists(key);
    }
};


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */


/*
vector implementation - too long

class MyHashSet {
    vector<int> hSet;
public:
   
    MyHashSet() {
        
    }
    
    void add(int key) {
        
            if(find(hSet.begin(),hSet.end(),key) == hSet.end()) {
                hSet.push_back(key);
            }
        
    }
    
    void remove(int key) {
        if(find(hSet.begin(),hSet.end(),key)!=hSet.end()) {
            hSet.erase(find(hSet.begin(),hSet.end(),key));    
        }
        
    }
    
    
    bool contains(int key) {
        if(find(hSet.begin(),hSet.end(),key)!=hSet.end()) {
            return true;
        }
        else {
            return false;
        }
    }
};
*/
