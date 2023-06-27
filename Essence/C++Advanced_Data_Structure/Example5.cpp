class Solution {
public:
    int nthUglyNumber(int n) {
        int cnt = 1;
        set<long long> s;
        s.insert(1ll);
        while(true){
            if(cnt==n) break;
            long long minS = *s.begin();
            s.insert(minS*2);
            s.insert(minS*3);
            s.insert(minS*5);
            s.erase(s.begin());
            cnt++;
        }
        return (int)(*s.begin());
    }
};