#include <memory>//智能指针头文件
#include <bits/stdc++.h>
using namespace std;

struct test{
    int id;
};

int main(){
    unique_ptr<int> int_ptr = unique_ptr<int>(new int()); //构造函数
    cout<<(*int_ptr); //获取左值对象
    unique_ptr<test> test_ptr = unique_ptr<test>(new test());
    cout<<test_ptr->id; 
}