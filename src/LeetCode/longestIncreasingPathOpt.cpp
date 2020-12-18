class Solution {
public:
    /*
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    if(matrix.empty()) return 0;

    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> check(m,vector<int>(n,0));
    int res = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            res = max(res, find(matrix, m, n, i, j, check));
        }
    }
    return res;
}

int find(vector<vector<int>>& matrix, int m, int n, int row, int col, vector<vector<int>>& check){
    int maxlen = check[row][col];
    if(check[row][col] > 0){return maxlen;}
    //if(check[row][col]< INT_MAX){
        if(row > 0 && matrix[row - 1][col] > matrix[row][col]){maxlen = max(find(matrix, m, n, row - 1, col,check),maxlen);}//up
        if(row < m - 1 && matrix[row + 1][col] > matrix[row][col]){maxlen = max(find(matrix, m, n,  row + 1, col,check),maxlen);}//down
        if(col > 0 && matrix[row][col - 1] > matrix[row][col]){maxlen = max(find(matrix, m, n, row, col - 1,check),maxlen);}//left
        if(col < n - 1 && matrix[row][col + 1] > matrix[row][col]){maxlen = max(find(matrix, m, n, row, col + 1,check),maxlen);}//right
        check[row][col] = ++maxlen;
    //}
    return maxlen;
}
    */
    /*
    DFS with memoization
    */
    
    
    
    int DFS(int i,int j, vector<vector<int>>& grid,vector<vector<int>>& cache) {
     //   vector<vector<int>>dirs{{-1,0},{0,-1},{1,0},{0,1}};
        int m=grid.size();
        int n=grid[0].size();
        int ans=1;
        
        if(cache[i][j]>0) {
            return cache[i][j];
        }
        
        if(i>0 && grid[i-1][j]>grid[i][j]) { ans = max(ans, 1+DFS(i-1,j,grid,cache));}
        if(j>0 && grid[i][j-1]>grid[i][j]) { ans = max(ans, 1+DFS(i,j-1,grid,cache));}
        if(i<m-1 && grid[i+1][j]>grid[i][j]) { ans = max(ans, 1+DFS(i+1,j,grid,cache));}
        if(j<n-1 && grid[i][j+1]>grid[i][j]) { ans = max(ans, 1+DFS(i,j+1,grid,cache));}
    //    for(int p=0; p<dirs.size();p++) {
    //        int neighX = i + dirs[p][0];
    //        int neighY = j + dirs[p][1];
            
    //        if(neighX>=0 && neighY>=0 && neighX<m && neighY<n && grid[neighX][neighY]<grid[i][j]) {
    //            ans=max(ans,1+DFS(neighX,neighY,grid,cache));
    //        }
    //    }
        
        cache[i][j]=ans;
        return cache[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0) {
            return 0;
        }
        int n=matrix[0].size();
        
        vector<vector<int>> cache;
        cache=vector<vector<int>>(m, vector<int>(n, 0));
        
        int maxlen=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                
                if(cache[i][j]==0) {
                    int len=DFS(i,j,matrix,cache);
                    if(len > maxlen) {
                        maxlen=len;
                    }
                }        

            }
        }
        return maxlen;
    }
    
    /*
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
        int m=grid.size();
        int n=grid[0].size();
        //vector<vector<bool>> visited(m,vector<bool>(n,false));
        int step=0;
        vector<vector<int>>dirs{{-1,0},{0,-1},{1,0},{0,1}};
        queue<pair<int,int>> Q;
        
        Q.push(make_pair(cx,cy));
        
        while(!Q.empty()) {
            int qsize=Q.size();
            step++;
            for(int i=0;i<qsize;i++) {
                pair<int,int> currElement = Q.front();
                Q.pop();
                
                
                int curx = (currElement).first;
                int cury = (currElement).second;
                for(int p=0; p<dirs.size(); p++) {
                    int neighX = curx + dirs[p][0];
                    int neighY = cury + dirs[p][1];
                    
                    if(neighX>=0 && neighY>=0 && neighX<m && neighY<n && grid[neighX][neighY]> grid[curx][cury]) {
                        Q.push(make_pair(neighX,neighY));
                    }
                }
            }
        }
        cout<<"\n for cx= "<<cx<<" cy= "<<cy<<" step = "<<step;
        return step;
    }
    */
};
