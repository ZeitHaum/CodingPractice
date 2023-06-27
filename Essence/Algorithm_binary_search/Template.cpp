#include <bits/stdc++.h>
using namespace std;

int data[5] {1,3,5,6,8};

auto binary_search(int n,int target){
    //二分查找数组第一个大于等于target的位置。
    //性质1: 小于target.
    //性质2: 大于等于target.
    int l = -1;
    int r = n;
    while(r - l>1){
        int mid = l+(r - l)/2;
        auto check = [&](){
            if(data[mid]<target) return 1; //满足性质1
            else return 2;
        };
        if(check()==1) l = mid;
        else r = mid;
    }
    return r;
}

int main(){
    auto p = binary_search(5,6);
    cout<<p;//data[3] = 6,输出3.
}