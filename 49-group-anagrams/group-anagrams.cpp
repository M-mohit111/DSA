class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>v;
        unordered_map<string,vector<string>>m;
        for(int i = 0;i<strs.size();i++){
            string a = strs[i];
            string sor = a;
            sort(a.begin(),a.end());
            m[a].push_back(sor);
        }
        for(auto it = m.begin();it!=m.end();it++){
            v.push_back(it->second);
        }
        return v;
    }
};