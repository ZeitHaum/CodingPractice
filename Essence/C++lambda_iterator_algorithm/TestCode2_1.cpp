#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr {1,2,3,4,5,6,7,8,9};
    cout<<"The elements of the array are ";
    for(vector<int>::iterator i = arr.begin();i<arr.end();i++){
        cout<<*i<<" ";
    }
    cout<<"."<<endl;
    cout<<"The elements of the reversed array are ";
    for(vector<int>::reverse_iterator i = arr.rbegin();i<arr.rend();i++){
        cout<<*i<<" ";
    }
    cout<<"."<<endl;

}