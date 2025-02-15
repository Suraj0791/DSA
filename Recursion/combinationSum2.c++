class Solution {
public:
    void solve(int idx, vector<int>& ds, vector<vector<int>>& ans, int target, vector<int>& candidates) {
        // Base case: If the target is reached, add the combination to the result
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        // If index is out of bounds, return
        if (idx >= candidates.size()) return;

        // Include the current element (only if it doesn't exceed the target)
        if (candidates[idx] <= target) {
            ds.push_back(candidates[idx]);
            solve(idx + 1, ds, ans, target - candidates[idx], candidates);
            ds.pop_back(); // Backtrack
        }

        // Skip duplicate elements
        int nextIdx = idx + 1;
        while (nextIdx < candidates.size() && candidates[nextIdx] == candidates[idx]) {
            nextIdx++;
        }

        // Exclude the current element and move to the next
        solve(nextIdx, ds, ans, target, candidates);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, ds, ans, target, candidates);
        return ans;
    }
};


#include <vector>
#include <algorithm>
using namespace std;

void backtrack(int index, vector<int>& candidates, int target, vector<int>& currentCombination, vector<vector<int>>& result) {
    // Base case: If target is 0, add the combination to the result
    if (target == 0) {
        result.push_back(currentCombination);
        return;
    }

    for (int i = index; i < candidates.size(); i++) {
        // Skip duplicates
        if (i > index && candidates[i] == candidates[i - 1]) {
            continue;
        }

        // If the current candidate exceeds the target, stop further exploration
        if (candidates[i] > target) {
            break;
        }

        // Include the current candidate
        currentCombination.push_back(candidates[i]);

        // Recurse with the next index (move forward since each number can be used once)
        backtrack(i + 1, candidates, target - candidates[i], currentCombination, result);

        // Backtrack: Remove the last added element
        currentCombination.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> currentCombination;

    // Sort the array to handle duplicates and make it easier to skip
    sort(candidates.begin(), candidates.end());

    // Start backtracking
    backtrack(0, candidates, target, currentCombination, result);

    return result;
}
