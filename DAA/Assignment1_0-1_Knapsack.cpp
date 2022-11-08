#include <bits/stdc++.h>
using namespace std;

// knapsack function get maximum profit using dynamic programming
int knapsack(vector<int> profit, vector<int> weight, int capacity)
{
    // 2D vector dp for dynamic programming initialised
    vector<vector<int>> dp(profit.size() + 1, vector<int>(capacity + 1, 0));

    //
    for (int i = 0; i <= weight.size(); i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            // i or j is zero, update the value in dp vector
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else
            {
                if (j - weight[i - 1] >= 0)
                {
                    // two cases
                    int dontCount = dp[i - 1][j];
                    int count = dp[i - 1][j - weight[i - 1]] + profit[i - 1];
                    dp[i][j] = max(dontCount, count);
                }

                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }

    return dp[profit.size()][capacity];
}

// driver function
int main()
{
    // vector to store profit array
    // vector<int> profit = {1, 2, 5, 6};

    // vector to store weights of the individual objects
    // vector<int> weight = {2, 3, 4, 5};
    int n, capacity;
    cout << "\nEnter number of items :- ";
    cin >> n;
    vector<int> profit(n);
    vector<int> weight(n);

    cout << "\nEnter values of profit :- ";
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }

    cout << "\nEnter values of weights :- ";
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    cout << "\nEnter capacity of knapsack :- ";
    cin >> capacity;

    // calling the knapsack function
    int ans = knapsack(profit, weight, capacity);
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout << "\nThe maximum profit is :- " << ans;
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}