#include <bits/stdc++.h>
using namespace std;

int quickpow(int x,int y){
    int ret = 1;
    while(y>0){
        //pow(x,y) = pow(x^2,y/2);
        if(y&1) ret*=x;
        x = x*x;
        y = y>>1;
    }
    return ret;
}

int main(){
    cout<<quickpow(2,7)<<endl;
}