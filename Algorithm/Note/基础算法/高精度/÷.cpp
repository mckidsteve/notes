vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> c;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        c.push_back(r / b);
        r %= b;
    }
    reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == 0)
    {
        c.pop_back();
    }
    return c;
}