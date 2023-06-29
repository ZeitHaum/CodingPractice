class Solution {
public:
    stack<int> st;
    map<char, char> match{{'(',')'}, {'[', ']'}, {'{','}'}};
    
    bool check(char c){
        if(match.count(c)!=0){
            st.push(c);
            return true;
        }   
        else{
            if(!st.empty() && match[st.top()]==c){
                st.pop();
                return true;
            }   
            else{
                return false;
            }
        }
    }

    bool isValid(string s) {       
        for(int i = 0;i<s.size();i++){
            if(check(s[i])==false){
                return false;
            }
        }
        return st.empty();
    }
};