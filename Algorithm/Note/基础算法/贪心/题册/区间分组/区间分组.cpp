#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 1e5+10;
int n;
pair<int,int> s[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    cin >> n;
    int x,y;
    for(int i = 0;i < n;i ++){
        cin >> x >> y;
        s[i] = {x,y};
    }
    
    sort(s,s+n);
    
    //呜呜呜，换了半天还是用了优先队列
    priority_queue<int, vector<int>, greater<int>>q;
    //自动升序排列
    
    /*
    q.top为右端点最大值
    如果大于放入左端点，则向q放入一个新序列
    否则更新当前右端点
    */
    for(int i = 0;i < n;i ++){
        if (q.empty() || q.top() >= s[i].first) q.push(s[i].second);
        else
        {
            q.pop();
            q.push(s[i].second);
        }
    }
    
    cout << q.size();//一共开了多少组即为所求
    return 0;
}