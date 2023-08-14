#include <bits/stdc++.h>
using namespace std;//recursive solution

int f(int i, int j)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }

    if (i < 0 || j < 0)
    {
        return 0;
    }

    int up = f(i - 1, j);
    int left = f(i, j - 1);

    return up + left;
}

int main()
{
        int m, n;
        cin >> m >> n;

        cout << f(m - 1, n - 1) << endl;
    
}