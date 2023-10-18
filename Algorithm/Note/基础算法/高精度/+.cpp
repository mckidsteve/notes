#include <iostream>
#include <vector>
using namespace std;

string a, b;

// add
vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size())
        return add(B, A);

    vector<int> c;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t += A[i];
        if (i < B.size())
            t += B[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if (t)
        c.push_back(t);
    return c;
}

int main()
{
    cin >> a >> b;
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    auto c = add(A, B);

    for (int i = c.size() - 1; i >= 0; i--)
        cout << c[i];
    cout << endl;
    return 0;
}