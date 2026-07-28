class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        unordered_map<int,int>m;
        for(int i = 0;i<nums2.size();i++){
            m[nums2[i]] = i;
        }
        for(int i = 0;i<nums1.size();i++){
            int a = nums1[i];
            int l = m[a];
            for(int j = l;j<nums2.size();j++){
                if(nums2[j]>a){
                    v.push_back(nums2[j]);
                    break;
                }
                else if(j == nums2.size()-1 && nums2[j]<=a){
                    v.push_back(-1);
                }
            }
        }
        return v;
    }
};