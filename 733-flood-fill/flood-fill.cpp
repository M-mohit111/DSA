class Solution {
public:
    bool check(int i,int j ,int r,int c){
        if(i<r && j<c && i>-1 && j>-1){
            return true;
        }
        else{
            return false;
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row = image.size();
        int col = image[0].size();

        int v = image[sr][sc];

        if(v == color)
            return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;

        int x[4]={0,0,1,-1};
        int y[4]={1,-1,0,0};
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            q.pop();
            for(int k = 0;k<4;k++){
                int xx = a+x[k];
                int yy = b+y[k];
                if(check(xx,yy,row,col) && image[xx][yy]==v){
                    image[xx][yy]=color;
                    q.push({xx,yy});
                }
            }
        }
        return image;
    }
};