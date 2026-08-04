class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool check(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int x = cur.first;
            int y = cur.second;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (check(nx, ny, n, m) && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return dist;
    }
};

// this will show tle

// class Solution {
// public:
//     int x[4] = {-1,1,0,0};
//     int y[4] = {0,0,1,-1};
//     bool check(int i,int j,int n,int m){
//         return i>-1 && j>-1 && i<n && j<m;
//     }
//     int find(vector<vector<int>>& mat, int i, int j, int n, int m){
//         vector<vector<bool>> vis(n, vector<bool>(m, false));
//         queue<pair<pair<int,int>,int>>q;
//         q.push({{i,j},0});vis[i][j] = true;
//         while(!q.empty()){
//             int a = q.front().first.first;
//             int b = q.front().first.second;
//             int c = q.front().second;
//             q.pop();
//             if (mat[a][b] == 0)
//                 return c;
//             for(int k = 0;k<4;k++){
//                 int xx = x[k]+a;
//                 int yy = y[k]+b;
//                 if(check(xx,yy,n,m) && !vis[xx][yy]){
//                     vis[xx][yy]=1;
//                     q.push({{xx,yy},c+1});
//                 }
//             }
//         }
//         return 0;
//     }
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int n = mat.size();
//         int m = mat[0].size();
//         vector<vector<int>>v(n,vector<int>(m,0));
//         for(int i = 0;i<n;i++){
//             for(int j = 0;j<m;j++){
//                 if(mat[i][j]==0){
//                     v[i][j]=0;
//                 }
//                 else{
//                     int a = find(mat, i, j, n, m);
//                     v[i][j]=a;
//                 }
//             }
//         }
//         return v;
//     }
// };