class Solution {
public:
    int n;
    int m;
    bool check(string& s){
        int curr = 0;
        for(int i = 0;i<s.size();i++){
            curr += (s[i]==')')? -1:1;
            if(curr<0){
                return false;
            }
        }
        return curr==0;
    }

    //C_n^{m}
    bool next_combination(vector<int>& now){
        int begin = m;
        bool is_end = true;
        //backward
        for(int i = m-1;i>=0;i--){
            now[i]++;
            if(now[i]<n - ((m-1)-i) + 1){
                begin = i+1;
                is_end = false;
                break;
            }
        }
        //forward
        for(int i = begin;i<m;i++){
            now[i] = now[i-1]+1;
        }
        return is_end;
    }

    string get_multi_char(char c, int num){
        string ret = "";
        for(int i = 0;i<num;i++){
            ret.push_back(c);
        }
        return ret;
    }

    vector<string> generateParenthesis(int n) {
        this->m = n;
        this->n = n*2;
        n = n*2;
        vector<int> to_search;
        for(int i = 0;i<m;i++){
            to_search.push_back(i+1);
        }
        vector<string> ret;
        auto solve = [&](){
            string reti = get_multi_char(')', this->n);
            for(int i = 0;i<m;i++){
                reti[to_search[i]-1] = '(';
            }
            // cout<<reti<<"\n";
            if(check(reti)){
                ret.push_back(reti);
            }
        };
        solve();
        while(!next_combination(to_search)){
            solve();
        }
        return ret;
    }
};