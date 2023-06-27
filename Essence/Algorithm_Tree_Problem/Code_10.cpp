#include <bits/stdc++.h>
using namespace std;

int pow2[31];

string binary_str1(int x){
    string rans;//初始设置ans为答案的翻转串
    while(true){
        if(x%2==0) rans.push_back('0');
        else rans.push_back('1');
        x = x/2;
        if(x==0) break;
    }
    reverse(rans.begin(),rans.end());
    return rans;
}

string binary_str2(int x){
    string ans;
    for(int i = 30;i>=0;i--){
        if(x>= pow2[i]){
            x -= pow2[i];
            ans.push_back('1');
        } 
        else ans.push_back('0');
    }
    //如果要求去除前导0...
    int first_1 = 0;
    for(int i = 1;i<=31;i++){
        if(ans[i]=='1'){
            first_1 = i;
            break;
        }
    }
    return ans.substr(first_1,31 - first_1+1);
}

int main(){
    //预处理pow2
    for(int i = 0;i<31;i++){
        if(i==0) pow2[i] = 1;
        else pow2[i] = pow2[i-1] * 2;
    }
    int x = 13;
    cout<<binary_str1(x)<<endl<<binary_str2(x)<<endl;
}