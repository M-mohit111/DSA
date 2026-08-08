class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> m;
        for (string word : wordDict) {
            m.insert(word);
        }
        int maxlen = 0;
        for(string i : wordDict){
            int l = i.length();
            maxlen = max(maxlen,l);
        }

        vector<bool>v(s.length()+1,0);
        
        v[0] = true;
        
        for(int i = 0;i<s.length();i++){

            for(int j = i;j>=0;j--){

                string t = s.substr(j,i-j+1);

                if(m.contains(t) && v[j]){
                    v[i+1] = 1;
                    break;
                }

            }
           
        }
        return v[s.length()];
    }
};

// backtracking method but will show tle

// class Solution {
// public:
//     bool solve(string& s, unordered_set<string>& dict, int start) {
//         if (start == s.length()) {
//             return true;
//         }
//         string t = "";
//         for (int r = start; r < s.length(); r++) {
//             t += s[r];
//             if (dict.contains(t)) {
//                 if (solve(s, dict, r + 1)) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict;
//         for (string word : wordDict) {
//             dict.insert(word);
//         }
//         return solve(s, dict, 0);
//     }
// };