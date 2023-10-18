#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

int n;
pair<int,int> ab[N];//pair数组

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    return a.second < b.second;
}//手写cmp，用于sort的排序

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    cin >> n;
    for(int i = 1;i <= n;i ++){
        int x,y;
        cin >> x >> y;
        ab[i] = {x,y};//pair的输入
    }
    
    sort(ab+1,ab+1+n,cmp);//sort
    
    int res = 0;//记录当前断点最少数量
    int r = -1e9 - 10;//当前最小右端点
    for(int i = 1;i <= n;i ++){
        if(ab[i].first > r){ // 若左端点＞最小右端点
            res ++;
            r = ab[i].second;
        }
        // r = min(ab[i].second,r)
        //待证
    }
    
    cout << res << '\n';
    
    return 0;
}