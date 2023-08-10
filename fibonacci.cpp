#include <bits/stdc++.h>
using namespace std;//recursion solution

int f(int n)
{
    if (n <= 1)
        return n;
    return f(n - 1) + f(n - 2);
}

int main() // fibonacci using dp
{
    int n;
    cin >> n;

    cout << f(n);
}