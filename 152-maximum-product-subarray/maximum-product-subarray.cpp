class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int p = 0;
        int s = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(p==0) p = 1;
            if(s==0) s = 1;
            p = p* nums[i];
            s = s* nums[n-i-1];
            ans = max(ans,max(p,s));
        }
        return ans;
    }
};