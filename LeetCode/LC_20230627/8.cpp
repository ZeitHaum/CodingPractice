class Solution {
public:
    const string INT_MAX_STR = to_string(INT_MAX);
    const string INT_MIN_STR = to_string(INT_MIN);

    bool is_invalid(const string& s){
        if(s[0]=='-'){
            //neg
            if(s.size() == INT_MIN_STR.size()){
                return s>INT_MIN_STR;
            }
            else{
                return s.size() > INT_MIN_STR.size();
            }
        }
        else{
            //pos
            if(s.size() == INT_MAX_STR.size()){
                return s>INT_MAX_STR;
            }
            else{
                return s.size() > INT_MAX_STR.size();
            }
        }
        return true;
    }

    string delete_pre_zeros(string s){
        string ret = "";
        bool nonzero_enable = false;
        for(int i = 0;i<s.size();i++){
            if(nonzero_enable){
                ret.push_back(s[i]);
            }
            else{
                if(s[i] != '0'){
                    nonzero_enable = true;
                    ret.push_back(s[i]);
                }
            }
        }
        return ret;
    }

    int myAtoi(string s) {
        string int_str = "";
        bool neg_flag = false;
        bool op_enable = false;
        for(int i = 0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                int_str.push_back(s[i]);
            }
            else if(s[i]=='-'){
                if(!op_enable && int_str==""){
                    op_enable = true;
                    neg_flag = true;
                }
                else{
                    cout<<"b1"<<"\n";
                    break;
                }
            }
            else if(s[i]=='+'){
                if(!op_enable && int_str==""){
                    op_enable = true;
                    neg_flag = false;
                }
                else{
                    break;
                }
            }
            else if(s[i]==' '){
                if(int_str!="" || op_enable==true){
                    break;
                }
            }
            else{
                break;
            }
        }
        //delete prezeros
        int_str = delete_pre_zeros(int_str);
        //SP
        if(int_str==""){
            return 0;
        }
        if(neg_flag){
            int_str = "-" + int_str;
        }
        //valid check
        if(is_invalid(int_str)){
            //invalid
            if(neg_flag){
                return INT_MIN;
            }
            else{
                return INT_MAX;
            }
        }
        else{
            //valid
            return stoi(int_str);
        }
    }
};