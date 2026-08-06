class Solution {
public:

    long long check(int i,vector<int>&piles,int h){
        long long sum = 0;
        for(int l:piles){
            double d = 1.0*l/i;
            sum += ceil(d);
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxx = 0;
        for(int i:piles){
            maxx = max(maxx,i);
        }
        int s = 1;
        int e = maxx;
        int ans = 0;
        while(s<=e){
            int m = s+(e-s)/2;
            long long t = check(m,piles,h);
            if(t <= h){
                ans =  m;
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
        return ans;
    }
};

// this will going to show tle 

// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int n = piles.size();
//         int sum = 0;
//         int ans = 0;
//         int i = 1;
//         while(true){
//             for(int j = 0;j<n;j++){
//                 double b = 1.0*piles[j]/i;
//                 sum += ceil(b);
//             }
//             if(sum == h){
//                 ans = i;
//                 break;
//             }
//             else{
//                 sum = 0;
//                 i++;
//             }
//         }
//         return ans;
//     }
// };