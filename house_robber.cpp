#include <bits/stdc++.h>
using namespace std; // pure recursive

int f(int ind, vector<int> &arr)
{
    if (ind == 0)
    {
        return arr[0];
    }
    if (ind < 0)
    {
        return 0;
    }

    int take = arr[ind] + f(ind - 2, arr);
    int not_take = 0 + f(ind - 1, arr);

    return max(take, not_take);
}
int main()
{
    vector<int> house = {4, 3, 7, 2, 6};

    int n = house.size();

    vector<int> temp1, temp2;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(house[i]);

        if (i != n - 1)
            temp2.push_back(house[i]);
    }

    int ans1 = f(n - 1, temp1);
    int ans2 = f(n - 1, temp2);
    cout << max(ans1, ans2) << endl;
}