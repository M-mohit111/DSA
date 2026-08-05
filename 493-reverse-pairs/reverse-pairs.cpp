class Solution {
public:

void merge(int i,int n,int& ans,vector<int>&nums,int m){
    
    int j = m+1;
    for(int l = i;l<=m;l++){
while(j <= n && (long long)nums[l] > 2LL * nums[j]){
            j++;
        }
       ans += (j - (m + 1));

    }
    vector<int>temp;
    int left = i;
    int right = m+1;
while(left <= m && right <= n){

        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
           temp.push_back(nums[right]);
            right++; 
        }

    }
    while (left <= m) {
        temp.push_back(nums[left]);
        left++;
    }

    while (right <= n) {
        temp.push_back(nums[right]);
        right++;
    }
    for (int l = i; l <= n; l++) {
        nums[l] = temp[l - i];
    }

}

void mergesort(int i,int n,int& ans,vector<int>&nums){
    if(i >= n)
        return;
    int m = i+(n-i)/2;
    mergesort(i,m,ans,nums);
    mergesort(m+1,n,ans,nums);
    merge(i,n,ans,nums,m);
}

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        mergesort(0,n-1,ans,nums);
        return ans;
    }
};

// this will show tle 

// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int n = nums.size();
//         int ans = 0;
//         for(int i = n-1;i>=0;i--){
//             int a = nums[i];
//             for(int j = 0;j<i;j++){
//                 int b = nums[j];
//                 long long k = (long long)2*a;
//                 if(b>k){
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };