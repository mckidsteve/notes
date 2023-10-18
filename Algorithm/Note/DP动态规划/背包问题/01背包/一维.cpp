#include <bits/stdc++.h>
using namespace std;

const int M = 1010;
int N, V;
int v[M], w[M];
int f[M];

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
        for (int j = V; j >= v[i]; j--)
        {
            f[j] = max(f[j - v[i]] + w[i], f[j]);
        }
    }
    cout << f[V];
    return 0;
}