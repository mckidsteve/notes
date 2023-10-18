/*
给定一个整数 n，将数字 1∼n 排成一排，将会有很多种排列方法。

现在，请你按照字典序将所有的排列方法输出。

输入格式
共一行，包含一个整数 n。

输出格式
按字典序输出所有排列方案，每个方案占一行。

数据范围
1≤n≤7
*/


#include <bits/stdc++.h>
using namespace std;

int n;//自定义的最大长度（总的n层）
int path[10];//用于储存输出的情况
bool state[10];//储存此点是否被使用过

//深度搜索dfs
void dfs(int x = 1){
    if(x > n) //边界条件，x的层数越过总的n层时即输出
    {
        for(int i = 1;i <= n; i ++){
            printf("%d ",path[i]);
        }
        cout<<endl;
    }
    //dfs核心：递归遍历
    for (int i = 1; i <= n; i ++)
    {
        if(!state[i]){//判断该是否使用过
            path[x] = i;//赋给path这个没有使用过的值
            state[i] = true;//将此值改为使用过
            dfs(x+1);//递归
            state[i] = false;//回溯归位
        }
    }
}

int main(){
    cin>>n;
    dfs();
    return 0;
}