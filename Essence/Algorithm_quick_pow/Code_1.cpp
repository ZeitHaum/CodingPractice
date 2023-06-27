#include <bits/stdc++.h>
using namespace std;

int quickpow(int x,int y){
    if(y==0) return 1;
    int temp = quickpow(x,y/2);
    if(y%2==1) return x*temp*temp;
    else return temp*temp;
}

int main(){
    cout<<quickpow(2,7)<<endl;
}