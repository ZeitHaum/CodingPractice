class Solution {
public:
    int romanToInt(string s) {
        map<char,int> dic = {{'I', 1},{'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            if(i!=s.size()-1){
                if(dic[s[i+1]] > dic[s[i]]){
                    ans -= dic[s[i]];
                    continue;
                }
            }
            ans += dic[s[i]];
        }
        return ans;
    }
};