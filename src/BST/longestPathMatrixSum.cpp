class Solution {
public:
    //Do BFS
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0) {
            return 0;
        }
        int n=matrix[0].size();
        int maxlen=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int len=BFS(i,j,matrix);
                if(len > maxlen) {
                    maxlen=len;
                }
            }
        }
        return maxlen;
    }
    int BFS(int cx,int cy, vector<vector<int>>& grid) {
        int maxlen=0;
        int m=grid.size();
        int n=grid[0].size();
        int step=0;
        vector<vector<int>>dirs{{-1,0},{0,-1},{1,0},{0,1}};
        queue<pair<pair<int,int>,int>> Q;
        
        Q.push(make_pair(make_pair(cx,cy),grid[cx][cy]));
        
        while(!Q.empty()) {
            int qsize=Q.size();
            step++;
            for(int i=0;i<qsize;i++) {
                pair<pair<int,int>,int> currElement = Q.front();
                Q.pop();
                
                int curx = (currElement.first).first;
                int cury = (currElement.first).second;
                int curlen = currElement.second;
                
                if(curlen > maxlen) {
                    maxlen = curlen;
                }
                for(int p=0; p<dirs.size(); p++) {
                    int neighX = curx + dirs[p][0];
                    int neighY = cury + dirs[p][1];
                    if(neighX>=0 && neighY>=0 && neighX<m && neighY<n && grid[neighX][neighY]> grid[curx][cury]) {
                        int addlen = grid[neighX][neighY];
                        Q.push(make_pair(make_pair(neighX,neighY),(curlen+addlen)));
                    }
                }
            }
        }
        return maxlen;
        
    }
};
