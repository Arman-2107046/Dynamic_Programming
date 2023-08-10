#include <bits/stdc++.h>
using namespace std;

int f(int n)//recursive
{
    if (n == 0)
        return 1;

    if (n == 1)
        return 1;

    int left = f(n - 1);
    int right = f(n - 2);

    return left + right;
}

int main() // climbing stairs
{
    int n;
    cin >> n;

    cout << f(n) << endl;
}
