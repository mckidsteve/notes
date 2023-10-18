#include <iostream>
using namespace std;

const int M = 12010;
int N,V;
int v[M] , w[M] ;
int f[M]; // 空间开大了好像

int main()
{
    cin >> N >> V;
    
    int a,b,s;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        cin >> a >> b >> s;
        int k = 1;
        for(;k <= s; k *= 2){
            v[++cnt] = a * k; // 物品体积分堆
            w[cnt] = b * k; // 物品价值分堆
            s -= k; // 拆分数量，二进制优化
        }
        if(s > 0){ // 余下的一组
            v[++cnt] = a * s;
            w[cnt] = b * s;
        }
    }
    
    N = cnt; // 更新物品数量
    
    for(int i = 1; i <= N; i ++){
        for(int j = V; j >= v[i]; j --){
            f[j] = max(f[j] , f[j - v[i]] + w[i]);
        }
    }
    
    cout << f[V];
    return 0;
}