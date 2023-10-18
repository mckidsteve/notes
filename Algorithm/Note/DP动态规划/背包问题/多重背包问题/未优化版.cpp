#include <iostream>
using namespace std;

const int M = 110;
int N, V;
int w[M], v[M], s[M];
int dp[M][M];

int main()
{
    cin >> N >> V;

    for (int i = 1; i <= N; i++)
    {
        cin >> v[i] >> w[i] >> s[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            for (int k = 0; k * v[i] <= j && k <= s[i]; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
            }
        }
    }

    cout << dp[N][V];
    return 0;
}