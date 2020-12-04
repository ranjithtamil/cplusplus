class Solution {
public:
    int totalFruit(vector<int>& tree) {
    int maximumSoFar=0;
    unordered_map<int,int>freq;
    //int K=2;
    int unique=0;
    int lptr=0;
    int rptr=1;
    freq[tree[lptr]]++;
    unique++;
    if(tree.size()<=2) {
        return tree.size();
    }
    while(rptr<tree.size()) {
        if(freq[tree[rptr]]==0) {
            unique++;
            while(unique>2) {
                freq[tree[lptr]]--;
                if(freq[tree[lptr]]==0) {
                    unique--;
                }
                lptr++;
            }
        }
        freq[tree[rptr]]++;
        if((rptr-lptr+1)>maximumSoFar) {
            maximumSoFar=rptr-lptr+1;
        }
        rptr++;
    }
    return maximumSoFar;
    }
};
