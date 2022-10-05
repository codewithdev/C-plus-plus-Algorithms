// Problem(3-D DP) : https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885

// Sample Inputs
// 3 4
// 2 3 1 2
// 3 4 2 2
// 5 6 3 5
// 2 2
// 1 1
// 1 2

// Corresponding Outputs
// 21
// 5

#include <bits/stdc++.h>
using namespace std;

// recursive function
int f(int i, int j1, int j2, vector<vector<int>> &grid, int n, int m, vector<vector<vector<int>>> &dp)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }
    int mx = INT_MIN;
    // if Alice can move to the left column in the row below
    if (((j1 - 1) >= 0))
    {
        // if Bob can move to the same column in the row below
        mx = max(mx, f(i + 1, j1 - 1, j2, grid, n, m, dp));
        // if Bob can move to the left column in the row below
        if ((j2 - 1) >= 0)
        {
            mx = max(mx, f(i + 1, j1 - 1, j2 - 1, grid, n, m, dp));
        }
        // if Bob can move to the right column in the row below
        if ((j2 + 1) < m)
        {
            mx = max(mx, f(i + 1, j1 - 1, j2 + 1, grid, n, m, dp));
        }
    }
    // if Alice can move to the same column in the row below
    // if Bob can move to the same column in the row below
    mx = max(mx, f(i + 1, j1, j2, grid, n, m, dp));
    // if Bob can move to the left column in the row below
    if ((j2 - 1) >= 0)
    {
        mx = max(mx, f(i + 1, j1, j2 - 1, grid, n, m, dp));
    }
    // if Bob can move to the right column in the row below
    if ((j2 + 1) < m)
    {
        mx = max(mx, f(i + 1, j1, j2 + 1, grid, n, m, dp));
    }
    // if Alice can move to the right column in the row below
    if (((j1 + 1) < m))
    {
        // if Bob can move to the same column in the row below
        mx = max(mx, f(i + 1, j1 + 1, j2, grid, n, m, dp));
        // if Bob can move to the left column in the row below
        if ((j2 - 1) >= 0)
        {
            mx = max(mx, f(i + 1, j1 + 1, j2 - 1, grid, n, m, dp));
        }
        // if Bob can move to the right column in the row below
        if ((j2 + 1) < m)
        {
            mx = max(mx, f(i + 1, j1 + 1, j2 + 1, grid, n, m, dp));
        }
    }
    if (j1 == j2)
    {
        // if same cell for both alice and bob, count chocolates only once
        return dp[i][j1][j2] = (mx + grid[i][j1]);
    }
    else
    {
        return dp[i][j1][j2] = (mx + grid[i][j1] + grid[i][j2]);
    }
}

// function returning answer
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c)));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            for (int k = 0; k < c; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }
    return f(0, 0, c - 1, grid, r, c, dp);
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << maximumChocolates(r, c, grid);
}
