#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string sub(const string& A, const string& B)
{
    string C;
    int t = 0;

    for (int i = A.size()-1, j = B.size()-1; i >= 0 || j >= 0 || t > 0; i--, j--)
    {
        if (i >= 0) t = (A[i] - '0') - t;
        if (j >= 0) t -= (B[j] - '0');
        C += ((t + 10) % 10 + '0');
        if (t < 0) t = 1;
        else t = 0;
    }
    while (C.size() > 1 && C.back() == '0') C.pop_back();
    reverse(C.begin(), C.end());
    return C;
}

bool cmp(const string& A, const string& B)
{
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = 0; i < A.size(); i++)
        if (A[i] != B[i]) return A[i] > B[i];
    return true;
}

int main ()
{
    string A, B;
    cin >> A >> B;

    if (cmp(A, B)) cout << sub(A, B) << endl;
    else cout << "-" << sub(B, A) << endl;

    return 0;
}
