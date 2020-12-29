class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> myMap; 
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        myMap[key].push_back(make_pair(timestamp,value));
    }
    
    string get(string key, int timestamp) {
        if(!myMap.count(key)) {
            return "";
        }
        
        int n=myMap[key].size();
        int l=0;
        int h=n;
        
 
        
        while(l<h) {
            int m=l + (h-l)/2;
            
            
            if(timestamp < (myMap[key])[m].first) {
                h=m;
            }
            else {
                l=m+1;
            }
        }
        if(l>0 && l<=n) {
            return myMap[key][l-1].second;
        }
        else {
            return "";
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
