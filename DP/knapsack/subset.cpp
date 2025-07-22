//Given an array of integers arr[] and a target sum, determine whether there is a subset of the array with a sum equal to the target.

/*
At every index i, we have two choices:

Take the element arr[i] if it's ≤ current sum.

Skip the element.

So, if we are at index i and current target is sum:

If arr[i] <= sum:
return subset(i-1, sum - arr[i]) OR subset(i-1, sum)

Else:
return subset(i-1, sum)


*/

/*
Recursive Solution (without memoization)
bool subsetSumRecursive(int i, int sum, vector<int>& arr) {
    // Base Cases
    if (sum == 0) return true;       // Empty subset with 0 sum is always possible
    if (i == 0) return arr[0] == sum; // Only one element to consider

    // Choice diagram
    if (arr[i] <= sum) {
        return subsetSumRecursive(i - 1, sum - arr[i], arr) || subsetSumRecursive(i - 1, sum, arr);
    } else {
        return subsetSumRecursive(i - 1, sum, arr);
    }
}


*/


/*
We are solving the same (i, sum) again and again, so we memoize it in a 2D array dp[i][sum].

🔸 DP Dimensions:
i goes from 0 to n → rows → n

sum goes from 0 to target sum → columns → sum

So, dp[n][sum+1] where dp[i][s] means:
"Is there a subset of first i elements with sum s?"

bool subsetSumMemo(int i, int sum, vector<int>& arr, vector<vector<int>>& dp) {
    // Base Cases
    if (sum == 0) return true;
    if (i == 0) return arr[0] == sum;

    if (dp[i][sum] != -1) return dp[i][sum];

    if (arr[i] <= sum) {
        return dp[i][sum] = subsetSumMemo(i - 1, sum - arr[i], arr, dp) || subsetSumMemo(i - 1, sum, arr, dp);
    } else {
        return dp[i][sum] = subsetSumMemo(i - 1, sum, arr, dp);
    }
}


*/

/*

Initial DP Table Meaning
t[i][j] = Is it possible to get sum j using first i elements?

🔸 Initialization:
t[0][0] = true → sum 0 with 0 items is always possible

t[0][j] = false for j > 0 → can't form any sum with no elements


bool subsetSumTabulation(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> t(n + 1, vector<bool>(sum + 1, false));

    // Initialize first column (sum = 0) as true
    for (int i = 0; i <= n; i++) {
        t[i][0] = true;
    }

    // Fill DP table using choice diagram
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                // Choice: take or skip
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            } else {
                // No choice: skip
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum];
}




*/