class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> endingTimeCnt; //map that maps key = endingTime, value = (count of them, index value in that row)
        
        int n = wall.size();
        int maxFreq = 0;
        int minBricksCrossed = wall.size();
        for(int i=0; i<n; i++) {
            int sum_i=0;
            for(int j=0;j<wall[i].size()-1;j++) {
                sum_i=sum_i + wall[i][j];
                endingTimeCnt[sum_i]++;
                
                
                if(endingTimeCnt[sum_i] > maxFreq) {
                    maxFreq = endingTimeCnt[sum_i];
                    minBricksCrossed = wall.size() - maxFreq;   //you want to return the number of bricks crossed.
                }
            }
        }
        
        return minBricksCrossed;
    }
};
