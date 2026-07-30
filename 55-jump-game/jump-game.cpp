class Solution{
public:
    bool canJump(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(i>count){
                return false;
            }
            count = max(count, nums[i]+i);
        }
        return true;
    }
};