class Solution {
public:
    const string INT_MAX_STR = to_string(INT_MAX);
    const string INT_MIN_STR = to_string(INT_MIN);//neg already has '-'
    bool neg_flag;
    bool is_invalid(string s){
        bool ret = false;
        if(this->neg_flag){
            if(s.size() == INT_MIN_STR.size()){
                return s>INT_MIN_STR;// str should use > ie. "-2" > "-1";
            }
            else{
                ret = s.size() > INT_MIN_STR.size();
            }
        }
        else{
            if(s.size() == INT_MAX_STR.size()){
                return s>INT_MAX_STR;
            }
            else{
                ret = s.size() > INT_MAX_STR.size();
            }
        }
        return ret;
    }

    int reverse(int x) {
        this->neg_flag = x<0;
        //特例
        string s;
        if(x == -2147483648){
            s = "2147483648";
        }else{
            s = to_string(abs(x));
        }
        std::reverse(s.begin(), s.end());
        if(neg_flag){
            s = "-" + s;  
        }  
        int ret = 0;
        if(is_invalid(s)){
            ret = 0;
        }
        else{
            ret = stoi(s);
        }
        return ret;
    }
};