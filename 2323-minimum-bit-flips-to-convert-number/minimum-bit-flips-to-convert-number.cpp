class Solution {
public:
    int minBitFlips(int start, int goal) {
        // string a = bitset<32>bits(start).tostring();
        // string b = bitset<32>bits(goal).tostring();
        // int n = a.length();


        int ans = 0;
        while(start>0 || goal>0){
            int a = start&1;
            int b = goal&1;

            if(a!=b){
                ans++;
            }

            start =start>>1;
            goal =goal>>1;
        }
        return ans;

    }
};