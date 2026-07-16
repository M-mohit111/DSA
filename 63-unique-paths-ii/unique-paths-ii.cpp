class Solution {
public:
    int find(int i,int j,int row,int col,vector<vector<int>> grid,vector<vector<int>>&v){
        if(i==row-1 && j == col-1){
            return 1;
        }
        if(i>=row || j>=col){
            return 0;
        }
        if(grid[i][j]==1){
            return 0;
        }
        if (v[i][j] != -1)
            return v[i][j];
        return v[i][j] = find(i+1,j,row,col,grid,v)+find(i,j+1,row,col,grid,v);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(grid[row-1][col-1]==1){
            return 0;
        }
        vector<vector<int>>v(row,vector<int>(col,-1));
        return find(0,0,row,col,grid,v);
    }
};