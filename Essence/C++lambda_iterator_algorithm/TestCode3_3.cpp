#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9};
    int b[] = {};
    int c[] = {2,4,5,8};
    int d[] = {7,8,9,10};
    auto check = [&a](int* arr,int size){//Size is the size of the array.
        if(includes(a,a+9,arr,arr+size))cout<<"All elements are in the array."<<endl;
        else cout<<"Some elements are not in the array."<<endl;
    };
    check(b,0);
    check(c,4);
    check(d,4);
}