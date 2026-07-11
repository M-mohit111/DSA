class Solution {
public:
    void dfs(int node,vector<vector<int>>v,vector<bool>&vi){
        for(int i = 0;i<v[node].size();i++){
            if(vi[v[node][i]]==0){
                vi[v[node][i]]=1;
                dfs(v[node][i],v,vi);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>v(n);
        for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++){
            if(isConnected[i][j]==1&& i != j){
                v[i].push_back(j);
            }
        }
        vector<bool>vi(n,0);
        int ans = 0;
        for(int i =0;i<n;i++){
            if(vi[i]==0){
                vi[i]=1;
                dfs(i,v,vi);
                ans++;
            }
        }
        return ans;
    }
};