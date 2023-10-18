/*输入一个长度为 n 的整数序列。

接下来再输入 m 个询问，每个询问输入一对 l,r。

对于每个询问，输出原序列中从第 l 个数到第 r 个数的和。

输入格式
第一行包含两个整数 n 和 m。

第二行包含 n 个整数，表示整数数列。

接下来 m 行，每行包含两个整数 l 和 r，表示一个询问的区间范围。

输出格式
共 m 行，每行输出一个询问的结果。

数据范围
1≤l≤r≤n,
1≤n,m≤100000,
−1000≤数列中元素的值≤1000
*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N],sum[N];

int main()
{
    int n,m,x;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        sum[i]=x+sum[i-1];
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }
    return 0;
}