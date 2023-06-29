class Solution {
public:
    vector<vector<char>> vec {{},{},{'a','b','c'}, {'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

    vector<string> cartesion_product(vector<string>& sv, vector<char>& cv){
        vector<string> ret;
        if(sv.size()==0){
            for(int j = 0;j<cv.size();j++){
                string tmp = "";
                tmp.push_back(cv[j]);
                ret.push_back(tmp);
            }
            return ret;
        }
        for(int i = 0;i<sv.size();i++){
            for(int j = 0;j<cv.size();j++){
                string tmp = sv[i];
                tmp.push_back(cv[j]);
                ret.push_back(tmp);
            }
        }
        return ret;
    }


    vector<string> letterCombinations(string digits) {
        //笛卡尔积
        vector<string>ans;
        for(int i = 0;i<digits.size();i++){
            ans = cartesion_product(ans, vec[(digits[i] - '0')]);
        }        
        set<string> s_ans;
        for(int i = 0;i<ans.size();i++){
            s_ans.insert(ans[i]);
        }
        vector<string> final_ans;
        final_ans.assign(s_ans.begin(), s_ans.end());
        return final_ans;
    }
};