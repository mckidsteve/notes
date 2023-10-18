#include <bits/stdc++.h>
using namespace std;

int n, q, a[100010];

void query(int k)
{
    int l = 0, r = n - 1;

    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (a[mid] <= k)
            l = mid;
        else
            r = mid - 1;
    }

    if (a[r] != k)
    {
        cout << "-1 -1\n";
        return;
    }

    int res = r;
    l = 0;

    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (a[mid] >= k)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << " " << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int k;
    while (q--)
    {
        cin >> k;
        query(k);
    }

    return 0;
}