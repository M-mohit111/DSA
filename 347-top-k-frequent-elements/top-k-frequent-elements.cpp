class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i : nums){
            m[i]++;
        }
        vector<int>v;
        priority_queue<pair<int,int>>q;
        for(auto it = m.begin();it!=m.end();it++){
            int a = it->second;
            int b = it->first;
            q.push({a,b});
        }
        while(k--){
            v.push_back(q.top().second);
            q.pop();
        }
        return v;
    }
};