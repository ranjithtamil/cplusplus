class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](vector<int> &l, vector<int> &r) { if(l[0]<r[0]) { return true;}return false;});
        
        
        vector<vector<int>> result;
        for(int i=0;i<intervals.size();i++) {
            if(result.size()==0) {
                vector<int> sample;
                sample.push_back(intervals[i][0]);
                sample.push_back(intervals[i][1]);
                result.push_back(sample);
            }
            else if((result.back())[1] >= intervals[i][0]) {
                (result.back())[1] = max((result.back())[1], intervals[i][1]);
            }
            else {
                vector<int> sample;
                sample.push_back(intervals[i][0]);
                sample.push_back(intervals[i][1]);
                result.push_back(sample);
            }
        }
        return result;
    }
};
