
#include <bits/stdc++.h>
using namespace std;
const int N=1000000+100;
int a[N],n,m,i,j;
int main()//C++ Stl使人快乐
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

