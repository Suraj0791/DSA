/*

APPROACH-2


#include <iostream>
#include <vector>
using namespace std;

int knapsack(int n, int W, vector<int>& wt, vector<int>& val) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}


*/


#include <iostream>
#include <vector>
using namespace std;

int knapsack(int n, int W, vector<int>& wt, vector<int>& val) {
    // dp[i][w] = max value using first i items with total capacity w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                int include = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                int exclude = dp[i - 1][w];
                dp[i][w] = max(include, exclude);
            } else {
                dp[i][w] = dp[i - 1][w]; // can't include this item
            }
        }
    }

    return dp[n][W]; // final answer
}



/*
ADITYA VERMA APPROACH 
int knapSack(int w, int wt[], int val[], int n) 
    {
        int t[n+1][w+1];
        
        //Initialize matrix
        for(int i=0; i<w+1; i++) t[0][i] = 0;
        for(int j=0; j<n+1; j++) t[j][0] = 0;
        
        //Choice Diagram to code
        for(int i = 1; i<n+1; i++){
            for(int j=1; j<w+1; j++){
                //1. In case of choice
                if(wt[i-1] <= j){
                    t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], 0+t[i-1][j]);
                }
                //2. No choice
                else if(wt[i-1] > j){
                    t[i][j] = 0+t[i-1][j];
                }
            }
        }
        return t[n][w];
    }



*/
