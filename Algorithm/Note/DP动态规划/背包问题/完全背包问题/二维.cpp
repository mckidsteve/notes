#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
// O2

#include <iostream>
using namespace std;
const int M = 1010;
int N, V;
int v[M], w[M];
int f[M][M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> V;
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i] >> w[i];
    }
    // f[i][j] = max(f[i][j] , f[i-1][j - k * v[i]] + k * w[i]);
    // 暴力做法TLE

    // f[i][j] = max(f[i][j] , f[i-1][j - v] + w , f[i-1][j - 2v] + 2w , ...... , f[i-1][j - kv] + kw)
    // f[i][j - v] = max(    , f[i][j - v]       , f[i-1][j - 2v] + w  , ...... , f[i-1][j - kv] + (k-1)w , //f[i-1][j - (k+1)v] + kw)

    // f[i][j] = max(f[i][j] , f[i][j - v] + w)

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }
    }
    cout << f[N][V];
    return 0;
}