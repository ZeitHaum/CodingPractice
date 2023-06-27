#include <bits/stdc++.h>
using namespace std;

int main(){
    int m = 1;
    int n = 0;
    [=] () mutable {
        n++;
        cout<<"The value of n is changed to "<<n<<"."<<endl;
    }();//Parentheses at the end indicate the default call.
    cout<<"The value of n is "<<n<<"."<<endl;
}