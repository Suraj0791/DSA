#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        // Base case: If we reach the end of the array, add the current subset to the result
        if (idx == nums.size()) {
            result.push_back(current);
            return;
        }

        // Case 1: Include the current element
        current.push_back(nums[idx]);
        solve(idx + 1, nums, current, result);
        current.pop_back(); // Backtrack

        // Case 2: Exclude the current element
        // Skip duplicates by moving idx to the next unique element
        while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) {
            idx++;
        }
        solve(idx + 1, nums, current, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        solve(0, nums, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = sol.subsetsWithDup(nums);

    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}

