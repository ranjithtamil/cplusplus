//TODO: Compare whether using distance[][] as in Leetcode brute force solution
//(OR)  using step and no distance vector (but visited vector) is better (in terms of space and time complexity).
class Solution {
public:
    int WALL = -1;
    int GATE = 0;
    int EMPTY = INT_MAX;
    vector<vector<int>> dirs{{-1,0},{0,-1},{1,0},{0,1}};
    int bfs(vector<vector<int>>& rooms, int row, int col) {
        int m=rooms.size();
        int n=rooms[0].size();
        int step = 0;
        bool visited[m][n];
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                visited[i][j]=0;
            }
        }
        
        queue<pair<int,int>> Q;
        Q.push(make_pair(row,col));
        
        while(!Q.empty()) {
            int siz=Q.size();
            step++;
            for(int i=0;i<siz;i++) {
                for(int j=0;j<dirs.size();j++) {
                    pair<int,int> cur = Q.front();
                    int neighrow = cur.first + dirs[j][0];
                    int neighcol = cur.second + dirs[j][1];
                    if(neighrow >=0 && neighrow <m && neighcol >=0 && neighcol <n && visited[neighrow][neighcol]==false && rooms[neighrow][neighcol]!=WALL) {
                        if(rooms[neighrow][neighcol] == GATE) {
                            return step;
                        }
                        Q.push(make_pair(neighrow,neighcol));
                        visited[neighrow][neighcol]=true;
                    } 
                }
                Q.pop();
            }
        }
        return INT_MAX;
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n1 = rooms.size();
        if(n1==0) {
            return;
        }
        int m=rooms.size();
        int n=rooms[0].size();
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(rooms[i][j]==EMPTY) {
                    rooms[i][j]=bfs(rooms,i,j);
                }
            }
        }
    }
};
