class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_set<int>s;
        for(int i :arr){
            s.insert(i);
        }
        int i = 1;
        int ans = 0;
        int count = 0;
        while(count!=k){
            if(!s.contains(i)){
                ans = i;
                count++;
                i++;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};