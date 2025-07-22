/*
Imagine you're solving a big puzzle — and you keep solving the same sub-puzzle again and again.

That’s exactly what recursion does in 0/1 Knapsack:

It solves the same (i, capacity) pair many times — wasting time.

knapsack(3, 10) calls knapsack(2, 10)
knapsack(2, 10) calls knapsack(1, 10)
...
→ These subproblems repeat many times!
This leads to exponential time → super slow for big inputs.

Memoization Solves That
Memoization says:

"I’ll store the result of each (i, capacity) combination so I don’t redo it."

✅ Result:
Each (i, W) subproblem is solved only once

Time goes from exponential → polynomial

🧠 Why Use a 2D Array?
Because:

One variable is i = index (which item we're on)

Another is W = current capacity

These are the only two things that change in recursion!

dp[i][W] = result of knapsack(i, W)


🔍 What Each Cell Represents
dp[i][W] means:

"What's the maximum profit I can get using items from 0 to i with a bag of capacity W?"

✅ It stores the result of that subproblem.


❓Can Rows and Columns Be Interchanged?
Technically yes — but:

Row = item index → feels natural to track what item we're on

Column = current capacity → natural to track bag space

So it’s better not to swap them unless you're very sure.



*/



// ✅ How to Memoize Any Recursive Function (Generic Steps)
// int solve(i, j) {
//     // base case
//     if (...) return ...;

//     // work and recursion
//     return max(solve(i-1, j), solve(i, j-1));
// }


// To Memoize it:
// Create a DP table: dp[i][j] (initialized to -1)

// Before doing work, check:
// if (dp[i][j] != -1) return dp[i][j];

// Before returning, store the result
// dp[i][j] = result;
// return result;



#include <iostream>
#include <vector>
using namespace std;

int knapsack(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if (i < 0 || W == 0) return 0;

    if (dp[i][W] != -1) return dp[i][W];

    if (wt[i] <= W) {
        int take = val[i] + knapsack(i - 1, W - wt[i], wt, val, dp);
        int skip = knapsack(i - 1, W, wt, val, dp);
        dp[i][W] = max(take, skip);
    } else {
        dp[i][W] = knapsack(i - 1, W, wt, val, dp);
    }

    return dp[i][W];
}

int main() {
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {10, 40, 50, 70};
    int W = 8;
    int n = wt.size();

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    cout << "Maximum Profit: " << knapsack(n - 1, W, wt, val, dp) << endl;
    return 0;
}




/*approach 2 
#include <iostream>
#include <vector>
using namespace std;

int knapsack(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if (i < 0 || W == 0) return 0;

    if (dp[i][W] != -1) return dp[i][W];

    int take = 0;
    if (wt[i] <= W)
        take = val[i] + knapsack(i - 1, W - wt[i], wt, val, dp);

    int skip = knapsack(i - 1, W, wt, val, dp);

    dp[i][W] = max(take, skip);
    return dp[i][W];
}

int main() {
    vector<int> wt = {1, 3, 4, 5};
    vector<int> val = {10, 40, 50, 70};
    int W = 8;
    int n = wt.size();

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));

    cout << "Maximum Profit: " << knapsack(n - 1, W, wt, val, dp) << endl;
    return 0;
}
*/

