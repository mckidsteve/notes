#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, t;
pair<int, int> q[100010];

int main()
{
    //输入与排序
    cin >> s >> t;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> q[i].first >> q[i].second;

    sort(q, q + n);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        // 只判断覆盖了左端点的区间，其他的无需考虑
        if (q[i].first > s)
        {
            res = -1;
            break;
        }

        if (q[i].first <= s && q[i].second >= s)
        {
            int r = -2e9 - 10; //更新最大右端点
            for (int j = i; j < n; j++)
            {
                //双指针，从i开始寻找可以匹配到的最大右端点
                if (q[j].first <= s)
                {
                    r = max(r, q[j].second);
                    i = j;
                    // 寻找覆盖了左端点的区间中，右端点最大的区间
                }
            }
            s = r; //以当前最大右端点更新左端点，再次寻找可匹配的最大右端点
            res++; //每次更新意味着找到最优解中的一个区间
        }
        if (s >= t)
            break; //一旦更新左端点到右端点即可停止寻找
    }
    if (s < t)
        res = -1; //如果循环结束还是没有找到可以覆盖右端点的区间，则无解
    cout << res;
    return 0;
}