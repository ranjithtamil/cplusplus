class Solution {
public://Can optimise even more by taking cols, if cols<rows... and taking rows, if rows<cols.
    //If you pick rows, then you have to traverse top to bottom..
    //If you pick cols(as solved below), you can traverse normal left to right
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int rows=grid.size();
        if(rows==0) {
            return 0;
        }
        int cols=grid[0].size();
        
        int rowHits=0;
        vector<int> colHits(cols,0);
        
        int maxEnemy=0;
        for(int row=0;row<rows;row++) {
            for(int col=0;col<cols;col++) {
                
                if(col==0 || grid[row][col-1]=='W') {
                    rowHits=0;
                    for(int k=col;k<cols;k++) {
                        if(grid[row][k]=='W') {
                            break;
                        }
                        if(grid[row][k]=='E') {
                            rowHits=rowHits+1;
                        }
                    }
                }
                
                if(row==0 || grid[row-1][col]=='W') {
                    colHits[col]=0;
                    for(int k=row;k<rows;k++) {
                        if(grid[k][col]=='W') {
                            break;
                        }
                        if(grid[k][col]=='E') {
                            colHits[col]=colHits[col]+1;
                        }
                    }
                }
                
                
                if(grid[row][col]=='0') {
                    maxEnemy = max(maxEnemy, rowHits + colHits[col]);
                }
            }
        }
        return maxEnemy;
    }
};
