#include <bits/stdc++.h>
using namespace std;

const int M = 1010;
int N, V;
int v[M], w[M];
int f[M][M];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i] >> w[i];
    }

    // f[0][1 ~ n] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= V; j++)
        {
                f[i][j] = f[i - 1][j];
                if(j >= v[i])) f[i][j] = max(f[i - 1][j - v[i]] + w[i], f[i - 1][j]);
        }
    }
    cout << f[N][V];
    return 0;
}