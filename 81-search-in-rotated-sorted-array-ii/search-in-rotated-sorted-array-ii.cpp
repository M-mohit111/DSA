class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0;
        int n = nums.size();
        int e = n-1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(target == nums[m] || target == nums[s] || target == nums[e]){
                return true;
            }
            else if(nums[m]<nums[e]){
                if(target > nums[m] && target <= nums[e]){
                    s = m+1;
                }
                else{
                    e = m-1;
                }
            }
            else if(nums[s] < nums[m]){
                if(target < nums[m] && target >= nums[s]){
                    e = m-1;
                }
                else{
                    s = m+1;
                }
            }
            else{
                s++ ; 
                e-- ;
            }
        }
        return false;
    }
};