/*
给定一个按照升序排列的长度为 n 的整数数组，以及 q 个查询。

对于每个查询，返回一个元素 k 的起始位置和终止位置（位置从 0 开始计数）。

如果数组中不存在该元素，则返回 -1 -1。

输入格式
第一行包含整数 n 和 q，表示数组长度和询问个数。

第二行包含 n 个整数（均在 1∼10000 范围内），表示完整数组。

接下来 q 行，每行包含一个整数 k，表示一个询问元素。

输出格式
共 q 行，每行包含两个整数，表示所求元素的起始位置和终止位置。

如果数组中不存在该元素，则返回 -1 -1。

数据范围
1≤n≤100000
1≤q≤10000
1≤k≤10000

*/
#include <bits/stdc++.h>
using namespace std;

int n,q,k;
int a[100010];

//从右缩小搜索第一个k值，即搜出第一个k的值前一个再加一
int search_start(int l,int r){
    while(l<r){
        int mid=l+r>>1;
        if(a[mid]>=k) r=mid;
        else l=mid+1;
    }
    if(a[l]!=k) l=-1;
    return l;
}

//从左搜索最后一个k值，停在第一个大于k的值处并且-1
int search_end(int l,int r){
    while (l<r)
    {
        int mid=l+r+1>>1;
        if(a[mid]<=k) l=mid;
        else r=mid-1;
    }
    if(a[l]!=k) l=-1;
    return l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //
    cin>>n>>q;
    for (int i = 0; i < n; i++) cin>>a[i];
    for (int i = 0; i < q; i++) {
        cin>>k;
        cout<<search_start(0,n-1)<<" ";
        cout<<search_end(0,n-1)<<endl;
    }
    return 0;
}