#include <bits/stdc++.h>
using namespace std;

int main(){
    list<int> a;
    a.emplace_front(1);
    auto a1 = a.begin();// a1 -> 1
    a.emplace_front(2); 
    a.emplace_back(3); //链表结构: 2->1 -> 3
    auto a2 = a.begin(); // a2 -> 2
    auto a3 = a1++; // a3 -> 3
    a.erase(a1); //链表结构: 2 -> 3

    //Check iterator Unchanged.
    cout<<(a.begin()==a2); 
    auto new_a3 = ++a.begin();
    cout<<(new_a3 == a3);
    
}