
#include <bits/stdc++.h>

using namespace std;

int trans(int x, int N)
{
    int sum = 0, i=0;
    while(x!=0)
    {
        sum += (x%10)*pow(N,i++);
        x /= 10;
    }
    return sum;
}

int main()
{
    int p, q, r;
    //cin>>p>>q>>r;
    cout<<trans(42,13);


    return 0;
}