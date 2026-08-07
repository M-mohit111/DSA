class Solution {
public:
    void helper(vector<string>&ans,int n,string& t,int open,int close){
        if(t.size()== 2*n){
            ans.push_back(t);
            return;
        }
        if(open<n){
            t.push_back('(');
            open++;
            helper(ans,n,t,open,close);
            t.pop_back();
            open--;
        }
        if(close<open){
            t.push_back(')');
            close++;
            helper(ans,n,t,open,close);
            t.pop_back();
            close--;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open = 0;
        int close = 0;
        string t = "";
        helper(ans,n,t,open,close);
        return ans;
    }
};