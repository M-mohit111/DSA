class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>m;
        unordered_set<char>set;
        for(int i = 0;i<s.length();i++){
            char a = s[i];
            char b = t[i];
            if(m.find(a)==m.end()){
                if(set.count(b)){
                    return false;
                }
                m[a]=b;
                set.insert(b);
            }
            else{
                if (m[a] != b)
                    return false;
            }
        }
        return true;
    }
};