#include <bits/stdc++.h>
using namespace std;

struct student{
    int math_score;
    int PE_score;
    bool operator>(const student& s1)const{ 
        if(this->math_score!=s1.math_score) return this->math_score > s1.math_score;
        else return this->PE_score>s1.PE_score;
    }    
};


int main(){
    vector<student> student_scores{{80,100},{90,70},{80,99},{70,100}};//初始化列表的嵌套使用
    greater<student> g;
    auto print = [](student i){
        cout<<i.math_score<<" "<<i.PE_score<<endl;
    };
    sort(student_scores.begin(),student_scores.end(),g);
    for_each(student_scores.begin(),student_scores.end(),print);
}