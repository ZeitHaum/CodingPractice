#include <bits/stdc++.h>
using namespace std;

int main(){
    //Check the elements in the vector whether are all even numbers.
    vector<int> arr {1,3,5,7,9,11};
    vector<int> arr2 {2,4,6,8,10};
    
    auto even_check = [](vector <int>& arr){
        if(all_of(arr.begin(),arr.end(),[&](int i){return i%2==1;})) cout<<"Check passed."<<endl;
        else cout<<"Check unpassed."<<endl;
    };
    even_check(arr);
    even_check(arr2);
}

