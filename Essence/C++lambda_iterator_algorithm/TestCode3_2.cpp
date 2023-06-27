#include <bits/stdc++.h>
using namespace std;
#define int long long

//function 1
void func1(long long &i){
    i--;
}

signed main(){
    auto func2 = [&](long long &i){
        i++;
    };
    vector<int> arr{2,0,2,3};
    auto print_arr = [&](){for_each(arr.begin(),arr.end(),[](int i){cout<<" "<<i;});};//Print the array.

    for_each(arr.begin(),arr.end(),func1);
    print_arr();
    cout<<endl;
    for_each(arr.begin(),arr.end(),func2);
    print_arr();
    cout<<endl;
}