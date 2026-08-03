class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(int i = 0;i<s.length();i++){
            m[s[i]]++;
        }
        string ans = "";
        vector<pair<char, int>> vec(m.begin(), m.end());
        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        for(int i = 0;i<vec.size();i++){
            int b = vec[i].second;
            while(b>0){
                 ans += vec[i].first;
                b--;
            }
        }
        return ans;
    }
};