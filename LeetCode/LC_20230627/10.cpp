class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string t = to_string(x);
        reverse(t.begin(),t.end());
        return s == t;
    }
};