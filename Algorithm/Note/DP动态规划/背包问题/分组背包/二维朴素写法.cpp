#include <iostream>
using namespace std;

const int M = 110;
int v[M][M] , w[M][M] ,f[M][M],s[M];
int N,V;

int main()
{
    cin >> N >> V;
    for (int i = 1;i <= N;i ++){
        cin >> s[i];
        for(int j = 0;j < s[i];j ++){
            cin >> v[i][j] >> w[i][j];
        }
    }
    
    for(int i = 1;i <= N;i ++){
        for(int j = 1;j <= V;j ++){
            f[i][j] = f[i-1][j];
            for(int k = 0;k < s[i];k ++){
                if(j >= v[i][k]) f[i][j] = max(f[i][j] , f[i-1][j - v[i][k]] + w[i][k]);
            }
        }
    }
    cout << f[N][V];
    return 0;
}
