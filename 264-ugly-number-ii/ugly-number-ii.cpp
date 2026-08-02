class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<long long>s;
        priority_queue<long long,vector<long long>,greater<long long>>q;
        q.push(1);
        s.insert(1);
        long long i = 1;
        for (int k = 0; k < n; k++) {
            i = q.top();
            q.pop();
            if (!s.count(i * 2)) {
                q.push(i * 2);
                s.insert(i * 2);
            }
            if (!s.count(i * 3)) {
                q.push(i * 3);
                s.insert(i * 3);
            }
            if (!s.count(i * 5)) {
                q.push(i * 5);
                s.insert(i * 5);
            }
        }
        return (int)i;

    }
};