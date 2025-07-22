//same as of subest sum 
//we will use that only just a little bit of modify


/*   
Given an array arr[] of size n, determine whether you can partition it into two subsets such that the sum of elements in both subsets is equal.

🎯 Key Insight:
Let total sum be S.

If S is odd, it's impossible to divide into two equal parts → return false.

If S is even, check if there exists a subset with sum S/2.

So this reduces to a Subset Sum problem with target = S / 2.


#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(int index, int target, vector<int>& arr) {
    if (target == 0) return true;
    if (index < 0) return false;

    if (arr[index] <= target) {
        bool take = isSubsetSum(index - 1, target - arr[index], arr);
        bool skip = isSubsetSum(index - 1, target, arr);
        return take || skip;
    } else {
        return isSubsetSum(index - 1, target, arr);
    }
}

bool canPartition(vector<int>& arr) {
    int total = 0;
    for (int num : arr) total += num;

    // If total sum is odd, we cannot partition into two equal subsets
    if (total % 2 != 0) return false;

    int target = total / 2;
    return isSubsetSum(arr.size() - 1, target, arr);
}

int main() {
    vector<int> arr = {1, 5, 11, 5};

    if (canPartition(arr)) cout << "YES, Equal Partition Exists\n";
    else cout << "NO, Equal Partition Not Possible\n";

    return 0;
}




*/


//We need to check if a subset with sum = total_sum / 2 exists.

/*   
We need to check if a subset with sum = total_sum / 2 exists.

This is Subset Sum, so we’ll use:

t[n+1][sum+1] table

n = size of array

sum = total_sum / 2


*/

#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& arr) {
    int n = arr.size();
    int total = 0;
    for (int i = 0; i < n; i++) total += arr[i];

    // If total is odd, cannot divide into two equal subsets
    if (total % 2 != 0) return false;

    int sum = total / 2;

    // Create DP table
    bool t[n + 1][sum + 1];

    // Initialize
    for (int i = 0; i <= n; i++) t[i][0] = true;    // sum=0 is always possible (empty subset)
    for (int j = 1; j <= sum; j++) t[0][j] = false; // sum > 0 with 0 elements is not possible

    // Fill the table using the choice diagram
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j) {
                // Include or exclude the current element
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            } else {
                // Can't include current element
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum]; // Final result
}

int main() {
    vector<int> arr = {1, 5, 11, 5};

    if (canPartition(arr)) cout << "YES, Equal Partition Exists\n";
    else cout << "NO, Equal Partition Not Possible\n";

    return 0;
}
