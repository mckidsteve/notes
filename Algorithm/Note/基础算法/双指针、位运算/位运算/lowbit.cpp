#include <bits/stdc++.h>
using namespace std;

int lowbit(int x)
{
    return x & -x; // -x 是 x的补码（反码+1），两者按位与后可以得到其中的末位1
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        int res = 0;
        while (x)
            x -= lowbit(x), res++;
        cout << res << " ";
    }
    return 0;
}