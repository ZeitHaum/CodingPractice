class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //特例
        if(strs.size()==0){
            return "";
        }
        if(strs.size()==1){
            return strs[0];
        }
        int ind = 0;
        string ret = "";
        while(true){
            bool isallsame = true;
            for(int i = 1;i<strs.size(); i++){
                if(ind==strs[i].size() || strs[i][ind]!=strs[0][ind]){
                    isallsame = false;
                    break;
                }
            }
            if(!isallsame){
                break;
            }
            else{
                ret.push_back(strs[0][ind]);
                ind++;
            }
        }
        return ret;
    }
};