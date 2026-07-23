class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i = 0;i<n;i++){
            m[nums[i]] = 1;
        }
        int ans = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            int a = it->first;
            if (m.find(a - 1) != m.end()) {
                continue;
            }
            int len = 1;
            while (m.find(a + 1) != m.end()) {
                a++;
                len++;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};