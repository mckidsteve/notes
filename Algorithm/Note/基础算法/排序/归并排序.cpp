#include <bits/stdc++.h>
using namespace std;

int n;
int q[100010],tmp[100010];//归并排序需要一个额外数组用于存储

void merge_Sort(int q[],int l,int r){
    if(l>=r) return;//返回

    int mid=l+r>>1;//取中值
    merge_Sort(q,l,mid);//左部
    merge_Sort(q,mid+1,r);//右部
    int k=0,i=l,j=mid+1;//k作tmp的指针，i作左部，j作右部
    
    //核心
    while(i<=mid && j<=r){
        if(q[i]<q[j]) tmp[k++] = q[i++];//如果qi更小就把qi复制到tmp中
        else tmp[k++] = q[j++];//如果qj更小就把qj复制到tmp中
    }


    while(i<=mid) tmp[k++] = q[i++];//将左半边还未循环完的挪过来
    while(j<=r) tmp[k++] = q[j++];//将右半边还未循环完的挪过来
    for (i = l,k = 0; i <= r; i++,k++)
    {
        q[i] = tmp[k];
    }
    //最后将tmp数组替换原q数组

}
int main(){
    cin>>n;
    for (int k = 0; k < n; k++) cin>>q[k];
    merge_Sort(q,0,n-1);
    for (int k = 0; k < n; k++) cout<<q[k];
    return 0;
    
}