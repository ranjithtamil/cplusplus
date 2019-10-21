
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> mymap;
        int n=nums.size();
        for(int i=0;i<n;i++) {
            mymap[nums[i]]++;
        }
        int k=0;    
        for(int i=0;i<n;) {
            if(mymap[nums[i]]>1) {
                mymap[nums[i]]--;
                int j=i;
                k++;
                while(j<(n-1)) {
                    nums[j]=nums[j+1];
                    j++;
                }
                
            }
            else {
                i++;
            }
        }
        return (n-k);
    }
};
