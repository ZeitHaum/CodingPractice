# C++ lambda表达式

C++ 11以上特性。

![image](fig1.png){width="90%"}

## capture子句

用于访问(捕获)外部变量。
\[=\]用于值捕获，\[&\]用于引用捕获，\[this\]捕获外部类指针this(\[&\]默认包含\[this\])。
补充:\[args\...\]用于捕获外部可变参数模板。

## 返回类型

编译器自动推导。也可以使用关键字"-\>"指定，此时不能省略空参数列表。

## mutable

在按值捕获时无法在作用域内修改外部变量的值，使用mutable修饰后可以解决这个问题。但是修改仅限于lambda表达式内部生效。

``` {.c++ language="c++"}
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
```

输出结果为

![image](fig3.png){width="50%"}

# 迭代器

迭代器用于访问顺序容器(主要是vector和数组)。

## 分类

分为正向迭代器、常量正向迭代器、反向迭代器、常量反向迭代器。
比较常用的是正向迭代器和反向迭代器，反向迭代器的开始和结束分别为rbegin()和rend()。

二者区别在于正向迭代器++返回顺序容器后一个数，后者返回前一个数。
以下是二者使用的一个例子:

``` {.c++ language="c++"}
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
```

输出结果为

![image](fig4.png){width="70%"}

数组的迭代器就是指针，使用"数组名+N"的形式表示。

## 不同容器中的迭代器

根据容器类型的不同，可将迭代器分为正向迭代器、双向迭代器、随机访问迭代器，
限制依次呈递减趋势。 其中数组和vector的迭代器都是随机访问迭代器。
其支持的功能如下:

![image](fig5.png){width="50%"}

另外p2 - p1 和p1 \< p2均有定义(和索引类似)。

不同容器的迭代器类型如下:

![image](fig6.png){width="50%"}

## 辅助函数

C++ 中关于迭代器的辅助函数为advance、distance、iter_swap; 其功能如下:

![image](fig7.png){width="90%"}

# algorithm库中常用函数

algorithm是C++ 标准库之一，需使用using namespace std;语句引入名称空间。

algorithm库函数具有丰富的可扩展性，这些需要使用lambda表达式和迭代器实现。

## all_of

对列表中的元素执行谓词，如果都为真返回true.

例子:

``` {.c++ language="c++"}
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
```

输出:

![image](fig8.png){width="30%"}

## any_of

和all_of区别是有任一为真即返回true.

## none_of

无一为真返回true.

## for_each

为每个函数执行操作，输入可以是函数指针也可以是lambda表达式。

例子:

``` {.c++ language="c++"}
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
```

输出结果为

![image](fig9.png){width="90%"}

## generate

类似于for_each,只是更新方式由参数指针修改变为返回值赋值。

## generate_n

类似于generate,只是结束迭代器被换为了大小n。(从开始迭代器开始，包含开始迭代器。)

## includes

对于两个**已经排序好的(增序)**的范围\[first1,last1)
和\[first2,last2),检查对于\[first2,last2)中的元素，
是否**所有的**元素都被包含在\[first1,last1)中。

若\[first1,last1)为空，C++98返回不确定值，而C++11返回真。

例子:

``` {.c++ language="c++"}
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
```

输出结果为

![image](fig10.png){width="60%"}

## inplace_merge

合并两部分**已经排好序的**数组，不常用。

## is_heap

检查一个数组是否是一个堆。

## is_heap_until

返回一个数组第一个不满足堆性质的非法字符。

## is_partitioned

若满足谓词性质的元素均在不满足谓词的元素前返回true,否则返回false.

# 参考文献 {#参考文献 .unnumbered}

\[1\]. [Microsoft C++、C 和
汇编程序](https://learn.microsoft.com/zh-cn/cpp/cpp/lambda-expressions-in-cpp?view=msvc-170)

\[2\]. [C++ algorithm
头文件下常用函数整理](https://blog.nowcoder.net/n/91357602b82d4377917a35afde085ff8)

\[3\].
[C++迭代器（STL迭代器）iterator详解](http://c.biancheng.net/view/338.html)

\[4\].
[cplusplus.com-algorithm](https://cplusplus.com/reference/algorithm/)
