class Solution {
public:
    
    /*
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        visited[i]=true;
        
        
        for(int j=0;j<isConnected[i].size();j++) {
            if(visited[j]==false && isConnected[i][j] ==1) {
                dfs(isConnected, visited,j);
            } 
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();       //for nxn=5x5 matrix, n=5
        vector<bool> visited(n,false);       
        int cntConnectedComponents = 0;
        
        for(int i=0;i<n;i++) {
            if(visited[i]==false) {
                visited[i]=true;
                dfs(isConnected, visited,i);
                cntConnectedComponents++;
            }
        }
        return cntConnectedComponents;
    }*/
    
    //BFS
    /*
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();       //for nxn=5x5 matrix, n=5
        vector<bool> visited(n,false);       
        int cntConnectedComponents = 0;
        
        queue<int> Q;
        for(int i=0; i<n;i++) {
            if(visited[i]==false) {
                visited[i]=true;
                cntConnectedComponents++;
                Q.push(i);
                
                while(!Q.empty()) {
                    int curr = Q.front();
                    Q.pop();
                    for(int j=0; j<n;j++) {
                        if(visited[j]==false && isConnected[curr][j]==1) {          //important [curr][j]
                            visited[j]=true;
                            Q.push(j);
                        }
                    }
                }
                
            }
        }
        
        return cntConnectedComponents;
    }*/
    int findSet(vector<int>& parent, int ele) {
        if(parent[ele]==ele) {
            return ele;
        }
        
        parent[ele]=findSet(parent,parent[ele]);
        return parent[ele];
    }
    void Union(int i, int j, vector<int>& parent) {
        if(i==j) {
            return;         //for same element (i,i), just return
        }
        
        
        
        int parentI = findSet(parent,i);
        int parentJ = findSet(parent,j);
        if(parentI == parentJ) {
            return;
        }
        if(parentI != parentJ) {
            parent[parentI]=parentJ;
            //Note that you dont need rank for this problem
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int cntConnectedComponents=0;
        vector<int> parent(n,0);
        for(int i=0;i<n;i++) {
            parent[i]=i;
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(isConnected[i][j]==1 && i!=j) {
                    Union(i,j,parent);
                }
            }
        }
        
        for(int i=0;i<n;i++) {
            if(parent[i]==i) {
                cntConnectedComponents++;
            }
        }
        return cntConnectedComponents;
    }
};
