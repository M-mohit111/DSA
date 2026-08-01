class Solution {
public:
    int helper(vector<int>& nums, int l, int r) {
        if (l == r)
            return nums[l];

        int left = nums[l] - helper(nums, l + 1, r);
        int right = nums[r] - helper(nums, l, r - 1);

        return max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {
        int ans = helper(nums, 0, nums.size() - 1);

        if (ans >= 0) {
            return true;
        } else {
            return false;
        }
    }
};