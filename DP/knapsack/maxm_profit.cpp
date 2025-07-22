#include <iostream>
#include <vector>
using namespace std;

// Recursive function to calculate max profit
int knapsack(int i, int capacity, vector<int>& weight, vector<int>& value) {
    // Base case: no more items or no capacity
    if (i == 0) {
        if (weight[0] <= capacity) return value[0];
        else return 0;
    }

    // Option 1: skip the current item
    int skip = knapsack(i - 1, capacity, weight, value);

    // Option 2: take the current item (only if it fits)
    int take = 0;
    if (weight[i] <= capacity) {
        take = value[i] + knapsack(i - 1, capacity - weight[i], weight, value);
    }

    // Return the better of two options
    return max(take, skip);
}

int main() {
    vector<int> weight = {1, 3, 4, 5};
    vector<int> value = {10, 40, 50, 70};
    int maxCapacity = 8;
    int n = weight.size();

    int maxProfit = knapsack(n - 1, maxCapacity, weight, value);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}


// //🔁 Final Recap:
// At every step, we explore both paths:

// Pick the item (if possible)

// Skip the item

// Then we return:
// return max(take, skip);


// weight = {1, 3, 4}
// value  = {10, 40, 50}
// capacity = 4

//                              knapsack(2, 4)
//                              /           \
//                          take            skip
//                     wt[2]=4<=4 ✅       skip item 2
//                   +val[2]=50           don't add value
//                      ↓                      ↓
//                knapsack(1, 0)          knapsack(1, 4)
//                  (no room left)           /       \
//                                         take      skip
//                                      wt[1]=3<=4 ✅   skip
//                                    +val[1]=40         ↓
//                                       ↓         knapsack(0,4)
//                                knapsack(0,1)         /     \
//                              wt[0]=1<=1 ✅        take     skip
//                            +val[0]=10              ↓        ↓
//                                ↓             knapsack(–1, 3) knapsack(–1, 4)
//                          knapsack(–1, 0)       → 0            → 0
//                              → 0




//                              📌 Key Takeaways from the Tree:
// The tree grows by branching into two decisions at each level: take or skip.

// Each leaf returns a final profit, which bubbles up via max(take, skip) at every node.

// At the top level, you get the maximum total profit possible.





/*
approach-2

If wt[i] <= W:  // It fits in the bag
     ➤ 1. Take the item
     ➤ 2. Don’t take the item

If wt[i] > W:   // It doesn’t fit
     ➤ 3. You MUST skip the item



               knapsack(i, W)
               ┌─────────────┐
        wt[i] <= W?         NO
          /   \              \
      YES     YES            Only Skip
     /         \
Take            Skip




int knapsack(int i, int W, vector<int>& wt, vector<int>& val) {
    // Base Case: no items or capacity
    if (i < 0 || W == 0) return 0;

    // If item fits
    if (wt[i] <= W) {
        // 1. Take it
        int take = val[i] + knapsack(i - 1, W - wt[i], wt, val);
        
        // 2. Skip it
        int skip = knapsack(i - 1, W, wt, val);
        
        // Return max of both choices
        return max(take, skip);
    }
    else {
        // 3. Can't take, only skip
        return knapsack(i - 1, W, wt, val);
    }
}




*/



/*

✅ The Clean Template:
Whenever you’re solving a 0/1 decision problem (like knapsack, subsets, coins, etc), this thinking applies:

int take = 0;
if (can_take(i, capacity)) {
    take = ... + f(i-1, new_capacity);
}
int skip = f(i-1, capacity);
return max(take, skip);


What are the decisions I can make?

Take the item

Skip the item

What are the conditions for those decisions?

I can only take it if it fits: wt[i] <= W

So I’ll do:

skip = f(i-1, W)

take = 0, and if wt[i] <= W, then:

take = val[i] + f(i-1, W - wt[i])





*/