#include <iostream>
#include <vector>
using namespace std;



// 🔍 Key Differences from 0/1 Knapsack:
// In 0/1 Knapsack, we do: t[i-1][j - wt[i]]

// In Unbounded, we do: t[i][j - wt[i]] → because we can reuse the item again (stay on same i)



int unboundedKnapsackRecursive(int wt[], int val[], int i, int W) {
    if (i == 0) {
        // Can take as many of item 0 as possible
        return (W / wt[0]) * val[0];
    }

    if (wt[i] <= W) {
        // Take it (stay on same index) or skip it
        return max(val[i] + unboundedKnapsackRecursive(wt, val, i, W - wt[i]),
                   unboundedKnapsackRecursive(wt, val, i - 1, W));
    } else {
        return unboundedKnapsackRecursive(wt, val, i - 1, W);
    }
}


int dp[1001][1001]; // adjust as needed

int unboundedKnapsackMemo(int wt[], int val[], int i, int W) {
    if (i == 0) {
        return (W / wt[0]) * val[0];
    }

    if (dp[i][W] != -1) return dp[i][W];

    if (wt[i] <= W) {
        return dp[i][W] = max(val[i] + unboundedKnapsackMemo(wt, val, i, W - wt[i]),
                              unboundedKnapsackMemo(wt, val, i - 1, W));
    } else {
        return dp[i][W] = unboundedKnapsackMemo(wt, val, i - 1, W);
    }
}


int unboundedKnapsackBottomUp(int wt[], int val[], int n, int W) {
    int t[n + 1][W + 1];

    // Initialization
    for (int i = 0; i <= n; i++) t[i][0] = 0; // 0 capacity → 0 value
    for (int j = 0; j <= W; j++) t[0][j] = (j / wt[0]) * val[0]; // Only item 0 unlimited

    // Fill DP table
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 1; j <= W; j++) {
            if (wt[i] <= j) {
                t[i][j] = max(val[i] + t[i][j - wt[i]], t[i - 1][j]);
            } else {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n - 1][W];
}


int main() {
    int wt[] = {2, 4, 6};
    int val[] = {5, 11, 13};
    int W = 10;
    int n = 3;

    cout << "Max value: " << unboundedKnapsackRecursive(wt, val, n - 1, W) << endl;
}


