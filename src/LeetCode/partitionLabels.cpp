class Solution {
public:
    //https://www.youtube.com/watch?v=5NCjHqx2v-k
    vector<int> partitionLabels(string S) {
        unordered_map<char,int> last_indices;
        
        int n = S.size();
        if(n==0) {
            return {};
        }
        for(int i=0; i<n; i++) {
            last_indices[S[i]]=i;
        }
        
        vector<int> result;
        int start=0;
        int end=0;
        
        for(int i=0; i<S.size();i++) {
            end = max(end,last_indices[S[i]]);
            if(i==end) {
                result.push_back(end-start+1);
                start=end+1;
                //end=end+1;    //can be there or not, anyway its being recomputed at top
            }
        }
        return result;
    }
};
