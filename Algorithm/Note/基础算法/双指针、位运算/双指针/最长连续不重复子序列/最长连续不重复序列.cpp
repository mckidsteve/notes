#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100010;

int n;

int main()
{
    cin >> n;
    vector<int> v(n,0); //优化空间为On
    
    for(int i = 0;i < n; i ++) cin >> v[i]; //输入
    
    vector<int> tmp(N,0); //辅助数组,注意这里上限取为值的上限
    
    int res = 0;
    
    for(int i = 0,j = 0;i < n;i ++){
        tmp[v[i]] ++ ; // 频率标记数组，标记当前序列出现的数字的出现次数
        while(tmp[v[i]] > 1) --tmp[v[j++]]; // 如果频率超1，就要把重复元素前的全清掉--
        res = max(res,i - j + 1);
    }
    
    cout << res;
    return 0;
}