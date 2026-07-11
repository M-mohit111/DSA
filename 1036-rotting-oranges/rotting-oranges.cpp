class Solution {
public:
    bool check(int xx,int yy,int n,int m){
        if(xx>-1&&xx<n&&yy>-1&&yy<m){
            return true;
        }
        else{
            return false;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int x[4] = {1,0,-1,0};
        int y[4] = {0,1,0,-1};
        int ans = 0;
        int count = 0;
        int total = 0;
        for(int i =0 ;i<n;i++)
        for(int j = 0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},ans});
                count++;total++;
            }
            if(grid[i][j]==1){total++;}
        }
        while(!q.empty()){
            int a = q.front().first.first;
            int b = q.front().first.second;
            int w = q.front().second;
            q.pop();
            for(int k = 0;k<4;k++){
                int xx = x[k]+a;
                int yy = y[k]+b;
                if(check(xx,yy,n,m) && grid[xx][yy]==1){
                    grid[xx][yy]=2;
                    count++;
                    q.push({{xx,yy},w+1});
                    ans = max(ans,w+1);
                }
            }
        }
        if(total != count){
            return -1;
        }
        return ans;
    }
};